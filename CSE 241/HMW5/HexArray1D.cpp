#include "AbstractHex.h"
#include "HexArray1D.h"

using namespace baseAbstract;
using namespace std;


void HexArray::play(){   //In this function played from computer.(non -parameter).

    
    int number,num;
                   
                    if(value >= size){
                        value = size -2;
                    }

                    if(num2 >= size){

                        num2 = size - 2;
                    }       
                        
                        if(value < size){

                                if(board[findIndex(value-1,num2)].cellState == empty){
                                    
                                    board[findIndex(value-1,num2)].cellState = user2;
                                    record = board[findIndex(value-1,num2)];
                                    Gmove++;
                                    turn = 1;
                                }

                                    else if(board[findIndex(value-1,num2)].cellState != empty){

                                            value++;

                                                if(board[findIndex(value-1,num2)].cellState !=empty){
                                                    num2++;
                                                }
                                            
                                                if(board[findIndex(value-1,num2)].cellState == empty){       
                                                    board[findIndex(value-1,num2)].cellState = user2;
                                                    record = board[findIndex(value-1,num2)];
                                                    Gmove++;
                                                    turn = 1;
                                                }

                                    }
                                                num2++;
                                                print(winFlag);               
                            }

}
void HexArray::play(const Cell& State){

     
     if(turn == 1 && board[State.column].cellState == empty ){  //I am updating the position for User 2
                    
                    board[State.column].cellState = user1;
                    record = board[State.column];
                    Gmove++;
                    print(winFlag);
                    turn = 2;
    }
                    else if(turn == 2 && board[State.column].cellState == empty ){ // I am updating the position for User1
                        
                        board[State.column].cellState = user2;
                        record = board[State.column];
                        Gmove++;          // I increase the static value for marked cells.
                        print(winFlag);  // I print the board.
                        turn = 1;
                    }
                        else {
                        
                            cout<<"Box already filled! Please choose another!!" << endl;   //if input position already filled
                        }
}

void HexArray::playGame(){  //In this function, we select size,game type in briefly we start the game here.

    int tempSize; 
    checkIn();        
    cout <<"<<<<  WELCOME TO THE HEXARRAY1D  >>>>" << endl;                      
    cout << "(PLEASE WRITE A NUMBER FOR BOARD SIZE(MINIMUM:6 FOR BOARD SIZE)" << endl;
    
    while(true){
        cin >> tempSize;
        
        if(setSize(tempSize) == true){

            break;
        }
    }
    
    createBoard();

    cout << "PLEASE SELECT GAME TYPE (TWO USER GAME OR VERSUS COMPUTER GAME)" << endl;
    cout << "<<<<<IF YOU WANT SAVE OR LOAD THE GAME YOU CAN WRITE LIKE THIS(SAVE file.txt or LOAD file.txt samples)>>>>>>" << endl;
    cout <<  "<<<<<  FOR PLAY USER1 VS USER2 PRESS '1' (PLEASE WRITE LIKE A7,B5,C4 samples)  >>>>" << endl
         << "<<<<<  FOR PLAY USER VS COMPUTER PRESS '2' (PLEASE WRITE LIKE A7,B5,C4 samples) >>>>>" << endl;

    cin >> selection;
    
    reset();

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

void HexArray::reset(){     //In this function, I made my assignments in the cell class.

    int k=0;

    for(int i=0;i<size;i++){

        for(k;k<(size*i)+size;k++){

            board[k].cellState = empty;
        } 
    } 
   
}

void HexArray::print(int winFlag){  //I set up this function to print the table with its point, x and letter o.
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

                            if(board[findIndex(i,j)].cellState == user1)  //Here I am converting the letter x as 1 and converting it to x here.
                                cout << ch1;

                                else if(board[findIndex(i,j)].cellState == user2) //Here I am converting the letter o as 2 and converting it to x here.
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

void HexArray::userGame(){   //Function to get the player input and update the board.

    int type,number,num;
    int check_x, check_o;
    string srd;
    decltype(srd)srd2;
    stringstream my_ss;
    bool saveGG = false;

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
                writeToFile(srd2);
                saveGG = true;
            }
                
                else if(srd == "LOAD"){
                    cout << "LOADED"<< endl;
                    cin >> srd2;
                    readFromFile(srd2);
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
           
           play(board[findIndex(number-1,num)]);   //I called play function for user vs user.

                for(int i=0;i<size;i++){
                        if(board[findIndex(i,0)].cellState == user1)
                            check_x = winGame_X(i,0,1);  
                    
                }
                   for(int k=0;k<size;k++){
                        if(board[findIndex(0,k)].cellState == user2)
                        check_o =  winGame_X(0,k,2);  
                        
                    }            
       }
                
        saveGG = false;

    }while(check_x != 1 && check_o != 1);                       //If the winning condition is 1, the loop ends and the winner is written.

    if(check_o  == 1){ 
        print(2);
        isEnd(2);
        cout << "CONGRATS USER 2 WON!!!" << endl; 
    }
        else if(check_x == 1){
            print(1);
            isEnd(1);
            cout << "CONGRATS USER 1 WON!!!" << endl;       
        }
}

