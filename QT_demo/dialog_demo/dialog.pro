#-------------------------------------------------
#
# Project created by QtCreator 2019-09-10T22:03:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dialog
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mydialog.cpp

HEADERS  += mainwindow.h \
    mydialog.h

FORMS    += mainwindow.ui \
    mydialog.ui

RESOURCES += \
    icons.qrc
