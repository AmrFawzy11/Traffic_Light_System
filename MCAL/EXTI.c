/*
 * EXTI.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Shawky
 */
#include <avr/interrupt.h>
#include <avr/io.h>
#include "GPIO.h"
#include "std_types.h"
#include "common_macros.h"
#include "EXTI.h"
#include "EXTI_CFG.h"

#define NULL_PTR    ((void*)0)


static volatile void (*g_callBackPtrINT0)(void) = NULL_PTR;
static volatile void (*g_callBackPtrINT1)(void) = NULL_PTR;
static volatile void (*g_callBackPtrINT2)(void) = NULL_PTR;


ISR(INT0_vect)
{
	(*g_callBackPtrINT0)();
}

ISR(INT1_vect)
{
	(*g_callBackPtrINT1)();
}

ISR(INT2_vect)
{
	(*g_callBackPtrINT2)();
}

void SET_GlobalInterrupt(void)
{
	#if GLOBAL_INTERRUPT == GLOBAL_INTERRUPT_ENABLE
		SET_BIT(SREG,7);
	#elif
		CLEAR_BIT(SREG,7);
	#endif
}

void ExternalINT0_Init(void)
{
	SET_BIT(GICR,EXTERNAL_INT0);
	#if EXTERNAL_INT0_TRIGGER == INT0_TRIGGER_RISING_EDGE
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,0);
	#elif EXTERNAL_INT0_TRIGGER == INT0_TRIGGER_FALLING_EDGE
		SET_BIT(MCUCR,1);
		CLEAR_BIT(MCUCR,0);
	#elif EXTERNAL_INT0_TRIGGER == INT0_TRIGGER_LOW_LEVEL
		CLEAR_BIT(MCUCR,1);
		CLEAR_BIT(MCUCR,0);
	#elif EXTERNAL_INT0_TRIGGER == INT0_TRIGGER_ANY_LOGICAL_CHANGE
		SET_BIT(MCUCR,0);
		CLEAR_BIT(MCUCR,1);

	#endif

}

void ExternalINT1_Init(void)
{
	DIO_SetPinDir(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT);
	SET_BIT(GICR,EXTERNAL_INT1);
	#if EXTERNAL_INT1_TRIGGER == INT1_TRIGGER_RISING_EDGE
		SET_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	#elif EXTERNAL_INT1_TRIGGER == INT1_TRIGGER_FALLING_EDGE
		SET_BIT(MCUCR,3);
		CLEAR_BIT(MCUCR,2);
	#elif EXTERNAL_INT1_TRIGGER == INT1_TRIGGER_LOW_LEVEL
		CLEAR_BIT(MCUCR,2);
		CLEAR_BIT(MCUCR,3);
	#elif EXTERNAL_INT1_TRIGGER == INT1_TRIGGER_ANY_LOGICAL_CHANGE
		SET_BIT(MCUCR,2);
		CLEAR_BIT(MCUCR,3);

	#endif

}

void ExternalINT2_Init(void)
{
	SET_BIT(GICR,EXTERNAL_INT2);
	#if EXTERNAL_INT2_TRIGGER == INT2_TRIGGER_RISING_EDGE
		SET_BIT(MCUCSR,6);
	#elif EXTERNAL_INT0_TRIGGER == INT0_TRIGGER_FALLING_EDGE
		CLEAR_BIT(MCUCSR,6);
	#endif

}

void SetCallBackFunctionINT0(void (*a_ptr)(void))
{
	g_callBackPtrINT0 = a_ptr;
}
void SetCallBackFunctionINT1(void (*a_ptr)(void))
{
	g_callBackPtrINT1 = a_ptr;

}
void SetCallBackFunctionINT2(void (*a_ptr)(void))
{
	g_callBackPtrINT2 = a_ptr;

}



