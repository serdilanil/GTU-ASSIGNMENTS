#include "hexGame.h"

Hex::Hex():size(6),turn(1),board(nullptr),recordIndex(0){  //To use the undo property in this constructor .I'm recording the moves I made.
 

    record= new int*[144];

    for(int i=0;i<144;i++){

        record[i] = new int[2];
        
    }
}

int Hex::Gmove = 0;  //I am using a static value to show the cells marked here.

int Hex::markedCells(){   //I return marked Cells.

    return Gmove;
}


Hex::Cell::Cell(int x,int y,int z){  //for return Cell

    int row = x;
    int column = y;
    int cellState = z;
}

Hex::Cell::Cell(){}

ofstream &operator<<(ofstream &out,const Hex &boardGame){  //I modified this function by operator overloading.(To save game)

    out << boardGame.selection << endl;    //in this we write to file game type(user vs user or user vs computer.)
    out<< boardGame.size << endl;         //in this we write to outboard size.

        out << 'x' << endl;     

        for(auto i=0;i<boardGame.size;i++){    //in this we write the location coordinate for 'x'.
            
            for(auto j = 0;j< boardGame.size;j++){  // And I use the auto statement.

                if(boardGame.board[i][j].cellState == user1){  
                    
                    out << j << " " << i << endl;
                }
            }
        }
    
        out << 'o' << endl;       

        for(auto i =0;i<boardGame.size;i++){       //in this we write the location coordinate for 'o'.
            
            for(auto j = 0;j< boardGame.size;j++){

                if(boardGame.board[i][j].cellState == user2){

                    out << j << " " << i << endl;
                }
            }
        }

        out << '*' << endl;
        return out;  
}

ostream &operator<<(ostream &outTerm,const Hex &boardGame){ //I modified this function by operator overloading.

    char ch1 = 'x';                                         //I used to print board.
    char ch2 = 'o';
    int i,j;
    int counter = 1;
    char m;
    int count = 0;

     for(m = 'A'; m <= 'Z' ; m++){   //Here I filled the table with letters on one side and numbers on the other.
        
        count ++;
        outTerm <<" ";
        outTerm << m << " ";

        if(boardGame.size == count){

            break;
        }
    }
        cout << "\n";

            if(boardGame.size <= 12 && boardGame.size >= 6){

                for(i=0 ; i<boardGame.size;i++){

                    outTerm << i+1 <<"";

                    for(int k = 0 ; k < counter ; ++k)

                        outTerm <<" " ;
                        counter++;

                        for(j = 0; j<boardGame.size;j++){

                            if(boardGame.board[i][j].cellState == user1)  //Here I am converting the letter x as 1 and converting it to x here.
                                outTerm << ch1;

                                else if(boardGame.board[i][j].cellState == user2) //Here I am converting the letter o as 2 and converting it to x here.
                                    outTerm << ch2;

                                    else
                                        outTerm << ".";  // if there is not x or o I put the point.

                                            outTerm << "  ";
                        }
                                        outTerm << "\n";
                }
            }
    else{

        cout << "Please enter the from 6 to 12: " << endl;
    }
                        return outTerm;
}


