#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
protected:
    void keyPressEvent(QKeyEvent *e);//任何鍵盤按鍵按下時
    void moveEvent(QMoveEvent *e);
};

#endif // WIDGET_H
