#ifndef BASECLASS
#define BASECLASS

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

namespace baseAbstract{ //I create the abstract.

    class Cell{
        public:
            int row;
            int column;
            int cellState;

    };

enum cellSitutation{empty,user1,user2};   

class AbstractHex{

    protected:
        static int Gmove;
        int size,selection;
        char character;
        int checkBoard[12][12];
        int winFlag = 0;
        int value = 1;
        int num2 = 0;
        int countRecord=0;


    public:
        virtual ~AbstractHex(){};
        virtual void writeToFile(const string& filename)=0; //save file
        virtual void readFromFile(const string& filename)=0; //load file
        virtual void print(int winFlag)=0;  //Print board on the screen.
        virtual void play()=0;      //for User vs computer
        virtual void play(const Cell& State)=0;  //For user vs user
        virtual int winGame_X(int x,int y,int a)=0;  //winning condition
        virtual void reset()=0;  //Resets the board to the beginning.
        virtual void userGame()=0;   //User vs User      
        virtual void userComputer()=0; //User vs Computer
        virtual void playGame()=0; //I play game in this function.
        virtual int operator()(int x,int y)const=0;
        Cell lastMove();
        bool operator == (const AbstractHex& )const;
        bool setSize(int tempSize); //I set the board size about input.
        
        int getSize(){
            return size;
        }
        bool isEnd(int winFlag);
        static int numberOfMoves();  
        AbstractHex():size(6),turn(1){}
        int convertCoordinate();      //I convert the char to int
        int checkRange(int x,int y);  //here I make sure the coordinates do not go out of the table.
        int turn;
        Cell record;
        void resize();         
        void checkIn();
};

}

#endif