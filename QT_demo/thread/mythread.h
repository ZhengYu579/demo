#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread:public QThread
{
    Q_OBJECT
public:
    int a;
    MyThread(QObject *parent);
    void run();
    ~MyThread();
signals:
    void send(int i);
};

#endif // MYTHREAD_H
