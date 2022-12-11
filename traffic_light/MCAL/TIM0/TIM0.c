/*
 * TIM0.c
 *
 * Created: 11/12/2022 03:17:45
 *  Author: es-HusseinMourad2024
 */ 


#include "TIM0.h"
#include <math.h>

void TIM0_init(){};
void TIM0_setCompare(uint8_t compareValue)
{
	OCR0 = compareValue;
}

uint8_t TIM0_getCompare()
{
	uint8_t compareValue = OCR0;
	return compareValue;
}


void TIM0_setTIM0(uint8_t TIM0Value)
{
	TCNT0 = TIM0Value;
}


uint8_t TIM0_getTIM0()
{
	uint8_t TIM0 = TCNT0;
	return TIM0;
}


void TIM0_delay_ms( uint32_t delay )
{
	uint16_t T_init;
	uint32_t N_overflows;
	double T_tick;
	double T_max;
	

	//Compute T_tick and N_overflows
	T_tick      = 1.0*TIM0_PRESCALER / F_CPU;
	T_max       = T_tick * 256 * 1000;
	N_overflows = ceil(delay / T_max);
	
	//Compute T_init
	if (N_overflows == 1)
	T_init = ceil(1.0*(T_max - delay)/(T_tick));
	else
	T_init = ceil(T_max - ((1.0*delay/T_tick)/(1.0*N_overflows)));

	//Clear TCCR0
	TCCR0  = 0x00;


	//Set Clock Source
	TCCR0  |=  TIM0_CLOCK_SOURCE;
	
	//Delay by busy wait
	for(int i=0; i< N_overflows ; i++)
	{
		TCNT0 = T_init;
		while( READ_BIT(TIFR, TIFR_TOV0) == 0 );  //Busy Wait
		SET_BIT(TIFR, TIFR_TOV0);                //Clear Overflow flag
	}
}


void TIM0_delay_steps( uint16_t Copy_u16Base, uint16_t Copy_u16Multi )
{
	//Clear TCCR0
	TCCR0  = 0x00;


	//Set Clock Source
	TCCR0  |=  TIM0_CLOCK_SOURCE;
	
	//Delay by busy wait
	for(int j=0; j<Copy_u16Multi; j++)
	{
		for(int i=0; i<ceil(Copy_u16Base) ; i++)
		{
			while( READ_BIT(TIFR, TIFR_TOV0) == 0 );  //Busy Wait
			SET_BIT(TIFR, TIFR_TOV0);                //Clear Overflow flag
		}
	}

	//Stop TIM0
	TCCR0 = 0x00;
}