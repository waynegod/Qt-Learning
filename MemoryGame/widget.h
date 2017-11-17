#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void set_btn();
    void set_game();
    void showans();
    void startT();
    ~Widget();

public slots:
    void TimerSec();
    void playtime();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void slotGetNumber();

    void on_PB_range_DW_clicked();

    void on_PB_range_UP_clicked();

    void on_PB_amount_DW_clicked();

    void on_PB_amount_UP_clicked();

    void on_PB_sec_DW_clicked();

    void on_PB_sec_UP_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QTimer *Timer_play, *Timer_sec;



};

#endif // WIDGET_H
