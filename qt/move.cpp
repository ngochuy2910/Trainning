#include "move.h"

int loc = 50 ;
Move::Move(QObject *parent)
    : QObject{parent}
{


}

void Move::changeLocation(int a)
{
    if(a == 1)
    {
        loc += 40 ;
        emit locationChanged(loc);
    }
    else if(a == 2)
    {
         loc -= 40 ;
        emit locationChanged(loc);
    }
}
