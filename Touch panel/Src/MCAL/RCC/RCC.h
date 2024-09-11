/*
 * RCC.h
 *
 *  Created on: Jul 2, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef RCC_RCC_H_
#define RCC_RCC_H_

/**************** Includes ********************/
#include <stdint.h>
#include "RCC_cfg.h"
#include "RCC_private.h"
#include "../Inc/Common.h"

/**************** Macro Declarations ********************/

/************************* Clock Source ***********************************/
#define AHB		0
#define APB2	1
#define APB1	2


/**************** Macro Function Declarations ********************/

/************** PLL Clock Source ******************/
#define HSI_OSC_DIV_2_PLL_CLK		0
#define HSE_OSC_PLL_CLK				1

/**************  AHB prescaler ********************/
#define	SYSCLK_NOT_DIV			0b0000
#define	SYSCLK_DIV_BY_2			0b1000
#define	SYSCLK_DIV_BY_4			0b1001
#define	SYSCLK_DIV_BY_8			0b1010
#define	SYSCLK_DIV_BY_16		0b1011
#define	SYSCLK_DIV_BY_64		0b1100
#define	SYSCLK_DIV_BY_128		0b1101
#define	SYSCLK_DIV_BY_256		0b1110
#define	SYSCLK_DIV_BY_512		0b1111

/**************************** APB2 prescaler & APB1 prescaler  ***********************************/
#define HCLK_NOT_DIV		0b000
#define HCLK_DIV_BY_2		0b100
#define HCLK_DIV_BY_4		0b101
#define HCLK_DIV_BY_8		0b110
#define HCLK_DIV_BY_16		0b111

/********** MCO clock source ************/
#define MCO_NO_CLOCK				0B000
#define MCO_SYSTEM_CLOCK			0B100
#define MCO_HSI_SELECTED			0B101
#define MCO_HSE_SELECTED			0B110
#define MCO_PLL_SELECTED			0B111

/********************* AHB peripheral clock enable register ***************/
#define SDIOEN		10
#define FSMCEN		8
#define CRCEN		6
#define FLITFEN		4
#define SRAMEN		2
#define DMA2EN		1
#define DMA1EN		0

/********************** APB2 peripheral clock enable register ***********************/
#define TIM11EN		21
#define TIM10EN		20
#define TIM9EN		19
#define ADC3EN		15
#define USART1EN	14
#define TIM8EN		13
#define SPI1EN		12
#define TIM1EN		11
#define ADC2EN		10
#define ADC1EN		9
#define IOPGEN		8
#define IOPFEN		7
#define IOPEEN		6
#define IOPDEN		5
#define IOPCEN		4
#define IOPBEN		3
#define IOPAEN		2
#define AFIOEN		0

/********************** APB1 peripheral clock enable register ***********************/
#define DACEN		29
#define PWREN		28
#define BKPEN		27
#define CANEN		25
#define USBEN		23
#define I2C2EN		22
#define I2C1EN		21
#define UART5EN		20
#define UART4EN		19
#define USART3EN	18
#define USART2EN	17
#define SPI3EN		15
#define SPI2EN		14
#define WWDGEN		11
#define TIM14EN		8
#define TIM13EN		7
#define TIM12EN		6
#define TIM7EN		5
#define TIM6EN		4
#define TIM5EN		3
#define TIM4EN		2
#define TIM3EN		1
#define TIM2EN		0

/**************** Data Type Declaration ********************/
typedef enum{
	RCC_HSI,
	RCC_HSE
}clockType_t;

typedef enum{
	PLL_CLK_MUL_2,
	PLL_CLK_MUL_3,
	PLL_CLK_MUL_4,
	PLL_CLK_MUL_5,
	PLL_CLK_MUL_6,
	PLL_CLK_MUL_7,
	PLL_CLK_MUL_8,
	PLL_CLK_MUL_9,
	PLL_CLK_MUL_10,
	PLL_CLK_MUL_11,
	PLL_CLK_MUL_12,
	PLL_CLK_MUL_13,
	PLL_CLK_MUL_14,
	PLL_CLK_MUL_15,
	PLL_CLK_MUL_16
}PLL_Multiplication;

/**************** Software Interfaces Declaration ********************/
/*
 * @brief : HSE as main clock
 */
void RCC_HSE_CLK(void);
/*
 * @brief : HSI as main clock
 */
void RCC_HSI_CLK(void);
/*
 * @brief : PLL as main clock
 */
void RCC_PLL_CLK(clockType_t clk, PLL_Multiplication value);


/*
 * @brief : Set APB2 Prescaler
 */
void RCC_APB2_Prescaler (uint32_t value);
/*
 * @brief : Set APB1 Prescaler
 */
void RCC_APB1_Prescaler (uint32_t value);
/*
 * @brief : Set AHP Prescaler
 */
void RCC_AHB_Prescaler (uint32_t value);


/*
 * @brief : Enable Peripheral on AHB bus
 */
void RCC_Enable_Peripheral_AHB(uint32_t peripheral);
/*
 * @brief : Enable Peripheral on APB2 bus
 */
void RCC_Enable_Peripheral_APB2(uint32_t peripheral);
/*
 * @brief : Enable Peripheral on APB1 bus
 */
void RCC_Enable_Peripheral_APB1(uint32_t peripheral);


/*
 * @brief : Disable Peripheral on AHB bus
 */
void RCC_Disable_Peripheral_AHB(uint32_t peripheral);
/*
 * @brief : Disable Peripheral on APB2 bus
 */
void RCC_Disable_Peripheral_APB2(uint32_t peripheral);
/*
 * @brief : Disable Peripheral on APB1 bus
 */
void RCC_Disable_Peripheral_APB1(uint32_t peripheral);


/*
 * @brief : Enable MCO clock
 */
void RCC_MCO_CLK(uint8_t clk);

void RCC_BackupReset(uint8_t State);

#endif /* RCC_RCC_H_ */
