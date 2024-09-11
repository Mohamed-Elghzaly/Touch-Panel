/*
 * timer2.h
 *
 *  Created on: Jul 16, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef TIMERS_TIM2_TIMER2_H_
#define TIMERS_TIM2_TIMER2_H_

/**************** Includes ********************/
#include <stdint.h>
#include "../Inc/Common.h"
#include "../Src/MCAL/GPIO/GPIO.h"
#include "../Src/MCAL/RCC/RCC.h"
#include "timer_private.h"
#include "../Src/MCAL/DMA/dma.h"

/**************** Macro Declarations ********************/

/* select witch timer */
#define TIMER2_PWM_EN			0U
#define TIMER3_PWM_EN			1U
#define TIMER4_PWM_EN			2U

/*  Center-aligned mode or edge mode selection */
#define EDGE_ALIGNED_MODE			0u
#define CENTER_ALIGNED_MODE_1		1u
#define CENTER_ALIGNED_MODE_2		2u
#define CENTER_ALIGNED_MODE_3		3u

/* Auto-reload preload enable */
#define AUTO_RELOAD_PRELOAD_BUFFERED			1
#define AUTO_RELOAD_PRELOAD_NOT_BUFFERED		0

/* Output compare preload enable */
#define PRELOAD_REGISTER_CCRx_ENABLE		1
#define PRELOAD_REGISTER_CCRx_DISABLE		0

/* Direction */
#define COUNTER_USED_AS_UPCOUNTER				0
#define COUNTER_USED_AS_DOWNCOUNTER				1

/* PWM mode */
#define PWM_MODE_1 		6u
#define PWM_MODE_2 		7u

/* select channel */
#define PWM_CHANNEL_1_ENABLE		0b0001
#define PWM_CHANNEL_2_ENABLE		0b0010
#define PWM_CHANNEL_3_ENABLE		0b0100
#define PWM_CHANNEL_4_ENABLE		0b1000



/* Capture/Compare x selection */
#define CHANNEL_IS_OUTPUT		0u

/* UG: Update generation */
#define NO_ACTION					0u
#define RE_INITIALIZE_COUNTER		1u

/* Capture/Compare X output enable */
#define OUTPUT_COMPARE_ENABLE			1u
#define OUTPUT_COMPARE_DISABLE			0u

/* OUTPUT CAMPARE */
#define OC_ACTIVE_HIGH		0u
#define OC_ACTIVE_LOW		1u

/* Counter enable */
#define COUNTER_ENABLE			1u
#define COUNTER_DISABLE			0u

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef struct _Timer_PWM_t{
	uint32_t	frequancy;
	uint16_t	dutyCycle;
	uint16_t	prescaler;
	uint8_t		timer;
	uint8_t		channel;
	uint8_t		mode;
}Timer_PWM_t;

/**************** Software Interfaces Declaration ********************/
/*
 * brief : Timer as PWM Initialization
 */
void TIMER_PWM_Initialize(const Timer_PWM_t pwm);
/*
 * brief : Set PWM Duty Cycle
 */
void TIMER_PWM_DutyCycle(const Timer_PWM_t pwm, uint32_t channel, uint32_t dutyCycle);
/*
 * brief : Set PWM Frequency
 */
void TIMER_PWM_Frequency(const Timer_PWM_t pwm, uint32_t freq);
/*
 * brief : Set PWM Prescaler
 */
void TIMER_PWM_SetPrescaler(const Timer_PWM_t pwm, uint32_t prescaler);
/*
 * brief : Start PWM
 */
void TIMER_PWM_Start(const Timer_PWM_t pwm, uint32_t channel);
/*
 * brief : Stop PWM
 */
void TIMER_PWM_Stop(const Timer_PWM_t pwm, uint32_t channel);
/*
 * brief : Start PWM using DMA
 */
void TIMER_PWM_Start_DMA(const Timer_PWM_t pwm, const DMA_t _dma, uint32_t Channel, const uint32_t *pData, uint16_t Length);
/*
 * brief : Stop PWM using DMA
 */
void TIMER_PWM_Stop_DMA(const Timer_PWM_t pwm, const DMA_t _dma, uint32_t Channel) ;

#endif /* TIMERS_TIM2_TIMER2_H_ */
