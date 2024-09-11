/*
 * RGB_Led.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef HAL_RGB_LED_RGB_LED_H_
#define HAL_RGB_LED_RGB_LED_H_



/**************** Includes ********************/
#include "../Src/MCAL/GPIO/GPIO.h"
#include "../Src/MCAL/TIMERS/timer.h"
/**************** Macro Declarations ********************/

/**************/
typedef enum{
	RGB_RED,
	RGB_GREEN,
    RGB_BLUE
}RGB_Pin_t;

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef struct{
	Timer_PWM_t Led;
}RGBLed_t;

/**************** Software Interfaces Declaration ********************/
void RGB_Led_Init(const RGBLed_t led);
void RGB_Led_Set_Color(const RGBLed_t led, uint8_t red, uint8_t green,  uint8_t blue);
//void RGB_Led_Set_Brightness(const Pin_cfg_t *led);
//void Led_Toggle(const Pin_cfg_t *led);


#endif /* HAL_RGB_LED_RGB_LED_H_ */
