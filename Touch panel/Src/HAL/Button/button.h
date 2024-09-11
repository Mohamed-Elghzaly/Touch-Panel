/*
 * button.h
 *
 *  Created on: Jul 6, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_

/**************** Includes ********************/
#include "../Src/MCAL/GPIO/GPIO.h"

/**************** Macro Declarations ********************/
/* Number of Button */
#define NUMBER_OF_BUTTON		3
/****************** button state *******************/
#define BUTTON_PRESSED			1
#define BUTTON_RELEASED			0


/**** Reading Counter *****/
#define MaxReadCounter		10

/********* Button Config **********/
#define ANALOG_MODE						0UL
#define FLOATING_INPUT					1UL
#define BUTTON_INPUT_PULL_UP_DOWN		2UL

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef struct{
	Pin_cfg_t btn;
	uint8_t PressedCounterBtn;
	uint8_t LastStateBtn;
}Button_t;
/**************** Software Interfaces Declaration ********************/
void Button_Init(const Button_t btn);
uint8_t Button_Read_State(const Button_t btn);



#endif /* HAL_BUTTON_BUTTON_H_ */
