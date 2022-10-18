#include "AbstractHex.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

//Base Class
using namespace baseAbstract; //I create the namespace
using namespace std;

int AbstractHex::Gmove = 0;  //I am using a static value to show the cells marked here.

int AbstractHex::numberOfMoves(){   //I return marked Cells.

    return Gmove;
}
int AbstractHex::convertCoordinate(){  //In this function, I convert the entered character with the number to a number and send it to the integer array.
    int x =0;

    for(char m = 'A'; m <= 'Z'; m++){

        if(character == m){
            return x;
        }
            x++;
    }
        return -1;
}

void AbstractHex::checkIn(){  // I control checkboard in this function.
    
    for(int i = 0; i < size; i++){

        for(int j =0 ; j<size;j++){

            checkBoard[i][j] = empty;
        }
    }
}

int AbstractHex::checkRange(int x,int y){  //here I make sure the coordinates do not go out of the table.

    int flag =0;
    
    if(x >= 0 && x < size + 1){
        if(y >= 0 && y < size + 1){
            flag = 1;
        }
    }
    return flag;
}

bool AbstractHex::isEnd(int winFlag){  //Returns true if the board is a game end

    if(winFlag ==1){

        return true;
    }
        
        else if(winFlag==2){
            return true;
        }
            else
                return false;

}

bool AbstractHex::operator == (const AbstractHex& game2)const{ //if the boards are the same.This operator does not consider last move or the number of steps
    
    for(int x=0;x<size;x++){
        for(int y =0;y<size;y++){

            if(game2.operator()(x,y) != (*this).operator()(x,y)){
                return false;
            }
        }
    }

                return true;

}

bool AbstractHex::setSize(int tempSize){ //This function set the board size if size is false returned false otherwise returned true.

    if(tempSize > 5 && tempSize < 30){

        size = tempSize;
        return true;
    }
        else{
            cout << "Invalid Value!!! Please enter the larger than 5*5 table size" << endl;
            return false;
        }
} 

Cell AbstractHex::lastMove(){

    return record;
}
