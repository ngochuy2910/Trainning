#include <iostream>
#include <windows.h>
#include <conio.h>

#pragma once

using namespace std;

class View
{
    private: 
        char Board[10][10] ; 
    public:
        
        void SetBoard();
        void DrawBoard();
        void gotoXY(int &x , int &y);
        char getElementInBoard(int x , int y);
        //void drawBoard();
        // void setOXByCursor();
        void updateBoard( int &x_mouse , int &y_mouse , bool &turn);
        void cls(HANDLE hStdOut);
};

void View::SetBoard()
{
    //Set kí tự cho mỗi ô cờ
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            this->Board[i][j] = '_'; 
        }

    };
};

void View::DrawBoard()
{
    //Set kí tự cho mỗi ô cờ
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            cout<<'|';
            cout<<'_'<<Board[i][j]<<'_';
        }
        cout<<endl ;

    };
};

void View::gotoXY(int &x , int &y)
{
    COORD cord;
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),cord);
    // cout<<'X';


}

void View::updateBoard(int &x_mouse , int &y_mouse , bool &turn)
{
    // for(int i = 0 ; i < 10 ; i++)
    // {
    //     for(int j = 0 ; j < 10 ; j++)
    //     {
    //         cout<<'|';
    //         if(j == x_mouse && i == y_mouse )
    //         {
    //             // turn = !turn ;
    //             if(turn){ 
    //                 this->Board[i][j] = 'X' ;
    //             }
    //             else this->Board[i][j] = 'O';
    //            // cout<<'_'<<Board[i][j]<<'_';
    //            turn = !turn ;
    //         }
    //         cout<<'_'<<Board[i][j]<<'_';
    //     }
    //     cout<<endl ;
    // }
    int x_location = 4 * x_mouse + 2 ;
    int y_location = y_mouse + 1 ; 
    View::gotoXY( x_location , y_location);
    if(this->Board[y_mouse][x_mouse] == '_')
    {
        if(turn){ 
            this->Board[y_mouse][x_mouse] = 'X' ;
        }
        else this->Board[y_mouse][x_mouse] = 'O';
        turn = !turn ;
    }
    cout<<this->Board[y_mouse][x_mouse];
    // turn = !turn ;



}

void View::cls(HANDLE hStdOut)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coordScreen = {0,0};
    DWORD cCharsWritten;
    DWORD dwConSize;
    
    GetConsoleScreenBufferInfo(hStdOut, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hStdOut,(TCHAR)' ',dwConSize,coordScreen,&cCharsWritten);
    GetConsoleScreenBufferInfo(hStdOut,&csbi);
    FillConsoleOutputAttribute(hStdOut,csbi.wAttributes,dwConSize,coordScreen,&cCharsWritten);
    SetConsoleCursorPosition(hStdOut,coordScreen);
    
    return;
}

char View::getElementInBoard(int x , int y)
{
    return this->Board[x][y];
};

// int main()
// {
//      //View :
//     View view ; 
//     view.SetBoard();
//     bool turn = true;  // lượt chơi

//     // set up screen ; 
//     INPUT_RECORD ir[128];
//     HANDLE       hStdInput  = NULL;
//     HANDLE       hStdOutput = NULL;
//     HANDLE       hEvent     = NULL;
//     DWORD        nRead;                                                
//     COORD        xy;


//     hStdInput=GetStdHandle(STD_INPUT_HANDLE);
//     hStdOutput=GetStdHandle(STD_OUTPUT_HANDLE);
//     view.cls(hStdOutput);
//     SetConsoleMode(hStdInput,ENABLE_ECHO_INPUT|ENABLE_LINE_INPUT|ENABLE_MOUSE_INPUT|ENABLE_EXTENDED_FLAGS);
//     FlushConsoleInputBuffer(hStdInput);
//     hEvent=CreateEvent(NULL,FALSE,FALSE,NULL);                   
//     HANDLE handles[2] = {hEvent, hStdInput};



//     while(WaitForMultipleObjects(2,handles,FALSE,INFINITE))     
//     {                                                    
//         ReadConsoleInput(hStdInput,ir,128,&nRead); 


//         for(size_t i=0;i<nRead;i++)                             
//         {   
//             // SetBoard(Board);                           
//             switch(ir[i].EventType)                                
//             {                                    
//                 case MOUSE_EVENT:                                     
//                     xy.X=0, xy.Y=1;                                     
//                     SetConsoleCursorPosition(hStdOutput,xy);
//                     if((GetKeyState(VK_LBUTTON) & 0x8000) != 0)
//                     {   
//                         //turn = !turn ; 

//                         int x_mouse = ir[i].Event.MouseEvent.dwMousePosition.X / 4 ; 
//                         int y_mouse = ir[i].Event.MouseEvent.dwMousePosition.Y - 1 ;

//                     // cout<<x_mouse<<endl;
//                         view.updateBoard(x_mouse, y_mouse ,turn);
                   


//                     };
//                     break;
//             }
//         }
//     };


// }