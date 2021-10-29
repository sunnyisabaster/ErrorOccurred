# -*- coding: utf-8 -*-
"""
Created on Wed Jul 14 10:46:19 2021

@author: admin
"""

from PyQt5 import QtCore, QtWidgets
#from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox, QFileDialog
from PyQt5.QtCore import pyqtSignal, QThread, QSize, Qt
from PyQt5.QtGui import QImage, QPixmap, QTextCursor
import sys
import cv2 
import numpy as  np
import matplotlib
import matplotlib.image as img

##########################################
#ui界面设置
class Ui_MainWindow(object):

    def setupUi(self, MainWindow):
    
        #主窗口参数设置
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1080, 980)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")

        # 设置按键参数
        self.file = QtWidgets.QPushButton(self.centralwidget)
        self.file.setGeometry(QtCore.QRect(157, 900, 175, 28))
        self.file.setObjectName("file") 
        self.file.setStyleSheet("background-color:rgb(111,180,219)")
        self.file.setStyleSheet(
            "QPushButton{background-color:rgb(111,180,219)}"  # 按键背景色
            "QPushButton:hover{color:green}"  # 光标移动到上面后的前景色
            "QPushButton{border-radius:6px}"  # 圆角半径
            "QPushButton:pressed{background-color:rgb(180,180,180);border: None;}"  # 按下时的样式
        )

        # 设置显示窗口参数
        self.fileT = QtWidgets.QPushButton(self.centralwidget)
        self.fileT.setGeometry(QtCore.QRect(350, 900, 550, 28))
        self.fileT.setObjectName("file")
        self.fileT.setStyleSheet("background-color:rgb(111,180,219)")
        self.fileT.setStyleSheet(
            "QPushButton{background-color:rgb(111,180,219)}"  # 按键背景色
            "QPushButton:hover{color:green}"  # 光标移动到上面后的前景色
            "QPushButton{border-radius:6px}"  # 圆角半径
            "QPushButton:pressed{background-color:rgb(180,180,180);border: None;}"  # 按下时的样式
        )
        
        # cmd box
        self.cmd = QtWidgets.QTextBrowser(self.centralwidget)
        self.cmd.setGeometry(QtCore.QRect(157, 650, 740, 200))
        self.cmd.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAsNeeded)
        self.cmd.setObjectName("cmd")
        
        # Text edit 1 floor 1
        self.numFloor1 = QtWidgets.QLineEdit(self.centralwidget)
        self.numFloor1.setGeometry(QtCore.QRect(25, 550, 50, 30))
        #self.numFloor1.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAsNeeded)
        self.numFloor1.setObjectName("numFloor1")
        self.numFloor1.raise_()
        
        # water avg pic show
        self.water_avg = QtWidgets.QGroupBox(self.centralwidget)
        self.water_avg.setGeometry(QtCore.QRect(25, 30, 512, 512))
        self.water_avg.setObjectName("water_avg")
        self.water_avg.raise_()
        
        self.water_avg_show = QtWidgets.QLabel(self.centralwidget)
        self.water_avg_show.setGeometry(QtCore.QRect(25, 30, 512, 512))
        self.water_avg_show.setObjectName("water_avg_show")
        self.water_avg_show.raise_()
        
        # different materials avg pic show
        self.diff_mat_avg = QtWidgets.QGroupBox(self.centralwidget)
        self.diff_mat_avg.setGeometry(QtCore.QRect(547, 30, 512, 512))
        self.diff_mat_avg.setObjectName("diff_mat_avg")
        self.diff_mat_avg.raise_()
        
        self.diff_mat_avg_show = QtWidgets.QLabel(self.centralwidget)
        self.diff_mat_avg_show.setGeometry(QtCore.QRect(547, 30, 512, 512))
        self.diff_mat_avg_show.setObjectName("diff_mat_avg_show")
        self.diff_mat_avg_show.raise_()
        
        # Text edit 2 floor 2
        self.numFloor2 = QtWidgets.QLineEdit(self.centralwidget)
        self.numFloor2.setGeometry(QtCore.QRect(547, 550, 50, 30))
        #self.numFloor2.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAsNeeded)
        self.numFloor2.setObjectName("numFloor2")
        self.numFloor2.raise_()
        
        # change cmd output to text browser
        self.th = MyThread()
        self.th.signalForText.connect(self.onUpdateText)
        sys.stdout = self.th


        #主窗口及菜单栏标题栏设置
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 848, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

        ################button按钮点击事件回调函数################

        self.file.clicked.connect(self.msg)
        #self.fileD.clicked.connect(self.get_clips)


    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "HU Value Detector"))
        self.file.setText(_translate("MainWindow", "选择文件"))
        self.fileT.setText(_translate("MainWindow", ""))
        self.water_avg.setTitle(_translate("MainWindow", "Water Average calculation"))
        self.diff_mat_avg.setTitle(_translate("MainWindow", "Different Materials Average calculation"))
   
    #########更新cmd#########
    def onUpdateText(self,text):
        cursor = self.cmd.textCursor()
        cursor.movePosition(QTextCursor.End)
        cursor.insertText(text)
        self.cmd.setTextCursor(cursor)
        self.cmd.ensureCursorVisible()

    #########选择文件#########

    def msg(self,Filepath):
        m = QtWidgets.QFileDialog.getOpenFileName(None,"选取文件","C:/", "(*.raw)")  # 起始路径
        self.fileT.setText(str(m[0]))
        # read raw file and convert float64 to float32
        #read raw file and convert float64 to float32
        filtered_img_smoothed=np.fromfile(str(m[0]), dtype='int16')
        
        #("Select 1 floor is: ", self.numFloor1.text())
        
        # num of floor 1 for water 102
        floor1 = int(self.numFloor1.text())
        
        
        # num of floor 2 for diff materials 205
        floor2 = int(self.numFloor2.text())
        
        print("Select water's floor is : ", floor1)
        print("Select different materials's floor is : ", floor2)
        
        # calculate water HU value
        img_arr = []
        for ii in range(300):
            slice_1 = 1024*1024*ii
            slice_2 = 1024*1024*(ii+1)
        
            img_arr.append(filtered_img_smoothed[slice_1 : slice_2])
        
        filtered_img = np.array(img_arr).reshape(300, 1024, 1024)
        
        #102
        models_arr = filtered_img[floor1: floor1+1]
        
        
        x0 = 512 + 187 * np.cos(0 * np.pi / 180)
        y0 = 512 + 187 * np.sin(0 * np.pi /180)
        
        x45 = 512 + 187 * np.cos(45 * np.pi / 180)
        y45 = 512 + 187 * np.sin(45 * np.pi /180)
        
        x90 = 512 + 187 * np.cos(90 * np.pi / 180)
        y90 = 512 + 187 * np.sin(90 * np.pi /180)
        
        x135 = 512 + 187 * np.cos(135 * np.pi / 180)
        y135 = 512 + 187 * np.sin(135 * np.pi /180)
        
        x180 = 512 + 187 * np.cos(180 * np.pi / 180)
        y180 = 512 + 187 * np.sin(180 * np.pi /180)
        
        x225 = 512 + 187 * np.cos(225 * np.pi / 180)
        y225 = 512 + 187 * np.sin(225 * np.pi /180)
        
        x270 = 512 + 187 * np.cos(270 * np.pi / 180)
        y270 = 512 + 187 * np.sin(270 * np.pi /180)
        
        x315 = 512 + 187 * np.cos(-45 * np.pi / 180)
        y315 = 512 + 187 * np.sin(-45 * np.pi /180)
        
        
        
        radius=51
        roi=np.zeros([1024,1024],dtype="uint8")
        cv2.circle(roi,(512, 512),radius,255,-1) #mid
        cv2.circle(roi,(round(x0), round(y0)),radius,255,-1) #3
        cv2.circle(roi,(round(x90), round(y90)),radius,255,-1) #6
        cv2.circle(roi,(round(x180), round(y180)),radius,255,-1) #9
        cv2.circle(roi,(round(x270), round(y270)),radius,255,-1) #12
        
        
        cv2.circle(roi,(round(x45), round(y45)),radius,255,-1) #45deg
        cv2.circle(roi,(round(x135), round(y135)),radius,255,-1) #45deg
        cv2.circle(roi,(round(x225), round(x225)),radius,255,-1) #135deg
        cv2.circle(roi,(round(x315), round(y315)),radius,255,-1) #315deg
        
        #save image as png
        masked_aim=cv2.bitwise_and(models_arr[0],models_arr[0],mask=roi)
        
        #均匀度 中间
        radius=51
        models_arr = filtered_img[floor1: floor1+1]
        roi=np.zeros([1024,1024],dtype="uint8")
        cv2.circle(roi,(512, 512),radius,1,-1)
        masked=cv2.bitwise_and(models_arr[0],models_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_mid  = np.sum(masked)/roi_area
        print("water's slice mid HU value is: ",round(average_pixel_mid, 2))
        cv2.putText(masked_aim, str(round(average_pixel_mid, 2)), (512, 512), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        #均匀度 3点
        models_arr = filtered_img[floor1: floor1+1]
        roi=np.zeros([1024,1024],dtype="uint8")
        cv2.circle(roi,(round(x0), round(y0)),radius,255,-1)
        masked=cv2.bitwise_and(models_arr[0],models_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_3  = np.sum(masked)/roi_area
        print("water's slice 0 deg HU value is: ",round(average_pixel_3, 2))
        cv2.putText(masked_aim, str(round(average_pixel_3, 2)), (round(x0), round(y0)), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        
        #均匀度 45deg
        #radius=51
        models_arr = filtered_img[floor1: floor1+1]
        roi=np.zeros([1024,1024],dtype="uint8")
        cv2.circle(roi,(round(x45), round(y45)),radius,255,-1)
        masked=cv2.bitwise_and(models_arr[0],models_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_45_deg  = np.sum(masked)/roi_area
        print("water's slice 45 deg HU value is: ",round(average_pixel_45_deg, 2))
        cv2.putText(masked_aim, str(round(average_pixel_45_deg, 2)), (round(x45), round(y45)), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        #均匀度 6点
        #radius=51
        models_arr = filtered_img[floor1: floor1+1]
        roi=np.zeros([1024,1024],dtype="uint8")
        cv2.circle(roi,(round(x90), round(y90)),radius,255,-1)
        masked=cv2.bitwise_and(models_arr[0],models_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_6  = np.sum(masked)/roi_area
        print("water's slice 90 deg HU value is: ",round(average_pixel_6, 2))
        cv2.putText(masked_aim, str(round(average_pixel_6, 2)), (round(x90), round(y90)), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        #均匀度 135deg
        #radius=51
        models_arr = filtered_img[floor1: floor1+1]
        roi=np.zeros([1024,1024],dtype="uint8")
        cv2.circle(roi,(round(x135), round(y135)),radius,255,-1)
        masked=cv2.bitwise_and(models_arr[0],models_arr[0],mask=roi)
        roi_area = np.pi*radius*radius      
        average_pixel_135_deg  = np.sum(masked)/roi_area
        print("water's slice 135 deg HU value is: ",round(average_pixel_135_deg, 2))
        cv2.putText(masked_aim, str(round(average_pixel_135_deg, 2)), (round(x135), round(y135)), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        
        #均匀度 9点
        #radius=51 
        models_arr = filtered_img[floor1: floor1+1]
        roi=np.zeros([1024,1024],dtype="uint8")
        cv2.circle(roi,(round(x180), round(y180)),radius,255,-1)
        masked=cv2.bitwise_and(models_arr[0],models_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_9  = np.sum(masked)/roi_area
        print("water's slice 180 deg HU value is: ",round(average_pixel_9, 2))
        cv2.putText(masked_aim, str(round(average_pixel_9, 2)), (round(x180), round(y180)), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        #均匀度 225deg
        #radius=51
        models_arr = filtered_img[floor1: floor1+1]
        roi=np.zeros([1024,1024],dtype="uint8")
        cv2.circle(roi,(round(x225), round(y225)),radius,255,-1)
        masked=cv2.bitwise_and(models_arr[0],models_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_225_deg  = np.sum(masked)/roi_area
        print("water's slice 225 deg HU value is: ",round(average_pixel_225_deg, 2))
        cv2.putText(masked_aim, str(round(average_pixel_225_deg, 2)), (round(x225), round(y225)), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        
        #均匀度 12点
        #radius=51
        
        models_arr = filtered_img[floor1: floor1+1]
        roi=np.zeros([1024,1024],dtype="uint8")
        cv2.circle(roi,(round(x270), round(y270)),radius,255,-1)
        masked=cv2.bitwise_and(models_arr[0],models_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_12  = np.sum(masked)/roi_area
        print("water's slice 270 deg HU value is: ",round(average_pixel_12, 2))
        cv2.putText(masked_aim, str(round(average_pixel_12, 2)), (round(x270), round(y270)), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        #均匀度 315deg
        #radius=51
        models_arr = filtered_img[floor1: floor1+1]
        roi=np.zeros([1024,1024],dtype="uint8")
        cv2.circle(roi,(round(x315), round(y315)),radius,255,-1)
        masked=cv2.bitwise_and(models_arr[0],models_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_315_deg  = np.sum(masked)/roi_area
        print("water's slice 315 deg HU value is: ",round(average_pixel_315_deg, 2))
        cv2.putText(masked_aim, str(round(average_pixel_315_deg, 2)), (round(x315), round(y315)), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        # save img as png
        matplotlib.image.imsave('water.png', masked_aim, cmap = "gray")
        
        print("The water average HU value is: ", round((average_pixel_mid + average_pixel_3 + average_pixel_45_deg + average_pixel_6 + average_pixel_135_deg + average_pixel_9 + average_pixel_225_deg + average_pixel_12 + average_pixel_315_deg)/9, 2))

        # calculate different materials HU value
        # Draw pics
        
        
        # 205
        materials_arr = filtered_img[floor2: floor2+1]
        radius=40
        
        roi=np.zeros(materials_arr.shape[1: 3],dtype="uint8")
        cv2.circle(roi,(493+19, 747-2),radius,255,-1)
        cv2.circle(roi,(611+21, 717-4),radius,255,-1)
        cv2.circle(roi,(757-10, 515-5),radius,255,-1)
        cv2.circle(roi,(643-14, 311-3),radius,255,-1)
        cv2.circle(roi,(394+3, 307),radius,255,-1)
        cv2.circle(roi,(263+13, 509+5),radius,255,-1)
        cv2.circle(roi,(376+18, 714),radius,255,-1)
        
        diff_masked=cv2.bitwise_and(materials_arr[0],materials_arr[0],mask=roi)
        
        
        # AIR
        radius=23
        materials_arr = filtered_img[floor2: floor2+1]
        roi=np.zeros(materials_arr.shape[1: 3],dtype="uint8")
        cv2.circle(roi,(493+19, 747-2),radius,255,-1)
        masked=cv2.bitwise_and(materials_arr[0],materials_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_air  = np.sum(masked)/roi_area
        print("Air average HU value is: ", round(average_pixel_air, 2))
        cv2.putText(diff_masked, str(round(average_pixel_air, 2)), (493+19+radius, 747-2), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        
        # PMP
        radius=23
        materials_arr = filtered_img[floor2: floor2+1]
        roi=np.zeros(materials_arr.shape[1: 3],dtype="uint8")
        cv2.circle(roi,(611+19, 717-4),radius,255,-1)
        masked=cv2.bitwise_and(materials_arr[0],materials_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_air  = np.sum(masked)/roi_area
        print("PMP average HU value is: ", round(average_pixel_air, 2))
        cv2.putText(diff_masked, str(round(average_pixel_air, 2)), (611+19+radius, 717-4), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        # LDPE
        radius=23
        materials_arr = filtered_img[floor2: floor2+1]
        roi=np.zeros(materials_arr.shape[1: 3],dtype="uint8")
        cv2.circle(roi,(757-10, 515-5),radius,255,-1)
        masked=cv2.bitwise_and(materials_arr[0],materials_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_air  = np.sum(masked)/roi_area
        print("LDPE average HU value is: ", round(average_pixel_air, 2))
        cv2.putText(diff_masked, str(round(average_pixel_air, 2)), (757-10+radius, 515-5), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        # POLY
        radius=23
        materials_arr = filtered_img[floor2: floor2+1]
        roi=np.zeros(materials_arr.shape[1: 3],dtype="uint8")
        cv2.circle(roi,(643-14, 311-3),radius,255,-1)
        masked=cv2.bitwise_and(materials_arr[0],materials_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_air  = np.sum(masked)/roi_area
        print("Polystyrene average HU value is: ", round(average_pixel_air, 2))
        cv2.putText(diff_masked, str(round(average_pixel_air, 2)), (643-14+radius, 311-3), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        # Acrylic
        radius=23
        materials_arr = filtered_img[floor2: floor2+1]
        roi=np.zeros(materials_arr.shape[1: 3],dtype="uint8")
        cv2.circle(roi,(394+3, 307),radius,255,-1)
        masked=cv2.bitwise_and(materials_arr[0],materials_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_air  = np.sum(masked)/roi_area
        print("Acrylic average HU value is: ", round(average_pixel_air, 2))
        cv2.putText(diff_masked, str(round(average_pixel_air, 2)), (394+3+radius, 307), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        # Derlin
        radius=23
        materials_arr = filtered_img[floor2: floor2+1]
        roi=np.zeros(materials_arr.shape[1: 3],dtype="uint8")
        cv2.circle(roi,(263+13, 509+5),radius,255,-1)
        masked=cv2.bitwise_and(materials_arr[0],materials_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_air  = np.sum(masked)/roi_area
        print("Derlin average HU value is: ", round(average_pixel_air, 2))
        cv2.putText(diff_masked, str(round(average_pixel_air, 2)), (263+13+radius, 509+5), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        # Teflon
        radius=23
        materials_arr = filtered_img[floor2: floor2+1]
        roi=np.zeros(materials_arr.shape[1: 3],dtype="uint8")
        cv2.circle(roi,(376+18, 714),radius,255,-1)
        masked=cv2.bitwise_and(materials_arr[0],materials_arr[0],mask=roi)
        roi_area = np.pi*radius*radius    
        average_pixel_air  = np.sum(masked)/roi_area
        print("Teflon average HU value is: ", round(average_pixel_air, 2))
        cv2.putText(diff_masked, str(round(average_pixel_air, 2)), (376+18+radius, 714), cv2.FONT_HERSHEY_PLAIN,
                    1.0, -1030, thickness=1)
        
        # save img as png
        matplotlib.image.imsave('diff_materials.png', diff_masked, cmap = "gray")
        
        
        # zoom
        scale = 1
        img = QImage("water.png")
        mgnWidth = int(512 * scale)  
        mgnHeight = int(512 * scale)
        size = QSize(mgnWidth, mgnHeight)
        pixImg = QPixmap.fromImage(img.scaled(size, Qt.IgnoreAspectRatio))
        self.water_avg_show.resize(mgnWidth, mgnHeight)
        self.water_avg_show.setPixmap(pixImg)
        im = cv2.imread("water.png", cv2.IMREAD_GRAYSCALE)
        cv2.imshow("water", im)
        
        # zoom
        scale = 1
        img = QImage("diff_materials.png")
        mgnWidth = int(512 * scale)  
        mgnHeight = int(512 * scale)
        size = QSize(mgnWidth, mgnHeight)
        pixImg = QPixmap.fromImage(img.scaled(size, Qt.IgnoreAspectRatio))
        self.diff_mat_avg_show.resize(mgnWidth, mgnHeight)
        self.diff_mat_avg_show.setPixmap(pixImg)
        im = cv2.imread("diff_materials.png", cv2.IMREAD_GRAYSCALE)
        cv2.imshow("different materials", im)

class MyThread(QThread):
    signalForText = pyqtSignal(str)

    def __init__(self,data=None, parent=None):
        super(MyThread, self).__init__(parent)
        self.data = data

    def write(self, text):
        self.signalForText.emit(str(text))  # 发射信号
    
    def flush(self):
        pass

#########主函数入口 #########
if __name__ == '__main__': 
    app = QtWidgets.QApplication(sys.argv)

    mainWindow = QtWidgets.QMainWindow()

    ui = Ui_MainWindow()

    ui.setupUi(mainWindow)

    mainWindow.show()

    sys.exit(app.exec_())

