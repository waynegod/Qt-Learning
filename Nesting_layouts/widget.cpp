#include "widget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout();//新增垂直佈局
    QHBoxLayout *hbox = new QHBoxLayout(this);//新增水平佈局

    QListWidget *lw = new QListWidget(this);//新增清單
    lw->addItem("The Omen");
    lw->addItem("The Exorcist");
    lw->addItem("Notes on a scandal");
    lw->addItem("Fargo");
    lw->addItem("Capote");

    QPushButton *add = new QPushButton("Add", this);
    QPushButton *rename = new QPushButton("Rename", this);
    QPushButton *remove = new QPushButton("Remove", this);
    QPushButton *removeall = new QPushButton("Remove All", this);

    vbox->setSpacing(3);//加入空白間距
    vbox->addStretch(1);//新增空白伸縮佈局
    vbox->addWidget(add);//加入部件
    vbox->addWidget(rename);
    vbox->addWidget(remove);
    vbox->addWidget(removeall);
    vbox->addStretch(1);//新增空白伸縮佈局

    hbox->addWidget(lw);//加入ListWidget
    hbox->addSpacing(15);
    hbox->addLayout(vbox);

    setLayout(hbox);//輸出
}

