#include<stdio.h>
#include<math.h>

int isprime (int a); //function prototype

int main(){
	int n1,b;
	printf("please enter the number\n");
	scanf("%d",&n1);

	for(b=2;b<n1;b++){		//Are the numbers up to the number we pressed here prime? if not, I used the for loop to print the smallest divisors one after the other.
			
		 if(isprime(b) == 1)		
			printf("%d is a prime number\n",b);   // here I print the number is prime.

			else
				printf("%d is not a prime number,it is dividible by %d\n",b,isprime(b)); //here I print the number and smallest divisor.
	}


}

int isprime (int a){
	int flag=1,i;			

	for(i=2;i<=sqrt(a);i++){  //here, if the number is not prime, I return the smallest divisor.

		if(a%i==0){

			return i;
				
		}



	}
		return flag;	//If there is no divider, I am turning the flag.


}		

