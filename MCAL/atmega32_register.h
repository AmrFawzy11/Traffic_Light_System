/*
 * atmega32_register.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Shawky
 */

#ifndef MCAL_ATMEGA32_REGISTER_H_
#define MCAL_ATMEGA32_REGISTER_H_

#define PORTA  (*(volatile int*)0x3B)
#define DDRA   (*(volatile int*)0x3A)
#define PINA   (*(volatile int*)0x39)

#define PORTB  (*(volatile int*)0x38)
#define DDRB   (*(volatile int*)0x37)
#define PINB   (*(volatile int*)0x36)

#define PORTC  (*(volatile int*)0x35)
#define DDRC   (*(volatile int*)0x34)
#define PINC   (*(volatile int*)0x33)

#define PORTD  (*(volatile int*)0x32)
#define DDRD   (*(volatile int*)0x31)
#define PIND   (*(volatile int*)0x30)

#endif /* MCAL_ATMEGA32_REGISTER_H_ */
