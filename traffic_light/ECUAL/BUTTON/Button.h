/*
 * Button.h
 *
 * Created: 11/12/2022 03:32:31
 *  Author: es-HusseinMourad2024
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/EXINT/EXINT.h"
#include "../../MCAL/TIM0/TIM0.h"

//Types
typedef struct
{
	EN_Port Port;
	EN_Pin  Pin ;
} ST_Button;

typedef enum
{
	NOT_PRESSED,
	PRESSED
} EN_ButtonState;


void BUTTON_init(ST_Button* Ptr_stButton, EN_Port port, EN_Pin pin);
EN_ButtonState BUTTON_read(ST_Button* Ptr_stButton);

#endif /* BUTTON_H_ */