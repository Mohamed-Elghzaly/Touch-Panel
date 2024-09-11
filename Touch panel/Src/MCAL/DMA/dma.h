/*
 * dma.h
 *
 *  Created on: Aug 19, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef MCAL_DMA_DMA_H_
#define MCAL_DMA_DMA_H_



/**************** Includes ********************/
#include "../Src/MCAL/RCC/RCC.h"
#include "../Src/MCAL/NVIC/NVIC.h"
#include "../Inc/Common.h"
#include "dma_private.h"
/**************** Macro Declarations ********************/
/* channel selection */
#define DMA_CHANNEL_1			0U
#define DMA_CHANNEL_2			1U
#define DMA_CHANNEL_3			2U
#define DMA_CHANNEL_4			3U
#define DMA_CHANNEL_5			4U
#define DMA_CHANNEL_6			5U
#define DMA_CHANNEL_7			6U
/* Memory to memory mode */
#define DMA_MEMORY_TO_MEMORY_ENABLE			1UL
#define DMA_MEMORY_TO_MEMORY_DISABLE		1UL
/* Channel priority level */
#define DMA_CHANNEL_PRIORITY_LOW			0U
#define DMA_CHANNEL_PRIORITY_MIDIUM			1U
#define DMA_CHANNEL_PRIORITY_HIGH			2U
#define DMA_CHANNEL_PRIORITY_VERY_HIGH		3U
/* Memory and Peripheral size */
#define DMA_BYTE							0U
#define DMA_HALF_WORD						1U
#define DMA_WORD							2U
/* Memory increment mode */
#define DMA_MEMORY_INC_ENABLE				1U
#define DMA_MEMORY_INC_DISABLE				0U
/* Peripheral increment mode */
#define DMA_PERIPHERAL_INC_ENABLE			1U
#define DMA_PERIPHERAL_INC_DISABLE			0U
/* Circular mode */
#define DMA_CIRCULAR_MODE_ENABLE			1U
#define DMA_CIRCULAR_MODE_DISABLE			0U
/* Data transfer direction */
#define DMA_PERIPHERAL_TO_MEMORY			0U
#define DMA_MEMORY_TO_PERIPHERAL			1U
/* Transfer error interrupt enable */
#define DMA_TRANS_ERR_IT_ENABLE				1U
#define DMA_TRANS_ERR_IT_DISABLE			0U
/* Half transfer interrupt enable */
#define DMA_HALF_TRANS_IT_ENABLE			1U
#define DMA_HALF_TRANS_IT_DISABLE			0U
/* Transfer complete interrupt enable */
#define DMA_COMPLETE_TRANS_IT_ENABLE		1U
#define DMA_COMPLETE_TRANS_IT_DISABLE		0U
/* Channel enable AND disable */
#define DMA_CHANNEL_ENABLE					1U
#define DMA_CHANNEL_DISABLE					0U

/*  Channel x flags */
#define DMA_ISR_GIF			0U
#define DMA_ISR_TCIF		1U
#define DMA_ISR_HTIF		2U
#define DMA_ISR_TEIF		3U
/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef struct _DMA_t{
	uint32_t channel;
	uint32_t Direction;
	uint32_t PeriphInc;
	uint32_t MemInc;
	uint32_t PeriphSize;
	uint32_t MemSize;
	uint32_t Mode;
	uint32_t Priority;
	void (* CpltCallback)(struct _DMA_t _dma);
}DMA_t;

/**************** Software Interfaces Declaration ********************/
void DMA_Init(DMA_t _dma);
void DMA_DeInit(DMA_t _dma);

void HAL_DMA_Start_IT(DMA_t _dma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
void HAL_DMA_Abort_IT(DMA_t _dma);

#endif /* MCAL_DMA_DMA_H_ */
