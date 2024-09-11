/*
 * flash_private.h
 *
 *  Created on: Aug 18, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef MCAL_FLASH_FLASH_PRIVATE_H_
#define MCAL_FLASH_FLASH_PRIVATE_H_

/**************** Includes ********************/

/**************** Macro Declarations ********************/
#define MCAL_FLASH_BASE			(0x40022000UL)
#define MCAL_FLASH				((FLASH_t *)MCAL_FLASH_BASE)
/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef union{
	struct{
		volatile uint32_t LATENCY		:3;
		volatile uint32_t HLFCYA		:1;
		volatile uint32_t PRFTBE		:1;
		volatile uint32_t PRFTBS		:1;
		volatile uint32_t RESERVED		:26;
	};
	uint32_t FLASH_ACR_REG;
}FLASH_ACR_t;

typedef union{
	struct{
		volatile uint32_t BSY		:1;
		volatile uint32_t RESERVED0	:1;
		volatile uint32_t PGERR		:1;
		volatile uint32_t RESERVED1	:1;
		volatile uint32_t WRPRTERR	:1;
		volatile uint32_t EOP		:1;
		volatile uint32_t RESERVED2	:26;
	};
	uint32_t FLASH_SR_REG;
}FLASH_SR_t;

typedef union{
	struct{
		volatile uint32_t PG		:1;
		volatile uint32_t PER		:1;
		volatile uint32_t MER		:1;
		volatile uint32_t RESERVED0	:1;
		volatile uint32_t OPTPG		:1;
		volatile uint32_t OPTER		:1;
		volatile uint32_t STRT		:1;
		volatile uint32_t LOCK		:1;
		volatile uint32_t RESERVED1	:1;
		volatile uint32_t OPTWRE	:1;
		volatile uint32_t ERRIE		:1;
		volatile uint32_t RESERVED2	:1;
		volatile uint32_t EOPIE		:1;
		volatile uint32_t RESERVED3	:19;
	};
	uint32_t FLASH_CR_REG;
}FLASH_CR_t;

typedef union{
	struct{
		volatile uint32_t OPTERR	:1;
		volatile uint32_t RDPRT		:1;
		volatile uint32_t USER		:3;
		volatile uint32_t RESERVED0	:5;
		volatile uint32_t Data0		:8;
		volatile uint32_t Data1		:8;
		volatile uint32_t RESERVED1	:5;
	};
	uint32_t FLASH_OBR_REG;
}FLASH_OBR_t;

typedef struct{
	volatile FLASH_ACR_t	FLASH_ACR;
	volatile uint32_t		FLASH_KEYR;
	volatile uint32_t		FLASH_OPTKEYR;
	volatile FLASH_SR_t		FLASH_SR;
	volatile FLASH_CR_t		FLASH_CR;
	volatile uint32_t		FLASH_AR;
	volatile FLASH_OBR_t	FLASH_OBR;
	volatile uint32_t		FLASH_WRPR;
}FLASH_t;

/**************** Software Interfaces Declaration ********************/



#endif /* MCAL_FLASH_FLASH_PRIVATE_H_ */
