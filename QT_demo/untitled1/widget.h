#ifndef WIDGET_H
#define WIDGET_H

#include <QFrame>

class Widget : public QFrame
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // WIDGET_H
