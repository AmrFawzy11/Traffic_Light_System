/*
 * lcd.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Shawky
 */

#ifndef LCD_H_
#define LCD_H_

#include "lcd_cfg.h"
#include "std_types.h"


/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80

void LCD_Init(void);

void LCD_WriteCommand(uint8 cmd);

void LCD_Writechar(uint8 chr);

void LCD_WriteString(uint8 *str);

void LCD_Clear(void);

void LCD_intgerToString(uint32 data);


#endif /* LCD_H_ */
