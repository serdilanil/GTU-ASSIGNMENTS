#include<stdio.h>

int number_length(int number);	//function prototypes
int binary_num(int a,int b);
int andop (int a, int b);


int main(){
	int n1,n2,length_n1,length_n2,flag1,flag2,a,b;  
	
	
	flag1 = (number_length(n1) == number_length(n2));
	
	while( flag1 == 0 || flag2 == 0){  
		printf("First integer\n");
		scanf("%d",&n1);
		printf("Second integer\n");
		scanf("%d",&n2);
		
		a=n1;
		b=n2;
		
		if(number_length(n1) == number_length(n2)){  //if the lengths of the numbers are equal, it will fall into the if condition.
			
			if(binary_num(n1,n2) == 1)		//If the length of two numbers is equal and these two numbers are binary, it runs the andop function.
				printf("integers should be binary , please enter 2 new integers\n");
			
			else
				printf("%d AND %d = %d\n",n1,n2,andop(a,b)); 
				return 0;
		
		}
	

	else
		printf("integers should have the same length , please enter 2 new integers\n");
	
	}


}

int number_length(int number){  //this function finds the digit of the number.
	int x,counter=1;

	while(number>0){
		
		number /=10;
		counter ++;
	}

		
	return counter;	
}			


int binary_num(int a,int b){  //this function finds if the number is a binary number.
	int z,y,t;
		
		while(a>0){

			t = a % 10;

			a = a / 10;

			if(t !=0 && t !=1){ //In order for a number to be binary, when it decreases the number by dividing it by 10, the remainder must either be 0 or 1, in this function we control this.
				return 1;
			}
					

				
		}

		while(b>0){

			z = b % 10;

			b = b / 10;

			if(z !=0 && z !=1){
				return 1;	
			}
		}



}


int andop (int a , int b){  //this function implements AND operators on two numbers.

	int temp=1,result=0,x,z;
		
		while(a>0 && b>0){

			z = a % 10;

			x = b % 10;
			a/=10;
			b/=10;


			if(x+z == 2)		//where the sum of the two numbers is 2, the AND operator will write it as 1 when writing a new number.
				result+=temp;

			temp*=10;				

		}
		
		return result;
		
}