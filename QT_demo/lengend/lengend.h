#ifndef LENGEND_H
#define LENGEND_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QColor>
#include <QString>

typedef struct{
    QColor color;
    QString text;
}lengendDate;

class Lengend : public QWidget
{
    Q_OBJECT
public:
    explicit Lengend(QWidget *parent = nullptr);
    void setLengend(QList<lengendDate> dates);

private:
    QVBoxLayout* mainLayout;

signals:

public slots:
};

#endif // LENGEND_H
