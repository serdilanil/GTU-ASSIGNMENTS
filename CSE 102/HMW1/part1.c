#include<stdio.h>
#include<math.h>
void find_root();
int main(){
	
	
	find_root();
}
void find_root(){
	int a,b,c;
	float x1,x2,delta,temp,x;
	printf("please enter the first coefficient:");
	scanf("%d",&a);
	printf("please enter the second coefficient:");
	scanf("%d",&b);
	printf("please enter the third coefficient:");
	scanf("%d",&c);
	printf("%dx^2 + %dx + %d\n",a,b,c);
	delta = b*b-4*a*c;

	if(delta==0){
		x1=-b/2*a;
		printf("output>your equation have real root %f\n",x1);
	}
	if(delta>0)
		{
			
			x1 = (-b+sqrt(delta))/2*a;
			x2 = (-b-sqrt(delta))/2*a;

			printf("output>your equation have real roots %f %f\n",x1,x2);
		}


	if(delta<0)	
		{
			printf("output>your equation does not have any real roots:");	
		}
}


