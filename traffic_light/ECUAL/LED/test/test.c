/*
 * test.c
 *
 * Created: 12/12/2022 03:42:06
 *  Author: es-HusseinMourad2024
 */ 

#include "../../../Utilities/bit_manipulation.h"
#include "../../../Utilities/register.h"
#include "../../../Utilities/Types.h"
#include "../LED.h"

uint8_t LED_init_test()
{
	ST_Led led;
	LED_init(&led, PORT_A,PIN_0);
	if (READ_BIT(DDRA,1) == 1) 
		return 1;
	else 
		return 0;
}

uint8_t LED_on_test()
{
	ST_Led led;
	LED_init(&led, PORT_A,PIN_0);
	LED_on(&led);
	if (GPIO_getPinValue(PORT_A, PIN_0)==1)
		return 1;
	else
		return 0;
	
}


uint8_t LED_of_test()
{
	ST_Led led;
	LED_init(&led, PORT_A,PIN_0);
	LED_off(&led);
	if (GPIO_getPinValue(PORT_A, PIN_0)==LOW)
	return 1;
	else
	return 0;
	
}

uint8_t LED_toggle_test()
{
	ST_Led led;
	LED_init(&led, PORT_A,PIN_0);
	LED_on(&led);
	LED_toggle(&led);
	if (GPIO_getPinValue(PORT_A, PIN_0)==LOW)
	return 1;
	else
	return 0;
}

uint8_t LED_read_test()
{
	ST_Led led;
	LED_init(&led, PORT_A,PIN_0);
	LED_on(&led);
	uint8_t value = LED_read(&led);
	if (value==1)
	return 1;
	else
	return 0;
}
