#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QTextEdit>

class Absoluts : public QWidget{
public:
    Absoluts(QWidget *parent = 0);
};

Absoluts::Absoluts(QWidget *parent)
    :QWidget(parent){
    QTextEdit *ledit = new QTextEdit(this);//新增QTextEdit
    ledit->setGeometry(5, 5, 200, 150);//設定QTextEdit位置
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Absoluts window;
    window.show();

    return a.exec();
}
