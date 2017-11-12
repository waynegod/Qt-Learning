#include "widget.h"
#include <QApplication>
#include "ui_widget.h"
#include <QGridLayout>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();


    return a.exec();
}
