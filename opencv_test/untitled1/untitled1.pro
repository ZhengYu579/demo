#-------------------------------------------------
#
# Project created by QtCreator 2019-09-22T21:54:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
INCLUDEPATH += D:/openCV/install/include
INCLUDEPATH += D:/openCV/install/include/opencv
INCLUDEPATH += D:/openCV/install/include/opencv2
LIBS += D:/openCV/install/x86/mingw/lib/libopencv_*.a
