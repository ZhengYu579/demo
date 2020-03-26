#-------------------------------------------------
#
# Project created by QtCreator 2019-09-22T14:56:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += D:/openCV/install/include
INCLUDEPATH += D:/openCV/install/include/opencv
INCLUDEPATH += D:/openCV/install/include/opencv2
LIBS += D:/openCV/install/x86/mingw/lib/libopencv_*.a
