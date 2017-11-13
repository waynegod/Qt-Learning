#include "widget.h"
#include "ui_widget.h"
#include "playbutton.h"
#include "topiclist.h"

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
    QGridLayout *laybox = new QGridLayout(ui->playbox);
    laybox->setMargin(0);//外框空白
    laybox->setSpacing(0);//內部空白
    laybox->setHorizontalSpacing(0);//行間空白
    for (int i = 0;i < 4;i++)
        for (int j = 0;j < 4;j++)
        {
            Playbutton *button = new Playbutton();
            button->addID();
            button->setFocusPolicy(Qt::NoFocus);//按鍵效果(無效果)
            button->setMinimumSize(QSize(ui->playbox->size().width()/4,ui->playbox->size().width()/4));
            button->setText(QString("%1").arg(button->getID()));
            Topiclist con;
            con.set_problem(5);
            laybox->addWidget(button,i,j);//新增button於i行j列
        }
}

void Widget::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);//跳至頁面0
}
