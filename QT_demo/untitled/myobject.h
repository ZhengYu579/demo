//myobject.h
#ifndef MYOBJECT_H
#define MYOBJECT_H
#include <QObject>
#include <QDebug>
#include <QThread>

class MyObject:public QObject{
    Q_OBJECT
public:
    MyObject(){}
    ~MyObject(){}
public slots:
    void first();
    void second();
    void three();
};
#endif
