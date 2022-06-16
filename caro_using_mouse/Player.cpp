#include <iostream>
#include <string>

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


Player::Player(string name)
{
    this->name = name ;
    this->numOfWin = 0 ;
    this->numOfLose = 0 ;
};

void Player::setName(string name)
{
    this->name = name ;
};

string Player::getName()
{
    return this->name ;
};


void Player::setNumOfWin(int numOfWin)
{
    this->numOfWin = numOfWin;
};

int Player::getNumOfWin()
{
    return this->numOfWin ; 
};

void Player::setNumOfLose(int numOfLose)
{
    this->numOfLose = numOfLose;
};

int Player::getNumOfLose()
{
    return this->numOfLose ; 
};

float Player::rateWin()
{
    if(this->numOfWin == 0 && this->numOfLose == 0) {
        return 0;
    } 
    else return  (float)this->numOfWin / (this->numOfWin + this->numOfLose) ;
}

void Player::display()
{
    cout<<"Name: "<<this->name<<endl ; 
    cout<<"Num of win game: "<<this->numOfWin<<endl;
    cout<<"Num of lose game: " << this->numOfLose<<endl;
    cout<< "Win rate: "<<this->rateWin()<<endl;
}



