#include "View.h"

bool View::OX = true ;

Cursor View::cursor(1,1);

void View::setBoard()
{
    //Set kí tự cho mỗi ô cờ
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            this->Board[i][j] = '_';
        }

    }
};

char View::getElementInBoard(int x , int y)
{
    return this->Board[x][y];
}


void View::setOXByCursor()
{
    char spaceKey;
    spaceKey = getch();
    if(spaceKey == 32)
    {
        int x = this->cursor.getX();
        int y = this->cursor.getY();

        if(this->Board[x][y] == '_')
        {
            if(this->OX == true)
            {
                this->Board[x][y] = 'X';
                this->OX = false ; 
            } 
            else
            {
                this->Board[x][y] = 'O';
                this->OX = true ; 
            }
        }
        

}
}


void View::display()
{
    
    // In ra bàn cờ . 
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            cout<<'|';
            if(cursor.getX() == i && cursor.getY()==j)
            {
                cout<<'_'<<'>'<<'_';
            }
            else cout<<'_'<<Board[i][j]<<'_';
        }
         cout<<endl ;
    }
};

