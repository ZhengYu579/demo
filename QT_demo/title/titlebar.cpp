#include "titlebar.h"

TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{
    initUI();
    initConect();
}

void TitleBar::initUI()
{
    setFixedHeight(20);
    setMinimumWidth(180);

    m_titleLayout = new QHBoxLayout;
    m_titleLayout->setMargin(0);
    setLayout(m_titleLayout);

    m_titleIcon = new QLabel;
    m_titleIcon->setFixedSize(20,20);

    m_titleText = new QLabel("window");
    m_titleText->setFixedHeight(20);

    m_titleLayout->addWidget(m_titleIcon);
    m_titleLayout->addSpacing(10);
    m_titleLayout->addWidget(m_titleText);
}

void TitleBar::initConect()
{

}
