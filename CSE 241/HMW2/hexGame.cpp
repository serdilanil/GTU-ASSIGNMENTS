#include<iostream>
#include<fstream>
#include<string>
#include "hexGame.h"
#include<sstream>

using namespace std;

void Game(){

    int size;
    int board[12][12] = {};         //I have created a table for the letters X and O.
    int checkBoard[12][12];         //I also used this table to see if the dot is filled or not.
    cout << "(PLEASE WRITE A NUMBER BETWEEN 6 AND 12.(6 AND 12 ARE INCLUDED)" << endl;
    cin >> size;

    cout << "PLEASE SELECT GAME TYPE (TWO USER GAME OR VERSUS COMPUTER GAME)" << endl;
    cout << "<<<<<IF YOU WANT SAVE OR LOAD THE GAME YOU CAN WRITE LIKE THIS(SAVE file.txt or LOAD file.txt samples)>>>>>>" << endl;
    cout <<  "<<<<<  FOR PLAY USER1 VS USER2 PRESS '1' (PLEASE WRITE LIKE A7,B5,C4 samples)  >>>>" << endl
         << "<<<<<  FOR PLAY USER VS COMPUTER PRESS '2' (PLEASE WRITE LIKE A7,B5,C4 samples) >>>>>" << endl;

    int selection;
    cin >> selection;

    switch(selection){

    case 1:
        userGame(board,size,checkBoard,selection);  //I created this function for User1 vs User2 game.
    break;

    case 2:
        userComputer(board,size,checkBoard,selection); //I created this function for User vs Computer game.
    break;

    default:
         cout<< "Please enter the 1 or 2 numbers:" << endl;

    }

}

void boardPrint(int size,int board[12][12],int winFlag){  //I set up this function to print the table with its point, x and letter o.
    
    char ch1 = 'x';
    char ch2 = 'o';
    int i,j;
    int counter = 1;
    char m;
    int count = 0;

            if(winFlag == 1)
                ch1 = 'X';
            
                else if(winFlag == 2)
                    ch2 = 'O';


    cout << endl;
    for(m = 'A'; m <= 'Z' ; m++){   //Here I filled the table with letters on one side and numbers on the other.
        count ++;
        cout <<" ";
        cout << m << " ";

        if(size == count){

            break;
        }
    }
        cout << "\n";

            if(size <= 12 && size >= 6){

                for(i=0 ; i<size;i++){

                    cout << i+1 <<"";

                    for(int k = 0 ; k < counter ; ++k)

                        cout<<" " ;
                        counter++;

                        for(j = 0; j<size;j++){

                            if(board[i][j] == user1)  //Here I am converting the letter x as 1 and converting it to x here.
                                cout << ch1;

                                else if(board[i][j] == user2) //Here I am converting the letter o as 2 and converting it to x here.
                                    cout << ch2;

                                    else
                                        cout << ".";  // if there is not x or o I put the point.

                                            cout << "  ";
                            }

                                        cout << "\n";
                    }

                }

    else{

        cout << "Please enter the from 6 to 12: " << endl;
    }
}


void userGame(int board[12][12],int size,int checkBoard[12][12],int selection){   //Function to get the player input and update the board.
    int type,number,num;
    int turn = 1;
    char character;
    int check_x, check_o;
    string srd;
    decltype(srd)srd2;
    stringstream my_ss;
    bool saveGG = false;

    do{
    	checkIn(checkBoard);   //Here I reset checkboard.
        
        if(turn == 1){
            cout << "first player - 1 [x] turn: ";  //for first user turn.
        }

        else if(turn == 2){

            cout << "second player- 2[o] turn :"; // for second user turn.
        }

        cin >> srd;
 
            if(srd == "SAVE"){
                cout <<"SAVED"<< endl;
                cin >> srd2;
                saveGame(board,srd2,size,selection);
                saveGG = true;
            }
                
                else if(srd == "LOAD"){
                    cout << "LOADED"<< endl;
                    cin >> srd2;
                    loadGame(board,size,srd2,selection);
                    saveGG = true;
                }


                    else
                    {
                        my_ss.str(srd); 
                        my_ss.clear();
                        my_ss >> character >> number;
                        num = convertCoordinate(character);   //Here I am converting the character to a number and sending it to the array.

                    }
                

       if(saveGG == false){ 
            if(turn == 1 && board[number-1][num] != user1 && board[number-1][num] != user2){  //I am updating the position for User 2
                    
                    board[number-1][num] = user1;
                    boardPrint(size,board);
                    turn = 2;
                }

                    else if(turn == 2 && board[number-1][num] != user1 && board[number-1][num] != user2 ){ // I am updating the position for User1
                        
                        board[number-1][num] = user2;
                        boardPrint(size,board);
                        turn = 1;
                    }
                        else {
                        
                            cout<<"Box already filled! Please choose another!!" << endl;   //if input position already filled
                        
                        }

                check_x = winGame_X(board,0,0,size - 1,checkBoard,1);  
                check_o = winGame_X(board,0,0,size - 1,checkBoard,2);   
       }

        saveGG = false;

    }while(check_x != 1 && check_o != 1);                       //If the winning condition is 1, the loop ends and the winner is written.

    if(turn == 1){ 
        boardPrint(size,board,2);
        cout << "CONGRATS USER 2 WON!!!" << endl; 
    }
        else if(turn == 2){
            boardPrint(size,board,1);
            cout << "CONGRATS USER 1 WON!!!" << endl;       
        }
}

