/*
 * usart.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

/**************** Includes ********************/
#include "usart.h"

/**************** Macro Declarations ********************/

#define USART1_TX_GPIO			((Pin_cfg_t){GPIO_OUTPUT_50MHz_ALTER_PUSH_PULL, GPIO_PORTA, GPIO_PIN9})
#define USART1_RX_GPIO			((Pin_cfg_t){GPIO_INPUT_PULL_UP_MODE, GPIO_PORTA, GPIO_PIN10})

#define USART2_TX_GPIO			((Pin_cfg_t){GPIO_OUTPUT_50MHz_ALTER_PUSH_PULL, GPIO_PORTA, GPIO_PIN2})
#define USART2_RX_GPIO			((Pin_cfg_t){GPIO_INPUT_PULL_UP_MODE, GPIO_PORTA, GPIO_PIN3})

#define USART3_TX_GPIO			((Pin_cfg_t){GPIO_OUTPUT_50MHz_ALTER_PUSH_PULL, GPIO_PORTA, GPIO_PIN10})
#define USART3_RX_GPIO			((Pin_cfg_t){GPIO_INPUT_PULL_UP_MODE, GPIO_PORTA, GPIO_PIN11})


#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            (((_PCLK_)*25U)/(4U*(_BAUD_)))
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U)\
                                                         + 50U) / 100U)

