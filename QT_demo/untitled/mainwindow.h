//mainwindow.h
//#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "myobject.h"
#include <QPushButton>
#include <QMainWindow>

namespace Ui{
class MainWindow;
}

class MainWindow:public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onSelfPushed();
    void onExitPushed();

private:
    Ui::MainWindow *ui;

    MyObject *my;
    QPushButton *firstButton;
    QPushButton *secondButton;
    QPushButton *threeButton;
    QPushButton *selfButton;
    QPushButton *exitButton;
};
