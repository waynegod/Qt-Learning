#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QSize>
#include <QGridLayout>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void getsize();
    void setbtn();
    ~Widget();

public slots:
    void setNamee();


private:
    Ui::Widget *ui;
    QPushButton *PB1;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_test();

    void on_pushButton_4_clicked();
};

#endif // WIDGET_H
