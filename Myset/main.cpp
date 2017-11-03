#include <QSet>
#include <QList>
#include <QTextStream>
#include <algorithm>//計算用lib

int main(void) {

    QTextStream out(stdout);

    QSet<QString> cols1 = {"yellow", "red", "blue"};//建立集合cols1
    QSet<QString> cols2 = {"blue", "pink", "orange"};//建立集合cols2
    out << "There are " << cols1.size() << " values in the set" << endl;
    cols1.insert("brown");//在cols1集合中加入"brown"
    out << "There are " << cols1.size() << " values in the set" << endl;
    cols1.unite(cols2);//將cols1與cols2合併成新的cols1
    out << "There are " << cols1.size() << " values in the set" << endl;
    for (QString val : cols1)
        out << val << endl;
    QList<QString> lcols = cols1.values();//把cols1集合轉換成lcols字串
    std::sort(lcols.begin(), lcols.end());//sort分類從頭到尾
    out << "*********************" << endl;
    out << "Sorted:" << endl;
    for (QString val : lcols)
        out << val << endl;
   return 0;
}
