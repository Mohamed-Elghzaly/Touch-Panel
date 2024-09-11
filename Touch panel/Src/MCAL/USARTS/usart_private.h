/*
 * usart_private.h
 *
 *  Created on: Jul 29, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef MCAL_USART_USART1_USART_PRIVATE_H_
#define MCAL_USART_USART1_USART_PRIVATE_H_



/**************** Includes ********************/

/**************** Macro Declarations ********************/
#define USART1_BASE					(0x40013800UL)
#define MCAL_USART1						((USARTx_t *)USART1_BASE)

#define USART2_BASE					(0x40004400UL)
#define MCAL_USART2						((USARTx_t *)USART1_BASE)

#define USART3_BASE					(0x40004800UL)
#define MCAL_USART3						((USARTx_t *)USART1_BASE)

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef union{
	struct{
		volatile uint32_t PE			:1;
		volatile uint32_t FE			:1;
		volatile uint32_t NE			:1;
		volatile uint32_t ORE			:1;
		volatile uint32_t IDLE			:1;
		volatile uint32_t RXNE			:1;
		volatile uint32_t TC			:1;
		volatile uint32_t TXE			:1;
		volatile uint32_t LBD			:1;
		volatile uint32_t CTS			:1;
		volatile uint32_t RESERVED		:22;
	};
	volatile uint32_t SR_REG;
}SR_t;

typedef union{
	struct{
		volatile uint32_t DIV_Fraction		:4;
		volatile uint32_t DIV_Mantissa		:12;
		volatile uint32_t RESERVED			:16;
	};
	volatile uint32_t BRR_REG;
}BRR_t;

typedef union{
	struct{
		volatile uint32_t SBK				:1;
		volatile uint32_t RWU				:1;
		volatile uint32_t RE				:1;
		volatile uint32_t TE				:1;
		volatile uint32_t IDLEIE			:1;
		volatile uint32_t RXNEIE			:1;
		volatile uint32_t TCIE				:1;
		volatile uint32_t TXEIE				:1;
		volatile uint32_t PEIE				:1;
		volatile uint32_t PS				:1;
		volatile uint32_t PCE				:1;
		volatile uint32_t WAKE				:1;
		volatile uint32_t M					:1;
		volatile uint32_t UE				:1;
		volatile uint32_t RESERVED			:18;
	};
	volatile uint32_t CR1_REG;
}CR1_t;

typedef union{
	struct{
		volatile uint32_t ADD		:4;
		volatile uint32_t RES		:1;
		volatile uint32_t LBDL		:1;
		volatile uint32_t LBDIE		:1;
		volatile uint32_t RES2		:1;
		volatile uint32_t LBCL		:1;
		volatile uint32_t CPHA		:1;
		volatile uint32_t CPOL		:1;
		volatile uint32_t CLKEN		:1;
		volatile uint32_t STOP		:2;
		volatile uint32_t LINEN		:1;
		volatile uint32_t RESERVED	:17;
	};
	volatile uint32_t CR2_REG;
}CR2_t;

typedef union{
	struct{
		volatile uint32_t EIE		:1;
		volatile uint32_t IREN		:1;
		volatile uint32_t IRLP		:1;
		volatile uint32_t HDSEL		:1;
		volatile uint32_t NACK		:1;
		volatile uint32_t SCEN		:1;
		volatile uint32_t DMAR		:1;
		volatile uint32_t DMAT		:1;
		volatile uint32_t RTSE		:1;
		volatile uint32_t CTSE		:1;
		volatile uint32_t CTSIE		:1;
		volatile uint32_t RESERVED	:21;
	};
	volatile uint32_t CR3_REG;
}CR3_t;

typedef union{
	struct{
		volatile uint32_t PSC			:8;
		volatile uint32_t GT			:8;
		volatile uint32_t RESERVED		:16;
	};
	volatile uint32_t GTPR_REG;
}GTPR_t;

typedef struct{
	volatile SR_t 		USART_SR;
	volatile uint32_t 	USART_DR;
	volatile BRR_t 		USART_BRR;
	volatile CR1_t 		USART_CR1;
	volatile CR2_t 		USART_CR2;
	volatile CR3_t 		USART_CR3;
	volatile GTPR_t		USART_GTPR;
}USARTx_t;
/**************** Software Interfaces Declaration ********************/


#endif /* MCAL_USART_USART1_USART_PRIVATE_H_ */
