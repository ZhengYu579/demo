#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mt = new MyThread(this);
    mt2 = new MyThread2(this);
    ui->setupUi(this);
    connect(mt,SIGNAL(send(int)),this,SLOT(recv(int)));
    connect(mt2,SIGNAL(send(int)),this,SLOT(recv2(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mt->start();
    mt2->start();
}

void MainWindow::recv(int a)
{
    ui->label_1->setText(QString::number(a));
}

void MainWindow::recv2(int a)
{
    ui->label_2->setText(QString::number(a));
}