ifstream &operator>>(ifstream &inTerm, Hex &boardGame){   //I modified this function by operator overloading.(To load game.)

int gameType;
string line;

     getline(inTerm,line);   //in this function I read the txt. file line by line with getline.
        gameType = stoi(line);
        getline(inTerm,line);
        boardGame.size = stoi(line);          // I convert the string to int by using stoi.

        while(getline(inTerm,line)){

            if(line == "x"){
                getline(inTerm,line);
                while(line != "o"){
                    boardGame.board[stoi(&line[2])][stoi(line)].cellState = user1;
                    getline(inTerm,line);
                }
            }
                if(line == "o"){
                    getline(inTerm,line);
                     while(line != "*"){
                        boardGame.board[stoi(&line[2])][stoi(line)].cellState = user2;
                        getline(inTerm,line);
                    }
                }    

            cout << line << endl;
        }

            boardGame.boardPrint(boardGame.winFlag);

        if(boardGame.selection != gameType){

            if(gameType == 1){

                boardGame.userGame();
            }
        
               else if(gameType == 2){

                   boardGame.userComputer();
               } 
        }

            return inTerm;
}

 Hex::Cell Hex::play(){   //In this function played from computer.(non -parameter).
    
    int number,num,a;
                   
                    if(value >= size){
                        value = size -2;
                    }

                    if(num2 >= size){

                        num2 = size - 2;
                    }       
                        
                        if(value < size){

                                if(board[value -1][num2].cellState == empty){
                                    board[value - 1][num2].cellState = user2;
                                    Gmove++;
                                    turn = 1;
                                    record[recordIndex][0] = num2;
                                    record[recordIndex++][1] = value-1;
                                    a = score(value-1,num2);
                                    cout << "computer_score:" << a << endl;
                                    return Cell(value-1,num2,user2);  
                                }

                                    else if(board[value - 1][num2].cellState != empty){

                                            value++;

                                                if(board[value-1][num2].cellState !=empty){
                                                    num2++;
                                                }
                                            
                                                if(board[value -1][num2].cellState == empty){       
                                                    board[value-1][num2].cellState = user2;
                                                    Gmove++;
                                                    turn = 1;
                                                    record[recordIndex][0] = num2;
                                                    record[recordIndex++][1] = value-1;
                                                     a = score(value-1,num2);
                                                    cout << "computer_score:" << a << endl;
                                                    return Cell(value-1,num2,user2);
                                                }
                                    }
                                                num2++;                          
                            }
                                    Cell temp;
                                    return temp;
}


Hex Hex::operator --(int){   //While playing here, I record the moves I make and transfer the order to the other user.

    Hex oper = *this;
    
    if(recordIndex != 0){
        board[record[recordIndex-1][1]][record[recordIndex-1][0]].cellState = empty;
        checkBoard[record[recordIndex-1][1]][record[recordIndex-1][0]] = 0;
            
            recordIndex--;  //When I turn back, I make sure that the point is blank.

            if(turn == 1){

                turn = 2;
            }

                else if(turn == 2){

                    turn = 1;
                }
    }
        
        return oper;

}

Hex& Hex::operator--(){  //While playing here, I record the moves I make and transfer the order to the other user.

    if(recordIndex != 0){
        board[record[recordIndex-1][1]][record[recordIndex-1][0]].cellState = empty;

        checkBoard[record[recordIndex-1][1]][record[recordIndex-1][0]] = 0;  //When I turn back, I make sure that the point is blank.

        if(turn == 1){

            turn = 2;
        }
            
            else if(turn == 2){

                turn = 1;
            }
    
        recordIndex--;
    }
    
    return (*this);
}

void Hex::playGame(){  //In this function, we select size,game type in briefly we start the game here.

   
    checkIn();        
                                
    cout << "(PLEASE WRITE A NUMBER FOR BOARD SIZE(MINIMUM:6 FOR BOARD SIZE)" << endl;
    cin >> size;

    cout << "PLEASE SELECT GAME TYPE (TWO USER GAME OR VERSUS COMPUTER GAME)" << endl;
    cout << "<<<<<IF YOU WANT SAVE OR LOAD THE GAME YOU CAN WRITE LIKE THIS(SAVE file.txt or LOAD file.txt samples)>>>>>>" << endl;
    cout <<  "<<<<<  FOR PLAY USER1 VS USER2 PRESS '1' (PLEASE WRITE LIKE A7,B5,C4 samples)  >>>>" << endl
         << "<<<<<  FOR PLAY USER VS COMPUTER PRESS '2' (PLEASE WRITE LIKE A7,B5,C4 samples) >>>>>" << endl;

    cin >> selection;
    
    resize();

    switch(selection){

    case 1:
        userGame();  //I created this function for User1 vs User2 game.
    break;

    case 2:
        userComputer(); //I created this function for User vs Computer game.
    break;

    default:
        cout<< "Please enter the 1 or 2 numbers:" << endl;
    
    }
}  

