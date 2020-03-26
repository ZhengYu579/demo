#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedHeight(600);
    leng = new Lengend(this);
    QList<lengendDate> dates;
    lengendDate date;
    date.color = QColor(255,0,0);
    date.text = "red";
    dates.push_back(date);
    leng->setLengend(dates);
}

MainWindow::~MainWindow()
{

}
