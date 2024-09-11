/*
 * NVIC.c
 *
 *  Created on: Jul 11, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */


#include "NVIC.h"



void NVIC_EnableIRQ(IRQn_Type IRQn){
	if((uint32_t)IRQn >= 0){
		MCAL_NVIC->ISER[(uint32_t)IRQn >> 5] = (1U << (((uint32_t)IRQn) & 0x1F));
	}
}


void NVIC_DisableIRQ(IRQn_Type IRQn){
	if((uint32_t)IRQn >= 0){
			MCAL_NVIC->ICER[(uint32_t)IRQn >> 5] = (1U << (((uint32_t)IRQn) & 0x1F));
		}
}


void NVIC_SetPendingIRQ(IRQn_Type IRQn){
	if((uint32_t)IRQn >= 0){
				MCAL_NVIC->ISPR[(uint32_t)IRQn >> 5] = (1U << (((uint32_t)IRQn) & 0x1F));
			}
}


void NVIC_ClearPendingIRQ(IRQn_Type IRQn){
	if((uint32_t)IRQn >= 0){
					MCAL_NVIC->ICPR[(uint32_t)IRQn >> 5] = (1U << (((uint32_t)IRQn) & 0x1F));
	}
}
uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn){
	if((uint32_t)IRQn >= 0){
		return ((MCAL_NVIC->ISPR[((uint32_t)IRQn >> 5)] & (1U << ((uint32_t)IRQn & 0x1F))) != ((uint32_t)0) ? 1U : 0U);
	}
	else{
		return 0;
	}
}


uint32_t NVIC_GetActive(IRQn_Type IRQn){
	if(IRQn >= 0){
		return ((MCAL_NVIC->IAPR[((uint32_t)IRQn >> 5)] & (1U << ((uint32_t)IRQn & 0x1F))) != ((uint32_t)0) ? 1U : 0U);
	}
	else{
		return 0;
	}
}

void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority){
	if((uint32_t)IRQn >= 0){
		MCAL_NVIC->IPR[(uint32_t)IRQn] = (uint8_t)((priority << 4) & (uint32_t)0xFF);
	}
	else{

	}
}
uint32_t NVIC_GetPriority(IRQn_Type IRQn){
	if((uint32_t)IRQn >= 0){
		return (((uint32_t)MCAL_NVIC->IPR[(uint32_t)IRQn]) >> 4);
	}
	else{
		return 0;
	}
}

