#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <iostream>
#include <windows.h>
#include <QDockWidget>
#include "widget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton *b;
    Widget *m;
    QDockWidget *d;

    bool isHidden;
};

#endif // MAINWINDOW_H
