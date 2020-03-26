#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DateTimeEidt *eidt = new DateTimeEidt(this);
    eidt->move(10,50);
}

MainWindow::~MainWindow()
{
    delete ui;
}