void HexArray::writeToFile(const string& filename){ //in this function I save the game information in txt file.

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

                if(board[findIndex(i,j)].cellState == user1){  
                    
                    file << j << " " << i << endl;
                }
            }
        }
    
        file << 'o' << endl;       

        for(auto i =0;i<size;i++){       //in this we write the location coordinate for 'o'.
            
            for(auto j = 0;j< size;j++){

                if(board[findIndex(i,j)].cellState == user2){

                    file << j << " " << i << endl;
                }
            }
        }

        file << '*' << endl;
    
    file.close();

}

void HexArray::readFromFile(const string& filename){ //I load the saved game in the terminal and I use the const reference parameter in this function.

    int gameType;
    string line;

    ifstream file;
    file.open(filename);

    for(int i =0;i<size;i++){

        for(int j=0;j<size;j++){

            board[findIndex(i,j)].cellState = empty;
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
                    board[findIndex(stoi(&line[2]),stoi(line))].cellState = user1;
                    getline(file,line);
                }
            }
                if(line == "o"){
                    getline(file,line);
                     while(line != "*"){
                        board[findIndex(stoi(&line[2]),stoi(line))].cellState = user2;
                        getline(file,line);
                    }
                }    

            cout << line << endl;
        }

            print(winFlag);

        if(selection != gameType){

            if(gameType == 1){

                userGame();
            }
        
               else if(gameType == 2){

                   userComputer();
               } 
        }
}

