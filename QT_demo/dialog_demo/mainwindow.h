#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mydialog.h"

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
    void on_pushButton_pop_clicked();

    void on_pushButton_color_clicked();

    void on_pushButton_input_clicked();

    void on_pushButton_item_clicked();

    void on_pushButton_fonts_clicked();

    void on_pushButton_file_clicked();

    void on_pushButton_message_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
