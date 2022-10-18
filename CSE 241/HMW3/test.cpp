#include "hexGame.h"

int main(){

    Hex game;
    Hex game2;
    Hex game3;
    Hex game4;
    Hex game5;
    game.playGame();
    cout << "NUMBER OF MARKEDS: = " << game.markedCells() << endl;  //My program print number of markeds in every end of game
    game2.playGame();
    cout << "NUMBER OF MARKEDS: = " << game.markedCells() << endl;
    game3.playGame();
    cout << "NUMBER OF MARKEDS: = " << game.markedCells() << endl;
    game4.playGame();
    cout << "NUMBER OF MARKEDS: = " << game.markedCells() << endl;
    game5.playGame();

  
    return 0;
}