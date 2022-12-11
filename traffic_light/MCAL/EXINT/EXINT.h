/*
 * EXINT.h
 *
 * Created: 11/12/2022 03:12:41
 *  Author: es-HusseinMourad2024
 */ 


#ifndef EXINT_H_
#define EXINT_H_

#include "../../Utilities/types.h"
#include "../../Utilities/bit_manipulation.h"

// MACROS
#define ISC0  0
#define ISC1  1

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2  6

#define INT0  6
#define INT1  7
#define INT2  5


#define ISR(vector, ...)   void vector (void) __attribute__ ((signal,used)) __VA_ARGS__;  void vector (void)
#define INT0_vect            __vector_1
#define INT1_vect            __vector_2
#define INT2_vect            __vector_3


//TYPES
typedef enum
{
	EXINT_INT0,
	EXINT_INT1,
	EXINT_INT2

} EXINT_Interrupt;

typedef enum
{
	LOW_LEVEL,
	CHANGE_EDGE,
	FALLING_EDGE,
	RISING_EDGE
} EXINIT_Type;


void EXINIT_init(EXINT_Interrupt extInt, EXINIT_Type intType);
void EXINIT_disable(EXINT_Interrupt extInt);


#endif /* EXINT_H_ */