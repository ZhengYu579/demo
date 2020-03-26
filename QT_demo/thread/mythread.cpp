#include "mythread.h"


MyThread::MyThread(QObject *parent)
    :QThread(parent)
{}

void MyThread::run()
{
    a = 0;
    while(true){
        emit send(a++);
        msleep(1000);
    }
}

MyThread::~MyThread()
{

}

