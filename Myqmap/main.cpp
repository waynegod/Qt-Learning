#include <QTextStream>
#include <QMap>//關聯容器

int main(void) {
    QTextStream out(stdout);
    QMap<QString, int> items = { {"coins", 5}, {"books", 3} };//新建關聯容器items
    items.insert("bottles", 7);//items加入新資料
    QList<int> values = items.values();//新增values列表，並將items的數值放入
    out << "Values:" << endl;
    for (int val : values)
        out << val << endl;
    QList<QString> keys = items.keys();//新增keys列表，並將items的文字放入
    out << "Keys:" << endl;
    for (QString key : keys)
        out << key << endl;
    QMapIterator<QString, int> it(items);//將item陣列轉換???
    out << "Pairs:" << endl;
    while (it.hasNext())
    {
        it.next();
        out << it.key() << ": " << it.value() << endl;
    }
}
