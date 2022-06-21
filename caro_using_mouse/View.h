#include <iostream>
#include <windows.h>
#include <conio.h>

#pragma once

using namespace std;

class View
{
    private: 
        char Board[10][10] ; 
    public:
        
        void SetBoard();
        void DrawBoard();
        void gotoXY(const int &x ,const int &y);
        char getElementInBoard(int x , int y);

        void updateBoard( int &x_mouse , int &y_mouse , bool &turn);
        void cls(HANDLE hStdOut);
};