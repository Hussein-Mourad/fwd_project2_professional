/*
 * Button.c
 *
 * Created: 11/12/2022 03:32:37
 *  Author: es-HusseinMourad2024
 */ 


#include "Button.h"


void BUTTON_init(ST_Button* Ptr_stButton, EN_Port port, EN_Pin pin)
{
	Ptr_stButton->Port = port;
	Ptr_stButton->Pin  = pin;
	GPIO_setPinMode(Ptr_stButton->Port, Ptr_stButton->Pin, INPUT);

}


EN_ButtonState BUTTON_read(ST_Button* Ptr_stButton)
{
	return GPIO_getPinValue(Ptr_stButton->Port, Ptr_stButton->Pin);
}