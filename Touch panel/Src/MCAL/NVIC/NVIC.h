/*
 * NVIC.h
 *
 *  Created on: Jul 11, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef CORTEX_M3_NVIC_NVIC_H_
#define CORTEX_M3_NVIC_NVIC_H_


/*------------------- Includes -------------------*/
#include "NVIC_cfg.h"
#include "NVIC_private.h"
#include "../Src/MCAL/GPIO/GPIO.h"

/*------------------- Macro Declarations -------------------*/

/*------------------- Macro Functions Declarations -------------------*/

/*------------------- Data Type Declarations -------------------*/
typedef enum{
	IRQ_NMI					= -14,
	IRQ_MemManage			= -12,
	IRQ_BusFault			= -11,
	IRQ_UsageFault			= -10,
	IRQ_SVCall				= -5,
	IRQ_DebugMonitor		= -4,
	IRQ_PendSV				= -2,
	IRQ_SysTick				= -1,
	IRQ_WWDG				= 0,
	IRQ_PVD					= 1,
	IRQ_TAMPER				= 2,
	IRQ_RTC					= 3,
	IRQ_FLASH				= 4,
	IRQ_RCC					= 5,
	IRQ_EXTI0				= 6,
	IRQ_EXTI1				= 7,
	IRQ_EXTI2				= 8,
	IRQ_EXTI3				= 9,
	IRQ_EXTI4				= 10,
	IRQ_DMA1_Channel1		= 11,
	IRQ_DMA1_Channel2		= 12,
	IRQ_DMA1_Channel3		= 13,
	IRQ_DMA1_Channel4		= 14,
	IRQ_DMA1_Channel5		= 15,
	IRQ_DMA1_Channel6		= 16,
	IRQ_DMA1_Channel7		= 17,
	IRQ_ADC1_2				= 18,
	IRQ_USB_HP_CAN_TX		= 19,
	IRQ_USB_LP_CAN_RX0		= 20,
	IRQ_CAN_RX1				= 21,
	IRQ_CAN_SCE				= 22,
	IRQ_EXTI9_5				= 23,
	IRQ_TIM1_BRK			= 24,
	IRQ_TIM1_UP				= 25,
	IRQ_TIM1_TRG_COM		= 26,
	IRQ_TIM1_CC				= 27,
	IRQ_TIM2				= 28,
	IRQ_TIM3				= 29,
	IRQ_TIM4				= 30,
	IRQ_I2C1_EV				= 31,
	IRQ_I2C1_ER				= 32,
	IRQ_I2C2_EV				= 33,
	IRQ_I2C2_ER				= 34,
	IRQ_SPI1				= 35,
	IRQ_SPI2				= 36,
	IRQ_USART1				= 37,
	IRQ_USART2				= 38,
	IRQ_USART3				= 39,
	IRQ_EXTI15_10			= 40,
	IRQ_RTCAlarm			= 41,
	IRQ_USBWakeup			= 42,
	IRQ_TIM8_BRK			= 43,
	IRQ_TIM8_UP				= 44,
	IRQ_TIM8_TRG_COM		= 45,
	IRQ_TIM8_CC				= 46,
	IRQ_ADC3				= 47,
	IRQ_FSMC				= 48,
	IRQ_SDIO				= 49,
	IRQ_TIM5				= 50,
	IRQ_SPI3				= 51,
	IRQ_UART4				= 52,
	IRQ_UART5				= 53,
	IRQ_TIM6				= 54,
	IRQ_TIM7				= 55,
	IRQ_DMA2_Channel1		= 56,
	IRQ_DMA2_Channel2		= 57,
	IRQ_DMA2_Channel3		= 58,
	IRQ_DMA2_Channel4_5		= 59
}IRQn_Type;
/*------------------- Software Interfaces Declarations -------------------*/
/*
 * @brief : Enable Interrupt
 */
void NVIC_EnableIRQ(IRQn_Type IRQn);
/*
 * @brief : Disable Interrupt
 */
void NVIC_DisableIRQ(IRQn_Type IRQn);
/*
 * @brief : Set Interrupt Pending
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn);
/*
 * @brief : Clear Interrupt Pending
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
/*
 * @brief : Read Interrupt Pending or not
 */
uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn);
/*
 * @brief : Read Interrupt Active or not
 */
uint32_t NVIC_GetActive(IRQn_Type IRQn);
/*
 * @brief : Set Interrupt Priority
 */
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);
/*
 * @brief : Read Interrupt Priority
 */
uint32_t NVIC_GetPriority(IRQn_Type IRQn);

#endif /* CORTEX_M3_NVIC_NVIC_H_ */
