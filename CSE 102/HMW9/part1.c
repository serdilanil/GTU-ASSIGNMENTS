#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


struct card{  //I created a structure for part3 here.

	  char *face;   // there is 13 faces.
	  char suit[9];  // there is 4 suits.
}; 

typedef struct card Game;  //I used typedef for the game here

//function prototypes

int numPathsHome(int street, int avenue); //In this function, I calculated how many different ways gamer can go to reach the point he wants.

void Deck_int(Game deck[]);    //In this function  I'm throwing suits and face array of deck here.
void shuff_deck(Game deck[]);   //In this function here I shuffle the cards in the deck array.
void execute(const Game deck[]);  //In this function, I print the cards on the screen in a regular way.


char *faces[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven","Eight", "Nine", "Ten", "Jack", "Queen", "King"}; //I'm assigning faces here.

char *suit[4] ={"Clubs", "Diamonds", "Hearts", "Spades"}; //I am assigning suits here.

void menu();   //here I created a menu function for the parts.

int main(){
		
	menu();  // I call the menu function.

	return 0;
}

int numPathsHome(int street, int avenue){

	if(street <= 1 || avenue <= 1)  // base case
		return 1;

		 if(street == 2)		//base case
			return avenue;

			if(avenue == 2)		// base case
				return street;


				else{
					return (numPathsHome(street -1,avenue)) + (numPathsHome(street,avenue-1)); //here I use the 1 to 1 technique, I take out 1 from both the street and the street.
				}

}



void Deck_int(Game deck[]){  // I am assigning to array here.

	int i = 0;
  for(i=0;i<52;i++){   // there is 52 card total.
    deck[i].face = faces[i%13];
    strncpy(deck[i].suit, suit[i/13], 9);  
  }
}


void shuff_deck(Game deck[]){  //here I will shuffle the cards randomly.

	int swap=0;
	int x;
	Game temp ={"", ""};
	srand(time(NULL));     
	 for(x=0;x<52;x++){
    swap = rand() % 52;  // I shuffle randomly the 52 cards.
    temp = deck[x];      
    deck[x] = deck[swap];
    deck[swap] = temp;
  }
}


void execute(const Game deck[]){   //I'm pressing the cards on the screen here
  int x = 0;
  for(x=0;x<52;x++){
    printf("%5s of %-12s",deck[x].face, deck[x].suit); //here, I point out that I use the suit and the face in the structure.

    if(0 == ((x+1) % 2)){  //here I used this to properly print the cards on the screen.
    	printf("\n");
    }
  }
}

 
void menu(){   //menu function for the different parts.

	int street,avenue;
	int selection;
	int flag = 1;
	
 
	Game deck[52] = {"",""};  // for the card game part.(there is 52 card).
	
	while(flag == 1){   //I used the flag in while to allow the program to continue until the user logged out.
	
		printf("\n--------------WELCOME TO HMW9-------------\n");
		
		printf("\n1-Execute part1----(STAY HOME PROBLEM)------\n");
		printf("2-Execute part3------(CARD GAME)--------\n");
		printf("3-Exit\n");
		printf("please enter the number you want to run.\n");
		scanf("%d",&selection);


			switch(selection){

				case 1:
				printf("Enter the street number:\n");
				printf("street:");
				scanf("%d",&street);
				printf("Enter the avenue number:\n");
				printf("avenue:");
				scanf("%d",&avenue);
				printf("Number of optimal paths to take back home : %d\n\n",numPathsHome(street,avenue));  // I call the function
				break;


				case 2:     //I call the void function.
				Deck_int(deck);
				shuff_deck(deck);
				execute(deck);
				break;


				case 3:  //Exit.
				exit(0);
				break;

				default:
				printf("please enter the from 1 to 3:\n");
				break;

			}
	}

}