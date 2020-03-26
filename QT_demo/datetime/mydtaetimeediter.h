#ifndef MYDTAETIMEEDITER_H
#define MYDTAETIMEEDITER_H

#include <QLineEdit>
#include <QPushButton>
#include <QDateTime>

class MyDtaeTimeEditer:public QLineEdit
{
public:
    MyDtaeTimeEditer(QWidget *parent =nullptr);
private:
    QPushButton *button;
    QDateTime m_dateTime;

    void initUI();
    void initconnect();
};

#endif // MYDTAETIMEEDITER_H
