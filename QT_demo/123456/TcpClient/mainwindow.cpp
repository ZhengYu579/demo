#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    socket = new QTcpSocket(this);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_connect_clicked()
{
    QString hostIP = ui->lineEdit_ip->text();
    socket->connectToHost(QHostAddress(hostIP),6666);
    connect(socket,SIGNAL(connected()),this,SLOT(onSuccessConnected()));
}

void MainWindow::on_pushButton_send_clicked()
{
    QString msg = ui->lineEdit_send->text();
    socket->write(msg.toLocal8Bit().data(),msg.toLocal8Bit().size());
}

void MainWindow::onSuccessConnected()
{
    ui->lineEdit_ip->setEnabled(false);
    ui->pushButton_connect->setEnabled(false);

    ui->lineEdit_send->setEnabled(true);
    ui->pushButton_send->setEnabled(true);

    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadServerMessage()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
}

void MainWindow::onReadServerMessage()
{
    QByteArray data = socket->readAll();
    ui->textBrowser->append(QString::fromLocal8Bit(data));
}

void MainWindow::onDisconnected()
{
    qDebug()<<"断开连接";
}
