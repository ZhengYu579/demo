#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mythread.h"
#include "mythread2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyThread2 *mt2;
    MyThread *mt;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void recv(int a);
    void recv2(int a);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
