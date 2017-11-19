#include "widget.h"
#include "ui_widget.h"
#include "playbutton.h"
#include "topiclist.h"
#include <QDebug>
#include <QMessageBox>
#include <QFontDatabase>

int *pose ,*qus ,*ans;
int range ,amount ,sec;
int ans_count = 1;
int ans_wrong = 0;
float count_time = 0;
bool game_Enabled;
bool game_over;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);//跳至頁面0
    Timer_play = new QTimer();
    font_ID_mvboli = QFontDatabase::addApplicationFont(":/fonts/Resourcesbox/mvboli.ttf");
    font_data_mvboli = QFontDatabase::applicationFontFamilies(font_ID_mvboli).at(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_PB_home_play_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);//跳至頁面1
}

void Widget::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);//跳至頁面2

    range = ui->label_range->text().toInt();
    amount = ui->label_amount->text().toInt();
    sec = ui->label_sec->text().toInt();

    game_Enabled = false;
    game_over =false;

    set_btn();//設置遊戲按鈕數量
    QMessageBox msgBox;
    msgBox.setText(tr("開始!!"));
    //msgBox.setFont(QFont("",12));
    msgBox.exec();

    set_game();
    startT();
}

void Widget::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);//跳至頁面1
    ui->timerbar->setValue(0);
    Playbutton id;
    id.Reset();
    ans_count = 1;
    for (int i = 0;i < ui->playbox->count();)//重製按鈕
    {
        Playbutton *button = qobject_cast<Playbutton *>(ui->playbox->itemAt(0)->widget());
        delete button;
    }
}

void Widget::slotGetNumber()//按下遊戲中的按鈕
{
    Playbutton *button = (Playbutton *)sender();
    if (button->answer() ==  ans_count)
    {
        if (ans_count == ui->label_amount->text().toInt())
        {
            Timer_play->stop();

            QMessageBox msgBox;
            msgBox.setWindowTitle("勝利~~!");
            msgBox.setText(QString("時間：%1s \n是否繼續?").arg(count_time / 10));
            msgBox.setStandardButtons (QMessageBox::Yes | QMessageBox::Reset);
            //QPushButton *connectButton = msgBox.addButton(tr("Connect"), QMessageBox::ActionRole);

            //msgBox.setDefaultButton(QMessageBox::No);
            //msgBox.addButton(tr("back"),QMessageBox::AcceptRole);
            int chose = msgBox.exec();

            switch (chose) {
            case QMessageBox::Yes:

                break;
            case QMessageBox::Reset:
                on_pushButton_9_clicked();
                break;
            }
            count_time = 0;
        }
        ans_count++;
    }
}

void Widget::set_btn()//設置遊戲按鈕數量
{
    ui->playbox->setMargin(0);
    ui->playbox->setSpacing(0);
    ui->playbox->setHorizontalSpacing(0);
    ui->BPlaybox->resize(ui->BPlaybox->size().width(),ui->BPlaybox->size().width());

    QFont font_mvboli(font_data_mvboli);
    font_mvboli.setPixelSize(50);

    for (int i = 0;i < range;i++)
    {
        for (int j = 0;j < range;j++)
        {
            Playbutton *button = new Playbutton();
            button->addID();
            button->setFocusPolicy(Qt::NoFocus);//按鍵效果(無效果)
            button->setMinimumSize(QSize(ui->BPlaybox->size().width() / range
                                         ,ui->BPlaybox->size().width() / range));//按鍵大小
            button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

            //button->setFont(QFont("",button->size().height()/13));//設定字體字型
            button->setFont(QFont(font_mvboli));
            ui->playbox->addWidget(button,i,j);//新增button於i行j列
            connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));//信號
        }
    }
}

