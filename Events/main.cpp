#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(400,400);
    w.setWindowTitle("");
    w.show();

    return a.exec();
}
