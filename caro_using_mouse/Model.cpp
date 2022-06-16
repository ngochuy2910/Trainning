#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>
#include<memory>
#include "Player.cpp"
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

void Model::addPlayer(shared_ptr<Player>player)
{
    this->players.push_back(std::move(player));
};

shared_ptr<Player> Model::checkPlayerExist(string name)
{
    for(auto iter = players.begin() ; iter != players.end() ; ++iter)
    {
        if((*iter)->getName() == name)
        {
            return (*iter);
        }
    }
    return NULL ; 
}
void Model::showInfor()
{
    for(auto i = players.begin() ; i != players.end() ; i++)
    {
        (*i)->display();
        cout<<endl;
    }
 };


void Model::findSimilarPlayer(string name)
{
    float rate = 0 ; 
    int flag = 0 ;
    for(int i = 0 ; i < players.size() ; ++i)
    {
        if(players[i]->getName()== name)
        {
            rate = players[i]->rateWin();
            flag = i ;
            break;
        };
    };

    float min = 100;

    for(int i = 0 ; i < players.size() ; ++i)
    {
        if(abs(players[i]->rateWin() - rate) < min && i!= flag)
        {
            min = abs(players[i]->rateWin() - rate);
        }
    }

    for(int i = 0 ; i< players.size() ; ++i)
    {
        if(abs(players[i]->rateWin() - rate) == min && i!= flag )
        {
            players[i]->display();
            cout<<endl ; 
        }
    }


}

void Model::WriteInFile()
{
    ofstream SaveFile ("PlayerData.ini");
    for(int i = 0 ; i < players.size() ; ++i)
    {
        SaveFile<<"Name: "<<players[i]->getName()<<endl;
        SaveFile<<"Num of win game: "<<players[i]->getNumOfWin()<<endl;
        SaveFile<<"Num of lose game: "<<players[i]->getNumOfLose()<<endl;
        SaveFile<<"Win rate: "<<players[i]->rateWin()<<endl;
        SaveFile<<endl;
    }
    SaveFile.close();
}

