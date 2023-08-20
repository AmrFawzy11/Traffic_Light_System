/*
 * lcd_cfg.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Shawky
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "GPIO.h"

#define LCD_MODE			4

#define	LCD_CMD_PORTID		DIO_PORTA
#define LCD_DATA_PORTID		DIO_PORTB

#define	LCD_D4				DIO_PIN0
#define	LCD_D5				DIO_PIN1
#define	LCD_D6				DIO_PIN2
#define	LCD_D7				DIO_PIN4

#define LCD_RS				DIO_PIN3
#define LCD_EN				DIO_PIN2




#endif /* LCD_CFG_H_ */
