#ifndef hexGame
#define hexGame

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

enum cellSitutation{empty,user1,user2};  //my board is integer so I use enum like this.

class Hex{  //I create the Hex class.

    private:
        
        class Cell{
            public:
                int row; //I created Cell information in Cell class.
                int column;
                int cellState;
        };
        
        vector < vector < Cell >> hexCells;  //I use the vector for Cells.

        static int Gmove;
        int size,selection;
        char character;
        int checkBoard[12][12];
        vector < vector < Cell > > board ; //I use the vector for board.
        void checkIn();                     // I reset board in this function.
        void saveGame(const string& filename); //I save the game in this function.
        void loadGame(const string& filename); //I load the game in this function.
        void boardPrint(int winFlag);  //I print the board in this function
        int winFlag = 0;
        int value = 1;
        int num2 = 0;

    public:
        Hex():size(6),turn(1){}
        static int markedCells();  //for to identify the marked points.
        void userGame();           //Function to get the player input and update the board.
        void userComputer();         //in this function Computer and user enter input to the board.
        int convertCoordinate();    //In this function, I convert the entered character with the number to a number and send it to the integer array.
        int checkRange(int x,int y);  //here I make sure the coordinates do not go out of the table.
        int winGame_X(int x,int y,int a);  //I used recursive to find the win condition in this function.
        int turn;
        void playGame();  //In this function choose game type and game size.
        void play();      //In this function AI make move.
        void play(const Cell& State);  //In this function users make move.
        void resize();          //I am using a static value to show the cells marked here.
        inline void endGame() const{  //If game end I return function.
            cout << "<<<THE GAME END "
                 << "IF YOU WANT TO PLAY AGAIN PLEASE SELECT SIZE >>>" << endl;
        }
};

#endif