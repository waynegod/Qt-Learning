#include "book.h"
#include <QString>

Book::Book(QString auth, QString tit){
    author = auth;
    title = tit;
}//設定author和title的目標

QString Book::getAuthor() const{
    return author;
}//執行getAuthor時回傳author

QString Book::getTitle() const{
    return title;
}//執行getTitle時回傳title

