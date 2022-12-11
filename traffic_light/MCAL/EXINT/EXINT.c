/*
 * EXINT.c
 *
 * Created: 11/12/2022 03:13:15
 *  Author: es-HusseinMourad2024
 */ 

#include "../../Utilities/register.h"
#include "EXINT.h"

void EXINIT_init(EXINT_Interrupt extInt, EXINIT_Type intType)
{
	SET_BIT(SREG, I);          // Enable Global Interrupt

	switch(extInt)
	{
		case EXINT_INT0:
		if (READ_BIT(intType, ISC0))
		SET_BIT(MCUCR, ISC00);
		else
		CLR_BIT(MCUCR, ISC00);

		if (READ_BIT(intType, ISC1))
		SET_BIT(MCUCR, ISC01);
		else
		CLR_BIT(MCUCR, ISC01);
		SET_BIT(GICR, INT0);
		break;

		case EXINT_INT1:
		if (READ_BIT(intType, ISC0))
		SET_BIT(MCUCR, ISC10);
		else
		CLR_BIT(MCUCR, ISC10);

		if (READ_BIT(intType, ISC1))
		SET_BIT(MCUCR, ISC11);
		else
		CLR_BIT(MCUCR, ISC11);
		SET_BIT(GICR, INT1);
		break;
		
		case EXINT_INT2:
		if (READ_BIT(intType, ISC1))
		SET_BIT(MCUCSR, ISC2);
		else
		CLR_BIT(MCUCSR, ISC2);
		SET_BIT(GICR, INT2);
		break;
		default:
		break;
	}	
}


void EXINIT_disable(EXINT_Interrupt extInt)
{
	switch(extInt)
	{
		case EXINT_INT0:
		CLR_BIT(GICR, INT0);
		break;
		case EXINT_INT1:
		CLR_BIT(GICR, INT1);
		break;
		case EXINT_INT2:
		CLR_BIT(GICR, INT2);
		break;
		default:
		break;
	}
}
