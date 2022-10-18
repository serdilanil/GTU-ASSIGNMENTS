#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//function prototypes
void menu();    //menu functıon
void genre_unique(char arr[20][20]); //In this function, I print the species varieties only once.
void platform_unique(char arr2[20][20]);  //In this function, I print the platform types only once.
void Games_Years(char arr4[2000][100],float array[2000][7]);  //In this function, I print the release dates of the games.
void Game_features(char arr4[2000][100],char arr[20][20],char arr2[20][20],float array[2000][7]); //In this function, I print all the features of the games.
void User_score(float array[2000][7]);  //In this function, I average the user scores of all games.
void Na_Eu(char arr4[2000][100],float array[2000][7]);  //In this function, it is written in which geography the game is played more.
void frequency_genre(char arr[20][20],float array[2000][7]); //this function writes the number of species varieties.
void frequency_platform(char arr2[20][20],float array[2000][7]); //In this function, the number of platform types is written.

int main(){

menu();

}

void menu(){
	
	float array[2000][7];  //I created a float array to store the information of the games.
	char arr[20][20],arr4[2000][100],arr2[20][20],*name;  //here I put the names on the arr4 array, put the types on the arr array, and the platforms on the arr2 array.
	float year,nasales,eusales,global,score;  //here I described the information about the game.
	int flag = 1,a=0,b=0,i=0,i_x,j_y,y,flag2=0,a_x,b_y,flag3=0,m,k;
	char *ptr,strx[200],not_available;

    FILE *fp;
            
        fp = fopen("Video_Games.txt","r");  //I open the file at once and fill the information into the required arrays.
            

             if(fp ==NULL){

                printf("error\n");
            }


                else if(fp != NULL){
                        
                    while(!feof(fp)){ 
                            
                            flag2=0;
                            flag3=0;
                            fgets(strx,200,fp); //here I get the line information from the file.			

                        	name= strtok(strx,",");  //here I take the names and strike them with strtok function.
                      
                      if(i != 0){
                       	
                       	strcpy(arr4[i-1],name);  //Thanks to the strcpy function, I put the names behind.
                       	
                       }	

                       		i++;
                        
                        char *genre = strtok(NULL,",");  //here I can get the comma separated information one by one thanks to the strtok function.
                        char *platform = strtok(NULL,",");
                        char *year_of_release = strtok(NULL,",");
						char *na_sales = strtok(NULL,",");
						char *eu_sales = strtok(NULL,",");
						char *global_sales = strtok(NULL,",");
						char *user_score = strtok(NULL,",");	

						for(i_x=0;i_x<20;i_x++){    
					
						if(strcmp(genre,arr[i_x])==0){  //here I used the strcmp function to write the genre variants to the array only once.
							flag2=1;
						}

					}
						
						if(flag2 == 0){		

							for(i_x=0;i_x<strlen(genre);i_x++){
								if(i==strlen(genre)-1){
									arr[j_y][i_x+1] ='\0';
								}

								arr[j_y][i_x] = genre[i_x];  //I put the species varieties into the series only once.
							}
							j_y++;							
						}							
					


						for(m=0;m<20;m++){   //here, I put the platform types into the series only once.
						
							if(strcmp(platform,arr2[m])==0){
								flag3=1;
							}

						}
							
							if(flag3 == 0){		

								for(m=0;m<strlen(platform);m++){
									if(m==strlen(platform)-1){
										arr2[k][m+1] ='\0';
									}

									arr2[k][m] = platform[m];
								}
								k++;							
							}							
							
						 year= strtod(year_of_release,&ptr);  //Here I used the strtod function to pull float values that look like strings.
                         nasales=strtod(na_sales,&ptr);
                         eusales=strtod(eu_sales,&ptr);
                         

                         if(strcmp(global_sales,"not_available") == 0){  //if it says not available it will print -1.
                         	global = -1;
                         }
                         else{
                         	global=strtod(global_sales,&ptr);
                         }  
                         score=strtod(user_score,&ptr);
	                    	array[a][2] = year;          //here after the strtod process is finished, I transfer this information to float sequence.
	                    	array[a][3] = nasales;
	                    	array[a][4] = eusales;
	                    	array[a][5] = global;                    	 
		                    array[a][6] = score;

	                    
	                    if(strcmp(genre,arr[1])==0)   //here I encode the type information as a float value.
	                    	array[a][0] = 1.0;
	                    if(strcmp(genre,arr[2])==0)
	                    	array[a][0] = 2.0;
	                    if(strcmp(genre,arr[3])==0)
	                    	array[a][0] = 3.0;
	                    if(strcmp(genre,arr[4])==0)
	                    	array[a][0] = 4.0;
	                    if(strcmp(genre,arr[5])==0)
	                    	array[a][0] = 5.0;
	                    if(strcmp(genre,arr[6])==0)
	                    	array[a][0] = 6.0;
	                    if(strcmp(genre,arr[7])==0)
	                    	array[a][0] = 7.0;
	                    if(strcmp(genre,arr[8])==0)
	                    	array[a][0] = 8.0;
	                    if(strcmp(genre,arr[9])==0)
	                    	array[a][0] = 9.0;
	                    if(strcmp(genre,arr[10])==0)
	                    	array[a][0] = 10.0;
	                    if(strcmp(genre,arr[11])==0)
	                    	array[a][0] = 11.0;
	                    if(strcmp(genre,arr[12])==0)
	                    	array[a][0] = 12.0; 

	                  

	                    
	                    if(strcmp(platform,arr2[1])==0)  //here I am coding the platform information as float value.
	                    	array[a][1] = 1.0;
	                    if(strcmp(platform,arr2[2])==0)
	                    	array[a][1] = 2.0;
	                    if(strcmp(platform,arr2[3])==0)
	                    	array[a][1] = 3.0;
	                    if(strcmp(platform,arr2[4])==0)
	                    	array[a][1] = 4.0;
	                    if(strcmp(platform,arr2[5])==0)
	                    	array[a][1] = 5.0;
	                    if(strcmp(platform,arr2[6])==0)
	                    	array[a][1] = 6.0;
	                    if(strcmp(platform,arr2[7])==0)
	                    	array[a][1] = 7.0;
	                    if(strcmp(platform,arr2[8])==0)
	                    	array[a][1] = 8.0;
	                    if(strcmp(platform,arr2[9])==0)
	                    	array[a][1] = 9.0;
	                    if(strcmp(platform,arr2[10])==0)
	                    	array[a][1] = 10.0; 
	                    
                    	a++;
                    }     
                        
                }



	while(flag != 0){  //I'm looping the menu here.

		printf("\n\n0:List of the Genres\n");
		printf("1:List of the Platforms\n");
		printf("2:List of the Games Through the Years\n");
		printf("3:All Informations of a Single Game\n");
		printf("4:Average of the User Scores\n");
		printf("5:Georographical Information of a Single Game\n");
		printf("6:Frequence of the Genres\n");
		printf("7:Frequence of the Platforms\n");
		printf("8:Exit\n\n");

		printf("Please select an operation:");


	int selection;    				//here I call the functions in the switch-case structure.
		
		scanf("%d",&selection);

		switch(selection){

			case 0:
		for(j_y=0;j_y<12;j_y++){        // I print the unique genre.
			printf("%s\n",arr[j_y]);
		}			
			break;
			
			case 1:
		for(k=0;k<10;k++){            // I print the unique platform.
			printf("%s\n",arr2[k]);
		}
			break;

			case 2:					// I print the years of games.
			Games_Years(arr4,array);
			break;

			case 3:						//here I am suppressing the features of the games.
			Game_features(arr4,arr,arr2,array);
			break;

			case 4:					//here I suppress the average of user scores.
			User_score(array);
			break;

			case 5:					//it says in which geography the play is played more.
			Na_Eu(arr4,array);
			break;

			case 6:					//here I am suppressing the number of species varieties.
			frequency_genre(arr,array);
			break;

			case 7:					//here I am suppressing the number of platform types.
			frequency_platform(arr2,array);
			break;

			case 8:  //exit
			exit(0);
			break;

			default:
			printf("\n\nTRY AGAIN.\n\n");
			menu();
			break;
		}

	}


}

