/*
 * RCC_private.h
 *
 *  Created on: Jul 2, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef RCC_RCC_PRIVATE_H_
#define RCC_RCC_PRIVATE_H_


/**************** Includes ********************/

/**************** Macro Declarations ********************/
#define RCC_Base				(0x40021000UL)
#define MCAL_RCC				((RCC_Registers_t *)RCC_Base)


#define FLASH_Base		(0x40022000UL)


/*************************** CR REGISTER *************************************/
#define HSION		0
#define HSIRDY		1
#define HSEON		16
#define HSERDY		17
#define CSSON		19
#define PLLON		24
#define PLLRDY		25
/*************************** CFGR REGISTER *************************************/
#define MCO				24
#define PLLMUL			18
#define PLLXTPRE		17
#define PLLSRC			16

/****************************** PLL multiplication factor *****************************/
#define PLL_MULTIPLIER_START		18
#define PLL_MULTIPLIER_BITS_POS		0XF


/***************************  AHB prescaler *************************************/
#define AHB_PRESCALER_POS		4
#define AHB_BITS_POS			0XF

/************** PLL Clock Source ******************/
#define PLLSRC_BITS_START			16
#define PLLSRC_BITS_POS				0b1

/*************************************************/
#define MCO_BITS_START			24
#define MCO_BITS_POSITION		0x7
/*************************************************/
#define APB1_PRESCALER_POS		8
#define APB1_BITS_POS			0X7

#define APB2_PRESCALER_POS		11
#define APB2_BITS_POS			0X7


/***************************  select SYSCLK source *************************************/
#define SW0		0
#define SW1		1




/**************** Macro Function Declarations ********************/
/**************** Data Type Declaration ********************/
typedef union{
	struct{
		volatile uint32_t LSEON			:1;
		volatile uint32_t LSERDY		:1;
		volatile uint32_t LSEBYP		:1;
		volatile uint32_t RESERVED0		:5;
		volatile uint32_t RTCSEL		:2;
		volatile uint32_t RESERVED1		:5;
		volatile uint32_t RTCEN			:1;
		volatile uint32_t BDRST			:1;
	};
	volatile uint32_t RCC_BDCR_REG;
}RCC_BDCR_t;

typedef struct{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_AHBENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RCC_APB1ENR;
	volatile RCC_BDCR_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
}RCC_Registers_t;

/**************** Software Interfaces Declaration ********************/

#endif /* RCC_RCC_PRIVATE_H_ */
