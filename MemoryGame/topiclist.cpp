#include "topiclist.h"
#include <QDebug>

Topiclist::Topiclist()
{

}
int *Topiclist::get_problem()
{
    static int  back_problm[16];
    return back_problm;
}
void Topiclist::set_problem(int list)
{
    qDebug()<<list;

}

