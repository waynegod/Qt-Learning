#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    setboxs();
}

void Widget::setboxs()
{

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
/*
    QFrame *line = new QFrame();
    qDebug()<<ui->box_0->size()<<line->size();
    line->setFrameStyle(QFrame::Box|QFrame::Plain);
    ui->box_1->layout()->setContentsMargins(1,1,1,1);
    line->setLineWidth(5);
    ui->box_1->addWidget(line);
    */
}

void Widget::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_pushButton_3_clicked()
{

}

void Widget::on_pushButton_4_clicked()
{
    laybox = new QGridLayout(ui->box);
    laybox->setMargin(0);
    laybox->setSpacing(0);
    laybox->setHorizontalSpacing(0);


    //laybox->setRowMinimumHeight(1,0);
    //laybox->setRowStretch(1,1);
    //laybox->setColumnStretch(1,0);


    int k = 0;
    for (int i = 0;i < 4;i++)
        for (int j = 0;j < 4;j++)
        {
            QPushButton *button = new QPushButton();
            button->setMinimumSize(QSize(ui->box->size().width()/4,ui->box->size().width()/4));
            button->setText(QString("%1").arg(++k));
            laybox->addWidget(button,i,j);


        }


    qDebug()<<ui->box->size()<<ui->box->sizeHint();
}


