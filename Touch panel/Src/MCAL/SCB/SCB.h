/**
 ******************************************************************************
 * @file           : CortexM3_Core_SCB.h
 * @author         : Mohamed Abdallah Elghzaly
 * @brief          : Declaration for SCB
 ******************************************************************************
 */

#ifndef CORTEXM3_CORE_SCB_H_
#define CORTEXM3_CORE_SCB_H_

/**************** Includes ********************/
#include "../Src/MCAL/GPIO/GPIO.h"
#include "SCB_private.h"

/**************** Macro Declarations ********************/

#define SCB_PRIGROUP_0				0x7U			/* 0-Bit for Group priority
 	 	 	 	 	 	 	 	 	 	 	 	 	   4-Bit for Sub priority*/
#define SCB_PRIGROUP_1       		0x6U			/* 1-Bit for Group priority
 	 	 	 	 	 	 	 	 	 	 	 	 	   3-Bit for Sub priority*/
#define SCB_PRIGROUP_2         		0x5U			/* 2-Bit for Group priority
 	 	 	 	 	 	 	 	 	 	 	 	 	   2-Bit for Sub priority*/
#define SCB_PRIGROUP_3         		0x4U			/* 3-Bit for Group priority
 	 	 	 	 	 	 	 	 	 	 	 	 	   1-Bit for Sub priority*/
#define SCB_PRIGROUP_4         		0x3U			/* 4-Bit for Group priority
 	 	 	 	 	 	 	 	 	 	 	 	 	   0-Bit for Sub priority*/

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/

/**************** Software Interfaces Declaration ********************/
/*
 * @brief : Set Groups of Priority
 */
void SCB_SetPriorityGrouping(uint32_t PriorityGroup);
/*
 * @brief : Read Groups of Priority
 */
uint32_t SCB_GetPriorityGrouping(void);

#endif /* CORTEXM3_CORE_SCB_H_ */
