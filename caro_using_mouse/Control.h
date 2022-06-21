#include "View.h"
#include "Model.h"
#include <fstream>

#pragma once
using namespace std;

class Control{
    private:

        View view;

        Model model;

    public:
        void AddPlayer(shared_ptr<Player>player);
        void PlayGame(shared_ptr<Player>player1 ,shared_ptr<Player>player2);
        bool CheckWin(int &x ,int &y , char OX);
        void showInforPlayer();
        Model getModel();
        
};