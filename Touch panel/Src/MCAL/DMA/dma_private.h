/*
 * dma_private.h
 *
 *  Created on: Aug 19, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef MCAL_DMA_DMA_PRIVATE_H_
#define MCAL_DMA_DMA_PRIVATE_H_

#include "stdint.h"
/**************** Includes ********************/
#define MCAL_DMA1_BASE				(0x40020000UL)
#define MCAL_DMA1				((DMAx_t *)MCAL_DMA1_BASE)

//#define DMA1_Channel1_BASE    (MCAL_DMA1_BASE + 0x00000008UL)
//#define DMA1_Channel2_BASE    (MCAL_DMA1_BASE + 0x0000001CUL)
//#define DMA1_Channel3_BASE    (MCAL_DMA1_BASE + 0x00000030UL)
//#define DMA1_Channel4_BASE    (MCAL_DMA1_BASE + 0x00000044UL)
//#define DMA1_Channel5_BASE    (MCAL_DMA1_BASE + 0x00000058UL)
//#define DMA1_Channel6_BASE    (MCAL_DMA1_BASE + 0x0000006CUL)
//#define DMA1_Channel7_BASE    (MCAL_DMA1_BASE + 0x00000080UL)
//
//#define DMA1_Channel1       ((DMAChannel_t *)DMA1_Channel1_BASE)
//#define DMA1_Channel2       ((DMAChannel_t *)DMA1_Channel2_BASE)
//#define DMA1_Channel3       ((DMAChannel_t *)DMA1_Channel3_BASE)
//#define DMA1_Channel4       ((DMAChannel_t *)DMA1_Channel4_BASE)
//#define DMA1_Channel5       ((DMAChannel_t *)DMA1_Channel5_BASE)
//#define DMA1_Channel6       ((DMAChannel_t *)DMA1_Channel6_BASE)
//#define DMA1_Channel7       ((DMAChannel_t *)DMA1_Channel7_BASE)

#define DMA1_CHANNEL(CHANNEL)				((DMAChannel_t *)(MCAL_DMA1_BASE+(0x08+(20*CHANNEL))))
#define DMA1_IT_FLAG(CHANNEL, FLAG)			((4*CHANNEL)+FLAG)
/**************** Macro Declarations ********************/

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef union {
	struct{
		volatile uint32_t GIF1		:1;
		volatile uint32_t TCIF1		:1;
		volatile uint32_t HTIF1		:1;
		volatile uint32_t TEIF1		:1;
		volatile uint32_t GIF2		:1;
		volatile uint32_t TCIF2		:1;
		volatile uint32_t HTIF2		:1;
		volatile uint32_t TEIF2		:1;
		volatile uint32_t GIF3		:1;
		volatile uint32_t TCIF3		:1;
		volatile uint32_t HTIF3		:1;
		volatile uint32_t TEIF3		:1;
		volatile uint32_t GIF4		:1;
		volatile uint32_t TCIF4		:1;
		volatile uint32_t HTIF4		:1;
		volatile uint32_t TEIF4		:1;
		volatile uint32_t GIF5		:1;
		volatile uint32_t TCIF5		:1;
		volatile uint32_t HTIF5		:1;
		volatile uint32_t TEIF5		:1;
		volatile uint32_t GIF6		:1;
		volatile uint32_t TCIF6		:1;
		volatile uint32_t HTIF6		:1;
		volatile uint32_t TEIF6		:1;
		volatile uint32_t GIF7		:1;
		volatile uint32_t TCIF7		:1;
		volatile uint32_t HTIF7		:1;
		volatile uint32_t TEIF7		:1;
		volatile uint32_t RESERVED	:4;
	};
	volatile uint32_t DMA_ISR_REG;
} DMA_ISR_t;

typedef union {
	struct{
		volatile uint32_t CGIF1		:1;
		volatile uint32_t CTCIF1	:1;
		volatile uint32_t CHTIF1	:1;
		volatile uint32_t CTEIF1	:1;
		volatile uint32_t CGIF2		:1;
		volatile uint32_t CTCIF2	:1;
		volatile uint32_t CHTIF2	:1;
		volatile uint32_t CTEIF2	:1;
		volatile uint32_t CGIF3		:1;
		volatile uint32_t CTCIF3	:1;
		volatile uint32_t CHTIF3	:1;
		volatile uint32_t CTEIF3	:1;
		volatile uint32_t CGIF4		:1;
		volatile uint32_t CTCIF4	:1;
		volatile uint32_t CHTIF4	:1;
		volatile uint32_t CTEIF4	:1;
		volatile uint32_t CGIF5		:1;
		volatile uint32_t CTCIF5	:1;
		volatile uint32_t CHTIF5	:1;
		volatile uint32_t CTEIF5	:1;
		volatile uint32_t CGIF6		:1;
		volatile uint32_t CTCIF6	:1;
		volatile uint32_t CHTIF6	:1;
		volatile uint32_t CTEIF6	:1;
		volatile uint32_t CGIF7		:1;
		volatile uint32_t CTCIF7	:1;
		volatile uint32_t CHTIF7	:1;
		volatile uint32_t CTEIF7	:1;
		volatile uint32_t RESERVED	:4;
	};
	volatile uint32_t DMA_IFCR_REG;
} DMA_IFCR_t;

typedef union {
	volatile uint32_t DMA_CCR_REG;
	struct {
		volatile uint32_t EN 			:1;
		volatile uint32_t TCIE 			:1;
		volatile uint32_t HTIE 			:1;
		volatile uint32_t TEIE 			:1;
		volatile uint32_t DIR 			:1;
		volatile uint32_t CIRC 			:1;
		volatile uint32_t PINC 			:1;
		volatile uint32_t MINC 			:1;
		volatile uint32_t PSIZE			:2;
		volatile uint32_t MSIZE 		:2;
		volatile uint32_t PL 			:2;
		volatile uint32_t MEM2MEM 		:1;
		volatile uint32_t RESERVED		:17;
	};
} DMA_CCR_t;

typedef struct {
	volatile DMA_ISR_t DMA_ISR;
	volatile DMA_IFCR_t DMA_IFCR;
} DMAx_t;

typedef struct {
	volatile DMA_CCR_t DMA_CCR;
	volatile uint32_t DMA_CNDTR;
	volatile uint32_t DMA_CPAR;
	volatile uint32_t DMA_CMAR;
} DMAChannel_t;

/**************** Software Interfaces Declaration ********************/

#endif /* MCAL_DMA_DMA_PRIVATE_H_ */
