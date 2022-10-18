#include<stdio.h>
#include<stdlib.h>
//function prototypes
void read_news(char buffer[500],char file_path[11],int is_Only_Title);  //In this function, I throw the texts in the file and print them in the terminal,I also print the title or all of the text through the only title function.
void append_file( char* file_path , char c);  //In this function, I save the number of the read files to another file.
int print_file(char * file_path,char ch);     //In this function, I print the readed files to the terminal only once.
int only_readed(char * file,char ch);		// In this function,I printf the readed files to the file only once.
void read_magic_numbers(char buffer_magic[11],char buffer_news[500]); //Here we reveal the hidden number with a special formula put in the is file.
double f_func(int x);	//where we wrote the formula of the function f_func and applied it in another magic number function.
double g_func(double f(int x),int a); //Here I found the magic numbers by adding the function f_func to the g_func function.
void Yes_No(char flag2);  //It asks the question Do you want to continue here? If he wants to continue, the program closes if he does not accept going to the menu.
void menu();	//In the menu function, I created the options a, b, c and called the functions in them.

int main(){
	
	menu();  //There will be only menu function in the main part.
}

void read_news(char buffer[500],char file_path[11],int is_Only_Title){
	
		FILE *fp;
				
		fp = fopen(file_path,"r");
	
	if(is_Only_Title == 0){		//if only title is zero, it prints all of the news text.
				
			if(fp != NULL){
				
				while(!feof(fp)){ //fp going to the end of the file.
						
						fgets(buffer,500,fp); //here I print the text into the array.
							
						printf("%s\n",buffer); //then I press the text on the terminal.
				}
				
						fclose(fp);
					
			}
	}

		else if(is_Only_Title == 1){  //If only title is 1, I just print the title of the news.
			
			fscanf(fp,"%[^\n]s",buffer); //I just used this method to use the first line.
			printf("%s\n",buffer);
		}

}

void append_file( char* file_path , char c){ //In this function, as I mentioned before, I print the number of news read.
	
		FILE *fpointer;
		fpointer = fopen(file_path,"a+"); //here I open the file to add characters to the file.
		rewind(fpointer);

		fprintf(fpointer,"%c\n",c);  // //here I add characters to the file.

		fclose(fpointer);
}

int print_file(char* file_path,char ch){ //here I press only once written characters to the terminal.
	
	int x;
	
	FILE *fptr;

	fptr = fopen(file_path,"r");   //here I open the file for reading.
	 
		while(x = fscanf(fptr,"%c",&ch) != EOF){ //here the characters in the file are printed until they are finished.

			if(x == 1 && ch != '\n')
				printf("%c. new is readed.\n",ch); //here we also press the terminal.
			
		}	
}

int only_readed(char* file_path,char ch){  //if the news text has already been read here, the character will not print the text again.

	int flag3=0;
	char ch2;
	FILE *fptr;

	fptr = fopen(file_path,"r");	 
			
		while(fscanf(fptr,"%c",&ch2) != EOF){

			if(ch2==ch){	//If the character read here is 1, the flag will be 1,And if it is 1, you have read this news in the menu. Would you like to read it again? he is writing.

				flag3=1;
			}
			
		}	

		return flag3;

}

double f_func(int x){

	return x*x*x-x*x+2;  //here I return the formula.
}

double g_func(double f(int x),int a){

	return f(a)*f(a);   //here I return the formula.
}

void read_magic_numbers(char buffer_magic[11],char buffer_news[500]){  ////Here we reveal the hidden number with a special formula put in the is file.

	int number,i;
	double x,y,sum=0;
	char ch;

	FILE *fptr;
	fptr = fopen(buffer_magic,"r"); //I open the file for reading.

	while(!feof(fptr)){		//I'm going to the end of the file.
		fscanf(fptr,"%c",&ch);
		printf("%c",ch);
		if(ch == '#'){  //Here the pointer progresses until the # sign ends, and it progresses by pressing the integers until it ends.
			fscanf(fptr,"%d",&number);
			printf("%d",number);
			y = g_func(f_func,number); //here, I apply the number formula in the file and subtract the secret number.
			sum = sum+y;
		}
		
	}
		printf("\n\n%.2lf",sum);  //secret number.
		fclose(fptr);
	
	if(buffer_magic[5]=='1'){ //In the 5th index, I write the file number, which file.
		i=1;
	}
	else if(buffer_magic[5]=='2'){
		i=2;
	}
	else if(buffer_magic[5] == '3'){
		i=3;
	}
	else if(buffer_magic[5] == '4'){
		i=4;
	}
}

