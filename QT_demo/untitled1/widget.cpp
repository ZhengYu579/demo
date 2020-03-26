#include "widget.h"

Widget::Widget(QWidget *parent) : QFrame(parent)
{
    this->setFixedSize(450,200);
    setStyleSheet("background:#000000");
}