/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                         (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

/**************** Data Type Declaration ********************/
static USARTx_t *const USARTS_Registers[] = {MCAL_USART1, MCAL_USART2, MCAL_USART3};
static volatile uint8_t RXChar[3] = {0};
static volatile IRQ_Status_t RXStatus = NO_IRQ;
static uint8_t RXBuffer[RX_BUFFER_SIZE+1] = {0};
/**************** Software Interfaces Declaration ********************/
//static void USART_Select_Mode(const USART_t _usart);
static void USART_GPIO_CLK_CFG(const USART_t _usart);
/**************** Software Interfaces Definition ********************/

void USART_Init(const USART_t _usart){
	uint32_t TempREG = 0;

		/* enable CLOCK */
		RCC_Enable_Peripheral_APB2(USART1EN);
		USART_GPIO_CLK_CFG(_usart);
		TempREG = _usart.StopBits;
		USARTS_Registers[_usart.usart]->USART_CR2.CR2_REG = TempREG;

		USARTS_Registers[_usart.usart]->USART_CR3.CR3_REG = 0u;

		USARTS_Registers[_usart.usart]->USART_BRR.BRR_REG = UART_BRR_SAMPLING16(F_CPU, _usart.baudRate);

		TempREG = (_usart.wordLength) | (_usart.Parity) | (_usart.Mode) | (USART_ENABLE);
		USARTS_Registers[_usart.usart]->USART_CR1.CR1_REG = TempREG;

}

void USART_DeInit(const USART_t _usart){
		/* Disable the USART */
		USARTS_Registers[_usart.usart]->USART_CR1.UE = USART_DISABLE;
}


void USART_Transmit_Byte_Polling(const USART_t _usart, uint8_t byte, uint32_t ticks){
		USARTS_Registers[_usart.usart]->USART_DR = (0xFF & byte);
	while(!(USARTS_Registers[_usart.usart]->USART_SR.TC) && (ticks--));

}

void USART_Transmit_Messege_Polling(const USART_t _usart, uint8_t *messege, uint32_t ticks){
	uint16_t TempReg = USARTS_Registers[_usart.usart]->USART_CR1.CR1_REG;
		while(*messege){
			USART_Transmit_Byte_Polling(_usart, *messege, ticks);
			messege++;
		}
		if(*messege == 0){

			TempReg |= USART_NULL_TERMINATION;
			USARTS_Registers[_usart.usart]->USART_CR1.CR1_REG = TempReg;
		}
}

uint8_t USART_Receive_Byte_Polling(const USART_t _usart, uint32_t ticks){
	uint8_t byteReceived = 0;
	while((USARTS_Registers[_usart.usart]->USART_SR.RXNE)==0 && (ticks--));
	byteReceived = ((uint8_t)USARTS_Registers[_usart.usart]->USART_DR) & 0xFF;
//	USARTS_Registers[_usart.usart]->DR = 0;
	return byteReceived;
}

uint8_t *USART_Receive_Messege_Polling(const USART_t usart, uint16_t length, uint32_t ticks){
	static uint8_t rxBuffer[RX_BUFFER_SIZE];
	memset(rxBuffer,'\0',RX_BUFFER_SIZE);
    uint16_t i = 0;
    while(i<length){
    	rxBuffer[i] = USART_Receive_Byte_Polling(usart, ticks);
    	i++;
    }
    return rxBuffer;
}

void USART_Receive_Byte_IT_EN(const USART_t _usart){
//	uint32_t Temp= USARTS_Registers[_usart.usart]->USART_CR1.CR1_REG;
//	Temp |= USART_RX_IT_EN;
//	USARTS_Registers[_usart.usart]->USART_CR1.CR1_REG = Temp;
	switch(_usart.usart){
		case USART1_EN:
			NVIC_EnableIRQ(IRQ_USART1);
			break;
		case USART2_EN:
			NVIC_EnableIRQ(IRQ_USART2);
			break;
		case USART3_EN:
			NVIC_EnableIRQ(IRQ_USART3);
			break;
		default:;
	};
	USARTS_Registers[_usart.usart]->USART_CR1.RXNEIE = 1;
}

uint8_t USART_Receive_Byte_IT(const USART_t _usart){
	uint8_t lByte=RXChar[_usart.usart];
	if(RXChar[_usart.usart] != 0){
		RXChar[_usart.usart]=0;
	}else{
//		USARTS_Registers[_usart.usart]->USART_CR1.RXNEIE = ENABLE;
	}

	return lByte;
}

uint8_t *USART_Receive_Messege_IT(const USART_t _usart){
	static uint8_t lRXBuffer[RX_BUFFER_SIZE] = {0};
	static uint16_t RX_Index = 0;
		if(CHAR_RECEIVED == RXStatus){
			if(RXChar[_usart.usart] == 0){
				if(RX_Index != 0){
					for(uint8_t i=0; i<RX_Index; i++){
						RXBuffer[i] = lRXBuffer[i];
	 				}
					RXBuffer[RX_Index] = '\0';
					RX_Index = 0;
				}
				else{}
			}
			else{
				lRXBuffer[RX_Index] = RXChar[_usart.usart];
				RX_Index++;
			}
			RXStatus = NO_IRQ;
		}else{}
	return RXBuffer;
}



static void USART_GPIO_CLK_CFG(const USART_t _usart){
	if(_usart.usart == USART1_EN){
		RCC_Enable_Peripheral_APB2(USART1EN);
		RCC_Enable_Peripheral_APB2(IOPAEN);
		switch(_usart.Mode){
			case USART_TX_RX:
				/* Configure GPIO */
				GPIO_Pin_Dir_Cfg(USART1_TX_GPIO);
				GPIO_Pin_Dir_Cfg(USART1_RX_GPIO);
				break;
			case USART_TX:
				/* Configure GPIO */
				GPIO_Pin_Dir_Cfg(USART1_TX_GPIO);
				break;
			case USART_RX:
				/* Configure GPIO */
				GPIO_Pin_Dir_Cfg(USART1_RX_GPIO);
				break;
			default:;
		};
	}
	else if(_usart.usart == USART2_EN){
		RCC_Enable_Peripheral_APB1(USART2EN);
		RCC_Enable_Peripheral_APB2(IOPAEN);
		switch(_usart.Mode){
			case USART_TX_RX:
				/* Configure GPIO */
				GPIO_Pin_Dir_Cfg(USART2_TX_GPIO);
				GPIO_Pin_Dir_Cfg(USART2_RX_GPIO);
				break;
			case USART_TX:
				/* Configure GPIO */
				GPIO_Pin_Dir_Cfg(USART2_TX_GPIO);
				break;
			case USART_RX:
				/* Configure GPIO */
				GPIO_Pin_Dir_Cfg(USART2_RX_GPIO);
				break;
			default:;
		};
	}
	else if(_usart.usart == USART3_EN){
		RCC_Enable_Peripheral_APB1(USART3EN);
		RCC_Enable_Peripheral_APB2(IOPBEN);
		switch(_usart.Mode){
			case USART_TX_RX:
				/* Configure GPIO */
				GPIO_Pin_Dir_Cfg(USART3_TX_GPIO);
				GPIO_Pin_Dir_Cfg(USART3_RX_GPIO);
				break;
			case USART_TX:
				/* Configure GPIO */
				GPIO_Pin_Dir_Cfg(USART3_TX_GPIO);
				break;
			case USART_RX:
				/* Configure GPIO */
				GPIO_Pin_Dir_Cfg(USART3_RX_GPIO);
				break;
			default:;
		};
	}
	else{}
}

void USART1_IRQHandler(void){
	if((USARTS_Registers[USART1_EN]->USART_SR.RXNE == 1) && (USARTS_Registers[USART1_EN]->USART_CR1.RXNEIE == 1)){
		RXChar[USART1_EN] = (uint8_t)USARTS_Registers[USART1_EN]->USART_DR;
		RXStatus = CHAR_RECEIVED;
	}
}

void USART2_IRQHandler(void){
	if((USARTS_Registers[USART2_EN]->USART_SR.RXNE == 1) && (USARTS_Registers[USART2_EN]->USART_CR1.RXNEIE == 1)){
		RXChar[USART2_EN] = (uint8_t)USARTS_Registers[USART2_EN]->USART_DR;
		USARTS_Registers[USART2_EN]->USART_CR1.RXNEIE = 0;
	}
}

void USART3_IRQHandler(void){
	if((USARTS_Registers[USART3_EN]->USART_SR.RXNE == 1) && (USARTS_Registers[USART3_EN]->USART_CR1.RXNEIE == 1)){
		RXChar[USART3_EN] = (uint8_t)USARTS_Registers[USART3_EN]->USART_DR;
		USARTS_Registers[USART3_EN]->USART_CR1.RXNEIE = 0;
	}
}
