#include "lengend.h"

Lengend::Lengend(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout;
    mainLayout->setAlignment(Qt::AlignTop);
    setLayout(mainLayout);
}

void Lengend::setLengend(QList<lengendDate> dates)
{
    for(auto date:dates){
        QHBoxLayout *layout = new QHBoxLayout;
        layout->setMargin(0);

        QLabel *colorLabel = new QLabel;
        colorLabel->setFixedSize(8,8);
        QPalette pe;
        pe.setColor(QPalette::Background,QColor(255,0,0));
        colorLabel->setAutoFillBackground(true);
        colorLabel->setPalette(pe);
        layout->addWidget(colorLabel);

        QLabel *textLabel = new QLabel;
        textLabel->setText(date.text);
        layout->addWidget(textLabel);
        mainLayout->addLayout(layout);
    }
}
