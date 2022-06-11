/*
 * DIO_Configuration.h
 *
 * Created: 5/29/2022 8:40:39 PM
 *  Author: Ammar
 */ 


#ifndef DIO_CONFIGURATION_H_
#define DIO_CONFIGURATION_H_

#include "CPU_Configurations.h"
#include "DIO_Address.h"

//Renaming ports
typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3
}port;

//Rename pins
typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7
}pin;
//Renaming states
typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH = 1
}state;
//Renaming Direction
typedef enum
{
	DIO_INPUT = 0,
	DIO_OUTPUT = 1
}direction;
//Renaming Dio Boolean
typedef enum
{
	DIO_FALSE = 0,
	DIO_TRUE = 1
}boolean;




#endif /* DIO_CONFIGURATION_H_ */