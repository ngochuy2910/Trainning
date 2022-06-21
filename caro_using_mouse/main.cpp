#include "Control.h"

int main()
{
    int key;
	char exit ;
   
	Control control ; 
	shared_ptr<Player>player1 ;
	shared_ptr<Player>player2 ; 

    while (true)
    {
        cout<<"-------- Caro Game ---------"<<endl;
        cout<<"1. New Game "<<endl;
        cout<<"2. Show All Information of Players"<<endl;
		cout<<"3. Find similar player "<<endl;
        cout<<"4. Exit "<<endl;

        cin>> key;
		system("cls");
        switch(key){
        case 1:
		{
			cout<<"-----------Add Player----------"<<endl;

			cout<<" Add Player 1"<<endl;
			// Nhập tên người chơi : 
			string name1;
			cin.ignore();
			getline(cin,name1);

			//Check tên đã tồn tại chưa , nếu có thì không cần thêm vào vector
			if(control.getModel().checkPlayerExist(name1)==NULL)
			{
				player1 = make_shared<Player>(name1);
				control.AddPlayer(player1);
			}
			else 
			{
				player1 = control.getModel().checkPlayerExist(name1);
			}

			cout<<" Add Player 2"<<endl;
			// Nhập tên người chơi : 
			string name2;
			getline(cin,name2);

			//Check tên đã tồn tại chưa , nếu có thì không cần thêm vào vector
			if(control.getModel().checkPlayerExist(name2)==NULL)
			{
				player2 = make_shared<Player>(name2);
				control.AddPlayer(player2);
			}
			else 
			{
				player2 = control.getModel().checkPlayerExist(name2);
			}

			// START GAME 
			cout<<"---------Start Game-----------"<<endl;
			control.PlayGame(player1,player2);

    		exit = getch();
			if(exit == 27)
			{
				system("cls");
				break ;
			}


			//break;
		};

		case 2:
		{
			cout<<"All infor of player "<<endl;
			control.showInforPlayer();
			// break;

			
			cout<< "Press esc to return menu "<<endl;
			exit = getch();
			if(exit == 27)
			{
				system("cls");
				break ;
			}
		}
		case 3:
		{
			cout<<"Input name"<<endl;
			string name;
			cin.ignore();
			getline(cin,name);
			control.getModel().findSimilarPlayer(name) ;

			cout<< "Press esc to return menu "<<endl;
			exit = getch();
			if(exit == 27)
			{
				system("cls");
				break ;
			}
		}
		case 4:
		{
			return 0 ;
		}

		}
	}
}