void Games_Years(char arr4[2000][100],float array[2000][7]){   //here I use the name string and float string as parameters.

	int g_year,number,i,j,sum=0,sum2=0,flag=1,flag2=1;
	char str[100];
		
	while(flag==1){							//here I used the loop to ask the same question again if the user entered the wrong date.
		printf("Enter a year:\n");
		scanf("%d",&g_year);

		printf("Until (0) or Since(1) %d:",g_year);
		scanf("%d",&number);

		if(number == 0){						//If it is up to that date, it will enter state 0.
			for(i=0;i<2000;i++){
				sum = i;
				if(g_year > array[sum+1][2]){
					printf("%s\n",arr4[sum]);
					flag =0;
				}					

					else if(flag ==1){
						printf("TRY AGAIN.\n");
						break;
					}


			}
		}

					if(number == 1){     		//If it is desired after that date, it will enter the status 1.
						for(j=0;j<2000;j++){
								sum2 = j;
								if(g_year<array[sum2+1][2]){
									printf("%s\n",arr4[sum2]);
									flag =0;
								}		
						}
					}

	}

}



void Game_features(char arr4[2000][100],char arr[20][20],char arr2[20][20],float array[2000][7]){  //In this function, all the features of the game whose name is entered are suppressed.
	
	int i,sum=0,flag=0,x,y;
	char str[100];
	printf("Please enter the name of the game:\n");
	scanf("%s",str);
	
	for(i=0;i<2000;i++){
		if(strcmp(arr4[i],str)==0){
			sum =i;
			flag=1;
			break;
		}	
	}

		x = array[sum+1][0];
		y = array[sum+1][1];

		if(flag==1){
			printf("Name:%s\n",arr4[sum]);
			printf("Genre:%s\n",arr[x]);
			printf("Platform:%s\n",arr2[y]);
			printf("Year:%.0f\n",array[sum+1][2]);
			printf("Sales In NA: %f\n",array[sum+1][3]);
			printf("Sales In EU:%f\n",array[sum+1][4]);
			printf("Total Sales:%f\n",array[sum+1][5]);
			printf("User Score:	%f\n",array[sum+1][6]);
		}

}

