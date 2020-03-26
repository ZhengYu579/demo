#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_connect_clicked();

    void on_pushButton_send_clicked();

    void onSuccessConnected();
    void onReadServerMessage();
    void onDisconnected();

private:
    Ui::MainWindow *ui;
    QTcpSocket* socket;
};

#endif // MAINWINDOW_H
