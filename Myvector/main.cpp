#include <QVector>
#include <QTextStream>

int main(void) {

    QTextStream out(stdout);//標準輸出

    QVector<int> vals = {1, 2, 3, 4, 5,5,5}; //動態容器

    out << "The size of the vector is: " << vals.size() << endl;

    out << "The first item is: " << vals.first() << endl;
    out << "The last item is: " << vals.last() << endl;

    vals.append(6);//新增在最後一位
    vals.prepend(0);//從第一位插入

    out << "Elements: ";

    for (int val : vals)//由vals內容長度決定執行幾次，val依vals決定
        out << val << " ";
    out << endl;

    return 0;
}
