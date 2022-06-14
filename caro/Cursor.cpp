#include "Cursor.h"

Cursor::Cursor(){};
Cursor::Cursor(int x , int y)
{
    this->x = x;
    this->y = y;
};
void Cursor::setX(int x)
{
    this->x = x ;
};
void Cursor::setY(int y)
{
    this->y = y;
}

int Cursor::getX()
{
    return this->x ;
}
int Cursor::getY()
{
    return this->y;
};
bool Cursor::move()
{
    
    char key ;
    key = getch();

    switch (key) {
            case 72:
                this->x -= 1 ; // up 
                break;
            case 75:
                this->y -= 1 ; // left
                break;
            case 77:
                this->y += 1 ; // right
                break;
            case 80:
                this->x += 1 ; // down
                break;
            case 27:
                //cout<< "Exit"<<endl;
                return 0; // Nhan esc de thoat
        }
    return 1 ;

    
}

