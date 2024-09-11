/*
 * SCB_private.h
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef CORTEX_M3_SCB_SCB_PRIVATE_H_
#define CORTEX_M3_SCB_SCB_PRIVATE_H_


/*------------------- Macro Declarations -------------------*/
#define SCB_Base        (0xE000ED00UL)
#define MCAL_SCB             ((SCB_Type *)SCB_Base)

/**************** Data Type Declaration ********************/
typedef struct{
	volatile uint32_t CPUID;                /* CPUID Base Register */
	volatile uint32_t ICSR;					/* Interrupt Control and State Register */
	volatile uint32_t VTOR;					/* Vector Table Offset Register */
	volatile uint32_t AIRCR;				/* Application Interrupt and Reset Control Register */
	volatile uint32_t SCR;					/* System Control Register */
	volatile uint32_t CCR;					/* Configuration and Control Register */
	volatile uint32_t SHPR1;				/* System Handler Priority Register 1 */
	volatile uint32_t SHPR2;				/* System Handler Priority Register 2 */
	volatile uint32_t SHPR3;				/* System Handler Priority Register 3 */
	volatile uint32_t SHCRS;				/* System Handler Control and State Register */
	volatile uint32_t CFSR;					/* Configurable Fault Status Register */
}SCB_Type;


#endif /* CORTEX_M3_SCB_SCB_PRIVATE_H_ */
