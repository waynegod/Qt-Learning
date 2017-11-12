#include "buttontype.h"
#include <QPushButton>

Buttontype::Buttontype(QWidget *parent) :
    QPushButton(parent)
{
    Btn_ID = ID_count;
}
int Buttontype::getID()
{
    return Btn_ID;
}
void Buttontype::addID()
{
    ID_count++;
}
int Buttontype::ID_count = 1;
