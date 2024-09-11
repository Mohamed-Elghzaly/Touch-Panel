/*
 * backup_private.h
 *
 *  Created on: Aug 26, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef MCAL_BACKUP_BACKUP_PRIVATE_H_
#define MCAL_BACKUP_BACKUP_PRIVATE_H_

/**************** Includes ********************/
#define MCAL_BKP_BASE				(0x40006C00UL)
#define MCAL_BKP				((Backup_t *)MCAL_BKP_BASE)

/**************** Macro Declarations ********************/

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef union{
	struct{
		volatile uint32_t CAL 		:7;
		volatile uint32_t CCO		:1;
		volatile uint32_t ASOE		:1;
		volatile uint32_t ASOS 		:1;
		volatile uint32_t RESERVED 	:22;
	};
	volatile uint32_t BKP_RTCCR_REG;
}BKP_RTCCR_t;

typedef union{
	struct{
		volatile uint32_t TPE 		:1;
		volatile uint32_t TPAL		:1;
		volatile uint32_t RESERVED 	:30;
	};
	volatile uint32_t BKP_CR_REG;
}BKP_CR_t;

typedef union{
	struct{
		volatile uint32_t CTE 		:1;
		volatile uint32_t CTI		:1;
		volatile uint32_t TPIE		:1;
		volatile uint32_t RESERVED0 :5;
		volatile uint32_t TEF		:1;
		volatile uint32_t TIF		:1;
		volatile uint32_t RESERVED1 :22;
	};
	volatile uint32_t BKP_CSR_REG;
}BKP_CSR_t;

typedef struct{
	volatile uint32_t		RESERVED0;
	volatile uint32_t		BKP_DR0x[10];
	volatile BKP_RTCCR_t 	BKP_RTCCR;
	volatile BKP_CR_t 		BKP_CR;
	volatile BKP_CSR_t 		BKP_CSR;
	volatile uint32_t 		RESERVED1[2];
	volatile uint32_t		BKP_DRxx[32];
}Backup_t;


#endif /* MCAL_BACKUP_BACKUP_PRIVATE_H_ */
