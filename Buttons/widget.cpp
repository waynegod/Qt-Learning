#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout(this);//垂直布局方式
    QHBoxLayout *hbox = new QHBoxLayout(this);//水平布局方式

    okBtn = new QPushButton("OK", this);
    applyBtn = new QPushButton("Apply", this);

    hbox->addWidget(okBtn, 1, Qt::AlignRight);//在hbox布局中加入(okBtn,延展係數<左側有1個物件>,對齊方式)
    hbox->addWidget(applyBtn, 0);

    vbox->addStretch(2);
    vbox->addLayout(hbox);
}

