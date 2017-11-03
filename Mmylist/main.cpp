#include <QTextStream>
#include <QList>
#include <algorithm>

int main(void) {

    QTextStream out(stdout);//標準輸出

    QList<QString> authors = {"Balzac", "Tolstoy",
        "Gulbranssen", "London"};

    for (int i=0; i < authors.size(); ++i)
        out << authors.at(i) << endl;
    authors << "Galsworthy" << "Sienkiewicz";//加入新資料
    out << "***********************" << endl;
    std::sort(authors.begin(), authors.end());//排序

    out << "Sorted:" << endl;
    for (QString author : authors)
        out << author << endl;
}
