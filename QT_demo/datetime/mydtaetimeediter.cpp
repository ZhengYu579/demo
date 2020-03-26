#include "mydtaetimeediter.h"

MyDtaeTimeEditer::MyDtaeTimeEditer(QWidget *parent):QLineEdit(parent)
{
    initUI();
    initconnect();
}

void MyDtaeTimeEditer::initUI()
{
    m_dateTime = QDateTime::currentDateTime();
    setText(m_dateTime.toString("yyyy-MM-dd hh:mm"));
    setMinimumWidth(140);
    button =  new QPushButton(this);
    button->setFlat(true);
    button->setText("aa");
    button->setFixedSize(height(),height());
    button->move(width()-height(),0);
}

void MyDtaeTimeEditer::initconnect()
{

}
