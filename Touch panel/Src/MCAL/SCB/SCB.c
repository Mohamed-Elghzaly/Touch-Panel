/**
 ******************************************************************************
 * @file           : CortexM3_Core_SCB.c
 * @author         : Mohamed Abdallah Elghzaly
 * @brief          : code to control SCB
 ******************************************************************************
 */
#include "SCB.h"

void SCB_SetPriorityGrouping(uint32_t PriorityGroup){
	uint32_t ReegisterValue = 0;
	uint32_t PriorityGroupTemp = 0;
	ReegisterValue = MCAL_SCB->AIRCR;
	ReegisterValue &= (uint32_t)0x0000F8FF;		// Clear VECTKEY and PRIGROUP
	PriorityGroupTemp = PriorityGroup & (uint32_t)0x07;
	MCAL_SCB->AIRCR = ReegisterValue | ((uint32_t)(0x5FA << 16)) | (PriorityGroupTemp << 8);
}

uint32_t SCB_GetPriorityGrouping(void){
	return (((uint32_t)MCAL_SCB->AIRCR & (uint32_t)0x0700) >> (uint32_t)8);
}
