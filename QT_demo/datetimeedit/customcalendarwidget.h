#ifndef CUSTOMCALENDARWIDGET_H
#define CUSTOMCALENDARWIDGET_H

#include <QCalendarWidget>
#include <QTimeEdit>
#include <QDateTime>
#include <QDialog>

class QPushButton;
class QLabel;

class CustomCalendarWidget : public QCalendarWidget
{
    Q_OBJECT

public:
    CustomCalendarWidget(QWidget *parent = nullptr);
    ~CustomCalendarWidget();

private:
    void initControl();
    void initTopWidget();
    void initTimeEdit();
    void initBottomWidget();
    void setDataLabelTimeText(int year, int month);

signals:
    void sigDateTimeChanged(const QDateTime& dateTime);

private slots:
    void onbtnClicked();

protected:
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;

private:
    QPushButton* m_leftYearBtn;
    QPushButton* m_leftMonthBtn;

    QPushButton* m_rightYearBtn;
    QPushButton* m_rightMonthBtn;

    QPushButton* m_ensureBtn;
    QPushButton* m_cancelBtn;

    QLabel* m_dataLabel;

    QTimeEdit *timeEdit;
};

#endif // CUSTOMCALENDARWIDGET_H