void Hex::play(const Cell& State){

int x,y,a;
     
     if(turn == 1 && board[State.row][State.column].cellState != user1 && board[State.row][State.column].cellState != user2){  //I am updating the position for User 2
                    
                    board[State.row][State.column].cellState = user1;
                    Gmove++;
                    boardPrint(winFlag);
                    a = score(State.row,State.column);
                    cout << "user1_score:" << a << endl;   //I print the score.
                    record[recordIndex][0] = State.column;
                    record[recordIndex++][1] = State.row;
                    turn = 2;
                }
                    else if(turn == 2 && board[State.row][State.column].cellState != user1 && board[State.row][State.column].cellState != user2 ){ // I am updating the position for User1
                        
                        board[State.row][State.column].cellState = user2;
                        Gmove++;                        // I increase the static value for marked cells.
                        boardPrint(winFlag);  // I print the board.
                        a = score(State.row,State.column);
                        cout << "user2_score:" << a << endl;   //I print the score.
                        record[recordIndex][0] = State.column;
                        record[recordIndex++][1] = State.row;
                        turn = 1;
                    }
                        else {
                        
                            cout<<"Box already filled! Please choose another!!" << endl;   //if input position already filled
                        }
}

void Hex::resize(){     //In this function, I made my assignments in the cell class.

      Cell ** temp;    // I used dynamic array.
      temp = new Cell*[size];
    
    if(board != nullptr){
    
        for(int i=0;i<size;i++){
            delete [] board[i];
        }
            delete [] board;
            board = nullptr;
    }

        for(int i=0;i<size;i++){

            
            temp[i] = new Cell[size];
            
            for(int j=0;j<size;j++){
                temp[i][j].cellState = empty;
                temp[i][j].column = j;  
                temp[i][j].row = i;
            }
        
        }
            board = temp;
}

void Hex::boardPrint(int winFlag){  //I set up this function to print the table with its point, x and letter o.
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

    cout << *this;

}

void Hex::userGame(){   //Function to get the player input and update the board.
    int type,number,num;
    int check_x, check_o;
    string srd;
    decltype(srd)srd2;
    stringstream my_ss;
    bool saveGG = false;
    const Hex end;

    do{
    	checkIn();   //Here I reset checkboard.
        
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
                saveGame(srd2);
                saveGG = true;
            }
                
                else if(srd == "undo"){   //undo

                    --(*this);
                    saveGG = true;
                    boardPrint(winFlag);
                }

                else if(srd == "LOAD"){
                    cout << "LOADED"<< endl;
                    cin >> srd2;
                    loadGame(srd2);
                    saveGG = true;
                }
                    else
                    {
                        my_ss.str(srd); 
                        my_ss.clear();
                        my_ss >> character >> number;
                        num = convertCoordinate();   //Here I am converting the character to a number and sending it to the array.

                    }
                
       if(saveGG == false){ 
           play(board[number-1][num]);   //I called play function for user vs user.

                for(int i=0;i<size;i++){
                        if(board[i][0].cellState == user1)
                            check_x = winGame_X(i,0,1);  
                    
                }
                   for(int k=0;k<size;k++){
                        if(board[0][k].cellState == user2)
                        check_o =  winGame_X(0,k,2);  
                        
                    }            
       }
                
        saveGG = false;

    }while(check_x != 1 && check_o != 1);                       //If the winning condition is 1, the loop ends and the winner is written.

    if(check_o  == 1){ 
        boardPrint(2);
        cout << "CONGRATS USER 2 WON!!!" << endl; 
        end.endGame();
    }
        else if(check_x == 1){
            boardPrint(1);
            cout << "CONGRATS USER 1 WON!!!" << endl;       
            end.endGame();
        }
}

