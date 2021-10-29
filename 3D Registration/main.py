import sys

from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox, QFileDialog
from PyQt5.QtGui import QImage, QPixmap, QTextCursor
from PyQt5.QtCore import pyqtSignal, QThread, QSize, Qt
from Registration import Ui_MainWindow

import os
import time
import datetime as dt
import threading as th
import ctypes
import inspect
import copy
import numpy as np 
 
import pyrealsense2 as rs
import open3d as o3d
import cv2

DELAY = 0

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
 
        # Set up the user interface from Designer.
        self.setupUi(self)
 
        self.dis_update.connect(self.camera_view)
        
        # Show current 2d depth png pic
        self.pushButton_takephotos.clicked.connect(self.pushButton_takephotos_clicked)
        
        # Show current 3d pointcloud button
        self.show_current_pointcloud.clicked.connect(self.show_current_pointcloud_clicked)
        
        # Select and show target 3d pointcloud button
        self.show_target_pointcloud.clicked.connect(self.show_target_pointcloud_clicked)
        
        self.registration_button.clicked.connect(self.registration_button_clicked)
        
        # change cmd output to text browser
        self.th = MyThread()
        self.th.signalForText.connect(self.onUpdateText)
        sys.stdout = self.th
        
        self.thread_camera = None
        self.takePhotos = False
        self.showCurrent3dPointCloud = False
        
 
    # 在对应的页面类的内部，与def定义的函数同级
    dis_update = pyqtSignal(QPixmap)
    
    def onUpdateText(self,text):
        cursor = self.cmd.textCursor()
        cursor.movePosition(QTextCursor.End)
        cursor.insertText(text)
        self.cmd.setTextCursor(cursor)
        self.cmd.ensureCursorVisible()
    
    def pushButton_takephotos_clicked(self):
        self.takePhotos = True
    
    def show_current_pointcloud_clicked(self):
        self.showCurrent3dPointCloud = True
        #print(self.showCurrent3dPointCloud)
    
    def show_target_pointcloud_clicked(self,Filepath):
        global target_dir
        
        c = QFileDialog.getOpenFileName(None, "Select the target file","C:/", "(*.ply)")
        print("Showing Target 3D pointcloud...")
        if c is not None:
            print("File dir is ", c[0])
            print("Succeed...")
            target_file_dir = str(c[0])
            pcd = o3d.io.read_point_cloud(target_file_dir)
            o3d.visualization.draw_geometries([pcd])
            
            target_dir = target_file_dir
            
    # add an event for exit the GUI
    def closeEvent(self, event):
        """我们创建了一个消息框，上面有俩按钮：Yes和No.第一个字符串显示在消息框的标题栏，第二个字符串显示在对话框，
              第三个参数是消息框的俩按钮，最后一个参数是默认按钮，这个按钮是默认选中的。返回值在变量reply里。"""
 
        reply = QMessageBox.question(self, 'Message', "Are you sure to quit?",
                                     QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        # 判断返回值，如果点击的是Yes按钮，我们就关闭组件和应用，否则就忽略关闭事件
        if reply == QMessageBox.Yes:
            self.stop_thread(self.thread_camera)
            event.accept()
            sys.stdout = sys.__stdout__
        else:
            event.ignore()
    
    
    # click event and register
    def registration_button_clicked(self):
        
        start = time.time()
        voxel_size = 0.05  # means 5cm for this dataset
        
        print(":: Load two point clouds and disturb initial pose.")
        source_reg = o3d.io.read_point_cloud(source_dir)
        target_reg = o3d.io.read_point_cloud(target_dir)
        
        # process data
        print(":: Downsample with a voxel size %.3f." % voxel_size)
        source_down = source_reg.voxel_down_sample(voxel_size)
        target_down = target_reg.voxel_down_sample(voxel_size)
    
        radius_normal = voxel_size * 2
        print(":: Estimate normal with search radius %.3f." % radius_normal)
        
        source_down.estimate_normals(
            o3d.geometry.KDTreeSearchParamHybrid(radius=radius_normal, max_nn=30))
        target_down.estimate_normals(
            o3d.geometry.KDTreeSearchParamHybrid(radius=radius_normal, max_nn=30))
    
        radius_feature = voxel_size * 5
        print(":: Compute FPFH feature with search radius %.3f." % radius_feature)
        source_fpfh = o3d.pipelines.registration.compute_fpfh_feature(
            source_down,
            o3d.geometry.KDTreeSearchParamHybrid(radius=radius_feature, max_nn=100))
        target_fpfh = o3d.pipelines.registration.compute_fpfh_feature(
            target_down,
            o3d.geometry.KDTreeSearchParamHybrid(radius=radius_feature, max_nn=100))
        
        
        print("prepare_dataset took %.3f sec.\n" % (time.time() - start))
        
        # global registration
        distance_threshold = voxel_size * 1.5
        print(":: RANSAC registration on downsampled point clouds.")
        print("   Since the downsampling voxel size is %.3f," % voxel_size)
        print("   we use a liberal distance threshold %.3f." % distance_threshold)
        result_ransac = o3d.pipelines.registration.registration_ransac_based_on_feature_matching(
            source_down, target_down, source_fpfh, target_fpfh, True,
            distance_threshold,
            o3d.pipelines.registration.TransformationEstimationPointToPoint(False),
            3, [
                o3d.pipelines.registration.CorrespondenceCheckerBasedOnEdgeLength(
                    0.9),
                o3d.pipelines.registration.CorrespondenceCheckerBasedOnDistance(
                    distance_threshold)
            ], o3d.pipelines.registration.RANSACConvergenceCriteria(100000, 0.999))
        
        print(result_ransac)
        
        print("execute_global_registration took %.3f sec.\n" % (time.time() - start))
        
        # refine registration (ICP registration)
        distance_threshold = voxel_size * 0.4
        print(":: Point-to-plane ICP registration is applied on original point")
        print("   clouds to refine the alignment. This time we use a strict")
        print("   distance threshold %.3f." % distance_threshold)
        
        print(":: Downsample with a voxel size %.3f." % voxel_size)
        source_down = source_reg.voxel_down_sample(voxel_size)
        target_down = target_reg.voxel_down_sample(voxel_size)
    
        radius_normal = voxel_size * 2
        print(":: Estimate normal with search radius %.3f." % radius_normal)
        
        source_down.estimate_normals(
            o3d.geometry.KDTreeSearchParamHybrid(radius=radius_normal, max_nn=30))
        target_down.estimate_normals(
            o3d.geometry.KDTreeSearchParamHybrid(radius=radius_normal, max_nn=30))
    
        radius_feature = voxel_size * 5
        print(":: Compute FPFH feature with search radius %.3f." % radius_feature)
        source_fpfh = o3d.pipelines.registration.compute_fpfh_feature(
            source_down,
            o3d.geometry.KDTreeSearchParamHybrid(radius=radius_feature, max_nn=100))
        target_fpfh = o3d.pipelines.registration.compute_fpfh_feature(
            target_down,
            o3d.geometry.KDTreeSearchParamHybrid(radius=radius_feature, max_nn=100))
        
        print(source_reg, target_reg, source_down, target_down, source_fpfh, target_fpfh)
        
        
        result_icp = o3d.pipelines.registration.registration_icp(
            source_down, target_down, distance_threshold, result_ransac.transformation,
            o3d.pipelines.registration.TransformationEstimationPointToPlane())
        
        print(result_icp)
        print("refine_registration took %.3f sec.\n" % (time.time() - start))
        
        self.show_results.setText("The transform Matrix is \n" + str(result_icp.transformation))
        
        source_temp = copy.deepcopy(source_reg)
        target_temp = copy.deepcopy(target_reg)
        source_temp.paint_uniform_color([1, 0.706, 0])
        target_temp.paint_uniform_color([0, 0.651, 0.929])
        source_temp.transform(result_icp.transformation)
        
        o3d.visualization.draw_geometries([source_temp, target_temp])
        
        
    def open_camera(self):
        # target选择开启摄像头的函数
        self.thread_camera = th.Thread(target=self.open_realsense)
        self.thread_camera.start()
        print('Open Camera...')
 
    def camera_view(self, c):
        # 调用setPixmap函数设置显示Pixmap
        self.label_show.setPixmap(c)
        # 调用setScaledContents将图像比例化显示在QLabel上
        self.label_show.setScaledContents(True)
 
    def _async_raise(self, tid, exctype):
        """raises the exception, performs cleanup if needed"""
        tid = ctypes.c_long(tid)
        if not inspect.isclass(exctype):
            exctype = type(exctype)
        res = ctypes.pythonapi.PyThreadState_SetAsyncExc(tid, ctypes.py_object(exctype))
        if res == 0:
            raise ValueError("invalid thread id") 
        elif res != 1:
            # """if it returns a number greater than one, you're in trouble,
            # and you should call it again with exc=NULL to revert the effect"""
            ctypes.pythonapi.PyThreadState_SetAsyncExc(tid, None)
            raise SystemError("PyThreadState_SetAsyncExc failed")
 
    def stop_thread(self, thread):
        self._async_raise(thread.ident, SystemExit)
 
    def open_realsense(self):
        
        global source_dir
        
        print('open_realsense')
        
        # Create a pipeline
        pipeline = rs.pipeline()
 
        # Create a config and configure the pipeline to stream
        #  different resolutions of color and depth streams
        config = rs.config()
        config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
        config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
 
        # Start streaming
        profile = pipeline.start(config)
 
        # Getting the depth sensor's depth scale (see rs-align example for explanation)
        depth_sensor = profile.get_device().first_depth_sensor()
        depth_scale = depth_sensor.get_depth_scale()
        print("Depth Scale is: ", depth_scale)
 
        # We will be removing the background of objects more than
        #  clipping_distance_in_meters meters away
        clipping_distance_in_meters = 1  # 1 meter
        clipping_distance = clipping_distance_in_meters / depth_scale
 
        
        # Processing blocks
        pc = rs.pointcloud()
        thr_filter = rs.threshold_filter()
        thr_filter.set_option(rs.option.min_distance, 0)
        thr_filter.set_option(rs.option.max_distance, 1.830)
        
        # Color Intrinsics
        # intr = color_frame.profile.as_video_stream_profile().intrinsics
 
        # Create an align object
        # rs.align allows us to perform alignment of depth frames to others frames
        # The "align_to" is the stream type to which we plan to align depth frames.
        align_to = rs.stream.color
        align = rs.align(align_to)
 
        # Streaming loop
        try:
            while True:
                # Get frameset of color and depth
                frames = pipeline.wait_for_frames()
                # frames.get_depth_frame() is a 640x360 depth image
 
                # Align the depth frame to color frame
                aligned_frames = align.process(frames)
 
                # Get aligned frames
                aligned_depth_frame = aligned_frames.get_depth_frame()  # aligned_depth_frame is a 640x480 depth image
                color_frame = aligned_frames.get_color_frame()
 
                # Validate that both frames are valid
                if not aligned_depth_frame or not color_frame:
                    continue
                
                aligned_depth_frame = thr_filter.process(aligned_depth_frame)
                
                depth_image = np.asanyarray(aligned_depth_frame.get_data())
                color_image = np.asanyarray(color_frame.get_data())
                
                #aligned_depth_frame = aligned_frames.first(aligned_depth_frame).as_video_frame()
                
                points = pc.calculate(aligned_depth_frame)
 
                if(self.takePhotos == True):
                    
                    now_date = dt.datetime.now().strftime('%F')
                    now_time = dt.datetime.now().strftime('%F_%H%M%S')
 
                    path_ok = os.path.exists(now_date)
                    if(path_ok == False):
                        os.mkdir(now_date)
 
                    if(os.path.isdir(now_date)):
                        #id = "1"
 
                        depth_full_path = ''
                        color_full_path = ''
 
                        depth_col = cv2.applyColorMap(cv2.convertScaleAbs(depth_image, alpha=0.03), cv2.COLORMAP_JET)
                            
                        depth_full_path = os.path.join('./', now_date, now_time + '_depth.png')
                        depth_col_full_path = os.path.join('./', now_date, now_time + '_depth_col.png')
                        color_full_path = os.path.join('./', now_date, now_time + '_color.png')
                        ply_full_path = os.path.join('./', now_date, now_time + '_pointcloud.ply')
 
                        cv2.imencode('.png', depth_image)[1].tofile(depth_full_path)
                        cv2.imencode('.png', color_image)[1].tofile(color_full_path)
                        cv2.imencode('.png', depth_col)[1].tofile(depth_col_full_path)
                        points.export_to_ply(ply_full_path, color_frame)
                        
                        
                        print('Saved Successful...')
                        
                        # show current depth pic
                        # zoom
                        scale = 0.8
                        img = QImage(depth_col_full_path)
                        mgnWidth = int(640 * scale)  
                        mgnHeight = int(480 * scale)
                        size = QSize(mgnWidth, mgnHeight)
                        pixImg = QPixmap.fromImage(img.scaled(size, Qt.IgnoreAspectRatio))
                        self.show_currentPointCloud.resize(mgnWidth, mgnHeight)
                        self.show_currentPointCloud.setPixmap(pixImg)
                     
                        source_dir = ply_full_path
                    self.takePhotos = False
                    
                if(self.showCurrent3dPointCloud == True and self.takePhotos == False):
                    print(ply_full_path)
                    pcd = o3d.io.read_point_cloud(ply_full_path)
                    o3d.visualization.draw_geometries([pcd])
                    print("Showing the current 3D Pointcloud in Open3D GUI")
                        
                    self.showCurrent3dPointCloud = False  
 
 
                # Remove background - Set pixels further than clipping_distance to grey
                grey_color = 153
                depth_image_3d = np.dstack(
                    (depth_image, depth_image, depth_image))  # depth image is 1 channel, color is 3 channels
                bg_removed = np.where((depth_image_3d > clipping_distance) | (depth_image_3d <= 0), grey_color,
                                      color_image)
 
                images = bg_removed
 
 
                qimage = QImage(images, 640, 480, QImage.Format_RGB888)
                pixmap = QPixmap.fromImage(qimage)
                self.dis_update.emit(pixmap)
                
                
 
                time.sleep(DELAY)
                
        finally:
            pipeline.stop()

class MyThread(QThread):
    signalForText = pyqtSignal(str)

    def __init__(self,data=None, parent=None):
        super(MyThread, self).__init__(parent)
        self.data = data

    def write(self, text):
        self.signalForText.emit(str(text))  # 发射信号
    
    def flush(self):
        pass
    
if __name__ == "__main__":
    app = QApplication(sys.argv)
    app.aboutToQuit.connect(app.deleteLater)
    w = MainWindow()
    w.show()
 
    w.open_camera()
 
    sys.exit(app.exec_())