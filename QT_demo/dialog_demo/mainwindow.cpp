#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QColorDialog"
#include "QInputDialog"
#include "QFontDialog"
#include "QFileDialog"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pop_clicked()
{
    MyDialog* mydialog = new MyDialog();
    mydialog->setModal(true);
    mydialog->show();
}

void MainWindow::on_pushButton_color_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"颜色对话框");
    ui->frame->setAutoFillBackground(true);
    ui->frame->setPalette(QPalette(color));
}

void MainWindow::on_pushButton_input_clicked()
{
    QString str = QInputDialog::getText(this,"文本输入对话框","请输入",QLineEdit::Normal,"",0);
    ui->label_textinput->setText(str);
}

void MainWindow::on_pushButton_item_clicked()
{
    QStringList items;
    items.append("哈哈");
    items.append("呵呵");
    items.append("呼呼");
    items.append("悠哈");
    items.append("嘻嘻");
    QString str = QInputDialog::getItem(this,"选择输入对话框","请选择",items,0,false,0);
    ui->label_item->setText(str);
}

void MainWindow::on_pushButton_fonts_clicked()
{
    QFont font;
    bool ok;
    font = QFontDialog::getFont(&ok,this);
    ui->label_item->setFont(font);
}

void MainWindow::on_pushButton_file_clicked()
{
    QString fileName = QFileDialog::getOpenFileName();
    ui->label_filename->setText(fileName);
}

void MainWindow::on_pushButton_message_clicked()
{
    QMessageBox::about(this,"关于","这是一个关于关于的对话框");
    QMessageBox::question(this,"问题框","你知道这是一个问题对话框吗？",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    QMessageBox::information(this,"信息框","这是一个信息框",QMessageBox::Ok);
    QMessageBox::warning(this,"警告","这是一个警告框",QMessageBox::Ok,QMessageBox::Ok);
    QMessageBox myMessage;
    myMessage.setText("这是我自己的对话框");
    myMessage.exec();
}











