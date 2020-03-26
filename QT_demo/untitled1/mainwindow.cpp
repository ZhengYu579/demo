#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    isHidden = true;
    d = new QDockWidget;
    d->setFixedSize(1600,900);
    addDockWidget(Qt::LeftDockWidgetArea,d);

    m = new Widget(this);
    m->move(0-m->width(),0);

    b = new QPushButton(this);
    b->setText(">");
    b->setFixedSize(25,25);
    b->move(0,0);

    QLabel *l = new QLabel("hahahahahahahah",this);
    l->move(20,20);

    connect(b,&QPushButton::clicked,this,[=]{
        if(isHidden){
            m->move(0,0);
            b->move(m->width(),0);
            b->setText("<");
            isHidden = false;
        }else{
            m->move(0-m->width(),0);
            b->move(0,0);
            b->setText(">");
            isHidden = true;
        }
    });


    resize(1600,900);
}

MainWindow::~MainWindow()
{
}
