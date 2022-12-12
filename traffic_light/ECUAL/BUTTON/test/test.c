/*
 * test.c
 *
 * Created: 12/12/2022 03:42:06
 *  Author: es-HusseinMourad2024
 */ 

#include "../../../Utilities/bit_manipulation.h"
#include "../../../Utilities/register.h"
#include "../../../Utilities/Types.h"
#include "../Button.h"

uint8_t BUTTON_init_test()
{
	ST_Button button;
	BUTTON_init(&button, PORT_A, PIN_0);
	if (READ_BIT(DDRA,PIN_0)==0)
		return 1;
	else
		return 0;
}


EN_ButtonState BUTTON_read_test(ST_Button* Ptr_stButton)
{
	ST_Button button;
	BUTTON_init(&button, PORT_A, PIN_0);
	uint8_t value = BUTTON_read(&button);
	return !value; // button is not pressed
}