void Yes_NO(char flag2){ //I wrote this function to ask if the user wants to continue.

		printf("\nDo you want to continue? Yes(y)/No(n):\n");
				
				scanf(" %c",&flag2);
				
				if(flag2 == 'y')	 //If the answer is 'y', I call the menu function.								
				{
					menu();
				}

			else if(flag2 == 'n') //if the answer is 'n', the program closes.
			{
														
			printf("Good Bye!\n");
			exit(0);												
			}	
}


void menu(){
	char file_path1[11] = "news/1.txt",file_path2[11] = "news/2.txt",file_path3[11] = "news/3.txt",file_path4[11] = "news/4.txt",buffer[500],buffer_j[500];  //here I defined the sequences and assigned the texts to the file path markers.
	char buffer_magic[11]="news/1.txt",buffer_magic2[11]="news/2.txt",buffer_magic3[11]="news/3.txt",buffer_magic4[11]="news/4.txt";
	char selection,flag2= 'y';
	int choose,flag =1,result;	
	int is_only_title;
			
		printf("\n\n*** Daily Press ***\n");
		printf("Today's news are listed for you :\n\n");  //here I just print the headlines of the text,because if only title was 1, it would only print the title.

		printf("Title of 1. news:");
		
		read_news(buffer,"news/1.txt",1);
		
		printf("Title of 2. news:");
		
		read_news(buffer,"news/2.txt",1);
		
		printf("Title of 3. news:");
		
		read_news(buffer,"news/3.txt",1);
		
		printf("Title of 4. news:");
		
		read_news(buffer,"news/4.txt",1);
 

 		
			printf("\nWhat do you want to do?\n"); //we created options according to the user's request.
			printf("a.Read a new\n");
			printf("b.List the readed news\n");
			printf("c.Get decrypted information from the news\n");
		
	while(flag == 1 && flag2 == 'y'){	//As long as the flag is equal to 1 or flag2 is the letter y, the cycle will continue.

		scanf("%c",&selection);  //From here, a, b, c states begin.
			
			if(selection == 'a'){

				printf("Which news do you want to read? \n");
				scanf("%d",&choose);
					
				switch(choose){

					case 1:	
						
							if(only_readed("readed_news_id.txt",'1') == 1){  //If the file has already been read, would you like to read it again? article appears
									printf("\nThis new is readed.Do you want to read again? Yes(1)/No(0):\n");
									scanf(" %d",&flag);
									
									if(flag == 1){  //Since the flag is 1 and only title is 0, all of the text is printed.
										printf("Entire new:(0) Only title:(1)");
										scanf("%d",&is_only_title);
										read_news(buffer,"news/1.txt",is_only_title);

										 Yes_NO(flag2);
									}
									
									
									else if(flag == 0)		//If the flag returns 0, it goes to the menu.
										Yes_NO(flag2);

							}

							else{  //if not read the text is printed.
										printf("Entire new:(0) Only title:(1)");
										scanf("%d",&is_only_title);								
								read_news(buffer,"news/1.txt",is_only_title);
								
								if(only_readed("readed_news_id.txt",'1') == 0){
									append_file("readed_news_id.txt",'1');
								}
							
									Yes_NO(flag2);
							}
											
					break;

					case 2:
							
							if(only_readed("readed_news_id.txt",'2') == 1){ //If the file has already been read, would you like to read it again? article appears
								
									printf("\nThis new is readed.Do you want to read again? Yes(1)/No(0):\n");
									scanf(" %d",&flag);
									
									if(flag == 1){		//Since the flag is 1 and only title is 0, all of the text is printed.
										
										printf("Entire new:(0) Only title:(1)");
										scanf("%d",&is_only_title);
										read_news(buffer,"news/2.txt",is_only_title);
										
										 Yes_NO(flag2);
									}
							
										else if(flag==0)	//If the flag returns 0, it goes to the menu.
											Yes_NO(flag2);
							}

							else{  	//if not read the text is printed.
										printf("Entire new:(0) Only title:(1)");
										scanf("%d",&is_only_title);								
								read_news(buffer,"news/2.txt",is_only_title);
								
								if(only_readed("readed_news_id.txt",'2') == 0){
									append_file("readed_news_id.txt",'2');
								}
							
									 Yes_NO(flag2);

							}												
						
					break;
					
					case 3:
								
							if(only_readed("readed_news_id.txt",'3') == 1){   //If the file has already been read, would you like to read it again? article appears
								
									printf("\nThis new is readed.Do you want to read again? Yes(1)/No(0):\n");		
									scanf(" %d",&flag);
									
									if(flag == 1){		//Since the flag is 1 and only title is 0, all of the text is printed.
										
										printf("Entire new:(0) Only title:(1)");
										scanf("%d",&is_only_title);
										read_news(buffer,"news/3.txt",is_only_title);
										
										 Yes_NO(flag2);

									}
									
									else if(flag == 0)  //If the flag returns 0, it goes to the menu.
										Yes_NO(flag2) ;

							}

							else{		//if not read the text is printed.
								
									printf("Entire new:(0) Only title:(1)");
									scanf("%d",&is_only_title);	
								read_news(buffer,"news/3.txt",is_only_title);
								
								if(only_readed("readed_news_id.txt",'3') == 0){
									append_file("readed_news_id.txt",'3');
								}
							
								 Yes_NO(flag2);
							}

					break;

					case 4:
							
							if(only_readed("readed_news_id.txt",'4') == 1){   //If the file has already been read, would you like to read it again? article appears
								
									printf("\nThis new is readed.Do you want to read again? Yes(1)/No(0):\n");		
									scanf(" %d",&flag);
									
									if(flag == 1){			//Since the flag is 1 and only title is 0, all of the text is printed.
										
										printf("Entire new:(0) Only title:(1)");
										scanf("%d",&is_only_title);
										read_news(buffer,"news/4.txt",is_only_title);
										
										 Yes_NO(flag2);
									}
									
									else if(flag == 0)  //If the flag returns 0, it goes to the menu.
										Yes_NO(flag2) ;

							}

							else{		//if not read the text is printed.
										printf("Entire new:(0) Only title:(1)");
										scanf("%d",&is_only_title);
								read_news(buffer,"news/4.txt",is_only_title);
								
								if(only_readed("readed_news_id.txt",'4') == 0){
										append_file("readed_news_id.txt",'4');
								
								}
							
								 Yes_NO(flag2);
							}
					break;

							default:
							printf("Please enter the from 1 to 5\n");
							exit(0);
				}

			}

			

			else if(selection == 'b'){		//In the 'b' option, we only print the printed characters for the file to the terminal once.
				
				printf("Readed news are listed below:\n");

				print_file("readed_news_id.txt",'c');  //Thanks to the printf_file function, we print the characters on the terminal.

				 Yes_NO(flag2);
			}	

			

			
			else if(selection == 'c'){  //In the 'c' option, we press the secret numbers to the terminal using the numbers written between the text.
				printf("\nWhich news would you like to decrypt?\n");
				scanf("%d",&choose);

				switch(choose){  //in these cases, each case has its own secret numbers and all represent numbers in different states.

					case 1:
					read_magic_numbers(buffer_magic,buffer_j);  //I print the secret numbers through this function.
					printf(" = the number of tests performed.\n");
					break;

					case 2:
					read_magic_numbers(buffer_magic2,buffer_j); //I print the hidden numbers through this function.
					printf(" = the number of sick people.\n");
					break;

					case 3:
					read_magic_numbers(buffer_magic3,buffer_j); //I print the hidden numbers through this function.
					printf(" = the number of deaths.\n");
					break;

					case 4:
					read_magic_numbers(buffer_magic4,buffer_j);	//I print the hidden numbers through this function.
					printf(" = the expected number of sick people.\n");
					break;

					default:
					printf("invalid value:\n");
					exit(0);

				}

				Yes_NO(flag2);
			}
	}
}
