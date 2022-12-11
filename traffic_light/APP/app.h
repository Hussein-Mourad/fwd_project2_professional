/*
 * APP.h
 *
 * Created: 11/12/2022 03:27:18
 *  Author: es-HusseinMourad2024
 */ 


#ifndef APP_H_
#define APP_H_


#include "../Utilities/bit_manipulation.h"
#include "../Utilities/types.h"
#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/EXINT/EXINT.h"
#include "../MCAL/TIM0/TIM0.h"
#include "../ECUAL/LED/LED.h"
#include "../ECUAL/Button/Button.h"

//DEFINE PERIPHERALS PORT AND PINS
#define PEDASTRIAN_BUTTON_PORT   PORT_D
#define PEDASTRIAN_GREEN_PORT    PORT_A
#define PEDASTRIAN_YELLOW_PORT   PORT_A
#define PEDASTRIAN_RED_PORT      PORT_A
#define NORMAL_GREEN_PORT        PORT_B
#define NORMAL_YELLOW_PORT       PORT_B
#define NORMAL_RED_PORT          PORT_B

#define PEDASTRIAN_BUTTON_PIN    PIN_2
#define PEDASTRIAN_GREEN_PIN     PIN_0
#define PEDASTRIAN_YELLOW_PIN    PIN_1
#define PEDASTRIAN_RED_PIN       PIN_2
#define NORMAL_GREEN_PIN         PIN_0
#define NORMAL_YELLOW_PIN        PIN_1
#define NORMAL_RED_PIN           PIN_2

typedef enum
{
	PEDASTRIAN_LIGHT,
	NORMAL_LIGHT,
	BOTH_LIGHT
} TRAFFIC_TYPE;

//Pedestrian mode Component
ST_Button pedastrian_button;
ST_Led    pedastrian_grnLED;
ST_Led    pedastrian_ylwLED;
ST_Led    pedastrian_redLED;


//Normal mode Component
ST_Led    normal_redLED;
ST_Led    normal_grnLED;
ST_Led    normal_ylwLED;


void blink_yellow(TRAFFIC_TYPE traffic_type);
void normal_mode();
void pedastrain_mode();


void APP_init();
void APP_start();

#endif /* APP_H_ */