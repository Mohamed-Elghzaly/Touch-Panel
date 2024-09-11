/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Abdallah Elghzaly
 * @brief          : Main program body
 ******************************************************************************
 */
#include "main.h"

int main(void)
{
	/* RCC initialization*/
	RCC_PLL_CLK(RCC_HSE, PLL_CLK_MUL_9);
	RCC_AHB_Prescaler(SYSCLK_NOT_DIV);
	RCC_APB2_Prescaler(HCLK_NOT_DIV);
	RCC_Enable_Peripheral_APB2(IOPAEN);
	RCC_Enable_Peripheral_APB2(IOPBEN);

	/* Systick initialization */
	Systick_Init(AHB_CLK);
	Systick_Ticks();


	/* Code */
	application();
//	/* Loop forever */
//	while(1)
//	{}
}