int HexArray::winGame_X(int x,int y,int a){  //I used recursive to find the win condition in this function.

    int direction = 0;
    int exit_for = 0;
    if(x == 0 && y == 0){
        for(int i=0; i<size; i++){
            for(int k=0; k<size; k++){
                if(board[findIndex(i,k)].cellState == a){
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
		if(y == size-1  && board[findIndex(x,y)].cellState == user1){   //Base condition
            return 1;
		}
	}
	
        else if(a == 2){                     //Base condition
            if(x == size-1  && board[findIndex(x,y)].cellState == user2){
                return 1;
            }
        }
    
	
    //Here, I scan all 6 directions, if they meet the conditions, I continue the same way and when I reach the end of the table, I meet the winning condition.
    //North
            if(x-1 >= 0 && x-1 < size && y >= 0 && y < size){
                if(board[findIndex(x,y)].cellState == a && checkRange(x,y) == 1  && board[findIndex(x-1,y)].cellState == a && checkBoard[x-1][y] == empty){
                    checkBoard[x][y] = 1;
                    direction = winGame_X(x-1,y,a);
                }
        }


                        //In these conditions, I enter the coordinates of the condition according to the directions and scan it.
        //South
             if(x+1 >= 0 && x+1 < size && y >= 0 && y < size && direction == 0){
                if(board[findIndex(x,y)].cellState == a && checkRange(x,y) == 1  && board[findIndex(x+1,y)].cellState == a && checkBoard[x+1][y] == empty){
                    checkBoard[x][y] = 1;
                    direction = winGame_X(x+1,y,a);
                } 
        }

        //East
             if(x >= 0 && x < size && y+1 >= 0 && y+1 < size && direction == 0){
                 if(board[findIndex(x,y)].cellState == a && checkRange(x,y) == 1  && board[findIndex(x,y+1)].cellState == a && checkBoard[x][y+1] == empty){
                    checkBoard[x][y] = 1;
                    direction = winGame_X(x,y+1,a);
                }
        }

        //West
                 if(x >= 0 && x < size && y-1 >= 0 && y-1 < size && direction == 0){
                    if(board[findIndex(x,y)].cellState == a && checkRange(x,y) == 1   && board[findIndex(x,y-1)].cellState == a && checkBoard[x][y-1] == empty){
                        checkBoard[x][y] = 1;
                        direction = winGame_X(x,y-1,a);
                    }
        }

        //South West
            if(x+1 >= 0 && x+1 < size && y-1 >= 0 && y-1 < size && direction == 0){
                        if(board[findIndex(x,y)].cellState == a && checkRange(x,y) == 1   && board[findIndex(x+1,y-1)].cellState == a && checkBoard[x+1][y-1] == empty){
                            checkBoard[x][y] = 1;
                            direction = winGame_X(x+1,y-1,a);
                        }
        }

        //North East
            if(x-1 >= 0 && x-1 < size && y+1 >= 0 && y+1 < size && direction == 0){
                    if(board[findIndex(x,y)].cellState == a && checkRange(x,y) == 1   && board[findIndex(x-1,y+1)].cellState == a && checkBoard[x-1][y+1] == empty){
                        checkBoard[x][y] = 1;
                        direction = winGame_X(x-1,y+1,a);
                    }
        }

		return direction;
}


void HexArray::userComputer(){   //in this function Computer and user enter input to the board.
    int number,num;
    int check_x, check_o,i,j;
    string srd,srd2;
    stringstream my_ss;
    bool saveGG = false;

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
                writeToFile(srd2);
                saveGG = true;
            }
                
                else if(srd == "LOAD"){    //If you write LOAD file.txt etc. all game loaded.
                    cout << "LOADED" << endl;
                    cin >> srd2;
                    readFromFile(srd2);
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

                            if(turn == 1 && board[findIndex(number-1,num)].cellState != user1 && board[findIndex(number-1,num)].cellState != user2){
                                    
                                    board[findIndex(number-1,num)].cellState = user1;
                                    print(winFlag);
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
                                        if(board[findIndex(i,0)].cellState == user1)
                                            check_x = winGame_X(i,0,1);
                                    }

                                    for(int k=0;k<size;k++){
                                        if(board[findIndex(0,k)].cellState == user2)
                                        check_o = winGame_X(0,k,2);
                                    }

                        }
                                saveGG = false;

    }while(check_x != 1 && check_o != 1);
    
    if(check_o == 1){ 
        print(2);
        isEnd(2);
        cout << "CONGRATS USER 2 WON!!!" << endl; 
    }
        else if(check_x == 1){
            print(1);
            isEnd(1);
            cout << "CONGRATS USER 1 WON!!!" << endl;       
        }
}

void HexArray::createBoard(){  //I use the calloc for 1D array.

    board = (Cell*)calloc(size*size,sizeof(Cell));
    int k=0;

    for(int i=0;i<size;i++){

        for(k;k<(size*i)+size;k++){

            board[k].column = k;
            board[k].row = i;
            board[k].cellState = empty;
        } 
    } 
        free(board);
}

int HexArray::findIndex(int row,int column)const{  //I create this function for record index.

    return (row*size)+column;

}

int HexArray::operator()( int x, int y)const{

    return board[findIndex(x,y)].cellState;
}


