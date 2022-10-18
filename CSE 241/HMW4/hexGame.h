#ifndef hexGame
#define hexGame

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

enum cellSitutation{empty,user1,user2};  //my board is integer so I use enum like this.

class Hex{  //I create the Hex class.

    public:
        
        class Cell{
            public:
                int row; //I created Cell information in Cell class.
                int column;
                int cellState;
                Cell(int,int,int);
                Cell();
        };
    
    
    private:
        Cell **board;  //I used Cell **hexCells as Cell **board.
        int **record;  //I created a record double pointer to record the moves I made to undo the moves.
        int user1_score=0,user2_score=0;  //For user scores
        void checkIn();                     // I reset board in this function.
        void saveGame(const string& filename); //I save the game in this function.
        void loadGame(const string& filename); //I load the game in this function.
        void boardPrint(int winFlag);  //I print the board in this function
        int convertCoordinate();    //In this function, I convert the entered character with the number to a number and send it to the integer array.
        int checkRange(int x,int y);  //here I make sure the coordinates do not go out of the table.
        void resize();          //I am using a static value to show the cells marked here I used dynamic array in this function and nullpointer.
        static int Gmove;
        int size,selection;
        char character;
        int checkBoard[12][12];
        int turn;
        int winFlag = 0;
        int value = 1;
        int num2 = 0;
        int recordIndex;
    

    public:

        explicit Hex();      //I used explicit and nullpointer, nullpointer shown in third line in hexGame.cpp.
        Hex& operator--();     //I used for undo.
        Hex operator--(int);   //I used for undo.
        Cell play();                 //In this function AI make move.
        static int markedCells();  //for to identify the marked points.
        void userGame();           //Function to get the player input and update the board.
        void userComputer();         //in this function Computer and user enter input to the board.
        int winGame_X(int x,int y,int a);  //I used recursive to find the win condition in this function.
        int score(int x,int y);             //For user score return users scores.
        void playGame();  //In this function choose game type and game size.
        void play(const Cell& State);  //In this function users make move.
        inline void endGame() const{  //If game end I return function.
            cout << "<<<THE GAME END "
                 << "IF YOU WANT TO PLAY AGAIN PLEASE SELECT SIZE >>>" << endl;
        }

        friend ofstream& operator<<(ofstream& output,const Hex &boardGame); //I used operator overloading for file input,output and terminal.
        friend ostream&  operator<<(ostream &outTerm,const Hex &boardGame);
        friend ifstream& operator>>(ifstream &inTerm, Hex &boardGame);

};

#endif
