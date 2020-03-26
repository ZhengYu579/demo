#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("min-width:16px; min-height:16px; max-width:16px; max-height:16px; border-radius: 8px; border:1px solid black; background: red；");
    QLabel *lab = new QLabel;
    lab->setStyleSheet("min-width:16px; min-height:16px; max-width:16px; max-height:16px; border-radius: 8px; border:1px solid black; background: red；");
    ui->verticalLayout->addWidget(lab);
}

MainWindow::~MainWindow()
{
    delete ui;
}
