/*
 * test.c
 *
 * Created: 12/12/2022 03:42:06
 *  Author: es-HusseinMourad2024
 */ 

#include "../../../Utilities/bit_manipulation.h"
#include "../../../Utilities/register.h"
#include "../../../Utilities/Types.h"
#include "../EXINT.h"

uint8_t EXINIT_init_test()
{
	EXINIT_init(EXINT_INT0, RISING_EDGE);
	if (READ_BIT(MCUCR, RISING_EDGE) == RISING_EDGE)
		return 1;
	else
		return 0;
}


uint8_t EXINIT_disable_test()
{
	EXINIT_init(EXINT_INT0, RISING_EDGE);
	EXINIT_disable(EXINT_INT0);
	if (READ_BIT(GICR, INT0) == 0)
		return 1;
	else
		return 0;
	
}