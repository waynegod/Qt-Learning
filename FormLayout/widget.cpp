#include "widget.h"
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLineEdit *nameEdit = new QLineEdit(this);
    QLineEdit *addrEdit = new QLineEdit(this);
    QLineEdit *occpEdit = new QLineEdit(this);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);//設定對齊方式(靠右 和(|) 置中)
    formLayout->addRow("Name:", nameEdit);
    formLayout->addRow("Email:", addrEdit);
    formLayout->addRow("Age:", occpEdit);

    setLayout(formLayout);
}
