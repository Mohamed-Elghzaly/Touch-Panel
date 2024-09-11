/*
 * led.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */


#include "led.h"




void Led_Init(const Pin_cfg_t led){
	GPIO_Pin_Dir_Cfg(led);
}

void Led_On(const Pin_cfg_t led){
	GPIO_Pin_Set(led);
}

void Led_Off(const Pin_cfg_t led){
	GPIO_Pin_Clear(led);
}

void Led_Toggle(const Pin_cfg_t led){
	GPIO_Pin_Toggle(led);
}
