/*
 * GPIO.h
 *
 * Created: 11/12/2022 02:58:35
 *  Author: es-HusseinMourad2024
 */ 


#ifndef GPIO_H_
#define GPIO_H_


#include "../../Utilities/types.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/register.h"

#define PUD  2

typedef enum{
	INPUT,
	INPUT_PULLUP,
	OUTPUT
} EN_Mode;

void GPIO_setPinMode(EN_Port port, EN_Pin pin, EN_Mode mode);
void GPIO_setPinValue(EN_Port port, EN_Pin pin, BOOL value);
void GPIO_setPortValue(EN_Port port, uint8_t value);
void GPIO_pinToggle(EN_Port port, EN_Pin pin);
uint8_t GPIO_getPinValue(EN_Port port, EN_Pin pin);
uint8_t GPIO_getPortValue(EN_Port port);


#endif /* GPIO_H_ */