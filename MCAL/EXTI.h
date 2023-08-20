/*
 * EXTI.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Shawky
 */

#ifndef EXTI_H_
#define EXTI_H_

#define GLOBAL_INTERRUPT_ENABLE						1
#define GLOBAL_INTERRUPT_DISABLE					0

#define EXTERNAL_INT0								6
#define EXTERNAL_INT1								7
#define EXTERNAL_INT2								5

#define INT0_TRIGGER_LOW_LEVEL						0
#define INT0_TRIGGER_RISING_EDGE					1
#define INT0_TRIGGER_FALLING_EDGE					2
#define INT0_TRIGGER_ANY_LOGICAL_CHANGE				3

#define INT1_TRIGGER_LOW_LEVEL						0
#define INT1_TRIGGER_RISING_EDGE					1
#define INT1_TRIGGER_FALLING_EDGE					2
#define INT1_TRIGGER_ANY_LOGICAL_CHANGE				3


#define INT2_TRIGGER_RISING_EDGE					1
#define INT2_TRIGGER_FALLING_EDGE					0


void SET_GlobalInterrupt(void);
void ExternalINT0_Init(void);
void ExternalINT1_Init(void);
void ExternalINT2_Init(void);

void SetCallBackFunctionINT0(void(*a_ptr)(void));
void SetCallBackFunctionINT1(void(*a_ptr)(void));
void SetCallBackFunctionINT2(void(*a_ptr)(void));




#endif /* EXTI_H_ */
