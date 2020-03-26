#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QIcon>
#include <QPixmap>
#include <QHBoxLayout>

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);

private:
    void initUI();
    void initConect();

private:
    QHBoxLayout *m_titleLayout;
    QLabel *m_titleIcon;
    QLabel *m_titleText;
signals:

public slots:
};

#endif // TITLEBAR_H