int convertCoordinate(char &character){  //In this function, I convert the entered character with the number to a number and send it to the integer array.

    switch(character){     

        case 'A':
            return 0;
        break;

        case 'B':
            return 1;
        break;

        case 'C':
            return 2;
        break;

        case 'D':
            return 3;
        break;

        case 'E':
            return 4;
        break;

        case 'F':
            return 5;
        break;

        case 'G':
            return 6;
        break;

        case 'H':
            return 7;

        case 'I':
            return 8;
        break;
        
        case 'J':
             return 9;
        break;
        
        case 'K':
            return 10;
        break;
        
        case 'L':
             return 11;     
        break;

        default:
            cout << "Invalid value" << endl;

    }
        return -1;

}

void checkIn(int checkBoard[12][12]){  // I reset board in this function.

    for(int i = 0; i < 12; i++){

        for(int j =0 ; j<12;j++){

            checkBoard[i][j] = 0;
        }
    }
}

int checkRange(int x,int y,int size){  //here I make sure the coordinates do not go out of the table.
    int flag =0;

    if(x >= 0 && x < size + 1){
        if(y >= 0 && y < size + 1){
            flag = 1;
        }
    }
    return flag;
}


int winGame_X(int board[12][12],int x,int y,int size,int checkBoard[12][12], int a){  //I used recursive to find the win condition in this function.

    int exit_for = 0;
    if(x == 0 && y == 0){
        for(int i=0; i<size+1; i++){
            for(int k=0; k<size+1; k++){
                if(board[i][k] == a){
                    x = i;
                    y = k;
                    exit_for = 1;
                    break;
                }
            }
            if(exit_for == 1) break;
        }
    }

    if(a == 1){
		if(y == size  && board[x][y] == user1){   //Base condition
            return 1;
		}
	}
	
        else if(a == 2){                     //Base condition
            if(x == size  && board[x][y] == user2){
                return 1;
            }
        }

	
    //Here, I scan all 6 directions, if they meet the conditions, I continue the same way and when I reach the end of the table, I meet the winning condition.
    //North
    if(board[x][y] == a && checkRange(x,y,size) == 1 && x-1 >= 0 && board[x-1][y] == a &&checkBoard[x-1][y] == 0){

                checkBoard[x][y] = 1;
                return winGame_X(board,x-1,y,size,checkBoard,a);
        }


                        //In these conditions, I enter the coordinates of the condition according to the directions and scan it.
        //South
        else if(board[x][y] == a && checkRange(x,y,size) == 1  && x + 1 <= size && board[x+1][y] == a && checkBoard[x+1][y] == empty){
                checkBoard[x][y] = 1;
                return winGame_X(board,x+1,y,size,checkBoard,a);
        }

        //East
         else if(board[x][y] == a && checkRange(x,y,size) == 1 && y+1 <= size && board[x][y+1] == a && checkBoard[x][y+1] == empty){
                checkBoard[x][y] = 1;
                return winGame_X(board,x,y+1,size,checkBoard,a);
        }

        //West
         else if(board[x][y] == a && checkRange(x,y,size) == 1  && y-1 >= 0 && board[x][y-1] ==a && checkBoard[x][y-1] == empty){
                    checkBoard[x][y] = 1;
                    return winGame_X(board,x,y-1,size,checkBoard,a);
        }

        //South West
        else if(board[x][y] == a && checkRange(x,y,size) == 1  && board[x+1][y-1] == a && checkBoard[x+1][y-1] == empty){
                        checkBoard[x][y] = 1;
                        return winGame_X(board,x+1,y-1,size,checkBoard,a);
        }

        //North East
        else if(board[x][y] == a && checkRange(x,y,size) == 1 && y+1 <= size && board[x-1][y+1] == a && x -1 >= 0 && checkBoard[x-1][y+1] == empty){
                    checkBoard[x][y] = 1;
                    return winGame_X(board,x-1,y+1,size,checkBoard,a);
        }

		return 0;
}


