/*
 * SysTick.c
 *
 *  Created on: Jul 4, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#include "SysTick.h"

ptrFunction Systick_CallBack = NULL;
volatile uint64_t usTicks = 0;
volatile uint64_t msTicks = 0;

void Systick_Init(uint32_t clkSrc){
	/* Disable system timer */
	MCAL_SYSTICK->CSR.SENABLE = SYSTICK_TIMER_DISABLE;
	/* reset counter */
	MCAL_SYSTICK->RELOAD = 0;
	MCAL_SYSTICK->CURRENT = 0;
	/* Disable SysTick exception request */
	MCAL_SYSTICK->CSR.TICKINT = COUNT_DOWN_NOT_ASSERT_EXCEPTION;
	/* set clk source */
	MCAL_SYSTICK->CSR.CLKSOURCE = clkSrc;
}

void Systick_SingleInterval(uint32_t ticks, ptrFunction pFun){
	/* set reload value */
	MCAL_SYSTICK->RELOAD = ticks;
	/* */
	Systick_CallBack = pFun;
	/* enable intrrupt */
	MCAL_SYSTICK->CSR.TICKINT = COUNT_DOWN_ASSERT_EXCEPTION;
	/* Enable system timer */
	MCAL_SYSTICK->CSR.SENABLE = SYSTICK_TIMER_ENABLE;
}

void Systick_PeriodicInterval(uint32_t ticks, ptrFunction pFun){
	/* set reload value */
	MCAL_SYSTICK->RELOAD = ticks;
	/* pass Function */
	Systick_CallBack = pFun;
	/* enable intrrupt */
	MCAL_SYSTICK->CSR.TICKINT = COUNT_DOWN_ASSERT_EXCEPTION;
	/* Enable system timer */
	MCAL_SYSTICK->CSR.SENABLE = SYSTICK_TIMER_ENABLE;
}

void Systick_Ticks(void){
	uint32_t ticks = 0;
#if SYSTICK_MICROS_MILLIS_TYPE == SYSTICK_MICROS
	ticks = (F_CPU/1000000)-1;
#elif SYSTICK_MICROS_MILLIS_TYPE == SYSTICK_MILLIS
	ticks = (F_CPU/1000)-1;
#endif
	/* set reload value */
	MCAL_SYSTICK->RELOAD = ticks;
	/* enable intrrupt */
	MCAL_SYSTICK->CSR.TICKINT = COUNT_DOWN_ASSERT_EXCEPTION;
	/* Enable system timer */
	MCAL_SYSTICK->CSR.SENABLE = SYSTICK_TIMER_ENABLE;
}

#if SYSTICK_MICROS_MILLIS_TYPE == SYSTICK_MICROS
void Systick_Delay_us(uint32_t value){
	uint64_t lDelay = micros() + value;
	while(micros() < lDelay);
}
#elif SYSTICK_MICROS_MILLIS_TYPE == SYSTICK_MILLIS
void Systick_Delay_ms(uint32_t value){
	uint64_t lDelay = millis() + value;
	while(millis() < lDelay);
}
#endif


#if SYSTICK_MICROS_MILLIS_TYPE == SYSTICK_MICROS
uint64_t micros(void) {
    return usTicks;
}

#elif SYSTICK_MICROS_MILLIS_TYPE == SYSTICK_MILLIS
uint64_t millis(void) {
    return msTicks;
}
#endif



void SysTick_Handler(void){
#if SYSTICK_MICROS_MILLIS_TYPE == SYSTICK_MICROS
	usTicks++;
#elif SYSTICK_MICROS_MILLIS_TYPE == SYSTICK_MILLIS
    msTicks++;
#endif
}
