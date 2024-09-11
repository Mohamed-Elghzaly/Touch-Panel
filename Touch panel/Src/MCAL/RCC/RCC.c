/*
 * RCC.c
 *
 *  Created on: Jul 2, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */


#include "RCC.h"


static void RCC_Clock_Enable(clockType_t clk);
static void RCC_PLL_Multipler(PLL_Multiplication value);
static void RCC_PLL_Clock_Source(uint8_t value);


/* enable HSE clock */
void RCC_HSE_CLK(void){
	/* enable HSE */
	SET_BIT(MCAL_RCC->RCC_CR, HSEON);
	/* set as system clock*/
	SET_BIT(MCAL_RCC->RCC_CFGR, SW0);
	CLEAR_BIT(MCAL_RCC->RCC_CFGR, SW1);
}

/* enable HSI clock */
void RCC_HSI_CLK(void){
	/* enable HSI */
	SET_BIT(MCAL_RCC->RCC_CR, HSION);
	/* set as system clock*/
	CLEAR_BIT(MCAL_RCC->RCC_CFGR, SW0);
	CLEAR_BIT(MCAL_RCC->RCC_CFGR, SW1);
}

/* enable PLL clock */
void RCC_PLL_CLK(clockType_t clk, PLL_Multiplication value){
	/* PLL clock source*/
	RCC_PLL_Clock_Source(clk);
	/* enable PLL */
	SET_BIT(MCAL_RCC->RCC_CR, PLLON);
	/* set as system clock*/
	CLEAR_BIT(MCAL_RCC->RCC_CFGR, SW0);
	SET_BIT(MCAL_RCC->RCC_CFGR, SW1);
	/* Multiplication factor*/
	RCC_PLL_Multipler(value);
}


void RCC_Enable_Peripheral_AHB(uint32_t peripheral){
	SET_BIT(MCAL_RCC->RCC_AHBENR, peripheral);
}
void RCC_Enable_Peripheral_APB2(uint32_t peripheral){
	SET_BIT(MCAL_RCC->RCC_APB2ENR, peripheral);

}
void RCC_Enable_Peripheral_APB1(uint32_t peripheral){
	SET_BIT(MCAL_RCC->RCC_APB1ENR, peripheral);
}



void RCC_Disable_Peripheral_AHB(uint32_t peripheral){
	CLEAR_BIT(MCAL_RCC->RCC_AHBENR, peripheral);
}
void RCC_Disable_Peripheral_APB2(uint32_t peripheral){
	CLEAR_BIT(MCAL_RCC->RCC_APB2ENR, peripheral);

}
void RCC_Disable_Peripheral_APB1(uint32_t peripheral){
	CLEAR_BIT(MCAL_RCC->RCC_APB1ENR, peripheral);
}

void RCC_APB2_Prescaler (uint32_t value){
	MODIFY_REG(MCAL_RCC->RCC_CFGR, APB2_BITS_POS<<APB2_PRESCALER_POS, value << APB2_PRESCALER_POS);
}

void RCC_APB1_Prescaler (uint32_t value){
	MODIFY_REG(MCAL_RCC->RCC_CFGR, APB1_BITS_POS<<APB1_PRESCALER_POS, value << APB1_PRESCALER_POS);
}

void RCC_AHB_Prescaler (uint32_t value){
	MODIFY_REG(MCAL_RCC->RCC_CFGR, AHB_BITS_POS<<AHB_PRESCALER_POS, value << AHB_PRESCALER_POS);
}



void RCC_MCO_CLK(uint8_t clk){
	MODIFY_REG(MCAL_RCC->RCC_CFGR, MCO_BITS_POSITION<<MCO_BITS_START, clk << MCO_BITS_START);
}



/***************************/
static void RCC_Clock_Enable(clockType_t clk){
	switch(clk){
	case RCC_HSE:
		SET_BIT(MCAL_RCC->RCC_CR, HSEON);
		break;
	case RCC_HSI:
		SET_BIT(MCAL_RCC->RCC_CR, HSION);
		break;
		default:;
	};
}


static void RCC_PLL_Multipler(PLL_Multiplication value){
	MODIFY_REG(MCAL_RCC->RCC_CFGR, PLL_MULTIPLIER_BITS_POS<<PLL_MULTIPLIER_START, value << PLL_MULTIPLIER_START);
	/* latency These bits represent the ratio of the SYSCLK (system clock) period to the Flash access time.*/
	if(PLL_CLK_MUL_3 >= value){
		*((uint32_t*)FLASH_Base) |= 0;
	}
	else if((PLL_CLK_MUL_3 < value) && (PLL_CLK_MUL_6 >= value)){
		*((uint32_t*)FLASH_Base) |= 1;
	}
	else if(PLL_CLK_MUL_6 < value){
		*((uint32_t*)FLASH_Base) |= 2;
	}
}




static void RCC_PLL_Clock_Source(uint8_t value){
	MODIFY_REG(MCAL_RCC->RCC_CFGR, PLLSRC_BITS_POS<<PLLSRC_BITS_START, value << PLLSRC_BITS_START);
	if(HSE_OSC_PLL_CLK == value){
		RCC_Clock_Enable(RCC_HSE);
	}
	else if (HSI_OSC_DIV_2_PLL_CLK == value){
		RCC_Clock_Enable(RCC_HSI);
	}
}



void RCC_BackupReset(uint8_t State) {
    if (State == ENABLE) {
    	MCAL_RCC->RCC_BDCR.BDRST = 1;
    } else {
    	MCAL_RCC->RCC_BDCR.BDRST = 0;
    }
}
