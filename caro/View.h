#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Cursor.h"
#pragma once

using namespace std;

class View
{
    private: 
        char Board[10][10] ; 
    public:
        static bool OX ; 
        static Cursor cursor ;

        void setBoard();
        char getElementInBoard(int x , int y);
    
        void setOXByCursor();

        void display();
        
};


