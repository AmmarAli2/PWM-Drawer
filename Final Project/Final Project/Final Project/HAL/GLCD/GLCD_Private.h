/*
 * GLCD_Private.h
 *
 * Created: 6/8/2022 4:37:43 PM
 *  Author: Ammar
 */ 


#ifndef GLCD_PRIVATE_H_
#define GLCD_PRIVATE_H_



#include "GLCD_Configuration.h"

void GLCD_Initialize(void);
void GLCD_Command(char Command);
void GLCD_Data(char Data);
void GLCD_ClearAll();
void GLCD_String(char page_no, char *str);
void GLCD_Char(char page_no, char character);
void GLCD_Wave(char page_no, uint8_t Ds);



#endif /* GLCD_PRIVATE_H_ */