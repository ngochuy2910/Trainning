#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>
#include<memory>
#include "Player.h"
#pragma once
using namespace std;

class Model
{
    private:
        // vector<Player *> players; 
        vector<shared_ptr<Player>> players ;   

    public: 
        void addPlayer(shared_ptr<Player>player);  
        
        shared_ptr<Player> checkPlayerExist(string name); //trả về con trỏ trỏ đối tượng player

        void findSimilarPlayer(string name);
        void WriteInFile();
        void showInfor();
};

