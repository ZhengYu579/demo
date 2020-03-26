#-------------------------------------------------
#
# Project created by QtCreator 2019-09-23T22:29:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myOpenCV
TEMPLATE = app


SOURCES += main.cpp\
    myopencv.cpp

HEADERS  += \
    myopencv.h

FORMS    += mainwindow.ui
INCLUDEPATH += D:/openCV/install/include
INCLUDEPATH += D:/openCV/install/include/opencv
INCLUDEPATH += D:/openCV/install/include/opencv2
LIBS += D:/openCV/install/x86/mingw/lib/libopencv_*.a
