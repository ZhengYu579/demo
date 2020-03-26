#-------------------------------------------------
#
# Project created by QtCreator 2019-09-12T21:34:24
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServer
TEMPLATE = app


SOURCES += main.cpp \
    tcpserver.cpp

HEADERS  += \
    tcpserver.h

FORMS    += \
    tcpserver.ui
