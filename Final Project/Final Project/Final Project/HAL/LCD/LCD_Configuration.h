/*
 * GLCD_Configuration.h
 *
 * Created: 5/29/2022 8:33:35 PM
 *  Author: Ammar
 */ 


#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_

#include "CPU_Configurations.h"
//Renaming Ports
#define LCD_CTRL_PRT DIO_PORTB
#define LCD_DATA_PRT DIO_PORTA
//Renaming Control Pins
#define LCD_RS DIO_PIN1
#define LCD_RW DIO_PIN2
#define LCD_EN DIO_PIN3
//Renaming Data Pins
#define LCD_D0 DIO_PIN0
#define LCD_D1 DIO_PIN1
#define LCD_D2 DIO_PIN2
#define LCD_D3 DIO_PIN3
#define LCD_D4 DIO_PIN4
#define LCD_D5 DIO_PIN5
#define LCD_D6 DIO_PIN6
#define LCD_D7 DIO_PIN7
//Renaming State
#define LCD_LOW  DIO_LOW
#define LCD_HIGH DIO_HIGH
//Renaming Direction
#define LCD_OUT  DIO_OUTPUT

#endif /* GLCD_CONFIGURATION_H_ */