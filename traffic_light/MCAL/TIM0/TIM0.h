/*
 * TIM0.h
 *
 * Created: 11/12/2022 03:17:33
 *  Author: es-HusseinMourad2024
 */ 


#ifndef TIM0_H_
#define TIM0_H_

#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"
#include "../../Utilities/register.h"

//MACROS
#define TIM0_CS00    0
#define TIM0_CS01    1
#define TIM0_CS02    2
#define TIM0_WGM01   3
#define TIM0_COM00   4
#define TIM0_COM01   5
#define TIM0_WGM00   6
#define TIM0_FOC0    7

#define  TIFR_TOV0   0
#define  TIFR_OCF0   1


// CONFIGURATIONS
#define F_CPU        1000000U                //1Mz
#define TIM0_BITS    8
#define TIM0_MAX     256 * (1/F_CPU) * 1000

#define  TIM0_CLOCK_SOURCE  CLOCK_1_PRESCALER
#define  TIM0_MODE          TIM0_NORMAL
#define  TIM0_OC0_COMPARE   TIM0_CS0_DISCONNECTED

#if TIM0_CLOCK_SOURCE == CLOCK_1_PRESCALER
#define TIM0_PRESCALER  1
#elif TIM0_CLOCK_SOURCE == CLOCK_8_PRESCALER
#define TIM0_PRESCALER  8
#elif TIM0_CLOCK_SOURCE == CLOCK_64_PRESCALER
#define TIM0_PRESCALER  64
#elif TIM0_CLOCK_SOURCE == CLOCK_256_PRESCALER
#define TIM0_PRESCALER  256
#elif TIM0_CLOCK_SOURCE == CLOCK_1024_PRESCALER
#define TIM0_PRESCALER  1024
#endif

//TYPES
typedef enum
{
	NO_CLOCK_SOURCE,
	CLOCK_1_PRESCALER,
	CLOCK_8_PRESCALER,
	CLOCK_64_PRESCALER,
	CLOCK_256_PRESCALER,
	CLOCK_1024_PRESCALER,
	EXTERN_CLOCK_FALING,
	EXTERN_CLOCK_RAISING
} EN_TIM0_ClockSelect;

typedef enum
{
	TIM0_NORMAL,
	TIM0_PHASED_PWM,
	TIM0_CTC,
	TIM0_FAST_PWM
} EN_TIM0_ModeOperation;


typedef enum
{
	TIM0_CS0_DISCONNECTED,
	TIM0_CS0_TOGGLE,
	TIM0_CS0_CLEAR,
	TIM0_CS0_SET

}EN_TIM0_CompareOutput;


void TIM0_init();
void TIM0_setCompare(uint8_t compareValue);
uint8_t TIM0_getCompare();
void TIM0_setTIM0(uint8_t TIM0Value);
uint8_t TIM0_getTIM0();
void TIM0_delay_ms( uint32_t delay);
void TIM0_delay_steps(uint16_t base, uint16_t multi);


#endif /* TIM0_H_ */