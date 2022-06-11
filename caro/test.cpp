#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;


void GoTo(int posX, int posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;
    
	SetConsoleCursorPosition(hStdout, Position);
    cout<<"--";

}

void clearCursor()
{
    system("cls");
};


int main ()
{
   
    //cout<<"---";
    char key ; 
    int x = 10 ;
    int y = 10 ;
    GoTo(x,y);
    while(true)
    {
        key = _getch();
        // cout<<key ; 
        if(key == 72)
        {
            clearCursor();
            x += 2 ;
        };

         if(key == 80)
        {
            clearCursor();
            x -= 2 ;
        };

        // if(key == )
        //clearCursor();
        GoTo(x,y);
    }
}