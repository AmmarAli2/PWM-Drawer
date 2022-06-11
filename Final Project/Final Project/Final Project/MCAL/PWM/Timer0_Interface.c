/*
 * Timer0_Address.c
 *
 * Created: 5/29/2022 8:55:23 PM
 *  Author: Ammar
 */ 

#include "Timer0_Private.h"

void Timer0_OVF_WithoutInterrupt_Intialize(Timer0_Mode modes)
{
	cli();//Clear global interrupt, Disable global interrupt
	/*
	switch (mode)//Choose Mode
	{
	case OVF:
	break;
	case Phase_Correct_PWM:
	break;
	case CTC:
	break;
	case Fast_PWM:
	break;
	}
	*/
	CLR_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);//Choose OVF
	CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);//Disconnect OC0 pin
	CLR_BIT(TIMSK, TOIE0);//Disable peripheral interrupt
	sei();//Set global interrupt, Enable global interrupt
}
void Timer0_OVF_WithoutInterrupt_Start(Timer0_Prescaler prescaler)
{
	/*
	switch (prescaler)//Choose prescaler
	{
		
	}
	*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 1024
}
void Timer0_OVF_WithoutInterrupt_Stop(Timer0_Prescaler prescaler)
{
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 0
}
void Timer0_OVF_WithoutInterrupt_setDelay(uint32_t delay)
{
	uint32_t counter = 0;
	uint8_t Tick = ((1 * PRESCALER) / FREQUENCY);
	uint32_t Count = ((delay * MICROSECOND) / Tick);
	uint32_t No_OVF = (Count / BITS);
	uint8_t InitialValue_TCNT0 = (BITS - (Count % BITS));
	TCNT0 = InitialValue_TCNT0;
	No_OVF++;
	while (counter != No_OVF)//Polling Mode (Blocking Delay)
	{
		while (GET_BIT(TIFR, TOV0) != 1);//Wait until flag raise
		SET_BIT(TIFR, TOV0);//Clear flag manually in disable interrupt mode
		counter++;
	}
}

void Timer0_CTC_WithoutInterrupt_Intialize(Timer0_Mode modes, CTC0_Mode ctcmode)
{
	cli();//Clear global interrupt, Disable global interrupt
	/*
	switch (mode)//Choose Mode
	{
	case OVF:
	break;
	case Phase_Correct_PWM:
	break;
	case CTC:
	break;
	case Fast_PWM:
	break;
	}
	*/
	SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);//Choose CTC
	CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);//Disconnect OC0 pin
	CLR_BIT(TIMSK, OCIE0);//Disable peripheral interrupt
	sei();//Set global interrupt, Enable global interrupt
}
void Timer0_CTC_WithoutInterrupt_Start(Timer0_Prescaler prescaler)
{
	/*
	switch (prescaler)//Choose prescaler
	{
		
	}
	*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 1024
}
void Timer0_CTC_WithoutInterrupt_Stop(Timer0_Prescaler prescaler)
{
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 0
}
void Timer0_CTC_WithoutInterrupt_setDelay(uint32_t delay, uint8_t OCRValue)
{
	uint32_t counter = 0;
	uint8_t Tick = ((1 * PRESCALER) / FREQUENCY);
	uint32_t Count = ((delay * MICROSECOND) / Tick);
	uint32_t No_CTC = (Count / OCRValue);
	OCR0 = OCRValue;
	No_CTC++;
	while (counter != No_CTC)//Polling Mode (Blocking Delay)
	{
		while (GET_BIT(TIFR, OCF0) != 1);//Wait until flag raise
		SET_BIT(TIFR, OCF0);//Clear flag manually in disable interrupt mode
		counter++;
	}
}


uint8_t Initial_Value = 0;
uint32_t Number_OVF = 0;
uint32_t Number_CTC = 0;

void Timer0_OVF_WithInterrupt_Intialize(Timer0_Mode modes)
{
	cli();//Clear global interrupt, Disable global interrupt
	/*
	switch (mode)//Choose Mode
	{
	case OVF:
	break;
	case Phase_Correct_PWM:
	break;
	case CTC:
	break;
	case Fast_PWM:
	break;
	}
	*/
	CLR_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);//Choose OVF
	CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);//Disconnect OC0 pin
	SET_BIT(TIMSK, TOIE0);//Enable peripheral interrupt
	sei();//Set global interrupt, Enable global interrupt
}
void Timer0_OVF_WithInterrupt_Start(Timer0_Prescaler prescaler)
{
	/*
	switch (prescaler)//Choose prescaler
	{
		
	}
	*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 1024
}
void Timer0_OVF_WithInterrupt_Stop(Timer0_Prescaler prescaler)
{
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 0
}
void Timer0_OVF_WithInterrupt_setDelay(uint32_t delay)
{
	uint8_t Tick = ((1 * PRESCALER) / FREQUENCY);
	uint32_t Count = ((delay * MICROSECOND) / Tick);
	Number_OVF = (Count / BITS);
	Initial_Value = (BITS - (Count % BITS));
	Number_OVF++;
}

void Timer0_CTC_WithInterrupt_Intialize(Timer0_Mode modes, CTC0_Mode ctcmode)
{
	cli();//Clear global interrupt, Disable global interrupt
	/*
	switch (mode)//Choose Mode
	{
	case OVF:
	break;
	case Phase_Correct_PWM:
	break;
	case CTC:
	break;
	case Fast_PWM:
	break;
	}
	*/
	SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);//Choose CTC
	CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);//Disconnect OC0 pin
	SET_BIT(TIMSK, OCIE0);//Disable peripheral interrupt
	sei();//Set global interrupt, Enable global interrupt
}
void Timer0_CTC_WithInterrupt_Start(Timer0_Prescaler prescaler)
{
	/*
	switch (prescaler)//Choose prescaler
	{
		
	}
	*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 1024
}
void Timer0_CTC_WithInterrupt_Stop(Timer0_Prescaler prescaler)
{
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 0
}
void Timer0_CTC_WithInterrupt_setDelay(uint32_t delay, uint8_t OCRValue)
{
	uint8_t Tick = ((1 * PRESCALER) / FREQUENCY);
	uint32_t Count = ((delay * MICROSECOND) / Tick);
	Number_CTC = (Count / OCRValue);
	OCR0 = OCRValue;
	Number_CTC++;
}

