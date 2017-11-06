#include "widget.h"
#include <QVBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout  *vbox = new QVBoxLayout (this);
    vbox->setSpacing(1);//設定內容物間隔1px

    QPushButton *settings = new QPushButton("Settings", this);//新增按鈕
    settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//設定大小(水平延展,垂直延展)
    QPushButton *accounts = new QPushButton("Accounts", this);
    accounts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *loans = new QPushButton("Loans", this);
    loans->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *cash = new QPushButton("Cash", this);
    cash->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *debts = new QPushButton("Debts", this);
    debts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    vbox->addWidget(settings);//將部件新增至vbox
    vbox->addWidget(accounts);
    vbox->addWidget(loans);
    vbox->addWidget(cash);
    vbox->addWidget(debts);

    setLayout(vbox);//輸出vbox
}

Widget::~Widget()
{

}
