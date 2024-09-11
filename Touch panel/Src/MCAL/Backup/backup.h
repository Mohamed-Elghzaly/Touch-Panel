/*
 * backup.h
 *
 *  Created on: Aug 26, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef MCAL_BACKUP_BACKUP_H_
#define MCAL_BACKUP_BACKUP_H_


/**************** Includes ********************/
#include "../Inc/Common.h"
#include "backup_private.h"
#include "../Src/MCAL/RCC/RCC.h"

/**************** Macro Declarations ********************/
#define BUTTON1_STATE	0x00
#define BUTTON2_STATE	0x01
#define BUTTON3_STATE	0x02

#define BKP_TP_BASE_ADDRESS		0x40006C04UL
/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef struct{
	uint8_t TP_State[3];
}BKP_TP_t;

typedef enum{
	BKP_DR1,
	BKP_DR2,
	BKP_DR3,
	BKP_DR4,
	BKP_DR5,
	BKP_DR6,
	BKP_DR7,
	BKP_DR8,
	BKP_DR9,
	BKP_DR10,
	BKP_DR11,
	BKP_DR12,
	BKP_DR13,
	BKP_DR14,
	BKP_DR15,
	BKP_DR16,
	BKP_DR17,
	BKP_DR18,
	BKP_DR19,
	BKP_DR20,
	BKP_DR21,
	BKP_DR22,
	BKP_DR23,
	BKP_DR24,
	BKP_DR25,
	BKP_DR26,
	BKP_DR27,
	BKP_DR28,
	BKP_DR29,
	BKP_DR30,
	BKP_DR31,
	BKP_DR32,
	BKP_DR33,
	BKP_DR34,
	BKP_DR35,
	BKP_DR36,
	BKP_DR37,
	BKP_DR38,
	BKP_DR39,
	BKP_DR40,
	BKP_DR41,
	BKP_DR42,
}BKP_DR_t;

/**************** Software Interfaces Declaration ********************/
void BKP_Init(void);
void BKP_DeInit(void);

void BKP_WriteBackupRegister(BKP_DR_t BKP_DR, uint16_t Data);
uint16_t BKP_ReadBackupRegister(BKP_DR_t BKP_DR);

void BKP_Reset(void);
/************************* new declaration ******************************/
void BKP_WriteStruct(BKP_TP_t *Data);
void BKP_ReadStruct(BKP_TP_t *Data);

void BKP_WriteButtonState(uint8_t button, uint8_t state) ;
uint8_t BKP_ReadButtonState(uint8_t button);

#endif /* MCAL_BACKUP_BACKUP_H_ */
