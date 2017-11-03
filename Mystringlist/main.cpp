#include <QTextStream>
#include <QList>

int main(void) {

    QTextStream out(stdout);

    QString string = "coin, book, cup, pencil, clock, bookmark";//新增字串string
    QStringList items = string.split(",");//新增字串items，並將字串string用","分割放入
    QStringListIterator it(items);//將item陣列轉換???
    while (it.hasNext())
        out << it.next().trimmed() << endl;//依序印出???
    //trimmed()為整理印出位置
}
