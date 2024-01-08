#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<unistd.h>
#include<string>
#include<cstdio>

#include"TUI.h"


using namespace std;
unsigned char grid[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

void reset()
{
    for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                grid[i][j]=' ';
}
class person{
public:
    string name;

    void get_name(int x=1){
        cout<<"\nenter player "<< x <<" name : ";
        cin>>name;
    }
};

class Score
{
protected:
    int X=0;
    int O=0;
    public:
    virtual int checkwinner()=0;
};

class Winner:protected Score{
public:

    int getX(){return X;}
    int getO(){return O;}

    void incrX(){X++;}
    void incrY(){O++;}
    int checkwinner()
    {
            int empty = 0;
        for(int i=0; i<3; i++)
        {
            // Checking rows and columns for a win
            if((grid[i][0]=='X' && grid[i][1]=='X' && grid[i][2]=='X') || (grid[0][i]=='X' && grid[1][i]=='X' && grid[2][i]=='X'))
                return 1;
            if((grid[i][0]=='O' && grid[i][1]=='O' && grid[i][2]=='O') || (grid[0][i]=='O' && grid[1][i]=='O' && grid[2][i]=='O'))
                return 2;

            // Checking diagonals for a win
            if((grid[0][0]=='X' && grid[1][1]=='X' && grid[2][2]=='X') || (grid[0][2]=='X' && grid[1][1]=='X' && grid[2][0]=='X'))
                return 1;
            if((grid[0][0]=='O' && grid[1][1]=='O' && grid[2][2]=='O') || (grid[0][2]=='O' && grid[1][1]=='O' && grid[2][0]=='O'))
                return 2;

            // Checking if the board is full
            if(grid[i][0]==' ' || grid[i][1]==' ' || grid[i][2]==' ')
                empty = 1;
        }

        if(empty)
            return 0; // Game is not over, still possible moves
        else
            return -1; // Game is a draw
        }
};

void display(int y, int x)
 {//SetConsoleOutputCP(1251);
     cout<<"\33[35m";
    for(int i=1; i<=7; i++)
        {
        for(int j=1; j<=13; j++)
        {
                     cout<<"\33[35m";

            // Drawing the horizontal lines
            if((i==1 || i==3 || i==5 || i==7) && (j!=1 && j!=5 && j!=9 && j!=13))
                cout<<("-");

            // Drawing the vertical lines
            else if((i==2 || i==4 || i==6) && (j==1 || j==5 || j==9 || j==13))
               {

                cout<<("|");

                   cout<<"\33[35m";

               }
            // Drawing the intersection of horizontal and vertical lines
            else if((i==1) && (j==5 || j==9))
                cout<<("+");
            else if((i==7) && (j==5 || j==9))
                cout<<("+");
            else if((i==3 || i==5) && (j==1))
                cout<<("+");
            else if((i==3 || i==5) && (j==13))
                cout<<("+");
            else if((i==3 || i==5) && (j==5 || j==9))
                cout<<("+");

            // Drawing the corners
            else if(i==1 && j==1)
                cout<<("+");
            else if(i==1 && j==13)
                cout<<("+");
            else if(i==7 && j==1)
                cout<<("+");    //02EA
            else if(i==7 && j==13)
                cout<<("+");

            // Drawing the X or O marks
            else if((i==2 || i==4 || i==6) && (j==3 || j==7 || j==11))
            {
                if(i==2*(y+1) && j==4*(x+1)-1)
                    printf("\033[107m"); // Setting the background color
                printf("%c",grid[i/2-1][(j+1)/4-1]);
                if(i==2*(y+1) && j==4*(x+1)-1)
                    printf("\033[0m"); // Resetting the background color
            }
            else
            {
                printf(" "); // Empty space
            }
        } printf("\n");
    }
}
void hideCursor()
{
	CONSOLE_CURSOR_INFO cursor; // Create a CONSOLE_CURSOR_INFO object
	cursor.dwSize = 100; // Assigning size of cursor
	cursor.bVisible = false; // Making cursor invisible
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor); // Set the cursor for next thing to be printed
}
void display_tic()
{
 hideCursor();
 cout<<"\033[30;107m \33[94m";
     cout<<R"(








                      .       ________  ___  ________                _________  ________  ________               _________  ________  _______             .
                      .      |\___   ___\\  \|\   ____\             |\___   ___\\   __  \|\   ____\             |\___   ___\\   __  \|\  ___ \            .
                      .      \|___ \  \_\ \  \ \  \___|  ___________\|___ \  \_\ \  \|\  \ \  \___|  ___________\|___ \  \_\ \  \|\  \ \   __/|           .
                      .           \ \  \ \ \  \ \  \    |\____________\  \ \  \ \ \   __  \ \  \    |\____________\  \ \  \ \ \  \\\  \ \  \_|/__         .
                      .            \ \  \ \ \  \ \  \___\|____________|   \ \  \ \ \  \ \  \ \  \___\|____________|   \ \  \ \ \  \\\  \ \  \__\ \        .
                      .             \ \__\ \ \__\ \_______\                \ \__\ \ \__\ \__\ \_______\                \ \__\ \ \_______\ \_______\       .
                      .              \|__|  \|__|\|_______|                 \|__|  \|__|\|__|\|_______|                 \|__|  \|_______|\|_______|       .)";

    sleep(6);
    system("cls");
