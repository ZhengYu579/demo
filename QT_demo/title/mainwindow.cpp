#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    m_mainWidget = new QWidget;
    setCentralWidget(m_mainWidget);
    m_titleBar = new TitleBar(this);
    m_layout = new QVBoxLayout;
    m_layout->setMargin(5);
    m_mainWidget->setLayout(m_layout);
    m_layout->addWidget(m_titleBar);

    m_content = new QWidget;
    m_content->setMinimumHeight(50);
    m_layout->addWidget(m_content);
}

MainWindow::~MainWindow()
{

}
