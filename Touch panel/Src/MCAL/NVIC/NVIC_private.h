/*
 * NVIC_private.h
 *
 *  Created on: Jul 11, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef CORTEX_M3_NVIC_NVIC_PRIVATE_H_
#define CORTEX_M3_NVIC_NVIC_PRIVATE_H_

/*------------------- Includes -------------------*/
#include "../Inc/Common.h"
/*------------------- Macro Declarations -------------------*/
#define NVIC_BASE				(0xE000E100UL)
#define MCAL_NVIC					((NVIC_t *)NVIC_BASE)

/*------------------- Macro Functions Declarations -------------------*/

/*------------------- Data Type Declarations -------------------*/
typedef struct{
	volatile uint32_t ISER[8U];         /* Interrupt Set-enable Registers */
	uint32_t RESERVED0[24U];
	volatile uint32_t ICER[8U];			/* Interrupt Clear-enable Registers */
	uint32_t RESERVED1[24U];
	volatile uint32_t ISPR[8U];			/* Interrupt Set-pending Registers */
	uint32_t RESERVED2[24U];
	volatile uint32_t ICPR[8U];			/* Interrupt Clear-pending Registers */
	uint32_t RESERVED3[24U];
	volatile uint32_t IAPR[8U];			/* Interrupt Active Bit Registers */
	uint32_t RESERVED4[56U];
	volatile uint8_t IPR[240U];			/* Interrupt Priority Registers */
	uint32_t RESERVED5[644U];
	volatile uint32_t STIR;				/* Software Trigger Interrupt Register */
}NVIC_t;

/*------------------- Software Interfaces Declarations -------------------*/


#endif /* CORTEX_M3_NVIC_NVIC_PRIVATE_H_ */
