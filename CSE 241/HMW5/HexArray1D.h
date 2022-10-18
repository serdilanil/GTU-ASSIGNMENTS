#ifndef derivedArray
#define derivedArray

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>
#include"AbstractHex.h"


using namespace std;

using namespace  baseAbstract;

class HexArray : public AbstractHex{

    public:
        void print(int winFlag) override;
        void writeToFile(const string& filename)override; 
        void readFromFile(const string& filename)override; 
        int operator()(int x,int y)const override;
        int winGame_X(int x,int y,int a)override;  
        void play()override;
        void play(const Cell& State)override;
        void reset()override;
        void playGame()override;
        void userGame()override;           
        void userComputer()override; 
        void createBoard();
        int findIndex(int row,int column)const;
             
    private:
        Cell *board;
        
};

#endif