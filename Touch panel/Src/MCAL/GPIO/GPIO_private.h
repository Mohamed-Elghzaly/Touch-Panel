/*
 * GPIO_private.h
 *
 *  Created on: Jul 2, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef GPIO_GPIO_PRIVATE_H_
#define GPIO_GPIO_PRIVATE_H_



/**************** Includes ********************/

/**************** Macro Declarations ********************/

/******************************/



/************************ GPIO PORTS *********************/
#define MCAL_GPIOA			((GPIO_Registers_t *)0x40010800UL)
#define MCAL_GPIOB			((GPIO_Registers_t *)0x40010C00UL)
#define MCAL_GPIOC			((GPIO_Registers_t *)0x40011000UL)
#define MCAL_GPIOD			((GPIO_Registers_t *)0x40011400UL)
#define MCAL_GPIOE			((GPIO_Registers_t *)0x40011800UL)

/********************** Registers Offset **********************/
#define CRL_OFFSET		0x00
#define CRH_OFFSET		0x04
#define IDR_OFFSET		0x08
#define ODR_OFFSET		0x0C
#define BSRR_OFFSET		0x10
#define BRR_OFFSET		0x14
#define LCKR_OFFSET		0x18

/*************************************************************/
#define DIRECTION_MASK_CLEAR		0b1111


/*********************************************************/
#define GPIO_PIN_DIRECTION_START	4


/***************** Port bit CLEAR (GPIOx_BSRR) ********************/
#define GPIO_PINS_START		16


/**************** Macro Function Declarations ********************/

/************************* Port configuration register low ************************/


/**************** Data Type Declaration ********************/
/************************* CRL REGISTER **********************/


typedef union{
	 struct {
		volatile uint32_t MODE0			: 2;
		volatile uint32_t CNF0			: 2;
		volatile uint32_t MODE1			: 2;
		volatile uint32_t CNF1			: 2;
		volatile uint32_t MODE2			: 2;
		volatile uint32_t CNF2			: 2;
		volatile uint32_t MODE3			: 2;
		volatile uint32_t CNF3			: 2;
		volatile uint32_t MODE4			: 2;
		volatile uint32_t CNF4			: 2;
		volatile uint32_t MODE5			: 2;
		volatile uint32_t CNF5			: 2;
		volatile uint32_t MODE6			: 2;
		volatile uint32_t CNF6			: 2;
		volatile uint32_t MODE7			: 2;
		volatile uint32_t CNF7			: 2;
	};
	volatile uint32_t CRL_REG;
}CRL_t;

/************************* CRH REGISTER **********************/
typedef union{
	 struct {
			volatile uint32_t MODE8			: 2;
			volatile uint32_t CNF8			: 2;
			volatile uint32_t MODE9			: 2;
			volatile uint32_t CNF9			: 2;
			volatile uint32_t MODE10		: 2;
			volatile uint32_t CNF10			: 2;
			volatile uint32_t MODE11		: 2;
			volatile uint32_t CNF11			: 2;
			volatile uint32_t MODE12		: 2;
			volatile uint32_t CNF12			: 2;
			volatile uint32_t MODE13		: 2;
			volatile uint32_t CNF13			: 2;
			volatile uint32_t MODE14		: 2;
			volatile uint32_t CNF14			: 2;
			volatile uint32_t MODE15		: 2;
			volatile uint32_t CNF15			: 2;
	};
	volatile uint32_t CRH_REG;
}CRH_t;

/************************* ODR REGISTER **********************/
typedef union{
	 struct {
		volatile uint32_t ODR0			: 1;
		volatile uint32_t ODR1			: 1;
		volatile uint32_t ODR2			: 1;
		volatile uint32_t ODR3			: 1;
		volatile uint32_t ODR4			: 1;
		volatile uint32_t ODR5			: 1;
		volatile uint32_t ODR6			: 1;
		volatile uint32_t ODR7			: 1;
		volatile uint32_t ODR8			: 1;
		volatile uint32_t ODR9			: 1;
		volatile uint32_t ODR10			: 1;
		volatile uint32_t ODR11			: 1;
		volatile uint32_t ODR12			: 1;
		volatile uint32_t ODR13			: 1;
		volatile uint32_t ODR14			: 1;
		volatile uint32_t ODR15			: 1;
		volatile uint32_t RESERVED		: 15;
	};
	volatile uint32_t ODR_REG;
}ODR_t;

/************************* IDR REGISTER **********************/
typedef union{
	 struct {
		volatile uint32_t IDR0			: 1;
		volatile uint32_t IDR1			: 1;
		volatile uint32_t IDR2			: 1;
		volatile uint32_t IDR3			: 1;
		volatile uint32_t IDR4			: 1;
		volatile uint32_t IDR5			: 1;
		volatile uint32_t IDR6			: 1;
		volatile uint32_t IDR7			: 1;
		volatile uint32_t IDR8			: 1;
		volatile uint32_t IDR9			: 1;
		volatile uint32_t IDR10			: 1;
		volatile uint32_t IDR11			: 1;
		volatile uint32_t IDR12			: 1;
		volatile uint32_t IDR13			: 1;
		volatile uint32_t IDR14			: 1;
		volatile uint32_t IDR15			: 1;
		volatile uint32_t RESERVED		: 15;
	};
	 volatile uint32_t IDR_REG;
}IDR_t;

/************************* BSRR REGISTER **********************/
typedef union{
	 struct {
		volatile uint32_t BS0			: 1;
		volatile uint32_t BS1			: 1;
		volatile uint32_t BS2			: 1;
		volatile uint32_t BS3			: 1;
		volatile uint32_t BS4			: 1;
		volatile uint32_t BS5			: 1;
		volatile uint32_t BS6			: 1;
		volatile uint32_t BS7			: 1;
		volatile uint32_t BS8			: 1;
		volatile uint32_t BS9			: 1;
		volatile uint32_t BS10			: 1;
		volatile uint32_t BS11			: 1;
		volatile uint32_t BS12			: 1;
		volatile uint32_t BS13			: 1;
		volatile uint32_t BS14			: 1;
		volatile uint32_t BS15			: 1;
		volatile uint32_t BR0			: 1;
		volatile uint32_t BR1			: 1;
		volatile uint32_t BR2			: 1;
		volatile uint32_t BR3			: 1;
		volatile uint32_t BR4			: 1;
		volatile uint32_t BR5			: 1;
		volatile uint32_t BR6			: 1;
		volatile uint32_t BR7			: 1;
		volatile uint32_t BR8			: 1;
		volatile uint32_t BR9			: 1;
		volatile uint32_t BR10			: 1;
		volatile uint32_t BR11			: 1;
		volatile uint32_t BR12			: 1;
		volatile uint32_t BR13			: 1;
		volatile uint32_t BR14			: 1;
		volatile uint32_t BR15			: 1;
	};
	volatile uint32_t BSRR_REG;
}BSRR_t;


typedef struct{
	volatile uint32_t	CRL;
	volatile uint32_t	CRH;
	volatile IDR_t		IDR;
	volatile ODR_t		ODR;
	volatile BSRR_t 	BSRR;
}GPIO_Registers_t;
/**************** Software Interfaces Declaration ********************/



#endif /* GPIO_GPIO_PRIVATE_H_ */
