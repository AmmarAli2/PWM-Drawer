/*
 * GLCD_Configuration.h
 *
 * Created: 6/8/2022 4:37:27 PM
 *  Author: Ammar
 */ 


#ifndef GLCD_CONFIGURATION_H_
#define GLCD_CONFIGURATION_H_

#include "CPU_Configurations.h"

#define Data_Port PORTA
#define Command_Port PORTC
#define Data_Port_Dir DDRA
#define Command_Port_Dir DDRC

#define RS DIO_PIN0
#define RW DIO_PIN1
#define EN DIO_PIN2
#define CS1 DIO_PIN3
#define CS2 DIO_PIN4
#define RST DIO_PIN5

#define TotalPage 8




#endif /* GLCD_CONFIGURATION_H_ */