int Hex::convertCoordinate(){  //In this function, I convert the entered character with the number to a number and send it to the integer array.
    int x =0;

    for(char m = 'A'; m <= 'Z'; m++){

        if(character == m){
            return x;
        }
            x++;
    }
        return -1;
}

void Hex::checkIn(){  // I reset board in this function.
    
    for(int i = 0; i < size; i++){

        for(int j =0 ; j<size;j++){

            checkBoard[i][j] = empty;
        }
    }
}

int Hex::checkRange(int x,int y){  //here I make sure the coordinates do not go out of the table.
    int flag =0;
    
    if(x >= 0 && x < size + 1){
        if(y >= 0 && y < size + 1){
            flag = 1;
        }
    }
    return flag;
}

int Hex::score(int x,int y){  //Here, the function gives scores according to the moves made by the users.

    if(turn == 1){         //For user1
        if(x==1 && x==size){

             user1_score = user1_score+15;
             return user1_score;
        }
            else if(x== 2 || x == 3 || x == 4){
                user1_score = user1_score + 5;
                  return user1_score;
            }
                else{
                     user1_score = user1_score + 10;
                      return user1_score;
                }
    }
        else if(turn == 2){   //For useer2
            if(y==1 || y == size){
                 user2_score = user2_score+15;
                  return user2_score;
            }
        
                else if(y == 2 || y == 3 || y == 4 ){
                    user2_score = user2_score + 5;
                      return user2_score;
                }
        
                    else{
                       user2_score = user2_score + 10;
                        return user2_score;
                    }
        }
                return 5;
 }

