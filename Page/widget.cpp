#include "widget.h"
#include "ui_widget.h"
#include "buttontype.h"
#include <QMessageBox>
#include <QDebug>
#include <QIcon>
#include <QTime>
#include <QSize>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    setbtn();


}

Widget::~Widget()
{
    delete ui;
}

void Widget::setbtn()
{
    ui->box->layout()->setMargin(0);
    ui->box->setSpacing(0);
    QList<QString> values(
    { "1", "2", "3", "4",
      "5", "6", "7", "8",
      "9", "10", "11", "12",
      "13", "14", "15", "16"
    });

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            Buttontype *button = new Buttontype();
            button->addID();
            button->setFlat(false);
            //button->setStyleSheet("background: transparent;");

            button->setAutoFillBackground(true);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->box->addWidget(button,i,j);
            connect(button,SIGNAL(clicked()),SLOT(setNamee()));
        }
    }

}

void Widget::on_test()
{
}

void Widget::getsize()
{
    Buttontype *button = qobject_cast<Buttontype*>(ui->box->itemAt(6)->widget());
    delete button;
    qDebug()<<button->size() << ui->gridFrame->size();
    qDebug()<<ui->pushButton_2->size();
}

void Widget::setNamee()
{
    //QDynamicButton *button = qobject_cast<QDynamicButton*>(ui->verticalLayout->itemAt(i)->widget());
    Buttontype *button = (Buttontype *)sender();
    qDebug()<<button->size();
    /*for (int con = ui->box->count();con>0;con--)
    {
        //Buttontype *button = qobject_cast<Buttontype*>(ui->box->itemAt(0)->widget());
        //delete button;
    }*/

}

void Widget::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

   QPixmap icon(":/icon/Button-Yellow-icon.png");

    for(int cont = 0;cont < 16;cont++)
    {
        Buttontype *button = qobject_cast<Buttontype*>(ui->box->itemAt(cont)->widget());
        QPixmap newicon = icon.scaled(button->size(),Qt::KeepAspectRatio);

        button->setIcon(newicon);
        //button->setStyleSheet("border-image:url(:/icon/Button-Yellow-icon.png)");
        // button->setIconSize(QSize(button->size().width()-15,button->size().width()-15));
        //button->setIconSize(icon.size());
    }
}

void Widget::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_pushButton_6_clicked()
{
    QMessageBox::information(this,tr("EX"),tr("12000"));
}

void Widget::on_pushButton_4_clicked()
{
    //Buttontype *button = qobject_cast<Buttontype*>(ui->box));
}
