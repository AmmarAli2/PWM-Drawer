/*
 * DIO_Private.h
 *
 * Created: 5/29/2022 8:40:55 PM
 *  Author: Ammar
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "DIO_Configuration.h"

//To define direction (Input/Output)
void DIO_SetPinDirection(port Port, pin Pin, direction Direction);
//To define state (High/Low)
void DIO_SetPinValue(port Port, pin Pin, state State);
//To change current state of pin
void DIO_TogglePinValue(port Port, pin Pin);
//To get pin value (High/Low)
uint8_t DIO_ReadPinValue(port Port, pin Pin);
//To activate internal Pull-up
void DIO_SetPinPullUp(port Port, pin Pin);

//To define direction (Input/Output)
void DIO_SetPortDirection(port Port, direction Direction);
//To define state (High/Low)
void DIO_SetPortValue(port Port, state State);
//To change current state of pin
void DIO_TogglePort(port Port);
//To get pin value (High/Low)
uint8_t DIO_ReadPort(port Port);
//To activate internal Pull-up
void DIO_SetPortPullUp(port Port);



#endif /* DIO_PRIVATE_H_ */