/*
 * SysTick.h
 *
 *  Created on: Jul 4, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef CORTEX_M3_SYSTICK_SYSTICK_H_
#define CORTEX_M3_SYSTICK_SYSTICK_H_




/**************** Includes ********************/
#include <stdint.h>
#include "SysTick_cfg.h"
#include "SysTick_private.h"
#include "../Inc/Common.h"


typedef void (*ptrFunction)(void);
/**************** Macro Declarations ********************/
/******* Disable & Enables the counter *************/
#define SYSTICK_TIMER_ENABLE		0B1
#define SYSTICK_TIMER_DISABLE		0B0

/******* Indicates the clock source *************/
#define AHB_CLK_DIV_8				0B0
#define AHB_CLK						0B1
/************** Enables SysTick exception request ***************/
#define COUNT_DOWN_NOT_ASSERT_EXCEPTION			0B0
#define COUNT_DOWN_ASSERT_EXCEPTION				0B1
/********************* clear flag ******************/
#define SYSTICK_FLAG_START		16
#define SYSTICK_CLEAR_FLAG		0x0
/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/

/**************** Software Interfaces Declaration ********************/
/*
 * @brief : Initialization Systick Timer
 */
void Systick_Init(uint32_t clkSrc);
/*
 * @brief : Set Single Interval CFG
 */
void Systick_SingleInterval(uint32_t ticks, ptrFunction pFun);
/*
 * @brief : Set Periodic Interval CFG
 */
void Systick_PeriodicInterval(uint32_t ticks, ptrFunction pFun);
/*
 * @brief : Set Ticks CFG
 */
void Systick_Ticks(void);


#if SYSTICK_MICROS_MILLIS_TYPE == SYSTICK_MICROS
/*
 * @brief : Micro Delay Function
 */
void Systick_Delay_us(uint32_t value);
/*
 * @brief : return micros ticks
 */
uint64_t micros(void);

#elif SYSTICK_MICROS_MILLIS_TYPE == SYSTICK_MILLIS
/*
 * @brief : Milli Delay Function
 */
void Systick_Delay_ms(uint32_t value);
/*
 * @brief : return millis ticks
 */
uint64_t millis(void);
#endif

#endif /* CORTEX_M3_SYSTICK_SYSTICK_H_ */
