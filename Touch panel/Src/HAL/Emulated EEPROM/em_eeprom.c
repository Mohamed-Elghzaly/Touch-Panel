/*
 * em_eeprom.c
 *
 *  Created on: Aug 18, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */


#include "em_eeprom.h"


/*
void Em_EEPROM_Write(uint32_t srcAddress, uint32_t destAddress, uint32_t size)
{
	 Unlock the Flash memory
    Flash_Unlock();
    uint32_t endAddress = srcAddress + size;
    uint32_t eraseAddress = destAddress;
     Erase the destination pages
    while (eraseAddress < (destAddress+size))
    {
        Flash_Erase_Page(eraseAddress);
        eraseAddress += 1024;
    }
    // Copy data from source to destination
    while (srcAddress < endAddress)
    {
        uint16_t data = *(volatile uint16_t*)srcAddress;  // Read a byte from the source address
        Flash_Program_HalfWord(destAddress, data);      // Write the byte to the destination address
        srcAddress +=2;
        destAddress +=2;
    }
     Lock the Flash memory after writing
    Flash_Lock();
}


void Em_EEPROM_Read (uint8_t *Address, uint8_t *str)
{
	str = Address;
	return;
}

 edit part in emulated eeprom
void Em_EEPROM_Edit (uint32_t srcAddress, uint32_t destAddress, uint32_t size){
	uint16_t Data[FLASH_PAGE_SIZE/2] = {0};
	uint32_t ldestAddress = destAddress;
	ldestAddress &= (0xFFFFFF00);
	 Read the entire sector into the buffer
	for(uint32_t i=0; i<FLASH_PAGE_SIZE/2; i++)
	{
		Data[i] = *(volatile uint16_t *)(ldestAddress+(i*2));
	}
	 Modify the specific data in the buffer
	ldestAddress = destAddress - ldestAddress;
	for(uint32_t i=ldestAddress; i<ldestAddress+size; i++)
	{
		Data[i] = *(uint16_t *)(srcAddress);
		srcAddress += 2;
	}
	 Write the modified buffer back to Flash memory
	Em_EEPROM_Write((uint32_t)Data , (destAddress & 0xFFFFFF00), 1024);
}
 edit specific halfword in emulated eeprom
void Em_EEPROM_Edit_In_Sector(uint32_t sectorAddress, uint32_t offset, uint16_t newData){
	  uint16_t buffer[FLASH_PAGE_SIZE / 2];
	    uint32_t i;
	    Flash_Unlock();
	    // Step 1: Read the entire sector into the buffer
	    for (i = 0; i < FLASH_PAGE_SIZE / 2; i++)
	    {
	        buffer[i] = *(volatile uint16_t*)(sectorAddress + (i * 2));
	    }

	    // Step 2: Modify the specific data in the buffer
	    buffer[offset / 2] = newData;

	    // Step 3: Erase the sector in Flash memory
	    Flash_Erase_Page(sectorAddress);

	    // Step 4: Write the modified buffer back to Flash memory
	    for (i = 0; i < FLASH_PAGE_SIZE / 2; i++)
	    {
	        Flash_Program_HalfWord(sectorAddress + (i * 2), buffer[i]);
	    }
	    Flash_Lock();
}

*/


/***************** New Definition *********************/
void Em_EEPROM_TP_Write(EEPROM_TP_t*ptr)
{
	uint16_t *pData = (uint16_t *)ptr;
	Flash_Unlock();
	for(int i=0; i< sizeof(EEPROM_TP_t)/2; i++)
	{
		Flash_Program_HalfWord((uint16_t *)EEPROM_TP_BASE_ADDRESS+i , (uint16_t)(*(pData+i)));
	}
	Flash_Lock();
}

void Em_EEPROM_TP_Edit(uint8_t buttonN, uint8_t state, uint8_t red, uint8_t green, uint8_t blue)
{
	EEPROM_TP_t Temp = {0};
	/* read from flash */
	Temp = *((EEPROM_TP_t *)EEPROM_TP_BASE_ADDRESS);
	/* modify data*/
	Temp.TP_Led_Color[buttonN][state][RED_POS] = red;
	Temp.TP_Led_Color[buttonN][state][GREEN_POS] = green;
	Temp.TP_Led_Color[buttonN][state][BLUE_POS] = blue;
	/* write in flash */
	Flash_Unlock();
	Flash_Erase_Page(EEPROM_TP_BASE_ADDRESS);
	Em_EEPROM_TP_Write(&Temp);
	Flash_Lock();

}

void Em_EEPROM_TP_Read(EEPROM_TP_t *ptr)
{

		/* read from flash */
		*(ptr) = *((EEPROM_TP_t *)EEPROM_TP_BASE_ADDRESS);
}
