#ifndef hexGame
#define hexGame

enum cellSitutation{empty,user1,user2};  // I use the enum for the cell states.(Empty = 0,user1 = 1,user2 = 2) Because my board is integer.

void Game();  // I started the game
void boardPrint(int size,int board[12][12],int winFlag = 0);  //I printed the 'x','o'and value of 0, AND I use the default parameter in this function.
void userGame(int board[12][12],int size,int checkBoard[12][12],int selection);  // in this function played user1 vs user 2 
int convertCoordinate(char &character);    //in this function I convert char to integer value, AND I use the Reference in this function.
int checkRange(int x,int y,int size);     // I controlled that border of board in this function. 
int winGame_X(int board[12][12],int x,int y,int size,int checkBoard[12][12],int a);   //in this function I use recursion for try to follow winning path.
void userComputer(int board[12][12],int size,int checkBoard[12][12],int selection);  // in this function played user 1 vs computer
void checkIn(int checkBoard[12][12]);     // In this function I reset checkboard.
void saveGame(int board[12][12],const std::string& filename,int size,int selection); //I save the game and I use the const reference parameter. 
void loadGame(int board[12][12],int size,const std::string& filename,int selection); //I load the saved game in the terminal and I use the const reference parameter in this function.
#endif