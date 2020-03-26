#-------------------------------------------------
#
# Project created by QtCreator 2019-09-12T21:53:46
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = someschat
TEMPLATE = app


SOURCES += main.cpp \
    tcpserver.cpp \
    server.cpp \
    tcpclientsocket.cpp

HEADERS  += \
    tcpserver.h \
    server.h \
    tcpclientsocket.h

FORMS    += tcpserver.ui

RESOURCES += \
    ../icons.qrc
