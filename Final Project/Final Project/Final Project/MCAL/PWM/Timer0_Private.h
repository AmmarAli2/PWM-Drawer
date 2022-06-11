/*
 * Timer0_Private.h
 *
 * Created: 5/29/2022 8:56:23 PM
 *  Author: Ammar
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_


#include "PWM0_Private.h"
#include "Timer0_Configuration.h"

void Timer0_OVF_WithoutInterrupt_Intialize(Timer0_Mode modes);
void Timer0_OVF_WithoutInterrupt_Start(Timer0_Prescaler prescaler);
void Timer0_OVF_WithoutInterrupt_Stop(Timer0_Prescaler prescaler);
void Timer0_OVF_WithoutInterrupt_setDelay(uint32_t delay);

void Timer0_CTC_WithoutInterrupt_Intialize(Timer0_Mode modes, CTC0_Mode ctcmode);
void Timer0_CTC_WithoutInterrupt_Start(Timer0_Prescaler prescaler);
void Timer0_CTC_WithoutInterrupt_Stop(Timer0_Prescaler prescaler);
void Timer0_CTC_WithoutInterrupt_setDelay(uint32_t delay, uint8_t OCRValue);



void Timer0_OVF_WithInterrupt_Intialize(Timer0_Mode modes);
void Timer0_OVF_WithInterrupt_Start(Timer0_Prescaler prescaler);
void Timer0_OVF_WithInterrupt_Stop(Timer0_Prescaler prescaler);
void Timer0_OVF_WithInterrupt_setDelay(uint32_t delay);

void Timer0_CTC_WithInterrupt_Intialize(Timer0_Mode modes, CTC0_Mode ctcmode);
void Timer0_CTC_WithInterrupt_Start(Timer0_Prescaler prescaler);
void Timer0_CTC_WithInterrupt_Stop(Timer0_Prescaler prescaler);
void Timer0_CTC_WithInterrupt_setDelay(uint32_t delay, uint8_t OCRValue);




#endif /* TIMER0_PRIVATE_H_ */