/*
 * CPU_Configurations.h
 *
 * Created: 5/29/2022 8:35:15 PM
 *  Author: Ammar
 */ 


#ifndef CPU_CONFIGURATIONS_H_
#define CPU_CONFIGURATIONS_H_


#undef F_CPU //Disable internal oscillator
#define F_CPU 16000000 //Enable external oscillator 16MHz
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <avr/io.h> //All ports defined in avr library
#include <util/delay.h> //Enable _delay_ms() function
#include <avr/interrupt.h> //Enable interrupts function
#include "BIT_Math.h"
#include "STD_Types.h"
#include "DIO_Private.h"
#include "Timer0_Private.h"
#include "PWM0_Private.h"

	



#endif /* CPU_CONFIGURATIONS_H_ */