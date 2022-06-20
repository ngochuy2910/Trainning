#include "View.cpp"
#include "Model.cpp"
#include <fstream>

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

void Control::PlayGame(shared_ptr<Player>player1 ,shared_ptr<Player>player2)
{
    // View view ; 
    view.SetBoard();
    bool turn = true;  // lượt chơi
    bool isPlayer1Win  ;

    // set up screen ; 
    INPUT_RECORD ir[128];
    HANDLE       hStdInput  = NULL;
    HANDLE       hStdOutput = NULL;
    HANDLE       hEvent     = NULL;
    DWORD        nRead;  //                                               
    COORD        xy;


    hStdInput=GetStdHandle(STD_INPUT_HANDLE);
    hStdOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    view.cls(hStdOutput);
    SetConsoleMode(hStdInput,ENABLE_ECHO_INPUT|ENABLE_LINE_INPUT|ENABLE_MOUSE_INPUT|ENABLE_EXTENDED_FLAGS); //mode console
    //FlushConsoleInputBuffer(hStdInput);
    hEvent=CreateEvent(NULL,FALSE,FALSE,NULL);     // set               
    HANDLE handles[2] = {hEvent, hStdInput};
    xy.X=0, xy.Y=1;
    SetConsoleCursorPosition(hStdOutput,xy);

    cout<<player1->getName()<<" <X> "<<'\t';
    cout<<player2->getName()<<" <O> "<<endl;
    view.DrawBoard();



    while(WaitForMultipleObjects(2,handles,FALSE,INFINITE))     
    {                                                    
        ReadConsoleInput(hStdInput,ir,128,&nRead);  // lấy ra ir , ts1 vs 3: inout , 2 vs 4 output


        for(size_t i=0;i<nRead;i++)                             
        {                             
             
            if(ir[i].EventType == MOUSE_EVENT) 
            {                                 
                    // xy.X=0, xy.Y=1;                                     
                    // SetConsoleCursorPosition(hStdOutput,xy);
                    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0)
                    {   
                        // cout<<player1->getName()<<" <X> "<<'\t';
                        // cout<<player2->getName()<<" <O> "<<endl;
                        int x_mouse = ir[i].Event.MouseEvent.dwMousePosition.X / 4 ; 
                        int y_mouse = ir[i].Event.MouseEvent.dwMousePosition.Y - 1 ;

                        view.updateBoard(x_mouse, y_mouse ,turn);


                        // int x_loc = 0;
                        // int y_loc = 100 ;
                        // view.gotoXY(x_loc,y_loc);
                        // cout<<player1->getName()<<" <X> "<<'\t';
                        // cout<<player2->getName()<<" <O> "<<endl;

                        // cout<<"x_mouse "<<x_mouse<<endl;
                        // cout<<"y_mouse "<<y_mouse<<endl;

                        char XO = view.getElementInBoard(y_mouse , x_mouse);
                        if(Control::CheckWin(x_mouse,y_mouse ,XO ) == 1 )
                        {
                            int x_loc = 0;
                            int y_loc = 12 ;
                            view.gotoXY(x_loc,y_loc);

                            if(XO == 'X') {
                                isPlayer1Win = true ; 

                                cout << "CONGRATULATION "<<player1->getName() << endl ;
                                player1->setNumOfWin(player1->getNumOfWin() + 1 );
                                player2->setNumOfLose(player2->getNumOfLose() + 1 );
                            }
                            else
                            {
                                isPlayer1Win = false;

                                cout << "CONGRATULATION "<< player2->getName() << endl ;
                                player1->setNumOfLose(player1->getNumOfLose() + 1 );
                                player2->setNumOfWin(player2->getNumOfWin() + 1 );
                            }

                            model.WriteInFile();

                            cout<< "Press esc to return menu "<<endl;

                            return;
                        }                  

                    };
    
            }
            
        }
        // cout<<"end"<<endl;
        
    };
    // cout<< "Press esc to return menu "<<endl;
	// 		char key ;
    // 		key = getch();
	// 		if(key == 27)
	// 		{
	// 			break ;
	// 		}


}

bool Control::CheckWin(int &x ,int &y , char XO)
{
    int i, j ;
	int count1 , count2 ,count3 ,count4 ;
	count1 = count2 = count3 = count4 = 0;


	//dem theo chieu ngang
	i = x; j = y;

	while (0 <= j && view.getElementInBoard(j,i) == XO) 
	{
		count1++;
		j--;
	}

	i = x; j = y+1;
	while (j<10 && view.getElementInBoard(j,i) == XO) 
	{
		count1++;
		j++;
	}

	//check theo chieu doc
	i = x, j = y;
	while (0 <= i && view.getElementInBoard(j,i) == XO) 
	{
		count2++;
		i--;
	}

	i = x + 1, j = y;
	while (i < 10 && view.getElementInBoard(j,i) == XO) 
	{
		count2++;
		i++;
	}

	//check dg cheo thu nhat
	i = x, j = y;
	while (0 <= i && 0 <=j && view.getElementInBoard(j,i) == XO) 
	{
		count3++;
		i--;
		j--;
	}

	i = x + 1, j = y + 1;
	while (i < 10 && j < 10 && view.getElementInBoard(j,i) == XO) 
	{
		count3++;
		i++;
		j++;
	}

	//check duong cheo thu hai
	i = x, j = y;
	while (0 <= i && j<10 && view.getElementInBoard(j,i) == XO) 
	{
		count4++;
		i--;
		j++;
	}

	i = x + 1, j = y - 1;
	while (i < 10 && 0 <= j && view.getElementInBoard(j,i) == XO) 
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
}

void Control::AddPlayer(shared_ptr<Player>player)
{
	model.addPlayer(player);
};

void Control::showInforPlayer()
{
	model.showInfor();
}

Model Control::getModel()
{
	return this->model;
}
// int main()
// {
//     Control control ;
//     control.PlayGame();
// }