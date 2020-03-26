#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include "server.h"

namespace Ui {
class TcpServer;
}

class TcpServer : public QDialog
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = 0);
    ~TcpServer();

private:
    Ui::TcpServer *ui;
    int port;
    Server *server;

protected slots:
    void slotupdateserver(QString, int);//接收到server发过来的信号就更新界面的信息


private slots:
    void on_pushButtonCreateChattingRoom_clicked();
};

#endif // TCPSERVER_H