void User_score(float array[2000][7]){  //averaging all player scores here.
	int a,counter=0,i;
	float sum=0.0;
	for(i=1;i<=2000;i++){
		sum += array[i][6];

		counter++;
	}

	printf("Average is %f",sum/counter);

}

void Na_Eu(char arr4[2000][100],float array[2000][7]){  //where the game is popular in which geography it writes.
	int i,flag=0,sum=0;
	char str[100];
	printf("Please enter the name of the game:\n");
	scanf("%s",str);

	for(i=0;i<2000;i++){
		if(strcmp(arr4[i],str)==0){
			sum =i;
			flag=1;
			break;
		}
	}

			if(flag == 1){
				if(array[sum+1][3]>array[sum+1][4])  //I am comparing the information through the sequences I have recorded here.
					printf("This game was more popular in North America.\n");

					else if(array[sum+1][3]<array[sum+1][4])
						printf("This game was more popular in Europe.\n");	
			
						else{
							printf("this game is equally popular in both regions.");
						}
			}
}

void frequency_genre(char arr[20][20],float array[2000][7]){   //here I print the number of species varieties.

int i,simulation=0,shooter=0,fighting=0,action=0,role_playing=0,racing=0,misc=0,puzzle=0,platform=0,strategy=0,sports=0,adventure=0,genrex=0,sum =0,x,y;
						

					for(i=0;i<2000;i++){    //here I loop through the types of species and calculate how many are available, thanks to the strcmp function and float array.
						x = array[i+1][0];
						if(strcmp(arr[x],arr[1])==0){
		      					sum = i;
		                    	simulation++;
	                	}
	                    if(strcmp(arr[x],arr[2])==0){
	                    		sum = i;
	                    		shooter++;
	                    }
	                    if(strcmp(arr[x],arr[3])==0){
	                    		sum = i;
	                    		fighting++;
	                    }
	                     if(strcmp(arr[x],arr[4])==0){                 	
	                    		sum = i;
	                    		action++;       	
	                    }
	                    if(strcmp(arr[x],arr[5])==0){
	                    		sum = i;
	                    		role_playing++;
	                    }
	                    if(strcmp(arr[x],arr[6])==0){
	                    		sum = i;
	                    		racing++;
	                    }
	                    if(strcmp(arr[x],arr[7])==0){
	                    		sum = i;
	                    		misc++;
	                    }
	                    if(strcmp(arr[x],arr[8])==0){
	                    		sum = i;
	                    		puzzle++;
	                    }
	                    if(strcmp(arr[x],arr[9])==0){
	                    		sum = i;
	                    		platform ++;
	                    }
	                    if(strcmp(arr[x],arr[10])==0){
	                    		sum = i;
	                    		strategy++;
	                    }
	                    if(strcmp(arr[x],arr[11])==0){
	                    		sum = i;
	                    		sports++;
	                    }
	                    if(strcmp(arr[x],arr[12])==0){
	                    		sum = i;
	                   			adventure++;
	                    }
	                   
	                }
	                printf("simulation:%d\n",simulation);	                
	                printf("shooter:%d\n",shooter);
	                printf("fighting:%d\n",fighting);
	                printf("action:%d\n",action);
	                printf("role_playing:%d\n",role_playing);
	                printf("racing:%d\n",racing);
	                printf("misc:%d\n",misc);
	               	printf("puzzle:%d\n",puzzle);
	       	        printf("platform:%d\n",platform);
	       	       	printf("strategy:%d\n",strategy);
	          	    printf("sports:%d\n",sports);
	          	    printf("adventure:%d\n",adventure);


}

