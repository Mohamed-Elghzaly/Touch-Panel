/*
 * flash.c
 *
 *  Created on: Aug 18, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */


#include "flash.h"


void Flash_Unlock(void) {
    if ((MCAL_FLASH->FLASH_CR.FLASH_CR_REG & FLASH_CR_LOCK) != 0) {  // Check if the Flash is locked
        // Unlock the Flash
    	MCAL_FLASH->FLASH_KEYR = FLASH_KEY1;
    	MCAL_FLASH->FLASH_KEYR = FLASH_KEY2;
    }
}

void Flash_Lock(void) {
	MCAL_FLASH->FLASH_CR.FLASH_CR_REG |= FLASH_CR_LOCK;  // Lock the Flash memory
}


void Flash_Erase_Page(uint32_t page){
	/* Check that no Flash memory operation is ongoing */
	while(MCAL_FLASH->FLASH_SR.BSY);
	/* Set the PER bit in the FLASH_CR register */
	MCAL_FLASH->FLASH_CR.FLASH_CR_REG |= FLASH_CR_PER;
	/* Program the FLASH_AR register to select a page to erase */
	MCAL_FLASH->FLASH_AR = page;
	/* Set the STRT bit in the FLASH_CR register */
	MCAL_FLASH->FLASH_CR.FLASH_CR_REG |= FLASH_CR_STRT;
	/* Wait for the BSY bit to be reset */
	while(MCAL_FLASH->FLASH_SR.BSY);
	/* Disable page erase */
	MCAL_FLASH->FLASH_CR.FLASH_CR_REG &= ~FLASH_CR_PER;
    // Check for errors
	  if (MCAL_FLASH->FLASH_SR.FLASH_SR_REG & FLASH_SR_EOP) {
		  MCAL_FLASH->FLASH_SR.FLASH_SR_REG |= FLASH_SR_EOP;  // Clear the End of Programming flag
	    }else {}
	/* Read the erased page and verify */

}

void Flash_Erase_Mass(void){
	/* Check that no Flash memory operation is ongoing */
	while(MCAL_FLASH->FLASH_SR.BSY);
	/* Set the MER bit in the FLASH_CR register */
	MCAL_FLASH->FLASH_CR.FLASH_CR_REG |= FLASH_CR_MER;
	/* Set the STRT bit in the FLASH_CR register */
	MCAL_FLASH->FLASH_CR.FLASH_CR_REG |= FLASH_CR_STRT;
	/* Wait for the BSY bit to be reset */
	while(MCAL_FLASH->FLASH_SR.BSY);
	/* Read all the pages and verify */
}

void Flash_Program_HalfWord(uint16_t *address, uint16_t data){
	/* Check that no Flash memory operation is ongoing */
	while(MCAL_FLASH->FLASH_SR.FLASH_SR_REG & FLASH_SR_BSY);
	/* Write FLASH_CR_PG to 1 */
	MCAL_FLASH->FLASH_CR.FLASH_CR_REG |= FLASH_CR_PG;
    /* Write the byte to the specified address */
    *address = data;
	/* Wait for the BSY bit to be reset */
	while(MCAL_FLASH->FLASH_SR.FLASH_SR_REG & FLASH_SR_BSY);
	/* Disable programming */
	MCAL_FLASH->FLASH_CR.FLASH_CR_REG &= ~FLASH_CR_PG;
    // Check for errors
	  if (MCAL_FLASH->FLASH_SR.FLASH_SR_REG & FLASH_SR_EOP) {
		  MCAL_FLASH->FLASH_SR.FLASH_SR_REG |= FLASH_SR_EOP;  // Clear the End of Programming flag
	    }else {}
}

void Flash_Write_String(uint16_t* address, const uint8_t* str) {
    uint16_t halfWord;
    while (*str) {
        halfWord = *str;  // Get the lower byte (first character)
        str++;
        if (*str) {
            halfWord |= (*str << 8);  // Get the next character and form the half-word
            str++;

        }else {
            halfWord &= 0x00FF;  // If the string is odd length, fill the upper byte with 0xFF
            str++;
        }
        Flash_Program_HalfWord(address, halfWord);  // Write the half-word to Flash
        address += 2;  // Move to the next half-word address
    }
    if((*str == '\0') && (*(str-1))){
    	Flash_Program_HalfWord(address, 0xFF00);
    }
}
