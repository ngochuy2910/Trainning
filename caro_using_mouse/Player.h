#include <iostream>
#include <string>

#pragma once

using namespace std; 

class Player
{
    private:
        string name; 
        int numOfWin;
        int numOfLose;

    public:
        Player(string name);
        void setName(string name);
        string getName();
        
        void setNumOfWin(int numOfWin);
        int getNumOfWin();
        void setNumOfLose(int numOfLose);
        int getNumOfLose();
        float rateWin();

        void display();

};