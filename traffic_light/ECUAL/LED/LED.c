/*
 * LED.c
 *
 * Created: 11/12/2022 03:30:44
 *  Author: es-HusseinMourad2024
 */ 


#include "../../MCAL/GPIO/GPIO.h"
#include "LED.h"


void LED_init( ST_Led* Ptr_stLed, EN_Port port, EN_Pin pin )
{
	Ptr_stLed->Port = port;
	Ptr_stLed->Pin  = pin;
	GPIO_setPinMode(Ptr_stLed->Port, Ptr_stLed->Pin, OUTPUT);
}


void LED_on( ST_Led* Ptr_stLed )
{
	GPIO_setPinValue(Ptr_stLed->Port, Ptr_stLed->Pin, HIGH);
}


void LED_off( ST_Led* Ptr_stLed )
{
	GPIO_setPinValue(Ptr_stLed->Port, Ptr_stLed->Pin, LOW);
}


void LED_toggle( ST_Led* Ptr_stLed )
{
	GPIO_pinToggle(Ptr_stLed->Port, Ptr_stLed->Pin);
}


uint8_t LED_read( ST_Led* Ptr_stLed )
{
	return GPIO_getPinValue(Ptr_stLed->Port, Ptr_stLed->Pin);
}