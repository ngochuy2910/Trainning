#include <iostream>
#include <windows.h>
#include <conio.h>
#pragma once 

using namespace std;

class Cursor
{
    private:
        int x ; 
        int y ; 
    public:
        Cursor();
        Cursor(int x , int y);
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
        bool move();// bắt sự kiện từ bàn phím .
        // void displayCursor();
};