#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton * button = new QPushButton(this);
    button->move(50,50);
    connect(button,&QPushButton::clicked,this,[=]{
        Dialog *dialog = new Dialog;
        dialog->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
