/*
 * lcd.c
 *
 *  Created on: Aug 18, 2023
 *      Author: Shawky
 */
#include <util/delay.h>
#include "GPIO.h"
#include "lcd_cfg.h"
#include "common_macros.h"
#include "lcd.h"



void LCD_Init(void)
{
	DIO_SetPinDir(LCD_CMD_PORTID,LCD_RS,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_CMD_PORTID,LCD_EN,DIO_PIN_OUTPUT);

	_delay_ms(20);

	DIO_SetPinDir(LCD_DATA_PORTID,LCD_D4,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_DATA_PORTID,LCD_D5,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_DATA_PORTID,LCD_D6,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_DATA_PORTID,LCD_D7,DIO_PIN_OUTPUT);

	LCD_WriteCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_WriteCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	LCD_WriteCommand(LCD_TWO_LINES_FOUR_BITS_MODE);


	LCD_WriteCommand(LCD_CURSOR_OFF);
	LCD_WriteCommand(LCD_CLEAR_COMMAND);
	LCD_WriteCommand(0x0F);
}

void LCD_WriteCommand(uint8 cmd)
{

	DIO_SetPinVal(LCD_CMD_PORTID,LCD_RS,LOGIC_LOW);
	_delay_ms(1);
	DIO_SetPinVal(LCD_CMD_PORTID,LCD_EN,LOGIC_HIGH);
	_delay_ms(1);

	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D4,GET_BIT(cmd,4));
	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D5,GET_BIT(cmd,5));
	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D6,GET_BIT(cmd,6));
	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D7,GET_BIT(cmd,7));



	DIO_SetPinVal(LCD_CMD_PORTID,LCD_EN,LOGIC_LOW);
	DIO_SetPinVal(LCD_CMD_PORTID,LCD_EN,LOGIC_HIGH);
	_delay_ms(1);


	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D4,GET_BIT(cmd,0));
	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D5,GET_BIT(cmd,1));
	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D6,GET_BIT(cmd,2));
	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D7,GET_BIT(cmd,3));



	DIO_SetPinVal(LCD_CMD_PORTID,LCD_EN,LOGIC_LOW);


}

void LCD_Writechar(uint8 chr)
{
	DIO_SetPinVal(LCD_CMD_PORTID,LCD_RS,LOGIC_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_CMD_PORTID,LCD_EN,LOGIC_HIGH);
	_delay_ms(1);





	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D4,GET_BIT(chr,4));
	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D5,GET_BIT(chr,5));
	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D6,GET_BIT(chr,6));
	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D7,GET_BIT(chr,7));

	DIO_SetPinVal(LCD_CMD_PORTID,LCD_EN,LOGIC_LOW);
	DIO_SetPinVal(LCD_CMD_PORTID,LCD_EN,LOGIC_HIGH);
	_delay_ms(1);


	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D4,GET_BIT(chr,0));
	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D5,GET_BIT(chr,1));
	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D6,GET_BIT(chr,2));
	DIO_SetPinVal(LCD_DATA_PORTID,LCD_D7,GET_BIT(chr,3));


	DIO_SetPinVal(LCD_CMD_PORTID,LCD_EN,LOGIC_LOW);

}

void LCD_WriteString(uint8 *str)
{
	uint8 i=0;
	while(str[i] != '\0')
	{
		LCD_Writechar(str[i]);
		i++;
	}
}
/*
void LCD_intgerToString(uint32 data)
{
   char buff[16];
   itoa(data,buff,10);
   LCD_WriteString(buff);
}*/
void LCD_Clear(void)
{
	LCD_WriteCommand(LCD_CLEAR_COMMAND);
}








