/*
 * RGB_Led.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#include "RGB_Led.h"


void RGB_Led_Init(const RGBLed_t led)
{
	TIMER_PWM_Initialize(led.Led);
	TIMER_PWM_Start(led.Led, led.Led.channel);
}

void RGB_Led_Set_Color(const RGBLed_t led, uint8_t red, uint8_t green,  uint8_t blue)
{
	uint8_t i=0;
	uint8_t channels[4] = {(led.Led.channel&0b0001), (led.Led.channel&0b0010), (led.Led.channel&0b0100), (led.Led.channel&0b1000)};
	red = (red / 255.0) * 100;
	green = (green / 255.0) * 100;
	blue = (blue / 255.0) * 100;

		if(!channels[i]){i++;}

		if(channels[i]){
			TIMER_PWM_DutyCycle(led.Led, channels[i], red);
			if(channels[i+1]){i++;}
			else{i+=2;}
		}
		if(channels[i]){
			TIMER_PWM_DutyCycle(led.Led, channels[i], green);
			if(channels[i+1]){i++;}
			else{i+=2;}
		}
		if(channels[i]){
			TIMER_PWM_DutyCycle(led.Led, channels[i], blue);
			i++;
		}
}
