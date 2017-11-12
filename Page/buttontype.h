#ifndef BUTTONTYPE_H
#define BUTTONTYPE_H

#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QString>

class Buttontype : public QPushButton
{
    Q_OBJECT
public:

    explicit Buttontype(QWidget *parent = nullptr);
    static int ID_count;
    int getID();
    void addID();


signals:

public slots:

private:
    int Btn_ID = 0;
};

#endif // BUTTONTYPE_H
