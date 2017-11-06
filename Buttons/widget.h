#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
private:
    QPushButton *okBtn;
    QPushButton *applyBtn;
};

#endif // WIDGET_H
