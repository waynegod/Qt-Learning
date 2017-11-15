#include "widget.h"
#include "ui_widget.h"
#include "playbutton.h"
#include "topiclist.h"
#include <QDebug>

int *pose , *qus;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);//跳至頁面0
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);//跳至頁面1
}

void Widget::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);//跳至頁面2
    set_btn(4);//設置遊戲按鈕數量
    set_game(4,5);
}

void Widget::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);//跳至頁面0
    Playbutton id;
    id.Reset();

    for (int i = 0;i < ui->playbox->count();)//重製按鈕
    {
        Playbutton *button = qobject_cast<Playbutton *>(ui->playbox->itemAt(0)->widget());
        delete button;
    }
}

void Widget::slotGetNumber()//按下遊戲按鈕
{
    Playbutton *button = (Playbutton *)sender();
    qDebug()<< button->answer();

    //button->setText(QString::number(button->getID(),10));
    //button->getID();
    //button->setText(QString("%1").arg( *(pose + button->getID())) + "\n" + QString("%2").arg(button->getID()));
/*
    for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j <9;j++)
            if (button->getID() == *(qus + i))
                button->setText(QString("QUS%1").arg( *(pose + button->getID())));
    }*/

}

void Widget::set_btn(int range)//設置遊戲按鈕數量
{
    ui->playbox->setMargin(0);
    ui->playbox->setSpacing(0);
    ui->playbox->setHorizontalSpacing(0);
    for (int i = 0;i < range;i++)
        for (int j = 0;j < range;j++)
        {
            Playbutton *button = new Playbutton();
            button->addID();
            button->setFocusPolicy(Qt::NoFocus);//按鍵效果(無效果)
            button->setMinimumSize(QSize(ui->BPlaybox->size().width()/range
                                         ,ui->BPlaybox->size().width() / range));//按鍵大小
            ui->playbox->addWidget(button,i,j);//新增button於i行j列
            connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));//信號
        }
}

void Widget::set_game(int range, int amount)//設置遊戲題目
{
    Topiclist type;
    pose = type.get_position(range * range);//建立按鈕總數
    qus = type.get_problem(amount);//建立題目數
    for (int i = 0;i < 16;i++)
    {
        Playbutton *button = qobject_cast<Playbutton *>(ui->playbox->itemAt(i)->widget());
        button->answer(*(pose + i));
        button->setText(QString("%1").arg(button->answer()));
        qDebug()<<button->answer();
    }
}

void Widget::showans(int amount)//顯示答案
{

}
void Widget::on_pushButton_11_clicked()
{

}
