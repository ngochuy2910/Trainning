#include <iostream>
#include "MyGame.cpp"
#pragma once

class Monster : public MyGame
{
    private:
        string type ;
    public:
        Monster();
        Monster(string name, string shortName,int health, int damage,int gold , string type);
        string getType();
        void setType(string type); 
};
Monster::Monster(){};
Monster::Monster(string name, string shortName,int health, int damage,int gold , string type) : MyGame(name,shortName,health,damage,gold){

    this->type = type ; 


};

void Monster::setType(string type)
{
    this->type = type ; 
}

string Monster::getType()
{
    return this->type ;
};