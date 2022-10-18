#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu(); //I wrote this menu function to run 3part.
void part1();  //I wrote this function to run the first part.
void generate_hofstadters_sequence(int *arr,int n);  //In this function, I filled the array by applying the formula of the hofstadters array.
int find_max(int arr[],int index,int max_value);    //In this function, I find the largest number of numbers I fill in the array with recursive.
int sum_array(int arr[]);                        //here I find the sum of the numbers in the array I filled with the formula with recursive.
double std_array(int arr[],double *mean,int n,int index);
void shiftleft(char *str);   //here I used this function as auxiliary function for downloading duplicate letters one by one. The purpose of this function is to shift letters.
char* remove_duplicates(char* str); //I wrote this recursive function to convert duplicate letters to single letter.

int main(){

	menu();
}

void menu(){

int flag =1;
char str[500];  //I created this string string for part3.

	while(flag ==1){         //here the program will not close without the user logging out.
			printf("1-Execute Part1\n");
			printf("2-Execute Part2\n");
			printf("3-Execute Part3\n");
			printf("4-exit\n");
			printf("HOCAM PART3'E GİRDİĞİNİZ ZAMAN ARAYA MENÜNÜN GİRMESİNİ ÖNEMSEMEYİN KOD SIKINTISIZ ÇALIŞMAKTADIR.PART3'E GİRDİKTEN SONRA METNİ YAZMANIZ YETERLİDİR.\n");

		int selection;
			scanf("%d",&selection);
			switch(selection){
				
       			case 1:   //I'm calling part1 here.
       			part1();
				break;

				case 2:
				break;

				case 3:
				printf("please write the text:\n");   //I'm calling part 3 here.
				fgets(str,500,stdin);
				printf("%s\n",remove_duplicates(str+1));
				break;

				case 4:   
				exit(0);   //exit
				break;
			
				default:
				printf("please enter the 1 from 4:\n\n");
			}
	}
}

void part1(){

    int choice,n,index=500,max_value,max,flag=1,result;
    int array[500]={0};
    array[0] =1;
    array[500] =0;
    double *mean;
    while(flag==1){  //here the program will not close without the user logging out.
        
        printf("please make your choice:\n");    
        printf("1-Fill Array\n");
        printf("2-Find Biggest Number\n");
        printf("3-Calculate Sum\n");
        printf("4-Calculate Standard Deviation\n");
        printf("5-Exit\n");

        scanf("%d",&choice);
        switch(choice){

            case 1:
            generate_hofstadters_sequence(array,n);  //I call the function
            break;

            case 2:
            max_value = array[0];    
            max_value = find_max(array,index-1,max_value);
            printf("\n The largest element number in the index is:%d\n",max_value);  //In this function I call, I find the maximum number in the array by recursive I filled.
            break;

            case 3:
            printf("%d\n",sum_array(array));  //In this function I find the sum of the numbers in the series I filled.
            break;

            case 4:
            printf("%lf\n",std_array(array,mean,n,index));
            break;

            case 5:
            exit(0);  //exit
            break;

            default:
            printf("please choice the from 1 to 5 number:\n");
        }

    }
}


void generate_hofstadters_sequence(int *arr,int n){		//In this function, I fill the array with a formula.
  
    int i;
    arr[1] = arr[2] = 1;   //According to the formula 1st and 2nd index is equal to the number 1.
    arr[0] =1;
    printf("please enter the number:\n");
    scanf("%d",&n);

    for(i=3;i<=n;i++)
        arr[i] = arr[i-arr[i-1]] + arr[i-arr[i-2]];

    for(i=1;i<=n;i++)    
        printf("%d\n",arr[i]);
}

int find_max(int arr[],int index,int max_value){  //In this function, I enter the indexes one by one and find the largest number in the series.
     
    if(index>-1){  //I start from index 0.
        
        if(arr[index]>max_value){  //when scanning indexes, if the current index is greater than maximum, the maximum is now.
            
            max_value = arr[index];
        }
            return(max_value = find_max(arr,index-1,max_value));  //here I call the function over and over again with recursion.
    }
    
    else{
        
        return max_value;
    }
}

int sum_array(int arr[]){   // //here I find the sum of the numbers in the array I filled with the formula with recursive.
           
        if(arr[arr[0]] > 0){   //If arr [1] is greater than 0, I increase the arr [0] counter by 1.

            arr[500] = arr[500] + arr[arr[0]];  //I use arr [500] in total.
            arr[0]++;  //counter
            sum_array(arr);
        }     

            else{
                return arr[500];
            }
        
}

double std_array(int arr[],double *mean,int n,int index){

}



void shiftleft(char *str) {   //I use this helper function to shift letters.(part3)

	int length = strlen(str) - 1;	//here I find the length of the text.

	for (int i = 0; i < length; ++i)
	{
		str[i] = str[i+1];   //here I make room for the length of the text.
	}

	str[length] = '\0';  //I terminate the string.

}

char* remove_duplicates(char* str)    //here I am correcting duplicate numbers with the help of recursive function.
{
      	
	if (str[0] == '\0') return str;

	if (*(str - 1) == *str)
	{
		shiftleft(str);      //here I call my auxiliary function to shift the letters.
		remove_duplicates(str);  // I call the function again if the letter is the same.
	}

	remove_duplicates(str+1);  // if letters isn't the same str removed the next letter.
	return str - 1;
}