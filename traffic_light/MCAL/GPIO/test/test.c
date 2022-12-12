/*
 * test.c
 *
 * Created: 12/12/2022 03:42:06
 *  Author: es-HusseinMourad2024
 */ 


#include "../../../Utilities/bit_manipulation.h"
#include "../../../Utilities/register.h"
#include "../../../Utilities/Types.h"
#include "../GPIO.h"


uint8_t GPIO_setPinMode_test()
{
	GPIO_setPinMode(PORT_A, PIN_0, INPUT);
	if (READ_BIT(DDRA, PIN_0) == 0)
		return 1;
	else
		return 0;
}

uint8_t GPIO_setPinValue_test()
{
	GPIO_setPinValue(PORT_A, PIN_0, LOW);
	if (READ_BIT(PORT_A,PIN_0) == LOW)
		return 1;
	else
		return 0;
}

uint8_t GPIO_setPortValue_test()
{
	GPIO_setPortValue(PORT_A, LOW);
	for (int i = 0; i < PORT_SIZE; i++)
	{
		if(READ_BIT(PORT_A, i) == HIGH)
			return 0;
	}
	return 1;
}

uint8_t GPIO_pinToggle_test()
{
	GPIO_setPinValue(PORT_A, PIN_0, LOW);
	GPIO_pinToggle(PORT_A,PIN_0);
	if (GPIO_getPinValue(PORT_A, PIN_0) == HIGH)
		return 1;
	else
		return 0;
}


uint8_t GPIO_getPinValue_test()
{
	GPIO_setPinValue(PORT_A, PIN_0, HIGH);
	uint8_t value = GPIO_getPinValue(PORT_A, PIN_0);
	if (value == HIGH)
	return 1;
	else
	return 0;
}


uint8_t GPIO_getPortValue_test()
{
	GPIO_setPortValue(PORT_A, LOW);
	uint8_t value = GPIO_getPortValue(PORT_A);
	if (value == 0x0)
		return 1;
	else
		return 0;
}

