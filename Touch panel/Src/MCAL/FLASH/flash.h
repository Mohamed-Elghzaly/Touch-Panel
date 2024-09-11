/*
 * flash.h
 *
 *  Created on: Aug 18, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef MCAL_FLASH_FLASH_H_
#define MCAL_FLASH_FLASH_H_

/**************** Includes ********************/
#include "../Src/MCAL/RCC/RCC.h"
#include "flash_private.h"

/**************** Macro Declarations ********************/
#define FLASH_KEY1		(0x45670123UL)
#define FLASH_KEY2		(0xCDEF89ABUL)

#define FLASH_CR_PG		(0x00000001UL)
#define FLASH_CR_PER	(0x00000002UL)
#define FLASH_CR_MER	(0x00000004UL)
#define FLASH_CR_STRT	(0x00000040UL)
#define FLASH_CR_LOCK	(0x00000080UL)
#define FLASH_SR_EOP	(0x00000020UL)
#define FLASH_SR_BSY	(0x00000001UL)
/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
//typedef enum{
//	FLASH_PAGE0		= 0x08000000,
//	FLASH_PAGE1		= 0x08000400,
//	FLASH_PAGE2		= 0x08000800,
//	FLASH_PAGE3		= 0x08000C00,
//	FLASH_PAGE4		= 0x08001000,
//	FLASH_PAGE5		= 0x08001400,
//	FLASH_PAGE6		= 0x08001800,
//	FLASH_PAGE7		= 0x08001C00,
//	FLASH_PAGE8		= 0x08002000,
//	FLASH_PAGE9		= 0x08002400,
//	FLASH_PAGE10	= 0x08002800,
//	FLASH_PAGE11	= 0x08002C00,
//	FLASH_PAGE12	= 0x08003000,
//	FLASH_PAGE13	= 0x08003400,
//	FLASH_PAGE14	= 0x08003800,
//	FLASH_PAGE15	= 0x08003C00,
//	FLASH_PAGE16	= 0x08004000,
//	FLASH_PAGE17	= 0x08004400,
//	FLASH_PAGE18	= 0x08004800,
//	FLASH_PAGE19	= 0x08004C00,
//	FLASH_PAGE20	= 0x08005000,
//	FLASH_PAGE21	= 0x08005400,
//	FLASH_PAGE22	= 0x08005800,
//	FLASH_PAGE23	= 0x08005C00,
//	FLASH_PAGE24	= 0x08006000,
//	FLASH_PAGE25	= 0x08006400,
//	FLASH_PAGE26	= 0x08006800,
//	FLASH_PAGE27	= 0x08006C00,
//	FLASH_PAGE28	= 0x08007000,
//	FLASH_PAGE29	= 0x08007400,
//	FLASH_PAGE30	= 0x08007800,
//	FLASH_PAGE31	= 0x08007C00
//}FLASH_PAGE_t;
/**************** Software Interfaces Declaration ********************/
/* unlock flash memory */
void Flash_Unlock(void);
/* lock flash memory */
void Flash_Lock(void);
/* write half word (2 byte) in flash  */
void Flash_Program_HalfWord(uint16_t *address, uint16_t data);
/* erase page in flash */
void Flash_Erase_Page(uint32_t page);
/* erase all flash */
void Flash_Erase_Mass(void);
/* write string in flash with (\0) */
void Flash_Write_String(uint16_t* address, const uint8_t* str);
#endif /* MCAL_FLASH_FLASH_H_ */
