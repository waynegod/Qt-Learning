#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);//程式的初始、結束及處理事件

    QWidget window;

    window.resize(250, 150);//視窗大小
    window.setWindowTitle("Simple example");//標頭名稱
    window.show();//顯示視窗

    return app.exec();//回傳程式的執行迴圈
}
