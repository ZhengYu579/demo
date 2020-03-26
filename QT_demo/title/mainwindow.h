#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include "titlebar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    TitleBar *m_titleBar;
    QVBoxLayout *m_layout;
    QWidget *m_mainWidget;
    QWidget *m_content;

};

#endif // MAINWINDOW_H
