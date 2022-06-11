/*
 * GLCD_Private.h
 *
 * Created: 5/29/2022 8:33:15 PM
 *  Author: Ammar
 */ 


#ifndef GLCD_PRIVATE_H_
#define GLCD_PRIVATE_H_
#include "LCD_Configuration.h"

void LCD_Initialize(void);
void LCD_Clear(void);
void LCD_Write_Command(uint8_t command);
void LCD_Write_Character(uint8_t character);
void LCD_Write_String(uint8_t* str);
void LCD_Write_Number(uint32_t number);




#endif /* GLCD_PRIVATE_H_ */