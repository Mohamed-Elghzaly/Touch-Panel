/*
 * button.c
 *
 *  Created on: Jul 6, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#include "button.h"



void Button_Init(const Button_t _btn){
	GPIO_Pin_Dir_Cfg(_btn.btn);
}


uint8_t Button_Read_State(const Button_t _btn)
{
	static uint8_t LastState[NUMBER_OF_BUTTON] = {BUTTON_RELEASED};
	static uint8_t PressedCounter[NUMBER_OF_BUTTON] = {0};
	uint8_t returnState = BUTTON_RELEASED;

	if((GPIO_Pin_Read(_btn.btn) == BUTTON_PRESSED))
	{
		if(LastState[_btn.LastStateBtn] == BUTTON_PRESSED)
		{
			PressedCounter[_btn.PressedCounterBtn]++;
		}
		else
		{
			LastState[_btn.LastStateBtn] = BUTTON_PRESSED;
			PressedCounter[_btn.PressedCounterBtn] = 0;
		}
		returnState = BUTTON_RELEASED;
	}
	else
	{
		if(PressedCounter[_btn.PressedCounterBtn] >= MaxReadCounter)
		{
			PressedCounter[_btn.PressedCounterBtn] = 0;
			LastState[_btn.LastStateBtn] = BUTTON_RELEASED;
			returnState = BUTTON_PRESSED;
		}
		else
		{
			PressedCounter[_btn.PressedCounterBtn] = 0;
			LastState[_btn.LastStateBtn] = BUTTON_RELEASED;
			returnState = BUTTON_RELEASED;
		}
	}
	return returnState;
}


