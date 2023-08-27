/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Omar Shawky
 */

#include <util/delay.h>
#include "GPIO.h"
#include "lcd.h"
#include "push_button.h"
#include "leds.h"
#include "EXTI.h"


int skip_delay = 0 ;
int Cars_mode = 0;
int button_pressed = 0 ;

void App(void);
void init(void);
void Yellow_Blink(void);
void Setflag(void);

uint8 DELAY_IN_SEC(uint8 s){
	return 4*s;
}

int main(void){

	init();

	while(1)
	{
		skip_delay = 0 ;

		if(button_pressed==1)
		{
			App();
		}

		else if(isGreen_ON()==1)
		{
			letGreen_OFF();
			Yellow_Blink();
			letYellow_ON();
			skip_delay = 1;
		}

		else if(isYellow_ON()==1)
		{
			letYellow_OFF();
			letRed_ON();
		}

		else if(isRed_ON()==1)
		{
			letRed_OFF();
			letGreen_ON();
		}

		else
		{

		}

        uint8 i;
		for( i=0 ; i<DELAY_IN_SEC(5) ; i++){
			if(skip_delay || button_pressed)
			{
				break ;
			}
			else
			{
				_delay_ms(250);

			}
		}
	}
}
void App(void){


	if(isGreen_ON()==1){
		letGreen_OFF();
		Yellow_Blink();
		letYellow_OFF();
	}

	else if(isYellow_ON()==1){
		Yellow_Blink();
		letYellow_OFF();
	}
	else{}

	letRed_ON();
	letBlue_ON();

	LCD_Clear();
	LCD_WriteString("Pedestrian");


	_delay_ms(5000);

	letBlue_OFF();
	letRed_OFF();

	letGreen_ON();

	LCD_Clear();
	LCD_WriteString("CARS");

	button_pressed = 0 ;

}

void init(void){
	Set_led_green();
	Set_led_yellow();
	Set_led_red();
	Set_led_blue();
	LCD_Init();
	LCD_WriteString("CARS");
	SetCallBackFunctionINT1(Setflag);
	SET_GlobalInterrupt();
	ExternalINT1_Init();
	letRed_ON();

}
void Yellow_Blink(void)
{
	uint8 i;
	for(i = 0 ; i<DELAY_IN_SEC(5);i++)
	{
		if(skip_delay==1)
		{
			break;
		}

		else if(isYellow_ON()==1){
			letYellow_OFF();
		}

		else if(isYellow_ON()==0)
		{
			letYellow_ON();
		}
		else{}

		_delay_ms(250);
	}
}
void Setflag(void)
{
	button_pressed = 1 ;
}

