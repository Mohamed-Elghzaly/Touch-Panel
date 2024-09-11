/*
 * backup.c
 *
 *  Created on: Aug 26, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#include "backup.h"



void BKP_Init(void) {
	RCC_Enable_Peripheral_APB1(BKPEN);
	RCC_Enable_Peripheral_APB1(PWREN);
	 /* Allow access to Backup domain */
	*(volatile uint32_t*) 0x40007000 |= 0x100;
}

void BKP_DeInit(void) {
	RCC_Disable_Peripheral_APB1(BKPEN);
	RCC_Disable_Peripheral_APB1(PWREN);

	*(volatile uint32_t*) 0x40007000 &= ~0x100;
}

void BKP_WriteBackupRegister(BKP_DR_t BKP_DR, uint16_t Data) {
	if (BKP_DR < 10)
		MCAL_BKP->BKP_DR0x[BKP_DR] = Data;
	else
		MCAL_BKP->BKP_DRxx[BKP_DR] = Data;
}

uint16_t BKP_ReadBackupRegister(BKP_DR_t BKP_DR) {
//	uint16_t Temp=0;
//	if(BKP_DR < 10)
//		Temp = MCAL_BKP->BKP_DR0x[BKP_DR];
//	else
//		Temp = MCAL_BKP->BKP_DRxx[BKP_DR];
	return (BKP_DR < 10) ?
			MCAL_BKP->BKP_DR0x[BKP_DR] : MCAL_BKP->BKP_DRxx[BKP_DR];
}

void BKP_Reset(void) {
	/* Reset the Backup domain */
	RCC_BackupReset(ENABLE);
	/* Release the reset */
	RCC_BackupReset(DISABLE);
}

/************************* new definition ******************************/
void BKP_WriteStruct(BKP_TP_t *Data) {
	BKP_WriteBackupRegister(BKP_DR1, Data->TP_State[BUTTON1_STATE]);
	BKP_WriteBackupRegister(BKP_DR2, Data->TP_State[BUTTON2_STATE]);
	BKP_WriteBackupRegister(BKP_DR3, Data->TP_State[BUTTON3_STATE]);
}
void BKP_ReadStruct(BKP_TP_t *Data) {
	Data->TP_State[BUTTON1_STATE] = (uint8_t) (BKP_ReadBackupRegister(BKP_DR1) & 0xFF);
	Data->TP_State[BUTTON2_STATE] = (uint8_t)((BKP_ReadBackupRegister(BKP_DR2) & 0xFF));
	Data->TP_State[BUTTON3_STATE] = (uint8_t) (BKP_ReadBackupRegister(BKP_DR3) & 0xFF);
}


void BKP_WriteButtonState(uint8_t button, uint8_t state) {
	BKP_WriteBackupRegister(button, state);
}
uint8_t BKP_ReadButtonState(uint8_t button) {
	return (BKP_ReadBackupRegister(button));
}