void userComputer(int board[12][12],int size,int checkBoard[12][12],int selection){ //Here I get input from computer and user and pass it to the table.
    int winFlag;
    int value = 1;
    int turn = 1;
    char character;
    int number,num;
    int check_x, check_o,i,j;
    int num2 = 0;
    string srd,srd2;
    stringstream my_ss;
    bool saveGG = false;

    do{
        
        checkIn(checkBoard);  // I reset the checkboard
        
        if(turn == 1){
            cout << "first player - 1 [X] turn: ";
             cin >> srd;
        }

        else if(turn == 2){

            cout << "second player- 2[0] turn :\n";
        }

            if(srd == "SAVE"){
                cout << "SAVED"<< endl;
                cin >> srd2;
                saveGame(board,srd2,size,selection);
                saveGG = true;
            }
                
                else if(srd == "LOAD"){
                    cout << "LOADED" << endl;
                    cin >> srd2;
                    loadGame(board,size,srd2,selection);
                    saveGG = true;
                }


                    else
                    {
                        my_ss.str(srd); 
                        my_ss.clear();
                        my_ss >> character >> number;
                        num = convertCoordinate(character);   //Here I am converting the character to a number and sending it to the array.

                    }
                            
                        if(saveGG == false){


                        if(turn == 1 && board[number-1][num] != user1 && board[number-1][num] != user2){
                                
                                board[number-1][num] = user1;
                                boardPrint(size,board,winFlag);
                                turn = 2;
                            }

                                else if(turn == 2){    //If the row is equal to 2, I leave the assignment of the letter 'o' to artificial intelligence and I do this with ifs.
                                
                                if(value >= size){
                                    value = size -2;
                                }

                                if(num2 >= size){

                                    num2 = size - 2;
                                }       
                                    
                                    if(value < size){

                                        if(board[value -1][num2] == empty){

                                            board[value - 1][num2] = user2;
                                            turn = 1;
                                        }

                                            else if(board[value - 1][num2] != empty){

                                                value++;

                                                if(board[value-1][num2] !=empty){
                                                    num2++;
                                                }
                                                    
                                                    if(board[value -1][num2] == empty){       
                                                        board[value-1][num2] = user2;
                                                        turn = 1;
                                                    }

                                            }
                                                        num2++;
                                                        boardPrint(size,board,winFlag);               
                                    }
                                    
                                }
                                    else {
                                        cout<<"Box already filled! Please choose another!!" << endl;
                                        userGame(board,size,checkBoard,selection);
                                    }

                            check_x = winGame_X(board,0,0,size - 1,checkBoard,1);  //If the winning condition is 1, the loop ends and the winner is written.
                            check_o = winGame_X(board,0,0,size - 1,checkBoard,2);
                                        
                        }
                                saveGG = false;

    }while(check_x != 1 && check_o != 1);
    
    if(turn == 1){ 
        boardPrint(size,board,2);
        cout << "CONGRATS USER 2 WON!!!" << endl; 
    }
        else if(turn == 2){
            boardPrint(size,board,1);
            cout << "CONGRATS USER 1 WON!!!" << endl;       
        }
}

void saveGame(int board[12][12],const string& filename,int size,int selection){ //in this function I save the game information in txt file.

    int counter = 1;
    char m;
    char c = '.';
    string ssd;

    ofstream file;

    file.open(filename);

     if (!file) {
        cerr << "Unable to open file ";   // if we can't open the file , we take error with cerr.
    }

    
    file << selection << endl;    //in this we write to file game type(user vs user or user vs computer.)
    file << size << endl;         //in this we write to file board size.
        
        file << 'x' << endl;     


        for(auto i=0;i<size;i++){    //in this we write the location coordinate for 'x'.
            
            for(auto j = 0;j< size;j++){  // And I use the auto statement.

                if(board[i][j] == user1){  
                    
                    file << j << " " << i << endl;
                }
            }
        }
    

        file << 'o' << endl;       

        for(auto i =0;i<size;i++){       //in this we write the location coordinate for 'o'.
            
            for(auto j = 0;j< size;j++){

                if(board[i][j] == user2){

                    file << j << " " << i << endl;
                }
            }
        }

        file << '*' << endl;
    
    file.close();

}

void loadGame(int board[12][12],int size,const string& filename,int selection){ //I load the saved game in the terminal and I use the const reference parameter in this function.
    int winFlag,gameType;
    int checkBoard[12][12];
    string line;

    ifstream file;
    
    file.open(filename);

    for(int i =0;i<12;i++){

        for(int j=0;j<12;j++){

            board[i][j] = empty;
        }
    }


       if (!file) {
        cerr << "Unable to open file";
       }

        getline(file,line);   //in this function I read the txt. file line by line with getline.
        gameType = stoi(line);
        getline(file,line);
        size = stoi(line);          // I convert the string to int by using stoi.

        while(getline(file,line)){

            if(line == "x"){
                getline(file,line);
                

                while(line != "o"){
                    board[stoi(&line[2])][stoi(line)] = user1;
                    getline(file,line);

                }

            }

                if(line == "o"){
                    getline(file,line);
                     while(line != "*"){
                        board[stoi(&line[2])][stoi(line)] = user2;
                        getline(file,line);

                    }
                }    

            cout << line << endl;
        }

            boardPrint(size,board,winFlag);

        if(selection != gameType){

            if(gameType == 1){

                userGame(board,size,checkBoard,gameType);
            }
        
               else if(gameType == 2){

                   userComputer(board,size,checkBoard,gameType);
               } 
        }
}