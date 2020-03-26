
#include "datetimeeidt.h"

DateTimeEidt::DateTimeEidt(QWidget *parent):QLineEdit (parent)
{
    initUI();
    initconnect();
}

void DateTimeEidt::initUI()
{
    m_selectDateTime = new QDateTime(QDateTime::currentDateTime());
    setMinimumWidth(140);
    button = new QPushButton(this);
    button->setFixedSize(height(),height());
    button->move(width()-height(),0);
    button->setIcon(QIcon("://timg.jpg"));
    button->setFlat(true);
    calendar = new CustomCalendarWidget;
    calendar->hide();
    updataDateTime();
}

void DateTimeEidt::initconnect()
{
    connect(button,&QPushButton::clicked,this,&DateTimeEidt::onPopCalendar);
    connect(calendar,&CustomCalendarWidget::sigDateTimeChanged,this,[=](QDateTime selectedDateTime){
        this->setText(selectedDateTime.toString("yyyy-MM-dd hh:mm"));
    });
}

void DateTimeEidt::onPopCalendar()
{
    calendar->show();
    calendar->move(window()->x() + x(),window()->y() + y() + 65);
}

void DateTimeEidt::updataDateTime()
{
    setText(m_selectDateTime->toString("yyyy-MM-dd hh:mm"));
}
