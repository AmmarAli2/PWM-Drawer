/*
 * Timer0_Configuration.h
 *
 * Created: 5/29/2022 8:56:09 PM
 *  Author: Ammar
 */ 


#ifndef TIMER0_CONFIGURATION_H_
#define TIMER0_CONFIGURATION_H_

#include "CPU_Configurations.h"
#include "Timer0_Address.h"

#define BITS          256
#define PRESCALER     1024
#define FREQUENCY     16
#define MILLISECOND   1
#define MICROSECOND   1000

typedef enum
{
	OVF=0,
	Phase_Correct_PWM=1,
	CTC=2,
	Fast_PWM=3
}Timer0_Mode;

typedef enum
{
	OC0_Disconnected=0,
	OC0_Toggle=1,
	OC0_Clear=2,
	OC0_Set=3
}CTC0_Mode;

typedef enum
{
	No_clock_source=0,
	No_prescaling=1,
	From_prescaler8=2,
	From_prescaler64=3,
	From_prescaler256=4,
	From_prescaler1024=5,
}Timer0_Prescaler;




#endif /* TIMER0_CONFIGURATION_H_ */