void Widget::set_game()//設置遊戲題目
{
    Topiclist type;
    pose = type.get_position(range * range);//建立按鈕總數
    qus = type.get_problem(amount);//建立題目數

    QPixmap pixmapbox[9];
    pixmapbox[1].load(":/icon/Resourcesbox/button/bticon01.png");
    pixmapbox[2].load(":/icon/Resourcesbox/button/bticon02.png");
    pixmapbox[3].load(":/icon/Resourcesbox/button/bticon03.png");
    pixmapbox[4].load(":/icon/Resourcesbox/button/bticon04.png");
    pixmapbox[5].load(":/icon/Resourcesbox/button/bticon05.png");
    pixmapbox[6].load(":/icon/Resourcesbox/button/bticon06.png");
    pixmapbox[7].load(":/icon/Resourcesbox/button/bticon07.png");
    pixmapbox[8].load(":/icon/Resourcesbox/button/bticon08.png");
    pixmapbox[9].load(":/icon/Resourcesbox/button/bticon09.png");

    for (int i = 0;i < range * range;i++)
    {
        Playbutton *button = qobject_cast<Playbutton *>(ui->playbox->itemAt(i)->widget());
        button->setMaximumSize(button->size().width(),button->size().height());
        for(int j = 0;j < amount ;j++)
        {

            if (*(pose + i) == *(qus + j))
            {
                //qDebug()<<button->answer();
                button->answer(*(qus + j));
                //button->setText(QString("%1").arg(button->answer()));
                button->setIcon(pixmapbox[button->answer()]);
                button->setIconSize(QSize(button->size().width()+10,button->size().width()+10));
            }
        }
    }
}

void Widget::showans()//顯示答案
{


}

void Widget::startT()
{
    Timer_sec = new QTimer(this);
    ui->timerbar->setMaximum(sec * 100);
    Timer_sec->start(10);
    connect(Timer_sec,SIGNAL(timeout()),this,SLOT(TimerSec()));

}

int sec_count;

void Widget::TimerSec()
{
    int bar = ui->timerbar->value();
    bar++;
    ui->timerbar->setValue(bar);
    if(bar == ui->timerbar->maximum())
    {

        for (int i = 0;i < range * range;i++)
        {
            Playbutton *button = qobject_cast<Playbutton *>(ui->playbox->itemAt(i)->widget());
            button->setIcon(QIcon());
        }
        Timer_sec->stop();
        game_Enabled = true;

        Timer_play->start(100);
        connect(Timer_play,SIGNAL(timeout()),this,SLOT(playtime()));

    }
}

void Widget::playtime()
{
    count_time++;
}

void Widget::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);//跳至頁面0
}

void Widget::on_PB_range_DW_clicked()
{
    if(ui->label_range->text().toInt() > 1)
        ui->label_range->setText(QString("%1").arg(ui->label_range->text().toInt() - 1));
}

void Widget::on_PB_range_UP_clicked()
{
    if(ui->label_range->text().toInt() < 5)
        ui->label_range->setText(QString("%1").arg(ui->label_range->text().toInt() + 1));
}

int pix = 30;
void Widget::on_PB_amount_DW_clicked()
{
    if(ui->label_amount->text().toInt() > 1)
         ui->label_amount->setText(QString("%1").arg(ui->label_amount->text().toInt() - 1));
    ui->label_amount->setFont(QFont("PMingLiU", pix-- ,1,false));
    ui->pushButton_4->setText(QString("%1").arg(pix));

}

void Widget::on_PB_amount_UP_clicked()
{
    if(ui->label_amount->text().toInt() < 9)
        ui->label_amount->setText(QString("%1").arg(ui->label_amount->text().toInt() + 1));
    ui->label_amount->setFont(QFont("PMingLiU", pix++ ,1,false));
    ui->pushButton_4->setText(QString("%1").arg(pix));
}

void Widget::on_PB_sec_DW_clicked()
{
    if(ui->label_sec->text().toInt() > 1)
        ui->label_sec->setText(QString("%1").arg(ui->label_sec->text().toInt() - 1));
}

void Widget::on_PB_sec_UP_clicked()
{
    if(ui->label_sec->text().toInt() < 5)
        ui->label_sec->setText(QString("%1").arg(ui->label_sec->text().toInt() + 1));
}


void Widget::on_pushButton_2_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowFlags(Qt::Tool);
    QPushButton *dialog_OK = new QPushButton();
    QPushButton *dialog_add = new QPushButton("add",nullptr);
    QPushButton *dialog_less = new QPushButton("less",nullptr);

    dialog->resize(ui->stackedWidget->size().width() / 2
                  ,ui->stackedWidget->size().height() / 4);
    QHBoxLayout *lay = new QHBoxLayout(dialog);
    lay->addWidget(dialog_OK);
    //lay->addWidget(dialog_add);
    //lay->addWidget(dialog_less);

    connect(dialog_OK,SIGNAL(clicked(bool)),dialog,SLOT(close()));

    dialog->exec();
}

