#include<stdio.h>
#include <math.h>
void find_newtonian_root();

int main(){
	
	find_newtonian_root();
}

void find_newtonian_root(){
	float x0,x,x2,x3,x4,x5;	//x0 is guess of the root,x is another root
	float i=0,i2=0,i3=0,i4=0,i5=0;
	float temp1,temp2,temp3,temp4,temp5=0;
	float root1, root2, m_root, discr;
	int a,b,c;
	printf("please enter the first coefficient:");
	scanf("%d",&a);
	printf("please enter the second coefficient:");
	scanf("%d",&b);
	printf("please enter the third coefficient:");
	scanf("%d",&c);
	printf("please enter the initial:");
	scanf("%f",&x0);
	printf("output>your equation is (%dx^2)+(%dx)+(%d) and iterations are:\n",a,b,c);
	discr=b*b-4*a*c;
	if(discr==0){
		m_root=-b/2*a;
	}

	if(discr>0){
		root1=(-b+sqrt(discr))/2*a;
		root2=(-b-sqrt(discr))/2*a;

		if(fabs(x0-root1)>fabs(x0-root2)){
			m_root=root2;
		}

		if(fabs(x0-root2)>fabs(x0-root1)){
			m_root=root1;
		}
	}
	
				
		x = x0 - (a*x0*x0+b*x0+c) / (2*a*x0+b);  
		i = (a*x*x+b*x+c);
		temp1 = x - m_root;
		printf(" x is %.4f  f(x) is %.5f and difference is %.4f\n",x,i,temp1);
		
		
		x2 = x - (a*x*x+b*x+c) / (2*a*x+b);	
		i2 = (a*x2*x2+b*x2+c);
		temp2 = x2 - m_root;
		printf("x2 is %.4f f(x2) is %.5f and difference is %.4f\n",x2,i2,temp2);

		
		x3 = x2 - (a*x2*x2+b*x2+c) / (2*a*x2+b);
		i3 = (a*x3*x3+b*x3+c);
		temp3 = x3 - m_root;
		printf("x3 is %.4f f(x3) is %.5f and difference is %.4f\n",x3,i3,temp3);

		
		x4 = x3 - (a*x3*x3+b*x3+c) / (2*a*x3+b);
		i4 = (a*x4*x4+b*x4+c);
		temp4 = x4 - m_root;
		printf("x4 is %.4f f(x4) is %.5f and difference is %.4f\n",x4,i4,temp4);

		
		x5 = x4 - (a*x4*x4+b*x4+c) / (2*a*x4+b);
		i5 = (a*x5*x5+b*x5+c);
		temp5 = x5 - m_root;
		printf("x5 is %.4f f(x5) is %.5f and difference is %.4f\n",x5,i5,temp5);
	
		
}

