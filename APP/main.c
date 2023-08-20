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


#define DELAY_IN_SEC(s)  4*s

/* flag used to skip delay when it's on */
int skip_delay = 0 ;

/* flag set to (1) when we are in car mode and set to (0) in case of Pedestrian mode */
int Cars_mode = 0;

/* flag set to (1) when the button is pressed and (0) otherwise */
int button_pressed = 0 ;

void App(void);
void init(void);
void Yellow_Blink(void);
void Setflag(void);


int main(void){

	/* initialize our peripherals (LEDs, LCD and EXTi) */
	init();

	while(1)
	{	
		skip_delay = 0 ;

		if(button_pressed)
		{	
			App();
		}

		/* switch from green light to yellow light */
		else if(isGreen_ON())
		{
			letGreen_OFF();
			Yellow_Blink();
			letYellow_ON();
			skip_delay = 1;
		}

		/* switch from yellow light to red light */
		else if(isYellow_ON())
		{
			letYellow_OFF();
			letRed_ON();
		}

		/* switch from red light to green light */
		else if(isRed_ON())
		{
			letRed_OFF();
			letGreen_ON();
		}

		else
		{
			/* Error */
		}

		/* 5 seconds delay */
		for(int i=0 ; i<DELAY_IN_SEC(5) ; i++){
			if(skip_delay || button_pressed)
				break ;
			_delay_ms(250);
		}
	}
}
void App(void){

	/* when the button is pressed if the green light is on then switch to the yellow light */
	if(isGreen_ON()){
		letGreen_OFF();
		Yellow_Blink();
		letYellow_OFF();
	}
		
	/* when the button is pressed if yellow light is on then keep blinking */
	else if(isYellow_ON()){
		Yellow_Blink();
		letYellow_OFF();
	}

	/* turn on both red and blue lights and display Pedestrian on the LCD for 5 seconds*/
	letRed_ON();
	letBlue_ON();

	LCD_Clear();
	LCD_WriteString("Pedestrian");


	_delay_ms(5000);

	/* after 5 seconds turn off both red and blue lights*/
	letBlue_OFF();
	letRed_OFF();

	/* turn on the green light and display CARS on the LCD */
	letGreen_ON();

	LCD_Clear();
	LCD_WriteString("CARS");

	/* clear the falg */
	button_pressed = 0 ;

}

/* initialize our peripherals (LEDs, LCD and EXTi) */
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

/* function that  blinks the yellow light */
void Yellow_Blink(void)
{
	uint8 i;
	for(i = 0 ; i<DELAY_IN_SEC(5);i++)
	{
		if(skip_delay)
			break;

		if(isYellow_ON())
		letYellow_OFF();

		else if(!isYellow_ON())
			letYellow_ON();

		_delay_ms(250);
	}
}

/* function to set the flag when the button is pressed */ 
void Setflag(void)
{
	button_pressed = 1 ;
}

