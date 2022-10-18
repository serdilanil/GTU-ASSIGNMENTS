#include "hexGame.h"


int Hex::Gmove = 0;  //I am using a static value to show the cells marked here.

int Hex::markedCells(){   //I return marked Cells.

    return Gmove;
}

void Hex::play(){   //In this function played from computer.(non -parameter).
    
    int number,num;
                   
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
                                                }

                                    }
                                                num2++;
                                                boardPrint(winFlag);               
                            }

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


     if(turn == 1 && board[State.row][State.column].cellState != user1 && board[State.row][State.column].cellState != user2){  //I am updating the position for User 2
                    
                    board[State.row][State.column].cellState = user1;
                    Gmove++;
                    boardPrint(winFlag);
                    turn = 2;
                }
                    else if(turn == 2 && board[State.row][State.column].cellState != user1 && board[State.row][State.column].cellState != user2 ){ // I am updating the position for User1
                        
                        board[State.row][State.column].cellState = user2;
                        Gmove++;                        // I increase the static value for marked cells.
                        boardPrint(winFlag);  // I print the board.
                        turn = 1;
                    }
                        else {
                        
                            cout<<"Box already filled! Please choose another!!" << endl;   //if input position already filled
                        }
}

void Hex::resize(){     //In this function, I made my assignments in the cell class.

    vector < Cell > cellS;
    Cell cell;

    for(int i=0;i<size;i++){

        for(int j =0;j<size;j++){

            cell.column = j;
            cell.row = i;
            cell.cellState = empty;

            cellS.push_back(cell);    
        }
            board.push_back(cellS);
            cellS.clear();   
    } 
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

                            if(board[i][j].cellState == user1)  //Here I am converting the letter x as 1 and converting it to x here.
                                cout << ch1;

                                else if(board[i][j].cellState == user2) //Here I am converting the letter o as 2 and converting it to x here.
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
    int number,num;
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
                                    turn = 2;
                            }

                                    else if(turn == 2){
                                        
                                        play();           //I called play function for AI.            
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

    
    file << selection << endl;    //in this we write to file game type(user vs user or user vs computer.)
    file << size << endl;         //in this we write to file board size.
        
        file << 'x' << endl;     


        for(auto i=0;i<size;i++){    //in this we write the location coordinate for 'x'.
            
            for(auto j = 0;j< size;j++){  // And I use the auto statement.

                if(board[i][j].cellState == user1){  
                    
                    file << j << " " << i << endl;
                }
            }
        }
    
        file << 'o' << endl;       

        for(auto i =0;i<size;i++){       //in this we write the location coordinate for 'o'.
            
            for(auto j = 0;j< size;j++){

                if(board[i][j].cellState == user2){

                    file << j << " " << i << endl;
                }
            }
        }

        file << '*' << endl;
    
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

        getline(file,line);   //in this function I read the txt. file line by line with getline.
        gameType = stoi(line);
        getline(file,line);
        size = stoi(line);          // I convert the string to int by using stoi.

        while(getline(file,line)){

            if(line == "x"){
                getline(file,line);
                while(line != "o"){
                    board[stoi(&line[2])][stoi(line)].cellState = user1;
                    getline(file,line);
                }
            }
                if(line == "o"){
                    getline(file,line);
                     while(line != "*"){
                        board[stoi(&line[2])][stoi(line)].cellState = user2;
                        getline(file,line);
                    }
                }    

            cout << line << endl;
        }

            boardPrint(winFlag);

        if(selection != gameType){

            if(gameType == 1){

                userGame();
            }
        
               else if(gameType == 2){

                   userComputer();
               } 
        }
}