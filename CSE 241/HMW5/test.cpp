#include "AbstractHex.h"
#include "HexVector.h"
#include "HexArray1D.h"
#include "HexAdapter.h"
#include "HexAdapter.cpp"
#include<deque>
#include<vector>

using namespace baseAbstract;
using namespace std;


bool validSequenceOfMoves( AbstractHex * sequenceArray[],int numArray){   //I create the Global funtion about valid or invalid input.

    int ptr;
    for(int i=0;i<numArray;i++){
        AbstractHex *countGame = sequenceArray[i];
        for(int j=0; j<countGame->getSize();j++){

            for(int k=0;k<sequenceArray[i]->getSize();k++){

                ptr = (*countGame).operator()(j,k);

                if(ptr != 1 && ptr!= 2 && ptr != 0){  //because my board is int
                    cout<< i << "GAME IS INVALID"<<endl;
                    return false;
                }
            }
        }

    }
        cout<< "GAME IS VALID"<<endl;
        return true;
}

int main(){
    int choise1=-1,choise2=0;
    int choose;
    int countArray =0;
    
    AbstractHex *game = (AbstractHex*)new HexVector;            //HEXVECTOR
    AbstractHex *game2 = (AbstractHex*)new HexArray;            //HEXARRAY1D
    AbstractHex *game3 = (AbstractHex*)new HexAdapter<deque>;   //HEXADAPTER(DEQUE)
    AbstractHex *game4 =(AbstractHex*) new HexAdapter<vector>;  //HEXADAPTER(VECTOR)

    AbstractHex * arrayGame[4];
    
    try{                            //catch try throw exception
    
        while(choose != 5){
            cout<<"\n    ««««WELCOME THE TO HEXGAME»»»»»   "<< endl;                //MENU
            cout<<"    ««««PLEASE CHOOSE THE HEXGAME TYPES OR EXIT»»»»»   "<<endl;
            cout << "(PRESS '1' for HexVector Game)" << endl;
            cout << "(PRESS '2' for Hex1DArray Game)" << endl;
            cout << "(PRESS '3' for HexAdapter(DEQUE) Game)" << endl;
            cout << "(PRESS '4' for HexAdapter(VECTOR)Game)" << endl;
            cout << "(PRESS '5' for Exit)"<< endl;
            cin >> choose;
            
            if(choise1 == -1){

                choise1 = choose;
            }
                else
                    choise2 = choose;

            switch(choose){
                case 1:
                    game->playGame();
                    cout << "NUMBER OF MOVES: = " << game->numberOfMoves() << endl;  //My program print number of markeds in every end of game
                    arrayGame[countArray++] = game;
                    cout<< "LAST MOVE:" <<  char(game->lastMove().column + 'A') << game->lastMove().row+1 << endl;
                break;

                case 2:
                    game2->playGame();
                    cout << "NUMBER OF MOVES: = " << game2->numberOfMoves() << endl;  //I print the number of moves
                    arrayGame[countArray++] = game2;                                  //I Determine last move.
                    cout<< "LAST MOVE:" <<  char(game2->lastMove().column + 'A') << game2->lastMove().row+1 << endl;
                break;
            
                case 3:
                    cout<<"WELCOME TO THE HEXADAPTER(DEQUE) GAME"<<endl;
                    game3->playGame();
                    cout << "NUMBER OF MOVES: = " << game3->numberOfMoves() << endl;  
                    arrayGame[countArray++] = game3;
                    cout<< "LAST MOVE:" <<  char(game3->lastMove().column + 'A') << game3->lastMove().row+1 << endl;
                break;

                case 4:
                    cout<<"WELCOME TO THE HEXADAPTER(VECTOR) GAME"<<endl;
                    game4->playGame();
                    cout << "NUMBER OF MOVES: = " << game4->numberOfMoves() << endl;  
                    arrayGame[countArray++] = game4;
                    cout<< "LAST MOVE:" <<  char(game4->lastMove().column + 'A') << game4->lastMove().row+1 << endl;
                break;
                
                case 5: 
                    
                    if(countArray >= 2)
                        if(*arrayGame[countArray-1] == *arrayGame[countArray-2]){   //I use  the == operator (GAME EQUAL).

                            cout << "LAST TWO GAMES ARE EQUAL" << endl;
                        }
                            else
                                cout << "LAST TWO GAMES ARE NOT EQUAL" << endl;
                    exit(1);
                break;

                default:
                throw "Invalid input please enter the number from 1 to 5.";
            }
                validSequenceOfMoves(arrayGame,countArray);  //I call the Global function.


        }
        
    }  
       
        catch(const char* Error){
            
            cerr << Error;
            exit(1);
        }
    
    
    
    return 0;
}
