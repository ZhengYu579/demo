#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    //    ui->setupUi(this);
    setModal(true);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    setFixedSize(260,280);
    QScrollArea *area = new QScrollArea;
    area->setGeometry(10,10,240,240);
    QWidget *content = new QWidget;
    QVBoxLayout *conLayout = new QVBoxLayout;
    content->setLayout(conLayout);
    for(int i = 0;i < 20;i++){
        QCheckBox *box = new QCheckBox("checkbox" + QString::number(i));
        conLayout->addWidget(box);
    }
//    content->setFixedSize(180,800);
    area->setWidget(content);



    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *a = new QPushButton("test");
    QPushButton *b = new QPushButton("test");
    QPushButton *c = new QPushButton("test");
    buttonLayout->addWidget(a);
    buttonLayout->addWidget(b);
    buttonLayout->addWidget(c);

    mainLayout->addWidget(area);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

Dialog::~Dialog()
{
    delete ui;
}
