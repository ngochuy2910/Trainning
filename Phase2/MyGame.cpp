#include <iostream>

#pragma once
using namespace std;

class MyGame
{
    private:
        string name;
        string shortName;
        int health;
        int damage;
        int gold;

    public: 
        MyGame();
        MyGame(string name, string shortName,int health, int damage,int gold );

        void setName(string name);
        string getName();
        
        void setHealth(int health);
        int getHealth();

        void setDamage(int damage);
        int getDamage();

        void setGold(int gold);
        int getGold();

       

        void display();
};

MyGame::MyGame(){};
MyGame::MyGame(string name, string shortName,int health, int damage,int gold )
{
    this->name = name ; 
    this->shortName = shortName ; 
    this->health = health ; 
    this->damage = damage ;
    this->gold = gold;
    


};

void MyGame::setName(string name)
{
    this->name = name ; 
}

string MyGame::getName()
{
    return name; 
}

void MyGame::setHealth(int health)
{
    this->health = health ; 
}

int MyGame::getHealth()
{
    return health; 
};

void MyGame::setDamage(int damage)
{
    this->damage = damage ;
};
int MyGame::getDamage()
{
    return damage ; 
};

void MyGame::setGold(int gold)
{
    this->gold = gold;
};
int MyGame::getGold()
{
    return gold ; 
};

void MyGame::display()
{
    cout<<"name " <<this->name<<'\t';
    cout<<"health "<<this->health<<'\t'; 
    cout<<"gold "<<this->gold<<'\t';
    cout<<endl ; 
};