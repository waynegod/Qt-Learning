#include "playbutton.h"
#include <QPushButton>

Playbutton::Playbutton(QWidget *parent) :
    QPushButton(parent)
{
    ID_btn = ID_count;
}
int Playbutton::getID()
{
    return ID_btn;
}
void Playbutton::addID()
{
    ID_count++;
}
int Playbutton::ID_count = 1;