void frequency_platform(char arr2[20][20],float array[2000][7]){   //here I print the number of platform variants.

int pc=0,ps=0,dc=0,ps2=0,x=0,gba=0,gc=0,ds=0,psp=0,x360=0,i,n,y,sum=0;   //here I loop through the types of platform and calculate how many are available, thanks to the strcmp function and float array.

			for(i=0;i<2000;i++){
						n = array[i+1][1];
						if(strcmp(arr2[n],arr2[1])==0){
		      					sum = i;
		                    	pc++;
	                	}
	                    if(strcmp(arr2[n],arr2[2])==0){
	                    		sum = i;
	                    		ps++;
	                    }
	                    if(strcmp(arr2[n],arr2[3])==0){
	                    		sum = i;
	                    		dc++;
	                    }
	                     if(strcmp(arr2[n],arr2[4])==0){                 	
	                    		sum = i;
	                    		ps2++;       	
	                    }
	                    if(strcmp(arr2[n],arr2[5])==0){
	                    		sum = i;
	                    		x++;
	                    }
	                    if(strcmp(arr2[n],arr2[6])==0){
	                    		sum = i;
	                    		gba++;
	                    }
	                    if(strcmp(arr2[n],arr2[7])==0){
	                    		sum = i;
	                    		gc++;
	                    }
	                    if(strcmp(arr2[n],arr2[8])==0){
	                    		sum = i;
	                    		ds++;
	                    }
	                    if(strcmp(arr2[n],arr2[9])==0){
	                    		sum = i;
	                    		psp++;
	                    }
	                    if(strcmp(arr2[n],arr2[10])==0){
	                    		sum = i;
	                    		x360++;
	                    }
	                   
	                }
	                printf("pc:%d\n",pc);	                
	                printf("ps:%d\n",ps);
	                printf("dc:%d\n",dc);
	                printf("ps2:%d\n",ps2);
	                printf("x:%d\n",x);
	                printf("gba:%d\n",gba);
	                printf("gc:%d\n",gc);
	               	printf("ds:%d\n",ds);
	       	        printf("psp:%d\n",psp);
	       	       	printf("x360:%d\n",x360);

}