#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include "widget.h"

class MyButton : public QWidget {
 public:
     MyButton(QWidget *parent = 0);
};

MyButton::MyButton(QWidget *parent)
    : QWidget(parent) {

    QPushButton *quitBtn = new QPushButton("Quit", this);//新增QPushButton；內容"Quit"；置於主容器
    quitBtn->setGeometry(250, 180, 80, 50);//擺放位置
    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
    //信號：當quitBtn被執行clicked時，執行qApp的quit動作；qApp指整個APP
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MyButton window;
    window.resize(400, 300);
    window.setWindowTitle("QPushButton");
    window.show();

    return app.exec();
}
