#include <iostream>
#include "Monster.cpp"
#include "Player.cpp"
#include <time.h>

using namespace std;
class Control
{

    private: 
        bool run;
        Monster monster;
        Player player ; 

    public:
        Control(bool run , Monster monster , Player player);
        void playGame();    

};

Control::Control(bool run , Monster monster , Player player)
{
    this->run = run ;
    this->monster = monster;
    this->player = player; 
}

void Control::playGame()
{
    int success;
    srand(time(0)); 

    if(run)
    {
        success = rand() % 2; 
        
       
        if(success)
        {
            int health = player.getHealth() - monster.getDamage();
            player.setHealth(health);
            cout<<"Escape unsuccessful"<<endl;
        }
        else
        {
            cout<< "Escape successful"<<endl; 
        }
    }
    else{
        
        success = rand() % 2;
        
        // monster's die
        if(!success)
        {
            cout<<"monster is defeated"<<endl;
            int gold = player.getGold() + monster.getGold() ; 
            int level = player.getLevel() + 1 ;
            int damage = player.getDamage() + 1 ; 
            int health = player.getHealth() + 1 ; 

            player.setGold(gold);
            player.setLevel(level);
            player.setDamage(damage);
            player.setHealth(health);
        }
        else 
        {
            int health = player.getHealth() - monster.getDamage() ;
            player.setHealth(health); 
            cout<<"you're defeated"<<endl;
        }
    }
    player.display();
}

int main()
{
   
    Player player("huy","h",10,20,30,1);
    Monster monster;
    while(0<player.getLevel()<20 || player.getHealth()>0 )
    {
        srand(time(0));
        //  number random to create random monster
        int rand_1 = rand();

        // case 1: create dragon
        if(rand_1%3==0)     
        {
             Monster monster("dragon", "d", 20, 4, rand()%75+26, "dragon");
        }
        // case 2: create orc
        else if(rand_1%3==1)
        {
             Monster monster("orc", "o", 4, 2, rand()%15+11, "orc");
        }
        // case 3: create slime
        else            
        {
             Monster monster("slime", "s", 1, 1, rand()%10+1, "slime");
        }

        cout<<"Enter 0 to fight"<<endl;
        cout<<"Enter 1 to run"<<endl;
        
        int select ; 
        cin>>select;
        
        switch(select)
        {
            case 0:
            {
                Control control(0,monster,player);
                control.playGame();
                break;
            }
            case 1:
            {
                Control control(1,monster,player);
                control.playGame();
                break;
            }
        }
    }

    if(player.getLevel()>20)
    {
        cout<<"Player is win"<<endl;
    }else{
        cout<<"Player is fail"<<endl;
    }

}


