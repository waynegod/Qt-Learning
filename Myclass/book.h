#ifndef BOOK_H
#define BOOK_H
#include <QString>

class Book
{
public:
    Book(QString , QString);

    QString getAuthor() const;//const 說明函數是不能修改類中成員的值，只能用於類的成員函數中
    QString getTitle() const;
private:
    QString author;
    QString title;

};

#endif // BOOK_H
