#include<stdio.h>
//functions prototypes
float addition(float firstnumber, float secondnumber);
float subtraction (float firstnumber , float secondnumber);
float multiply (float firstnumber , float secondnumber);	
float divide (float firstnumber , float secondnumber);
float power (float firstnumber , float secondnumber);
float average(void);
float max(void);
int main(){
	float calculation;
	int choice=1;
	while(choice!=0){
		printf(" \nWELCOME TO GTU CALCULATOR MACHINE:");
		printf(" \nSTUDENT NAME: SERDIL ANIL UNLU:\n");
		printf("PLEASE SELECT FROM THE FOLLOWING:\n");
		printf("MENU :\n");                            
		printf("(1) ADD TWO NUMBERS:\n");
		printf("(2) SUBTRACT TWO NUMBERS:\n");
		printf("(3) MULTIPLY TWO NUMBERS:\n");
		printf("(4) DIVIDE TWO NUMBERS:\n");
		printf("(5) TAKE THE NTH POWER OF A NUMBER:\n");
		printf("(6) FIND AVERAGE OF NUMBERS INPUTTED:\n");
		printf("(7) FIND THE MAXIMUM OF NUMBERS INPUTTED:\n");
		printf("(0) EXIT:\n");
		printf("PLEASE SELECT: ");
		scanf("%d",&choice);
		if(choice==1){
			float firstnumber;
			float secondnumber;
			printf("please enter the first number:");
			scanf("%f",&firstnumber);
			
			printf("please enter the second number:");
			scanf("%f",&secondnumber);
			
			calculation	= addition(firstnumber,secondnumber);
			printf("The result is: %f\n",calculation);
				
		}
		if(choice==2){
			float firstnumber, secondnumber;
			printf("please enter the first number:");
			scanf("%f",&firstnumber);
			
			printf("please enter the second number:");
			scanf("%f",&secondnumber);
			
			printf("The result is: %f\n",subtraction(firstnumber, secondnumber));
		}
		if(choice==3){
			float firstnumber, secondnumber;
			
			
			printf("please enter the first number:");
			scanf("%f",&firstnumber);
			
			printf("please enter the second number:");
			scanf("%f",&secondnumber);
			
			
			calculation =multiply(firstnumber,secondnumber);
			printf("The result is: %f\n",calculation);
					
		}
		if(choice==4){
			float firstnumber, secondnumber;
			
			printf("please enter the first number:");
			scanf("%f",&firstnumber);
			
			printf("please enter the second number:");
			scanf("%f",&secondnumber);
			while(secondnumber==0){
				printf("You can not enter zero!\n");
				printf("Please enter again: ");
				scanf("%f",&secondnumber);
		}
			calculation = divide(firstnumber,secondnumber);
			printf("The result is: %.2f\n",calculation);
		
		}
		if(choice==5){
			float firstnumber, secondnumber;
			printf("please enter the first number:");
			scanf("%f",&firstnumber);
			printf("please enter the second number:");
			scanf("%f",&secondnumber);
			calculation = power(firstnumber,secondnumber);
			printf("The Result is: %.2f\n",calculation);
		}
		if (choice == 6) {
			float aver = average();
			printf("\nAverage : %.2f\n",aver);
		}
		if (choice == 7) {
			float Max = max();
			printf("\nMax : %.2f\n",Max);
		}
   	}   
	
	
		
	return 0;
}
float addition(float firstnumber, float secondnumber){
		return firstnumber + secondnumber;
}
float subtraction (float firstnumber , float secondnumber){
		return firstnumber - secondnumber;
}
	
float multiply (float firstnumber , float secondnumber){
	return firstnumber * secondnumber;
}
	
float divide (float firstnumber , float secondnumber){
	return firstnumber / secondnumber;
}

float power (float firstnumber , float secondnumber){
	
	float x = firstnumber;
	int i;
	for(i = 0;i<secondnumber-1;i++){
		
		x = x*firstnumber;	
	}
	return x;
}

float average(void){
	
	int i, count = 0;
    float n;
    float num[100], sum = 0.0, aver;
	int flag = 1;
	printf("Enter your numbers to exit enter -1234567\n");
    while (flag)
    {
        printf("Please Enter %d. Number : ",count + 1);
        scanf("%f", &n);
        if (n == -1234567.0) flag = 0;
        if (n != -1234567.0) {
			num[count++] = n;	
	}
    }

    for(i = 0; i < count; ++i)
    {
        sum += num[i];
    }

    aver = sum / count;
    return aver;
   }	

float max(void){
	
	int adet=0;
    float max , sayi=1;
    printf("Enter your numbers to exit enter -1234567\n");
    while(sayi!=-1234567){
    	printf("Enter your %d. number:",adet+1);
    	scanf("%f", &sayi);
    	if(adet == 0)
    		max=sayi;
    	if(sayi > max)
    		max=sayi;
    	adet++;
	}
    return max;
    
    
    
}
