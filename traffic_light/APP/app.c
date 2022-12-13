/*
 * app.c
 *
 * Created: 11/12/2022 03:27:05
 *  Author: es-HusseinMourad2024
 */ 


#include "app.h"


void APP_init()
{
	EXINIT_init(EXINT_INT0, RISING_EDGE);          
	BUTTON_init(&pedastrian_button, PEDASTRIAN_BUTTON_PORT, PEDASTRIAN_BUTTON_PIN );
	
	LED_init(&pedastrian_grnLED, PEDASTRIAN_GREEN_PORT, PEDASTRIAN_GREEN_PIN);
	LED_init(&pedastrian_ylwLED, PEDASTRIAN_YELLOW_PORT, PEDASTRIAN_YELLOW_PIN);
	LED_init(&pedastrian_redLED, PEDASTRIAN_RED_PORT, PEDASTRIAN_RED_PIN);
	LED_init(&normal_grnLED    , NORMAL_GREEN_PORT, NORMAL_GREEN_PIN);
	LED_init(&normal_ylwLED    , NORMAL_YELLOW_PORT, NORMAL_YELLOW_PIN);
	LED_init(&normal_redLED    , NORMAL_RED_PORT, NORMAL_RED_PIN);

}

void APP_start()
{
	while (1)
	{
		normal_mode();
	}
}

ISR(INT0_vect)
{
	pedastrain_mode();
}


void blink_yellow(TRAFFIC_TYPE traffic_type)
{
	// Blink for 5 sec
	for(int i=0; i<5; i++)
	{
		switch(traffic_type)
		{
			case PEDASTRIAN_LIGHT:
				LED_on(&pedastrian_ylwLED);
				break;
			case NORMAL_LIGHT:
				LED_on(&normal_ylwLED);
				break;
			case BOTH_LIGHT:
				LED_on(&pedastrian_ylwLED);
				LED_on(&normal_ylwLED);
			default:
				break;
		}

		TIM0_delay_ms(500);
	
		switch(traffic_type)
		{
			case PEDASTRIAN_LIGHT:
				LED_off(&pedastrian_ylwLED);
				break;
			case NORMAL_LIGHT:
				LED_off(&normal_ylwLED);
				break;
			case BOTH_LIGHT:
				LED_off(&pedastrian_ylwLED);
				LED_off(&normal_ylwLED);
			default:
				break;
		}

		TIM0_delay_ms(500);
	}
}


void normal_mode()
{
	LED_on(&normal_grnLED);
	TIM0_delay_ms(5000);
	LED_off(&normal_grnLED);
	
	blink_yellow(NORMAL_LIGHT);
	LED_off(&normal_ylwLED);
		
	LED_on(&normal_redLED);
	TIM0_delay_ms(5000);
	LED_off(&normal_redLED);
	
	blink_yellow(NORMAL_LIGHT);
	LED_off(&normal_ylwLED);	
}

void pedastrain_mode()
{
	if (LED_read(&normal_redLED))
	{
		LED_on(&pedastrian_grnLED);
		LED_on(&normal_redLED);
		
		TIM0_delay_ms(5000);

		LED_off(&pedastrian_grnLED);

		
	}
	else if (LED_read(&normal_grnLED))
	{
		LED_on(&pedastrian_redLED);
		LED_on(&normal_grnLED);
		
		TIM0_delay_ms(5000);

		LED_off(&pedastrian_redLED);
		LED_off(&normal_grnLED);
		
		 blink_yellow(BOTH_LIGHT);
		
		LED_on(&normal_redLED);
		LED_on(&pedastrian_grnLED);
		
		TIM0_delay_ms(5000);
		
		LED_off(&pedastrian_grnLED);
		LED_off(&normal_redLED);
		LED_on(&normal_grnLED);
	
	}
	else
	{
		blink_yellow(BOTH_LIGHT);
		
		LED_on(&normal_redLED);
		LED_on(&pedastrian_grnLED);
		
		TIM0_delay_ms(5000);
		
		LED_off(&pedastrian_grnLED);
		LED_off(&normal_redLED);
	}
}


