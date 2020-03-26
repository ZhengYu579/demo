#ifndef DATETIMEEIDT_H
#define DATETIMEEIDT_H

#include <QLineEdit>
#include <QPushButton>
#include <QDateTime>
#include "customcalendarwidget.h"

class DateTimeEidt : public QLineEdit
{
public:
    DateTimeEidt(QWidget *parent = nullptr);
private:
    QPushButton *button;
    CustomCalendarWidget *calendar;
    QDateTime *m_selectDateTime;

    void initUI();
    void initconnect();
    void updataDateTime();
private slots:
    void onPopCalendar();

};

#endif // DATETIMEEIDT_H
