/*
 * ws2812.h
 *
 *  Created on: Aug 23, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef HAL_WS2812_WS2812_H_
#define HAL_WS2812_WS2812_H_

/**************** Includes ********************/
#include "../Src/MCAL/GPIO/Pins.h"
#include "../Src/MCAL/TIMERS/timer.h"
#include "../Inc/Common.h"
/**************** Macro Declarations ********************/
#define LED_MAX				8U
#define LED_BRIGHTNESS		1U
#define USE_BRIGHTNESS		1U

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef struct
{
	Timer_PWM_t timer;
	DMA_t dma;
} WS2812_t;
/**************** Software Interfaces Declaration ********************/
void Set_LED(uint8_t LEDnum, uint8_t red, uint64_t green, uint8_t blue);
void Set_Brightness(uint8_t Brightness);
void WS2812_Send(const WS2812_t _led);
uint8_t rainbow_effiect_left(const WS2812_t _led);

#endif /* HAL_WS2812_WS2812_H_ */

/*
 Set_LED(0, 100, 255, 90);
 Set_LED(1, 98, 23, 45);
 Set_LED(2, 111, 21, 123);
 Set_LED(3, 222, 28, 98);
 Set_LED(4, 100, 255, 52);
 Set_LED(5, 169, 254, 125);
 Set_LED(6, 100, 19, 147);
 Set_LED(7, 135, 244, 90);
 Set_Brightness(45);
 WS2812_Send(WS2812_1);
 */
