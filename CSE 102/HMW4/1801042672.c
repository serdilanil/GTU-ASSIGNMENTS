#include<stdio.h>
#include<math.h>
#include<stdlib.h>		
#include<time.h>	

//function prototypes
void decrypt_and_print (char* file_path);  //In this function, we use the decrypt_numbers function to convert the numbers to the beginning of the line.
char decrypt_numbers (int number);	// In this function, we convert the numbers to characters.

void deep_decrypt_and_print (char* file_path);
char decrypt_numbers (int number);

void track_machine ();
void refresh_position (int *X, int *Y, double *D, double *R);

void encrypt_messages (char* file_path);
int decrypt_chars(char character);

void menu();

int main(){
	
	 menu();
	
}

void decrypt_and_print(char* file_path){
	
	char ch;
	FILE *fpointer;
	fpointer = fopen(file_path,"r"); //I open and read the file.


	do{
		
		fscanf(fpointer,"%c",&ch);
		if(ch!='\n')
			printf("%c",decrypt_numbers(ch - '0')); // here I substract zero from ch because I should convert integer.

			else
				printf("\n");		
		
		}while(!feof(fpointer)); //here I proceed until the file is over.
		
		fclose(fpointer);

}


char decrypt_numbers (int number){ //In this function, I turn the numbers into characters by switch-case.
	char answer;
	switch(number){
		case 0:
			answer= ' ';
		break;
		
		case 1:
			answer ='-';
		break;
		
		case 2:
			answer = '_';
		break;
		
		case 3:
			answer= '|';
		break;
		
		case 4:
			answer = '/';
		break;
		
		case 5:
			answer = '\\';
		break;
		
		case 6:
			answer = 'o';
		break;
				
	}
	return answer;
	
}

void deep_decrypt_and_print (char* file_path){ //In this function, this time we will decrypt the enemy using the formula.

	FILE *fp;
	fp = fopen(file_path,"r");
	char ch1,ch2,ch3;
	int n1,i, ans;

	fscanf(fp,"%c",&ch3);  //first,I reading last number data from file.


	while(!feof(fp)){ 	// here I am doing the process until the file is closed.
		ch1=ch2;
		ch2=ch3;	//here I proceed by assigning the value of the number to the previous number.

		fscanf(fp, "%c", &ch3);

		if(ch3!='\n'){  //where if the number is not the end of the line, it performs the operation.
			
			ans = (int)ch1 + (int)ch2 + (int)ch3 -(3*48);  //I apply the formula given here.
			ans%=7;
			printf("%c", decrypt_numbers(ans));
		}

		else{
			ans = (int)ch1 + (int)ch2 - (2*48);  
			ans%=7;
			printf("%c", decrypt_numbers(ans));
			fscanf(fp,"%c",&ch2);
			ans = (int)ch1-48;
			ans%=7;

			printf("%c", decrypt_numbers(ans));
			printf("\n");         //here, after pressing the 1st and 2nd numbers on the screen, we move to the next line and print the 3rd number.
			fscanf(fp,"%c",&ch3);
		}
	}

		fclose(fp);

}


void track_machine (){			//In this function, I created the 11 * 11 map and determined our location with that center.
	int i,j,X=0,Y=0,Ox=5,Oy=5;
	double D,R=0;				//I gave R zero value because at first the enemy's displacement is zero.
	char a;
	a = 'R';
	D = sqrt( pow(Ox-X,2) + pow(Oy-Y,2) );  //here I find the first distance of the enemy to our center.
	
	while(a=='R'){
		
		for(i=0;i<11;i++){  //I create the map in this section.
			
			for(j=0;j<11;j++){
				
				if(i*j==25 && i==j){
						printf("o\t");
				}
					
					else if(i==X && j==Y){
							printf("E\t");		
					}
						
						else{				
							printf(".\t");
						}
			
			}
					
					printf("\n");
	}	
	

	
	printf("Enemies X position: %d, Y position: %d, Displacement: %.2lf, Distance to our camp: %.2lf\n",X+1,Y+1,R,D);

	printf("Command waiting....:\n");
	scanf(" %c",&a);

	
		if(a == 'R'){
			refresh_position(&X,&Y,&D,&R);		
		}

		else if(a == 'E'){
			return ;
		}
	
		else{
			printf("Please try again\n");
		}
	}	
}

void refresh_position (int *X, int *Y, double *D, double *R){
	
	int Ex,Ey;		//where Ex and Ey show their location in the X and Y coordinates of the enemy.
	Ex = rand()%11;
	Ey = rand()%11;  //here I used the rand () function to get different values all the time.

	*R = sqrt(pow(*X-Ex,2)+pow(*Y-Ey,2)); //displacement
	*D = sqrt(pow(Ex-5,2)+pow(Ey-5,2)); 	//distance

	srand(time(NULL));

	*X = Ex; //here we discard the enemy's X and Y values.
	*Y = Ey;

}

void encrypt_messages (char* file_path){  //In this function, we print what we read from one file to another file.

	FILE *fp;
	fp = fopen(file_path,"r"); 
	FILE *fpointer;
	fpointer = fopen("encrypted_p4.img","w");
	int ans=0,n1=0,n2=0,k;  //I get the first two numbers as 0.
	char n3;




	while(!feof(fp)){
		fscanf(fp, "%c", &n3);

		if(n3!='\n'){  //I apply the formula until the last number does not reach the end of the line.
			
			k=decrypt_chars(n3);
			ans = n1 + n2 + k;
			ans%=7;
			fprintf(fpointer,"%d",ans);

		}

		else{  //otherwise I am going to the bottom line.
			
			k=0;
			fprintf(fpointer,"\n");
		}
			n1=n2;
			n2=k;
			ans=0;
	}

		fclose(fpointer);

}


int decrypt_chars (char character){  //Here I created a new function that converts the character to number.
	
	int answer;
	
	switch(character){
		case ' ':
			answer = 0;
		break;
		
		case '-':
			answer = 1;
		break;
		
		case '_':
			answer = 2;
		break;
		
		case '|':
			answer = 3;
		break;
		
		case '/':
			answer = 4;
		break;
		
		case '\\':
			answer = 5;
		break;
		
		case 'o':
			answer = 6;
		break;
				
	}
	return answer;
	
}

void menu(){  //Finally, I created the menu function.
	
	char *fpath1 = "encrypted_p1.img",*fpath2 = "encrypted_p2.img";
	int operation;
	
		while(operation != 5){		
		

		printf("\n1-) Decrypt and print encrypted_p1.img\n");
		printf("2-) Decrypt and print encrypted_p2.img\n");
		printf("3-) Switch on the tracking machine\n");
		printf("4-) Encrypt the message\n");
		printf("5-) Switch off\n");

		printf("\nPlease make your choice:\n");

		scanf("%d",&operation);
			
			switch(operation){  //I call functions within the switch-case structure for each section.

				case 1:
					decrypt_and_print(fpath1);  
					break;
					
				case 2:
					 
					deep_decrypt_and_print(fpath2);
					break;
					

				case 3:
					track_machine();
					break;

				case 4:
					encrypt_messages ("decrypted_p4.img");
					break;
					

				case 5:
					break;
					
				
		}
		
			}
}

