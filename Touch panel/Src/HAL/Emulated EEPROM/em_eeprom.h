/*
 * em_eeprom.h
 *
 *  Created on: Aug 18, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef HAL_EMULATED_EEPROM_EM_EEPROM_H_
#define HAL_EMULATED_EEPROM_EM_EEPROM_H_



/**************** Includes ********************/
#include "../Src/MCAL/FLASH/flash.h"
/**************** Macro Declarations ********************/
#define EEPROM_MAX_DATA 			50U
#define FLASH_PAGE_SIZE 			1024U

#define EEPROM_TP_BASE_ADDRESS		0x0800F800UL

#define RED_POS			0
#define GREEN_POS		1
#define BLUE_POS		2

#define BUTTON1_SEL		0
#define BUTTON2_SEL		1
#define BUTTON3_SEL		2
/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef struct{
	int16_t TP_Led_Color[3][2][3];
}EEPROM_TP_t;
/*
{
 {{255, 0, 0},{0, 255, 0}},
 {{255, 0, 0},{0, 255, 0}},
 {{255, 0, 0},{0, 255, 0}}
}


*/

/**************** Software Interfaces Declaration ********************/
/*

void Em_EEPROM_Write (uint32_t srcAddress, uint32_t destAddress, uint32_t size);
void Em_EEPROM_Read (uint8_t *Address, uint8_t *str);
void Em_EEPROM_Edit (uint32_t srcAddress, uint32_t destAddress, uint32_t size);
void Em_EEPROM_Edit_In_Sector(uint32_t sectorAddress, uint32_t offset, uint16_t newData);
*/

/***************** New Declaration *********************/
/* write struct EEPROM_TP_t in eeprom */
void Em_EEPROM_TP_Write(EEPROM_TP_t*ptr);
void Em_EEPROM_TP_Edit(uint8_t buttonN, uint8_t state, uint8_t red, uint8_t green, uint8_t blue);
/* read struct EEPROM_TP_t in eeprom */
void Em_EEPROM_TP_Read(EEPROM_TP_t *ptr);


#endif /* HAL_EMULATED_EEPROM_EM_EEPROM_H_ */
