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
        static bool OX ; 
        
    public:
        static Cursor cursor ;
        void setBoard();
        char getElementInBoard(int x , int y);
    
        void setOXByCursor();

        void display();
        
};

// bool View::OX = true ;

// Cursor View::cursor(1,1);

