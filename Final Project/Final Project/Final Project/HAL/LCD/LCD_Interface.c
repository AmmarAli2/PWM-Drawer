/*
 * GLCD_Interface.c
 *
 * Created: 5/29/2022 8:32:56 PM
 *  Author: Ammar
 */ 

#include "LCD_Private.h"

void LCD_Initialize(void)
{
	DIO_SetPinDirection(LCD_CTRL_PRT, LCD_RS, LCD_OUT);
	DIO_SetPinDirection(LCD_CTRL_PRT, LCD_RW, LCD_OUT);
	DIO_SetPinDirection(LCD_CTRL_PRT, LCD_EN, LCD_OUT);
	
	DIO_SetPinDirection(LCD_DATA_PRT, LCD_D4, LCD_OUT);
	DIO_SetPinDirection(LCD_DATA_PRT, LCD_D5, LCD_OUT);
	DIO_SetPinDirection(LCD_DATA_PRT, LCD_D6, LCD_OUT);
	DIO_SetPinDirection(LCD_DATA_PRT, LCD_D7, LCD_OUT);

	LCD_Write_Command(0x33);
	LCD_Write_Command(0x32);
	LCD_Write_Command(0x28);//4-Bit Mode
	LCD_Write_Command(0x01);//Clear Display
	LCD_Write_Command(0x02);//Return Home
	LCD_Write_Command(0x0C);//Display on, Cursor off
	LCD_Write_Command(0x06);//Increment Cursor Right
	
	_delay_ms(2);
}
void LCD_Clear(void)
{
	LCD_Write_Command(0x01);//Clear Display
}
void LCD_Write_Command(uint8_t command)
{
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_RS, LCD_LOW);//Choose Control Register
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_RW, LCD_LOW);//Choose Write on LCD
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable LCD
	//Send High Nibble First
	PORTA = ((command)& 0xF0) | (PORTA & 0x0F);
	//Send High to Low Pulse
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_EN, LCD_HIGH);//Disable LCD
	_delay_ms(1);
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable LCD
	//Send Low Nibble First
	PORTA = ((command<<4)& 0xF0) | (PORTA & 0x0F);
	//Send High to Low Pulse
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_EN, LCD_HIGH);//Disable LCD
	_delay_ms(1);
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable LCD
	_delay_ms(5);
}
void LCD_Write_Character(uint8_t character)
{
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_RS, LCD_HIGH);//Choose Data Register
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_RW, LCD_LOW);//Choose Write on LCD
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable LCD
	//Send High Nibble First
	PORTA = ((character)& 0xF0) | (PORTA & 0x0F);
	//Send High to Low Pulse
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_EN, LCD_HIGH);//Disable LCD
	_delay_ms(1);
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable LCD
	//Send Low Nibble First
	PORTA = ((character<<4)& 0xF0) | (PORTA & 0x0F);
	//Send High to Low Pulse
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_EN, LCD_HIGH);//Disable LCD
	_delay_ms(1);
	DIO_SetPinValue(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable LCD
	_delay_ms(5);
}
void LCD_Write_String(uint8_t* str)
{
	while (*str != '\0')//Termination of any string, NULL character
	{
		LCD_Write_Character(*str);
		_delay_ms(2);
		str++;
	}	
}
void LCD_Write_Number(uint32_t number)
{
	char num[15];
	ltoa(number, (uint8_t*)num, 10);
	LCD_Write_String((uint8_t*) num);
}