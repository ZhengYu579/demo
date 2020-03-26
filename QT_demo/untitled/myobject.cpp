//myobject.cpp
#include "myobject.h"
void MyObject::first()
{
    qDebug() << QThread::currentThreadId();
}
void MyObject::second()
{
    qDebug() << QThread::currentThreadId();
}
void MyObject::three()
{
    qDebug() << QThread::currentThreadId();
}
