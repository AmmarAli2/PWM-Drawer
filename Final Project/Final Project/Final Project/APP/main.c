/*
 * main.c
 *
 * Created: 5/29/2022 8:31:58 PM
 *  Author: Ammar
 */ 
#include "main.h"

int main(void)
{
	PWM0_Fast_Initialize();
	GLCD_Initialize();
	int Ds=20;
	int i=Ds/10;
	int j=Ds%10;
	char D=i+'0';
	char s=j+'0';

	PWM0_Fast_SetDutyCycle(Ds);
		
		GLCD_ClearAll();
		GLCD_Char(0,'D');
		GLCD_Char(0,'U');
		GLCD_Char(0,'T');
		GLCD_Char(0,'Y');
		GLCD_Char(0,'C');
		GLCD_Char(0,'Y');
		GLCD_Char(0,'C');
		GLCD_Char(0,'L');
		GLCD_Char(0,'E');
		GLCD_Char(0,'=');	
		GLCD_Char(0,D);
		GLCD_Char(0,s);
		GLCD_Char(1,' ');
		GLCD_Char(1,'F');
		GLCD_Char(1,'=');
		GLCD_Char(1,'1');
		GLCD_Char(1,'2');
		GLCD_Char(1,'M');
		GLCD_Char(1,'H');
		GLCD_Char(1,'z');
		GLCD_Wave(5,Ds);
		_delay_ms(1000);
	
		while(1);
}
	
