#include<stdio.h>

int find_multiple_closest(int a, int b);

int main(){
	
	int a,b;
	printf("enter the first integer:");
	scanf("%d",&a);
	printf("enter the second integer:");
	scanf("%d",&b);
	
	if(find_multiple_closest(a,b)==a){
		printf("Output> Closest number to %d that is multiple of %d is itself.\n",a,b);
	}
	else{
		printf("Output> Closest number to %d that is multiple of %d is %d.\n",a, b, find_multiple_closest(a,b));
	}

}

int find_multiple_closest(int a,int b){

	int x,y;

	if(a%b==0){
		return a;
	}

		else
		{ 
			x = a-(a%b);
			y = a + (b-(a%b)) ;
		
			if(a-x == y-a)
			{
				
				return y;
			}
							
			if(y-a < a-x)
				return y;

				else
				return x;
		}


}
	
