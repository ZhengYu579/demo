#-------------------------------------------------
#
# Project created by QtCreator 2019-10-23T21:34:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = thread
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mythread.cpp \
    mythread2.cpp

HEADERS  += mainwindow.h \
    mythread.h \
    mythread2.h

FORMS    += mainwindow.ui
