/*
 * GPIO.c
 *
 * Created: 11/12/2022 02:58:44
 *  Author: es-HusseinMourad2024
 */ 

#include "GPIO.h"

void GPIO_setPinMode(EN_Port port, EN_Pin pin, EN_Mode mode)
{
	switch(port)
	{
		case PORT_A:
		if( mode == INPUT)
		{
			CLR_BIT(DDRA, pin);
		}
		else if ( mode == INPUT_PULLUP)
		{
			CLR_BIT(DDRA, pin);
			SET_BIT(SFIOR, PUD);
		}
		else
		{
			SET_BIT(DDRA, pin);
		}
		break;
		
		case PORT_B:
		if( mode == INPUT)
		{
			CLR_BIT(DDRB, pin);
		}
		else if ( mode == INPUT_PULLUP)
		{
			CLR_BIT(DDRB, pin);
			SET_BIT(SFIOR, PUD);
		}
		else
		{
			SET_BIT(DDRB, pin);
		}
		break;
		case PORT_C:
		if( mode == INPUT)
		{
			CLR_BIT(DDRC, pin);
		}
		else if ( mode == INPUT_PULLUP)
		{
			CLR_BIT(DDRC, pin);
			SET_BIT(SFIOR, PUD);
		}
		else
		{
			SET_BIT(DDRC, pin);
		}
		break;
		case PORT_D:
		if( mode == INPUT)
		{
			CLR_BIT(DDRD, pin);
		}
		else if ( mode == INPUT_PULLUP)
		{
			CLR_BIT(DDRD, pin);
			SET_BIT(SFIOR, PUD);
		}
		else
		{
			SET_BIT(DDRD, pin);
		}
		break;
		
		default:
		break;
		
	}
}

void GPIO_setPinValue(EN_Port port, EN_Pin pin, BOOL value)
{
	switch(port)
	{
		case PORT_A:
		if(value == LOW)
		CLR_BIT(PORTA, pin);
		else
		SET_BIT(PORTA, pin);
		break;
		
		case PORT_B:
		if(value == LOW)
		CLR_BIT(PORTB, pin);
		else
		SET_BIT(PORTB, pin);
		break;
		
		case PORT_C:
		if(value == LOW)
		CLR_BIT(PORTC, pin);
		else
		SET_BIT(PORTC, pin);
		break;
		
		case PORT_D:
		if(value == LOW)
		CLR_BIT(PORTD, pin);
		else
		SET_BIT(PORTD, pin);
		break;
		
		default:
		break;
	}
}

void GPIO_setPortValue(EN_Port port, uint8_t value)
{
	switch(port)
	{
		case PORT_A:
		for(int i=0; i<PORT_SIZE ; i++)
		{
			if(READ_BIT(value, i))
			SET_BIT(PORTA, i);
			else
			CLR_BIT(PORTA, i);
		}
		break;
		
		case PORT_B:
		for(int i=0; i<PORT_SIZE ; i++)
		{
			if(READ_BIT(value, i))
			SET_BIT(PORTB, i);
			else
			CLR_BIT(PORTB, i);
		}
		break;
		
		
		case PORT_C:
		for(int i=0; i<PORT_SIZE ; i++)
		{
			if(READ_BIT(value, i))
			SET_BIT(PORTC, i);
			else
			CLR_BIT(PORTC, i);
		}
		break;
		case PORT_D:
		for(int i=0; i<PORT_SIZE ; i++)
		{
			if(READ_BIT(value, i))
			SET_BIT(PORTD, i);
			else
			CLR_BIT(PORTD, i);
		}
		break;
		
		default:
		break;
	}

}

void GPIO_pinToggle(EN_Port port, EN_Pin pin)
{
	switch(port)
	{
		case PORT_A:
		TOGGLE_BIT(PORTA, pin);
		break;
		
		case PORT_B:
		TOGGLE_BIT(PORTB, pin);
		break;
		
		case PORT_C:
		TOGGLE_BIT(PORTC, pin);
		break;
		
		case PORT_D:
		TOGGLE_BIT(PORTD, pin);
		break;
		
		default:
		break;
	}
	
}


uint8_t GPIO_getPinValue(EN_Port port, EN_Pin pin)
{

	uint8_t value  = 0 ;
	switch(port)
	{
		case PORT_A:
		value = READ_BIT(PINA, pin);
		break;
		
		case PORT_B:
		value = READ_BIT(PINB, pin);
		break;
		
		case PORT_C:
		value = READ_BIT(PINC, pin);
		break;
		
		case PORT_D:
		value = READ_BIT(PIND, pin);
		break;
		
		default:
		break;
	}
	return value;
}


uint8_t GPIO_getPortValue(EN_Port port)
{
	uint8_t value  = 0 ;
	switch(port)
	{
		case PORT_A:
		for(int i=0; i<PORT_SIZE; i++)
		value |= (READ_BIT(PINA, i) << i);
		break;
		
		case PORT_B:
		for(int i=0; i<PORT_SIZE; i++)
		value |= (READ_BIT(PINB, i) << i);
		break;
		
		case PORT_C:
		for(int i=0; i<PORT_SIZE; i++)
		value |= (READ_BIT(PINC, i) << i);
		break;
		
		case PORT_D:
		for(int i=0; i<PORT_SIZE; i++)
		value |= (READ_BIT(PIND, i) << i);
		break;
		
		default:
		break;
	}
	return value;
}
