	/*
 * DIO_Interface.c
 *
 * Created: 5/29/2022 8:41:09 PM
 *  Author: Ammar
 */ 

#include "DIO_Private.h"


//To define direction (Input/Output)
void DIO_SetPinDirection(port Port, pin Pin, direction Direction)
{
	switch(Direction)
	{
		case DIO_INPUT:
		switch (Port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA, Pin);
			break;
			case DIO_PORTB:
			CLR_BIT(DDRB , Pin);
			break;
			case DIO_PORTC:
			CLR_BIT(DDRC, Pin);
			break;
			case DIO_PORTD:
			CLR_BIT(DDRD, Pin);
			break;
			default:
			//#warning "Port or Pin Not Correcrt"
			break;
		}
		break;
		case DIO_OUTPUT:
		switch (Port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA, Pin);
			break;
			case DIO_PORTB:
			SET_BIT(DDRB , Pin);
			break;
			case DIO_PORTC:
			SET_BIT(DDRC, Pin);
			break;
			case DIO_PORTD:
			SET_BIT(DDRD, Pin);
			break;
			default:
			//#warning "Port or Pin Not Correcrt"
			break;
		}
		break;
	}
}
//To define state (High/Low)
void DIO_SetPinValue(port Port, pin Pin, state State)
{
	switch(State)
	{
		case DIO_LOW:
		switch (Port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA, Pin);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB , Pin);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC, Pin);
			break;
			case DIO_PORTD:
			CLR_BIT(PORTD, Pin);
			break;
			default:
			//#warning "Port or Pin Not Correcrt"
			break;
		}
		break;
		case DIO_HIGH:
		switch (Port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, Pin);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB , Pin);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC, Pin);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD, Pin);
			break;
			default:
			//#warning "Port or Pin Not Correcrt"
			break;
		}
		break;
	}
}
//To change current state of pin
void DIO_TogglePinValue(port Port, pin Pin)
{
	switch (Port)
	{
		case DIO_PORTA:
		TGL_BIT(PORTA, Pin);
		break;
		case DIO_PORTB:
		TGL_BIT(PORTB , Pin);
		break;
		case DIO_PORTC:
		TGL_BIT(PORTC, Pin);
		break;
		case DIO_PORTD:
		TGL_BIT(PORTD, Pin);
		break;
		default:
		//#warning "Port or Pin Not Corrert"
		break;
	}
}
//To get pin value (High/Low)
uint8_t DIO_ReadPinValue(port Port, pin Pin)
{
	uint8_t data = 5;
	switch (Port)
	{
		case DIO_PORTA:
		data = GET_BIT(PINA, Pin);
		break;
		case DIO_PORTB:
		data = GET_BIT(PINB, Pin);
		break;
		case DIO_PORTC:
		data = GET_BIT(PINC, Pin);
		break;
		case DIO_PORTD:
		data = GET_BIT(PIND, Pin);
		break;
		default:
		//#warning "Port or Pin Not Correct"
		break;
	}
	return data;
}
//To activate internal Pull-up
void DIO_SetPinPullUp(port Port, pin Pin)
{
	switch (Port)
	{
		case DIO_PORTA:
		SET_BIT(PORTA, Pin);
		break;
		case DIO_PORTB:
		SET_BIT(PORTB, Pin);
		break;
		case DIO_PORTC:
		SET_BIT(PORTC, Pin);
		break;
		case DIO_PORTD:
		SET_BIT(PORTD, Pin);
		break;
	}
}

//To define direction (Input/Output)
void DIO_SetPortDirection(port Port, direction Direction)
{
	switch(Direction)
	{
		case DIO_INPUT:
		switch (Port)
		{
			case DIO_PORTA:
			DDRA = 0x00;
			break;
			case DIO_PORTB:
			DDRB = 0x00;
			break;
			case DIO_PORTC:
			DDRC = 0x00;
			break;
			case DIO_PORTD:
			DDRD= 0x00;
			break;
			default:
			//#warning "Port Not Correcrt"
			break;
		}
		break;
		case DIO_OUTPUT:
		switch (Port)
		{
			case DIO_PORTA:
			DDRA = 0xFF;
			break;
			case DIO_PORTB:
			DDRB = 0xFF;
			break;
			case DIO_PORTC:
			DDRC = 0xFF;
			break;
			case DIO_PORTD:
			DDRD= 0xFF;
			break;
			default:
			//#warning "Port or Pin Not Correcrt"
			break;
		}
		break;
	}
}
//To define state (High/Low)
void DIO_SetPortValue(port Port, state State)
{
	switch(State)
	{
		case DIO_LOW:
		switch (Port)
		{
			case DIO_PORTA:
			PORTA = 0x00;
			break;
			case DIO_PORTB:
			PORTB = 0x00;
			break;
			case DIO_PORTC:
			PORTC = 0x00;
			break;
			case DIO_PORTD:
			PORTD= 0x00;
			break;
			default:
			//#warning "Port Not Correcrt"
			break;
		}
		break;
		case DIO_HIGH:
		switch (Port)
		{
			case DIO_PORTA:
			PORTA = 0xFF;
			break;
			case DIO_PORTB:
			PORTB = 0xFF;
			break;
			case DIO_PORTC:
			PORTC = 0xFF;
			break;
			case DIO_PORTD:
			PORTD= 0xFF;
			break;
			default:
			//#warning "Port Not Correcrt"
			break;
		}
		break;
	}
}
//To change current state of pin
void DIO_TogglePort(port Port)
{
	switch (Port)
	{
		case DIO_PORTA:
		PORTA ^= 0xFF;
		break;
		case DIO_PORTB:
		PORTB ^= 0xFF;
		break;
		case DIO_PORTC:
		PORTC ^= 0xFF;
		break;
		case DIO_PORTD:
		PORTD ^= 0xFF;
		break;
		default:
		//#warning "Port Not Correcrt"
		break;
	}
}
//To get pin value (High/Low)
uint8_t DIO_ReadPort(port Port)
{
	uint8_t data = 5;
	switch (Port)
	{
		case DIO_PORTA:
		data = PINA;
		break;
		case DIO_PORTB:
		data = PINB;
		break;
		case DIO_PORTC:
		data = PINC;
		break;
		case DIO_PORTD:
		data = PIND;
		break;
		default:
		//#warning "Port Not Correcrt"
		break;
	}
	return data;
}
//To activate internal Pull-up
void DIO_SetPortPullUp(port Port);