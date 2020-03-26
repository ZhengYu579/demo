#include "mythread2.h"

MyThread2::MyThread2(QObject *parent)
    :QThread(parent)
{}

void MyThread2::run()
{
    a = 0;
    while (true) {
        emit send(a++);
        msleep(800);
    }
}

MyThread2::~MyThread2()
{

}

