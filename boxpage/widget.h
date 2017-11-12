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
    void setboxs();
    ~Widget();
public slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private slots:


    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    QGridLayout *laybox;

};

#endif // WIDGET_H
