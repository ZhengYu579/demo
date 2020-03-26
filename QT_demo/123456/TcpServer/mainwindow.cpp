#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any,6666);
    connect(server,SIGNAL(newConnection()),this,SLOT(getNewConnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_send_clicked()
{
    QString message = ui->lineEdit_send->text();
    client->write(message.toLocal8Bit().data(),message.toLocal8Bit().size());
}

void MainWindow::getNewConnection()
{
    client = server->nextPendingConnection();
    connect(client,SIGNAL(readyRead()),this,SLOT(readNewMessage()));
    connect(client,SIGNAL(disconnected()),this,SLOT(onDisConnected()));
}

void MainWindow::readNewMessage()
{
    QByteArray data = client->readAll();
    ui->textBrowser->append(QString::fromLocal8Bit(data));
}

void MainWindow::onDisConnected()
{
    qDebug()<< "断开连接";
}
