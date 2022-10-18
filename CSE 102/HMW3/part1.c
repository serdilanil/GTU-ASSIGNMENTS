#include<stdio.h>
int sum (int n, int flag);	//function prototypes
int mult (int n, int flag); 

int main(){
	int flag,flag2,n,temp,temp2;
	printf("Enter an integer\n");
	scanf("%d",&n);

	printf("please enter '0' for sum '1' for multiplication\n"); //where flag determines the addition and multiplication.
	scanf("%d",&flag);
	printf("please enter '0' to work on even numbers,'1' to work on odd numbers\n"); //flag2 determines whether it will be done with odd or even numbers.
	scanf("%d",&flag2);
			

	if(flag2>1 || flag2 <0)  //I wrote this if condition because the flag will return 0 and 1 here.
		printf("Invalid value for odd / even selection\n"); //If you select your second choice greater than 1 or less than 0 while typing 0 and 1, you will encounter this error.
	
	else{
			switch(flag){		//I used the flag here because at first the flag will add if it is 0, and when it presses for the second time, it will perform the operation with even numbers.
				
					case 0:
							temp = sum(n,flag2);
							printf("= %d\n",temp);	
							

					break;
					
					case 1:		//here, if the flag is 1 at first, it will multiply if it presses for the second time, it will perform the operation with odd numbers.
							temp2 = mult(n,flag2);
							printf("= %d\n",temp2);						
						

					break;
					
					default :
						printf("Unsupported operation\n"); //If you select your first choice greater than 1 or less than 0 while typing 0 and 1, you will encounter this error.

				}
			
			
		}		


}

int sum (int n, int flag){
	
	int i,temp = 0;
	
	if(flag ==0){	
		
		for(i=1;i<=n;i++){
			
			if(i%2 == 0){
				if(i==2){		//here I print even numbers in the add function.
					printf("%d ", i);
				}
				else{
					printf("+ %d ",i);
				}
				temp +=i;		//I collect the numbers in temp.
			}
			
		}
	}

	else if(flag == 1){
			for(i=0;i<=n;i++){
				
				if(i%2 != 0){	
					if(i==1){
					printf("%d ", i); //here I print odd numbers in the add function.
				}
				else{
					printf("+ %d ",i);
				}
					temp +=i; //I collect the numbers in tempte
				}
				
			}
	}
		return temp ;

}


int mult (int n, int flag){
	int j,temp3=1;	

	if(flag == 0){
		for(j=1;j<=n;j++){

			if(j%2 == 0){
				if(j==2){	//here I print even numbers in the mult function
					printf("%d ",j);
				}
				else{
					printf("* %d ",j);	
				}
				temp3 *= j; //I write the numbers I multiply to temp3.
			}
	}


	}

	else if (flag ==1){
			for(j=1;j<=n;j++){
				if(j%2 != 0){
					if(j==1){		//here I print odd numbers in the mult function.
						printf("%d ",j);
					}
					else{
						printf("* %d ",j);
					}
					temp3 *=j; //I write the numbers I multiply to temp3.
				}
			}


	}
		return temp3;

}