cout<<"\033[30;107m \33[95m";
system("color 0B");

    cout<<R"(






                                            _///     _//      _/       _////_//////_//     _//      _/       _///     _//
                                            _/ _//   _//     _/ //          _//    _//     _//     _/ //     _/ _//   _//
                                            _// _//  _//    _/  _//         _//    _//     _//    _/  _//    _// _//  _//
                                            _//  _// _//   _//   _//        _//    _////// _//   _//   _//   _//  _// _//
                                            _//   _/ _//  _////// _//       _//    _//     _//  _////// _//  _//   _/ _//
                                            _//    _/ // _//       _//      _//    _//     _// _//       _// _//    _/ //
                                            _//      _//_//         _//     _//    _//     _//_//         _//_//      _//

                                             _///       _////     _///////    _/////    _////////_//_///////        _////
                                          _//    //  _//    _//  _//    _//  _//   _// _//      _//_//    _//    _//    _//
                                         _//       _//        _//_//    _//  _//    _//_//      _//_//    _//  _//        _//
                                         _//       _//        _//_/ _//      _//    _//_//////  _//_/ _//      _//        _//
                                         _//       _//        _//_//  _//    _//    _//_//      _//_//  _//    _//        _//
                                          _//   _//  _//     _// _//    _//  _//   _// _//      _//_//    _//    _//     _//
                                            _////      _////     _//      _//_/////    _////////_//_//      _//    _//////)";
    hideCursor();
    sleep(3);
    system("cls");
             cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t";

    do{
         cout << "\b\b\b\b\b\b\b\b\b\bLoading   " <<  flush;
         Sleep(100);
         cout << "\b\b\b\b\b\b\b\b\b\bLOading   " <<  flush;
         Sleep(100);
         cout << "\b\b\b\b\b\b\b\b\b\bLoAding   " <<  flush;
         Sleep(100);
         cout << "\b\b\b\b\b\b\b\b\b\bLoaDing   " <<  flush;
         Sleep(100);
         cout << "\b\b\b\b\b\b\b\b\b\bLoadIng   " <<  flush;
         Sleep(100);
         cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg   " <<  flush;
         Sleep(100);
         cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " <<  flush;
         Sleep(100);
         cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " <<  flush;
         Sleep(100);
         cout << "\b\b\b\b\b\b\b\b\b\bLoading.." <<   flush;
         Sleep(100);
         cout << "\b\b\b\b\b\b\b\b\b\bLoading..." <<  flush;
         Sleep(100);


    }while(_getwch()!=27);
    system("cls");
}

 int main()
 {
    display_tic();
    Winner w;
    person a,b;
    int cho=1;
    int diff_plyrs=1;
    cout<<("\033[0m");

    char ch;
    char choice = 'X';
    int y=0,x=0;
    int play;
do{
        char abc[][20] = {"Play Game","exit"};

        char ttt[]="TIC TAC TOE";
        play=WhiteHighlight(ttt,abc,2,1);

        switch(play){
            case 1:{
                        do{
                                    if(diff_plyrs!=2){
                                            a.get_name();
                                            b.get_name(1);
                                    }

                                            while(!w.checkwinner())
                                            {
                                            system("cls");

                                            display(y,x);

                                            ch = getch();

                                            // Handling player movements
                                            if(ch==75)
                                            {
                                                if(!(x>0))
                                                {
                                                    continue;
                                                }
                                                x--;
                                            }
                                            else if(ch==77)
                                            {
                                                if(!(x<2))
                                                {
                                                    continue;
                                                }
                                                x++;
                                            }
                                            else if(ch==80)
                                            {
                                                if(!(y<2))
                                                {
                                                    continue;
                                                }
                                                y++;
                                            }
                                            else if(ch==72)
                                            {
                                                if(!(y>0))
                                                {
                                                    continue;
                                                }
                                                y--;
                                            }
                                            else if(ch==13)
                                            {
                                                if(!(grid[y][x]==' '))
                                                {
                                                    continue;
                                                }
                                                grid[y][x]=choice;

                                                // Switching the player's turn
                                                if(choice=='X')
                                                {
                                                    choice = 'O';
                                                }
                                                else if(choice=='O')
                                                {
                                                    choice = 'X';
                                                }
                                            }
                                        }

                                        int result = w.checkwinner();

                                        // Printing the result of the game
                                        if(result==1)
                                        {
                                            cout<<"\n";
                                            string name= a.name;
                                            cout<<name;
                                            cout<<" wins\n";
                                            w.incrX();

                                        }
                                        if(result==2)
                                        {
                                            cout<<"\n"<<b.name<<" wins\n";
                                            w.incrY();
                                        }

                                        if(result==-1)
                                        {
                                            printf("\nResult : Draw\n");
                                        }

                                            cout<<"\nX = "<<w.getX();
                                            cout<<"\nY = "<<w.getO();
                            do{

                            }while(_getwch()!=13);
                            char b[][20] = {"yes", "no"};
                            char dywtpa[]="\33[0mdo you want play again";

                                cho=WhiteHighlight(dywtpa,b,2,1);
                                if(cho==2){
                                    play=0;
                                    break;
                                }

                                char df[]="different players ?";

                                diff_plyrs=WhiteHighlight(df,b,2,1);

                                system("cls");
                                reset();

                        }while(play);
            }
                        break;
                        case 2:exit(0);
        }
    }while(play);



    return 0;
 }

