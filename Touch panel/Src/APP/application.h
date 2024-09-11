/*
 * application.h
 *
 *  Created on: Aug 11, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef APP_APPLICATION_H_
#define APP_APPLICATION_H_


#include "../Inc/Common.h"
#include "../Src/MCAL/RCC/RCC.h"
#include "../Src/MCAL/Backup/backup.h"
#include "../Src/MCAL/FLASH/flash.h"
#include "../Src/MCAL/GPIO/GPIO.h"
#include "../Src/MCAL/SysTick/SysTick.h"
#include "../Src/MCAL/TIMERS/timer.h"
#include "../Src/MCAL/USARTS/usart.h"
#include "../Src/MCAL/DMA/dma.h"
#include "../Src/MCAL/FLASH/flash.h"
#include "../Src/HAL/Emulated EEPROM/em_eeprom.h"
#include "../Src/HAL/Button/button.h"
#include "../Src/HAL/LED/led.h"
#include "../Src/HAL/ShiftRegister_74HC595/ShiftRegister.h"
#include "../Src/HAL/RGB_Led/RGB_Led.h"
#include "../Src/HAL/WS2812/ws2812.h"



void application(void);



#endif /* APP_APPLICATION_H_ */
