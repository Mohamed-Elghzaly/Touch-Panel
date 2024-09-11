/*
 * SysTick_private.h
 *
 *  Created on: Jul 4, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef CORTEX_M3_SYSTICK_SYSTICK_PRIVATE_H_
#define CORTEX_M3_SYSTICK_SYSTICK_PRIVATE_H_




/**************** Includes ********************/
#include <stdint.h>

/**************** Macro Declarations ********************/
#define SYSTICK_BASE			(0xE000E010UL)
#define MCAL_SYSTICK					((SysTick_t *)SYSTICK_BASE)

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
/************************** SysTick Control and Status Register **********************/
typedef union{
	struct{
		volatile uint32_t SENABLE		:1;
		volatile uint32_t TICKINT		:1;
		volatile uint32_t CLKSOURCE		:1;
		volatile uint32_t RESERVED0		:12;
		volatile uint32_t COUNTFLAG		:1;
		volatile uint32_t RESERVED1		:15;
	};
	volatile uint32_t CSR_REG;
}CSR_t;

/*********************** SysTick Calibration Value Register ******************/
typedef union{
	struct{
		volatile uint32_t TENMS			:24;
		volatile uint32_t RESERVED		:6;
		volatile uint32_t SKEW			:1;
		volatile uint32_t NOREF			:1;
	};
	volatile uint32_t CALIB_REG;
}CALIB_t;


/**************************************************/

typedef struct{
	volatile CSR_t CSR;
	volatile uint32_t RELOAD;
	volatile uint32_t CURRENT;
	volatile CALIB_t CALIB;
}SysTick_t;


#endif /* CORTEX_M3_SYSTICK_SYSTICK_PRIVATE_H_ */
