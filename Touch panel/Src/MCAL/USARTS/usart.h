/*
 * usart.h
 *
 *  Created on: Jul 29, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef MCAL_USART_USART1_USART_H_
#define MCAL_USART_USART1_USART_H_




/**************** Includes ********************/
#include <stdint.h>
#include <string.h>
#include "../Inc/Common.h"
#include "usart_private.h"
#include "usart_cfg.h"
#include "../Src/MCAL/RCC/RCC.h"
#include "../Src/MCAL/GPIO/GPIO.h"
#include "../Src/MCAL/NVIC/NVIC.h"

/**************** Macro Declarations ********************/
/* Buffer to store received string */
#define RX_BUFFER_SIZE		100U

/* select witch timer */
#define USART1_EN			0U
#define USART2_EN			1U
#define USART3_EN			2U

/* Transmitter and Receiver enable */
#define USART_TX_RX						0xC
#define USART_TX						0x8
#define USART_RX						0x4

/* Interrupt Receive Enable */
#define USART_RX_IT_EN					0x20

/* Send Null Termination */
#define USART_NULL_TERMINATION			1

/* SET WORD LENGTH */
#define USART_WORD_LENGTH_8BITS			0x0
#define USART_WORD_LENGTH_9BITS			(0x1008U)

/* STOP bits */
#define USART_1_STOP_BIT				0x0
#define USART_POINT_5_STOP_BIT			0x1000
#define USART_2_STOP_BIT				0x2000
#define USART_1_POINT_5_STOP_BIT		0x3000

/* Enable the USART */
#define USART_ENABLE					0x2000
#define USART_DISABLE					0x0

/**/
#define USART_EVEN_PARITY				0x400
#define USART_ODD_PARITY				0x600
#define USART_PARITY_NONE				0x0

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef enum{
	NO_IRQ,
	CHAR_RECEIVED
}IRQ_Status_t;

typedef struct{
	uint32_t baudRate;
	uint8_t usart;
	uint8_t Mode;
	uint8_t Parity;
	uint8_t StopBits;
	uint32_t wordLength;
}USART_t;

/**************** Software Interfaces Declaration ********************/
/* initialization uart */
void USART_Init(const USART_t usart);
/* deinitialization uart */
void USART_DeInit(const USART_t usart);

/* send 1 byte polling */
void USART_Transmit_Byte_Polling(const USART_t usart, uint8_t byte, uint32_t ticks);
/* send n bytes polling */
void USART_Transmit_Messege_Polling(const USART_t usart, uint8_t *messege, uint32_t ticks);

/* receive 1 byte polling */
uint8_t USART_Receive_Byte_Polling(const USART_t _usart, uint32_t ticks);
/* receive n byte polling */
uint8_t *USART_Receive_Messege_Polling(const USART_t usart, uint16_t length, uint32_t ticks);

/* enable interrupt for UART receive */
void USART_Receive_Byte_IT_EN(const USART_t _usart);
/*
 * receive 1 byte by interrupt
 * must call USART_Receive_Byte_IT_EN(const USART_t _usart);
*/
uint8_t USART_Receive_Byte_IT(const USART_t _usart);
/*
 * receive n byte by interrupt
 * must call USART_Receive_Byte_IT_EN(const USART_t _usart);
*/
uint8_t *USART_Receive_Messege_IT(const USART_t usart);


#endif /* MCAL_USART_USART1_USART_H_ */
