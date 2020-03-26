#include "tcpserver.h"
#include "ui_tcpserver.h"


TcpServer::TcpServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/20190912.jpg"));
    this->setWindowTitle("多人聊天服务器");
    port = 8888;

}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::on_pushButtonCreateChattingRoom_clicked()
{
    server  = new Server(this, port);
    connect(server, &Server::updateserver, this, &TcpServer::slotupdateserver);
    ui->pushButtonCreateChattingRoom->setEnabled(false);
}

void TcpServer::slotupdateserver(QString msg, int length)
{
    ui->textEdit->append(msg);
}
