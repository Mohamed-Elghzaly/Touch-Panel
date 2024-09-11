/*
 * led.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

/**************** Includes ********************/
#include "../Src/MCAL/GPIO/GPIO.h"

/**************** Macro Declarations ********************/
/****************** led state *******************/
#define LED_ON			0
#define LED_OFF			1

/********* led Config **********/
#define ANALOG_MODE						0UL
#define FLOATING_INPUT					1UL
#define LED_INPUT_PULL_UP_DOWN		2UL

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/

/**************** Software Interfaces Declaration ********************/
void Led_Init(const Pin_cfg_t led);
void Led_On(const Pin_cfg_t led);
void Led_Off(const Pin_cfg_t led);
void Led_Toggle(const Pin_cfg_t led);



#endif /* HAL_LED_LED_H_ */
