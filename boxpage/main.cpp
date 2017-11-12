#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //w.resize(QSize(480,640));

    w.show();

    return a.exec();
}
