#include "Model.h"
#include "View.h"
#pragma once

using namespace std;

class Control{
    private:
        Model model;

        View view;

    public:
        void AddPlayer(shared_ptr<Player>player);
        void PlayGame(shared_ptr<Player>player1 , shared_ptr<Player>player2);
        bool CheckWin(int x ,int y);
        void showInforPlayer();
        Model getModel();
        
};