int Hex::winGame_X(int x,int y,int a){  //I used recursive to find the win condition in this function.

    int direction = 0;
    int exit_for = 0;
    if(x == 0 && y == 0){
        for(int i=0; i<size; i++){
            for(int k=0; k<size; k++){
                if(board[i][k].cellState == a){
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
		if(y == size-1  && board[x][y].cellState == user1){   //Base condition
            return 1;
		}
	}
	
        else if(a == 2){                     //Base condition
            if(x == size-1  && board[x][y].cellState == user2){
                return 1;
            }
        }

	
    //Here, I scan all 6 directions, if they meet the conditions, I continue the same way and when I reach the end of the table, I meet the winning condition.
    //North
            if(x-1 >= 0 && x-1 < size && y >= 0 && y < size){
                if(board[x][y].cellState == a && checkRange(x,y) == 1  && board[x-1][y].cellState == a && checkBoard[x-1][y] == empty){
                    checkBoard[x][y] = 1;
                    direction = winGame_X(x-1,y,a);
                }
            }


                        //In these conditions, I enter the coordinates of the condition according to the directions and scan it.
        //South
             if(x+1 >= 0 && x+1 < size && y >= 0 && y < size && direction == 0){
                if(board[x][y].cellState == a && checkRange(x,y) == 1  && board[x+1][y].cellState == a && checkBoard[x+1][y] == empty){
                    checkBoard[x][y] = 1;
                    direction = winGame_X(x+1,y,a);
                } 
            }

        //East
             if(x >= 0 && x < size && y+1 >= 0 && y+1 < size && direction == 0){
                 if(board[x][y].cellState == a && checkRange(x,y) == 1  && board[x][y+1].cellState == a && checkBoard[x][y+1] == empty){
                    checkBoard[x][y] = 1;
                    
                    direction = winGame_X(x,y+1,a);
                }
            }

        //West
                 if(x >= 0 && x < size && y-1 >= 0 && y-1 < size && direction == 0){
                    if(board[x][y].cellState == a && checkRange(x,y) == 1   && board[x][y-1].cellState == a && checkBoard[x][y-1] == empty){
                        checkBoard[x][y] = 1;
                         
                        direction = winGame_X(x,y-1,a);
                    }
                }

        //South West
            if(x+1 >= 0 && x+1 < size && y-1 >= 0 && y-1 < size && direction == 0){
                        if(board[x][y].cellState == a && checkRange(x,y) == 1   && board[x+1][y-1].cellState == a && checkBoard[x+1][y-1] == empty){
                            checkBoard[x][y] = 1;
                                                
                            direction = winGame_X(x+1,y-1,a);
                        }
            }

        //North East
            if(x-1 >= 0 && x-1 < size && y+1 >= 0 && y+1 < size && direction == 0){
                    if(board[x][y].cellState == a && checkRange(x,y) == 1   && board[x-1][y+1].cellState == a && checkBoard[x-1][y+1] == empty){
                        checkBoard[x][y] = 1;

                         direction = winGame_X(x-1,y+1,a);
                    }
            }

		return direction;
}


void Hex::userComputer(){   //in this function Computer and user enter input to the board.
    int number,num,a;
    int check_x, check_o,i,j;
    string srd,srd2;
    stringstream my_ss;
    bool saveGG = false;
    const Hex end2;

    do{
        checkIn();  // I reset the checkboard
        
        if(turn == 1){
            cout << "first player - 1 [X] turn: ";
            cin >> srd;
        }

        else if(turn == 2){

            cout << "second player- 2[0] turn :\n";
        }

            if(srd == "SAVE"){      //If you write SAVE file.txt etc. all game is saved. 
                cout << "SAVED"<< endl;
                cin >> srd2;
                saveGame(srd2);
                saveGG = true;
            }
                
                else if(srd == "LOAD"){    //If you write LOAD file.txt etc. all game loaded.
                    cout << "LOADED" << endl;
                    cin >> srd2;
                    loadGame(srd2);
                    saveGG = true;
                }

                     else if(srd == "undo"){  //undo

                        --(*this);
                        boardPrint(winFlag);
                    }

                    else
                    {
                        my_ss.str(srd); 
                        my_ss.clear();
                        my_ss >> character >> number;
                        num = convertCoordinate();   //Here I am converting the character to a number and sending it to the array.

                    }
                            
                        if(saveGG == false){

                            if(turn == 1 && board[number-1][num].cellState != user1 && board[number-1][num].cellState != user2){
                                    board[number-1][num].cellState = user1;
                                    boardPrint(winFlag);
                                    a = score(number-1,num);
                                    cout << "user_1 score: " << a << endl;
                                    turn = 2;
                            }

                                    else if(turn == 2){
                                        play();           //I called play function for AI.            
                                        boardPrint(winFlag); 
                                    }
                                            else {
                                                cout<<"Box already filled! Please choose another!!" << endl;
                                                userGame();
                                            }

                                    for(int i =0; i<size;i++){
                                        if(board[i][0].cellState == user1)
                                            check_x = winGame_X(i,0,1);
                                    }

                                    for(int k=0;k<size;k++){
                                        if(board[0][k].cellState == user2)
                                        check_o = winGame_X(0,k,2);
                                    }

                        }
                                saveGG = false;

    }while(check_x != 1 && check_o != 1);
    
    if(check_o == 1){ 
        boardPrint(2);
        cout << "CONGRATS USER 2 WON!!!" << endl; 
        end2.endGame();
    }
        else if(check_x == 1){
            boardPrint(1);
            cout << "CONGRATS USER 1 WON!!!" << endl;       
            end2.endGame();
        }
}

void Hex::saveGame(const string& filename){ //in this function I save the game information in txt file.

    int counter = 1;
    char m;
    char c = '.';
    string ssd;
    ofstream file;

    file.open(filename);

     if (!file) {
        cerr << "Unable to open file ";   // if we can't open the file , we take error with cerr.
    }
    
    file << (*this);
    file.close();

}

void Hex::loadGame(const string& filename){ //I load the saved game in the terminal and I use the const reference parameter in this function.
    int gameType;
    string line;

    ifstream file;
    file.open(filename);

    for(int i =0;i<size;i++){

        for(int j=0;j<size;j++){

            board[i][j].cellState = empty;
        }
    }

       if (!file) {
        cerr << "Unable to open file";
       }

       file >> *this;
}
