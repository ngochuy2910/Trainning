#include "Control.h"
#include <fstream>

void Control::AddPlayer(shared_ptr<Player>player)
{
	model.addPlayer(player);
};

void Control::PlayGame(shared_ptr<Player>player1 ,shared_ptr<Player>player2 )
{
    view.setBoard();
	bool isPlayer1Win  ;

    while(true)
    {
		// Set con trỏ 
        view.setOXByCursor();


		
		// Check win 
		if(view.getElementInBoard(view.cursor.getX(),view.cursor.getY() ) != '_') 
		{ 
			if (Control::CheckWin(view.cursor.getX() , view.cursor.getY()) == 1)
			{
				if(view.getElementInBoard(view.cursor.getX(),view.cursor.getY()) == 'X')
				{
					isPlayer1Win = true ;
					
				}
				else 
				{
					isPlayer1Win = false ; 
					
				}
				// Thoat vong lap neu co ng thang 
				break ;
			}
		};
	
		// Cho con tro di chuyen va check running 
        if(view.cursor.move() == 0 ) return ;
        

        system("cls");

		// render screen 
		cout<<player1->getName() << " <X> " << '\t' ;
		cout<<player2->getName() << " <O> " << endl ;
        view.display();
        Sleep(50);
        
    } 

	if(isPlayer1Win == true)
	{
		cout << "CONGRATULATION "<<player1->getName() << endl ;
		player1->setNumOfWin(player1->getNumOfWin() + 1 );
		player2->setNumOfLose(player2->getNumOfLose() + 1 );
	} else 
	{
		cout << "CONGRATULATION "<< player2->getName() << endl ;
		player1->setNumOfLose(player1->getNumOfLose() + 1 );
		player2->setNumOfWin(player2->getNumOfWin() + 1 );
	}

	// reset lại lượt
	view.OX = true ; 

	// Ghi file : 
	model.WriteInFile();
};

bool Control::CheckWin(int x , int y) //x,y là tọa độ cờ hiện tại
{
    int i, j ;
	int count1 , count2 ,count3 ,count4 ;
	count1 = count2 = count3 = count4 = 0;

	char XO = view.getElementInBoard(x,y);

	//dem theo chieu ngang
	i = x; j = y;
	while (0 <= j && view.getElementInBoard(i,j) == XO) 
	{
		count1++;
		j--;
	}

	i = x; j = y+1;
	while (j<10 && view.getElementInBoard(i,j) == XO) 
	{
		count1++;
		j++;
	}

	//check theo chieu doc
	i = x, j = y;
	while (0 <= i && view.getElementInBoard(i,j) == XO) 
	{
		count2++;
		i--;
	}

	i = x + 1, j = y;
	while (i < 10 && view.getElementInBoard(i,j) == XO) 
	{
		count2++;
		i++;
	}

	//check dg cheo thu nhat
	i = x, j = y;
	while (0 <= i && 0 <=j && view.getElementInBoard(i,j) == XO) 
	{
		count3++;
		i--;
		j--;
	}

	i = x + 1, j = y + 1;
	while (i < 10 && j < 10 && view.getElementInBoard(i,j) == XO) 
	{
		count3++;
		i++;
		j++;
	}

	//check duong cheo thu hai
	i = x, j = y;
	while (0 <= i && j<10 && view.getElementInBoard(i,j) == XO) 
	{
		count4++;
		i--;
		j++;
	}

	i = x + 1, j = y - 1;
	while (i < 10 && 0 <= j && view.getElementInBoard(i,j) == XO) 
	{
		count4++;
		i++;
		j--;
	}

	if (count1 == 4 || count2 == 4|| count3 == 4 || count4 == 4) 
	{
		return 1;
	}
	else {
		return 0;
	}
};

void Control::showInforPlayer()
{
	model.showInfor();
}


Model Control::getModel()
{
	return this->model;
}

