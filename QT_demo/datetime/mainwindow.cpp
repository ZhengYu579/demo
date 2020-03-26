#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyDtaeTimeEditer *a = new MyDtaeTimeEditer(this);
    a->move(50,50);
}

MainWindow::~MainWindow()
{
    delete ui;
}
