#include "arduino-serial-lib.c"
#include "arduino-serial-lib.h"

int main(){
	int ardo = serialport_init("/dev/ttyUSB0", 9600);
	const char* num1="a";
	const char* num2="b";
	const char* num3="c";
	const char* num4="d";
	char answer[256];
	float num_sq;
	int choice;
	do{
		printf("\n## WELCOME TO GTU ARDUINO LAB			##\n");
		printf("## STUDENT NAME: SERDIL ANIL UNLU		##\n");
		printf("## PLEASE SELECT FROM THE FOLLOWING		##\n");
		printf("## MENU : 					##\n");
		printf("(1) TURN ON LED ON ARDUINO\n(2) TURN OFF LED ON ARDUINO\n(3) FLASH ARDUINO LED 3 TIMES\n(4) SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO\n(0) EXIT\nPLEASE SELECT:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: 
				serialport_write(ardo, num1);
				break;

			case 2:
				serialport_write(ardo, num2);
				break;

			case 3:
				serialport_write(ardo, num3);
				break;

			case 4:
				printf("PLEASE WRITE A NUMBER: ");
				scanf("%f", &num_sq);
				if(num_sq<0)
				{
					num_sq=num_sq*-1;
				}
				serialport_write(ardo, num4);
				serialport_writebyte(ardo, num_sq);
				serialport_read_until(ardo, answer, '\n', 256, 1000);
				printf("Answer:");
				printf("%s\n",answer);
				
		}

		if(choice<0 || choice>4)
			{
				printf("PLEASE CHOOSE BETWEEN 0 AND 4\n");
			}

	}while(choice!=0);
	printf("THANKS FOR USING GTU ARDUINO LAB\n");


}
