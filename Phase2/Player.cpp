#include <iostream>
#include "MyGame.cpp"
// #include "Control.cpp"
#pragma once

class Player : public MyGame
{
    private:
        int level ;
    public:
        Player();
        Player(string name, string shortName,int health, int damage,int gold , int level );
        void setLevel(int level);
        int getLevel();


};
Player::Player()
{

};
Player::Player(string name, string shortName,int health, int damage,int gold , int level) : MyGame(name,shortName,health,damage,gold){

    this->level = level ; 


};

void Player::setLevel(int level)
{
    this->level = level ; 
}

int Player::getLevel()
{
    return this->level ;
};

