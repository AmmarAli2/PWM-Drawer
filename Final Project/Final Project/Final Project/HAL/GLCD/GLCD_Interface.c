/*
 * GLCD_Interface.c
 *
 * Created: 6/8/2022 4:37:58 PM
 *  Author: Ammar
 */ 

#include "GLCD_Private.h"
#include "Fonts.h"

void GLCD_Initialize()			/* GLCD initialize function */
{
	Data_Port_Dir = 0xFF;
	Command_Port_Dir = 0xFF;
	/* Select both left & right half of display & Keep reset pin high */
	Command_Port |= (1 << CS1) | (1 << CS2) | (1 << RST);
	_delay_ms(20);
	GLCD_Command(0x3E);		/* Display OFF */
	GLCD_Command(0x40);		/* Set Y address (column=0) */
	GLCD_Command(0xB8);		/* Set x address (page=0) */
	GLCD_Command(0xC0);		/* Set z address (start line=0) */
	GLCD_Command(0x3F);		/* Display ON */
}

void GLCD_Command(char Command)		/* GLCD command function */
{
	Data_Port = Command;		/* Copy command on data pin */
	Command_Port &= ~(1 << RS);	/* Make RS LOW for command register*/
	Command_Port &= ~(1 << RW);	/* Make RW LOW for write operation */
	Command_Port |=  (1 << EN);	/* HIGH-LOW transition on Enable */
	_delay_us(5);
	Command_Port &= ~(1 << EN);
	_delay_us(5);
}

void GLCD_Data(char Data)		/* GLCD data function */
{
	Data_Port = Data;		/* Copy data on data pin */
	Command_Port |= (1 << RS);	/* Make RS HIGH for data register */
	Command_Port &= ~(1 << RW);	/* Make RW LOW for write operation */
	Command_Port |= (1 << EN);	/* HIGH-LOW transition on Enable */
	_delay_us(5);
	Command_Port &= ~(1 << EN);
	_delay_us(5);
}



void GLCD_ClearAll()			
{
	int i,j;
	/* Select both left & right half of display */
	Command_Port |= (1 << CS1) | (1 << CS2);
	for(i = 0; i < TotalPage; i++)
	{
		GLCD_Command((0xB8) + i);/* Increment page */
		for(j = 0; j < 64; j++)
		{
			GLCD_Data(0);	
		}
	}
	GLCD_Command(0x40);		/* Set Y address (column=0) */
	GLCD_Command(0xB8);		/* Set x address (page=0) */
}


void GLCD_Char(char page_no, char character)
{
		unsigned int Page = ((0xB8) + page_no);
		int i=((character-32)*5);
		int j=i+5;
		Command_Port |= (1 << CS2);	/* Select Left half of display */
		Command_Port &= ~(1 << CS1);
		GLCD_Command(Page);
		
	
	DIO_SetPinValue(DIO_PORTC, DIO_PIN0, DIO_HIGH);//Choose Data Register
	DIO_SetPinValue(DIO_PORTC, DIO_PIN1, DIO_LOW);//Choose Write on LCD
	DIO_SetPinValue(DIO_PORTC, DIO_PIN2, DIO_LOW);//EN low

for(int x=i; x<j; x++)
	GLCD_Data(font5x8[x]);
}
void GLCD_Wave(char page_no, uint8_t Ds)  /* Display Duty Cycle Waveform */
{
			int j=(Ds/10); 
			unsigned int Page = ((0xB8) + page_no);
			Command_Port |= (1 << CS2);	/* Select Left half of display */
			Command_Port &= ~(1 << CS1);
			GLCD_Command(Page);
			
	for(int x=0;x<5;x++)			/*Repeat cycle 5 times*/
	{
	GLCD_Data(0x00);
	for(int i=0;i<(10-j);i++)
	{
		GLCD_Data(0x7F);
	}
	GLCD_Data(0x00);
	for(int i=0;i<j;i++)
	{
		GLCD_Data(0xFE);
	}
	GLCD_Data(0x00);
	}
	}