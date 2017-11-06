#include "widget.h"
#include <QPushButton>
#include <QApplication>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->setSpacing(5);
    QPushButton *quitBtn = new QPushButton("Quit", this);
    hbox->addWidget(quitBtn, 0, Qt::AlignRight | Qt::AlignBottom);//設置向右、置底

    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);

}
void Widget::keyPressEvent(QKeyEvent *event)//任何鍵盤按鍵按下時
{
    if(event->key() == Qt::Key_Escape)//Esc按下時
        qApp->quit();//結束程式
}
void Widget::moveEvent(QMoveEvent *e)
{
    int x = e->pos().x();
    int y = e->pos().y();
    QString text = QString::number(x) + "," + QString::number(y);
    setWindowTitle(text);
}
