#include <QTextStream>

int main(void) {

  QTextStream out(stdout);
  QString str = "There are many stars.";
  foreach (QChar qc, str) {
    out << qc << " ";
  }//foreach寫法; qc 參數是字串元素，str 參數是字符串。
  out << endl;
  for (QChar *it=str.begin(); it!=str.end(); ++it) {
    out << *it << " " ;
  }//for寫法
  out << endl;
  for (int i = 0; i < str.size(); ++i) {
    out << str.at(i) << " ";
  }//str.at(i) 和 str[i] 都可用
  out << endl;

  return 0;
}
