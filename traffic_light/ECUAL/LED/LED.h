/*
 * LED.h
 *
 * Created: 11/12/2022 03:29:37
 *  Author: es-HusseinMourad2024
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"

//Types
typedef struct
{
	EN_Port Port;
	EN_Pin  Pin ;
} ST_Led;


void LED_init( ST_Led* Ptr_stLed, EN_Port port, EN_Pin pin);
void LED_on( ST_Led* Ptr_stLed );
void LED_off( ST_Led* Ptr_stLed );
void LED_toggle( ST_Led* Ptr_stLed );
uint8_t LED_read( ST_Led* Ptr_stLed );


#endif /* LED_H_ */