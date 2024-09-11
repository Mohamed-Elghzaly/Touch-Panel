/*
 * dma.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */



/**************** Includes ********************/

#include "dma.h"

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
static DMA_t DMA_CH[7];
static void DMA_SetConfig(DMA_t _dma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
/**************** Software Interfaces Declaration ********************/

void DMA_Init(DMA_t _dma) {
	RCC_Enable_Peripheral_AHB(DMA1EN);
	DMA1_CHANNEL(_dma.channel)->DMA_CCR.DIR = _dma.Direction;
	DMA1_CHANNEL(_dma.channel)->DMA_CCR.PINC = _dma.PeriphInc;
	DMA1_CHANNEL(_dma.channel)->DMA_CCR.MINC = _dma.MemInc;
	DMA1_CHANNEL(_dma.channel)->DMA_CCR.MSIZE = _dma.MemSize;
	DMA1_CHANNEL(_dma.channel)->DMA_CCR.PSIZE = _dma.PeriphSize;
	DMA1_CHANNEL(_dma.channel)->DMA_CCR.PL= _dma.Priority;
	DMA1_CHANNEL(_dma.channel)->DMA_CCR.CIRC = _dma.Mode;
	switch(_dma.channel){
		case DMA_CHANNEL_1:
			NVIC_EnableIRQ(IRQ_DMA1_Channel1);
			break;
		case DMA_CHANNEL_2:
			NVIC_EnableIRQ(IRQ_DMA1_Channel2);
			break;
		case DMA_CHANNEL_3:
			NVIC_EnableIRQ(IRQ_DMA1_Channel3);
			break;
		case DMA_CHANNEL_4:
			NVIC_EnableIRQ(IRQ_DMA1_Channel4);
			break;
		case DMA_CHANNEL_5:
			NVIC_EnableIRQ(IRQ_DMA1_Channel5);
			break;
		case DMA_CHANNEL_6:
			NVIC_EnableIRQ(IRQ_DMA1_Channel6);
			break;
		case DMA_CHANNEL_7:
			NVIC_EnableIRQ(IRQ_DMA1_Channel7);
			break;
	}
	DMA_CH[_dma.channel] = _dma;
}

void DMA_DeInit(DMA_t _dma) {

}


void HAL_DMA_Start_IT(DMA_t _dma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength){
	/* Disable the peripheral */
	DMA1_CHANNEL(_dma.channel)->DMA_CCR.EN = DMA_CHANNEL_DISABLE;
	/* Configure the source, destination address and the data length & clear flags*/
	DMA_SetConfig(_dma, SrcAddress, DstAddress, DataLength);
	/* Enable the transfer complete interrupt */
	DMA1_CHANNEL(_dma.channel)->DMA_CCR.TCIE = ENABLE;
	/* Enable the transfer Error interrupt */
//	DMA1_CHANNEL(_dma.channel)->DMA_CCR.TEIE = ENABLE;
	/* Enable the Half transfer complete interrupt as well */
//	DMA1_CHANNEL(_dma.channel)->DMA_CCR.HTIE = ENABLE;
	/* Enable the Peripheral */
	DMA1_CHANNEL(_dma.channel)->DMA_CCR.EN = DMA_CHANNEL_ENABLE;
}

void HAL_DMA_Abort_IT(DMA_t _dma)
{
    /* Disable DMA IT */
	DMA1_CHANNEL(_dma.channel)->DMA_CCR.TCIE = DISABLE;
//	DMA1_CHANNEL(_dma.channel)->DMA_CCR.TEIE = DISABLE;
//	DMA1_CHANNEL(_dma.channel)->DMA_CCR.HTIE = DISABLE;
    /* Disable the channel */
    DMA1_CHANNEL(_dma.channel)->DMA_CCR.EN = DMA_CHANNEL_DISABLE;

    /* Clear all flags */
	SET_BIT(MCAL_DMA1->DMA_IFCR.DMA_IFCR_REG, DMA1_IT_FLAG(_dma.channel, DMA_ISR_GIF));

}


static void DMA_SetConfig(DMA_t _dma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{
  /* Clear all flags */
	CLEAR_BIT(MCAL_DMA1->DMA_IFCR.DMA_IFCR_REG, DMA1_IT_FLAG(_dma.channel, DMA_ISR_GIF));
  /* Configure DMA Channel data length */
	DMA1_CHANNEL(_dma.channel)->DMA_CNDTR = DataLength;

  /* Memory to Peripheral */

  if((_dma.Direction) == DMA_MEMORY_TO_PERIPHERAL)
  {
	  /* Configure DMA Channel destination address */
	  DMA1_CHANNEL(_dma.channel)->DMA_CPAR = DstAddress;
	  /* Configure DMA Channel source address */
	  DMA1_CHANNEL(_dma.channel)->DMA_CMAR = SrcAddress;
  }
  /* Peripheral to Memory */
  else
  {
    /* Configure DMA Channel source address */
	  DMA1_CHANNEL(_dma.channel)->DMA_CPAR = SrcAddress;

    /* Configure DMA Channel destination address */
	  DMA1_CHANNEL(_dma.channel)->DMA_CMAR = DstAddress;
  }
}

// (((DMA1_IT_FLAG(_dma.channel, DMA_ISR_TCIF))&1U) != 0) && (DMA1_CHANNEL(_dma.channel)->DMA_CCR.TCIE != 0)
// (MCAL_DMA1->DMA_ISR.DMA_ISR_REG >> (DMA1_IT_FLAG(_dma.channel, DMA_ISR_TCIF))) & 1U
void DMA1_IRQHandler(DMA_t _dma){
//	  uint32_t flag_it = MCAL_DMA1->DMA_ISR.DMA_ISR_REG;
//	  uint32_t source_it = (DMA1_CHANNEL(_dma.channel)->DMA_CCR.DMA_CCR_REG);
	if (READ_BIT(MCAL_DMA1->DMA_ISR.DMA_ISR_REG,(DMA1_IT_FLAG(_dma.channel, DMA_ISR_TCIF))) && (DMA1_CHANNEL(_dma.channel)->DMA_CCR.TCIE != 0))
	{
	if((DMA1_CHANNEL(_dma.channel)->DMA_CCR.CIRC) == 0U)
	{
	  /* Disable the transfer complete and error interrupt */
		(DMA1_CHANNEL(_dma.channel)->DMA_CCR.TCIE )= 0U;

	}
	/* Clear the transfer complete flag */
	SET_BIT(MCAL_DMA1->DMA_IFCR.DMA_IFCR_REG, DMA1_IT_FLAG(_dma.channel, DMA_ISR_TCIF));

	if(_dma.CpltCallback != NULL)
	{
	  /* Transfer complete callback */
		_dma.CpltCallback(_dma);
	}
	}

}

void DMA1_Channel1_IRQHandler(void){
	DMA1_IRQHandler(DMA_CH[DMA_CHANNEL_1]);
}

void DMA1_Channel2_IRQHandler(void){
	DMA1_IRQHandler(DMA_CH[DMA_CHANNEL_2]);
}

void DMA1_Channel3_IRQHandler(void){
	DMA1_IRQHandler(DMA_CH[DMA_CHANNEL_3]);
}

void DMA1_Channel4_IRQHandler(void){
	DMA1_IRQHandler(DMA_CH[DMA_CHANNEL_4]);
}

void DMA1_Channel5_IRQHandler(void){
	DMA1_IRQHandler(DMA_CH[DMA_CHANNEL_5]);
}

void DMA1_Channel6_IRQHandler(void){
	DMA1_IRQHandler(DMA_CH[DMA_CHANNEL_6]);
}

void DMA1_Channel7_IRQHandler(void){
	DMA1_IRQHandler(DMA_CH[DMA_CHANNEL_7]);
}
