#ifndef MYTHREAD2_H
#define MYTHREAD2_H

#include <QThread>

class MyThread2 : public QThread
{
    Q_OBJECT
public:
    int a;
    MyThread2(QObject *parent);
    void run();
    ~MyThread2();
signals:
    void send(int i);
};

#endif // MYTHREAD2_H
