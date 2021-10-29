# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Test.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1920, 1080)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.label_show = QtWidgets.QLabel(self.centralwidget)
        self.label_show.setGeometry(QtCore.QRect(320, 50, 640, 480))
        self.label_show.setObjectName("label_show")
        
        self.depth_bg = QtWidgets.QTextBrowser(self.centralwidget)
        self.depth_bg.setGeometry(QtCore.QRect(319, 50, 642, 480))
        self.depth_bg.setObjectName("depth_bg")
        self.depth_bg.raise_()
        
        self.camera_Stream = QtWidgets.QGroupBox(self.centralwidget)
        self.camera_Stream.setGeometry(QtCore.QRect(300, 20, 681, 541))
        self.camera_Stream.setObjectName("camera_Stream")
        self.camera_Stream.raise_()
        
        self.show_currentPointCloud = QtWidgets.QLabel(self.centralwidget)
        self.show_currentPointCloud.setGeometry(QtCore.QRect(30, 570, 640, 480))
        self.show_currentPointCloud.setObjectName("show_currentPointCloud")
        
        self.depth_png = QtWidgets.QGroupBox(self.centralwidget)
        self.depth_png.setGeometry(QtCore.QRect(10, 555, 550, 405))
        self.depth_png.setObjectName("depth_png")
        self.depth_png.raise_()
        
        self.pushButton_takephotos = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_takephotos.setGeometry(QtCore.QRect(130, 520, 101, 41))
        self.pushButton_takephotos.setObjectName("pushButton_takephotos")
        
        self.show_current_pointcloud = QtWidgets.QPushButton(self.centralwidget)
        self.show_current_pointcloud.setGeometry(QtCore.QRect(130, 960, 101, 41))
        self.show_current_pointcloud.setObjectName("show_current_pointcloud")
        
        self.show_target_pointcloud = QtWidgets.QPushButton(self.centralwidget)
        self.show_target_pointcloud.setGeometry(QtCore.QRect(760, 730, 101, 41))
        self.show_target_pointcloud.setObjectName("show_target_pointcloud")
        
        self.registration_button = QtWidgets.QPushButton(self.centralwidget)
        self.registration_button.setGeometry(QtCore.QRect(1410, 525, 101, 41))
        self.registration_button.setObjectName("registration_button")
        
        self.cmd = QtWidgets.QTextBrowser(self.centralwidget)
        self.cmd.setGeometry(QtCore.QRect(1130, 41, 642, 480))
        self.cmd.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAsNeeded)
        self.cmd.setObjectName("cmd")
        #self.cmd.raise_()
        
        self.show_results = QtWidgets.QTextBrowser(self.centralwidget)
        self.show_results.setGeometry(QtCore.QRect(1130, 570, 642, 421))
        self.show_results.setObjectName("show_results")
        #self.show_results.raise_()
        
        self.outPut_box = QtWidgets.QGroupBox(self.centralwidget)
        self.outPut_box.setGeometry(QtCore.QRect(1110, 20, 681, 981))
        self.outPut_box.setObjectName("outPut_box")
        self.outPut_box.raise_()
        
        self.label_show.raise_()
        self.show_currentPointCloud.raise_()
        self.pushButton_takephotos.raise_()
        self.registration_button.raise_()
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1300, 23))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "CBCT Registration V0.0"))
        self.pushButton_takephotos.setText(_translate("MainWindow", "Save Pointcloud"))
        self.show_current_pointcloud.setText(_translate("MainWindow", "Show Pointcloud"))
        self.show_target_pointcloud.setText(_translate("MainWindow", "Select Target"))
        self.registration_button.setText(_translate("MainWindow", "Registration"))
        self.camera_Stream.setTitle(_translate("MainWindow", "Camera Streaming"))
        self.depth_png.setTitle(_translate("MainWindow", "2D Depth Image"))
        self.outPut_box.setTitle(_translate("MainWindow", "Output"))

