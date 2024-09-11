/*
 * ws2812.c
 *
 *  Created on: Aug 23, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#include "ws2812.h"

static uint8_t LED_Data[LED_MAX][4];
static uint8_t LED_Mode[LED_MAX][4];	// for brightness
static uint16_t pwmData[(24 * LED_MAX) + 50];

void Set_LED(uint8_t LEDnum, uint8_t red, uint64_t green, uint8_t blue)
{
	LED_Data[LEDnum][0] = LEDnum;
	LED_Data[LEDnum][1] = green;
	LED_Data[LEDnum][2] = red;
	LED_Data[LEDnum][3] = blue;
}

/*
 LED_Mode[i][j] = LED_Data[i][j]*45/255.0


 */

void Set_Brightness(uint8_t Brightness)
{
#if USE_BRIGHTNESS
	if (Brightness > 45)
		Brightness = 45;
	for (uint16_t i = 0; i < LED_MAX; i++)
	{
		LED_Mode[i][0] = LED_Data[i][0];
		for (uint8_t j = 0; j < 4; j++)
		{
			float angle = 90 - Brightness; // in degree
			angle = angle * PI / 180; // in rad
			LED_Mode[i][j] = (LED_Data[i][j]) / (tan(angle));
		}
	}
#endif
}

void WS2812_Send(const WS2812_t _led)
{
	uint32_t index = 0;
	uint32_t color;
	for (uint16_t i = 0; i < LED_MAX; i++)
	{
		color = ((LED_Mode[i][1] << 16) | (LED_Mode[i][2] << 8)
				| (LED_Mode[i][3]));
		for (int8_t i = 23; i >= 0; i--)
		{
			if (color & (1 << i))
			{
				pwmData[index] = 60;
			}
			else
			{
				pwmData[index] = 30;
			}
			index++;
		}
	}
	for (uint8_t i = 0; i < 50; i++)
	{
		pwmData[index] = 0;
		index++;
	}
	TIMER_PWM_Start_DMA(_led.timer, _led.dma, _led.timer.channel,
			(uint32_t*) pwmData, index);
//	while(!dataSendFlag);
//	dataSendFlag=0;
}

uint16_t effStep = 0;
/***********************/
uint8_t rainbow_effiect_left(const WS2812_t _led)
{
	// Strip ID: 0 - Effect: Rainbow - LEDS: 8
	// Steps: 39 - Delay: 32
	// Colors: 3 (255.0.0, 0.255.0, 0.0.255)
	// Options: rainbowlen=11, toLeft=true,
//  if(millis() - strip_0.effStart < 32 * (strip_0.effStep)) return 0x00;
	float factor1, factor2;
	uint16_t ind;
	for (uint16_t j = 0; j < 8; j++)
	{
		ind = effStep + j * 3.5454545454545454;
		switch ((int) ((ind % 39) / 13))
		{
		case 0:
			factor1 = 1.0 - ((float) (ind % 39 - 0 * 13) / 13);
			factor2 = (float) ((int) (ind - 0) % 39) / 13;
			Set_LED(j, 255 * factor1 + 0 * factor2, 0 * factor1 + 255 * factor2,
					0 * factor1 + 0 * factor2);
			WS2812_Send(_led);
			break;
		case 1:
			factor1 = 1.0 - ((float) (ind % 39 - 1 * 13) / 13);
			factor2 = (float) ((int) (ind - 13) % 39) / 13;
			Set_LED(j, 0 * factor1 + 0 * factor2, 255 * factor1 + 0 * factor2,
					0 * factor1 + 255 * factor2);
			WS2812_Send(_led);
			break;
		case 2:
			factor1 = 1.0 - ((float) (ind % 39 - 2 * 13) / 13);
			factor2 = (float) ((int) (ind - 26) % 39) / 13;
			Set_LED(j, 0 * factor1 + 255 * factor2, 0 * factor1 + 0 * factor2,
					255 * factor1 + 0 * factor2);
			WS2812_Send(_led);
			break;
		}
	}
	if (effStep >= 39)
	{
		effStep = 0;
		return 0x03;
	}
	else
		effStep++;
	return 0x01;
}
