#include <QTextStream>

#define STR_EQUAL 0

int main(void) {

   QTextStream out(stdout);

   QString a = "Rain";
   QString b = "rain";
   QString c = "rain\n";

   if (QString::compare(a, b) == STR_EQUAL) {
     out << "a, b are equal" << endl;
   } else {
     out << "a, b are not equal" << endl;
   }//compare 區分大小寫
   out << "In case insensitive comparison:" << endl;
   if (QString::compare(a, b, Qt::CaseInsensitive) == STR_EQUAL) {
     out << "a, b are equal" << endl;//CaseInsensitive不分大小寫
   } else {
     out << "a, b are not equal" << endl;
   }
   if (QString::compare(b, c) == STR_EQUAL) {
     out << "b, c are equal" << endl;
   } else {
     out << "b, c are not equal" << endl;
   }

   c.chop(1);//刪除最後一個字元

   out << "After removing the new line character" << endl;

   if (QString::compare(b, c) == STR_EQUAL) {
     out << "b, c are equal" << endl;
   } else {
     out << "b, c are not equal" << endl;
   }

   return 0;
}
