#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void set_btn(int range);
    void set_game(int range ,int amount);
    void showans(int amount);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void slotGetNumber();

    void on_pushButton_11_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
