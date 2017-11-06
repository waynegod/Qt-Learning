#include "widget.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout(this);
    grid->setVerticalSpacing(15);//垂直空白間距
    grid->setHorizontalSpacing(10);//水平空白間距

    QLabel *title = new QLabel("Title:", this);
    grid->addWidget(title, 0, 0, 1, 1);//加入部件(物件,行,列,占用行,占用列)
    title->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *edt1 = new QLineEdit(this);
    grid->addWidget(edt1, 0, 1, 1, 1);

    QLabel *author = new QLabel("Author:", this);
    grid->addWidget(author, 1, 0, 1, 1);
    author->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *edt2 = new QLineEdit(this);
    grid->addWidget(edt2, 1, 1, 1, 1);

    QLabel *review = new QLabel("Review:", this);
    grid->addWidget(review, 2, 0, 1, 1);
    review->setAlignment(Qt::AlignRight | Qt::AlignTop);

    QTextEdit *te = new QTextEdit(this);
    grid->addWidget(te, 2, 1, 3, 1);

    setLayout(grid);
}
