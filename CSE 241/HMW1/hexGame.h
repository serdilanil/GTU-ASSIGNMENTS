#ifndef hexGame
#define hexGame

void Game();  // I started the game
void boardPrint(int size,int board[12][12],int winFlag);  //I printed the 'x','o'and value of 0,
void userGame(int board[12][12],int size,int checkBoard[12][12]);  // in this function played user1 vs user 2 
int convertCoordinate(char character);    //in this function I convert char to integer value. 
int checkRange(int x,int y,int size);     // I controlled that border of board in this function.
int winGame_X(int board[12][12],int x,int y,int size,int checkBoard[12][12],int a);   //in this function I use recursion for try to follow winning path.
void userComputer(int board[12][12],int size,int checkBoard[12][12]);  // in this function played user 1 vs computer
void checkIn(int checkBoard[12][12]);     // In this function I reset checkboard.


#endif