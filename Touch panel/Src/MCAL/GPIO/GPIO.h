/*
 * GPIO.h
 *
 *  Created on: Jul 2, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_



/**************** Includes ********************/
#include <stdint.h>
#include "GPIO_private.h"
#include "../Inc/Common.h"
#include "Pins.h"

/**************** Macro Declarations ********************/
/************** select port *****************/
#define GPIO_PORTA 0U
#define GPIO_PORTB 1U
#define GPIO_PORTC 2U
#define GPIO_PORTD 3U
#define GPIO_PORTE 4U
/************** select pin *****************/
#define GPIO_PIN0			0U
#define GPIO_PIN1			1U
#define GPIO_PIN2			2U
#define GPIO_PIN3			3U
#define GPIO_PIN4			4U
#define GPIO_PIN5			5U
#define GPIO_PIN6			6U
#define GPIO_PIN7			7U
#define GPIO_PIN8			8U
#define GPIO_PIN9			9U
#define GPIO_PIN10			10U
#define GPIO_PIN11			11U
#define GPIO_PIN12			12U
#define GPIO_PIN13			13U
#define GPIO_PIN14			14U
#define GPIO_PIN15			15U

/******** select logic *********/
#define GPIO_LOW			0U
#define GPIO_HIGH			1U

/* INPUT DIRECTION CONFIGURATION */
#define GPIO_INPUT_ANALOG_MODE										0B00000
#define GPIO_INPUT_FLOATING_MODE									0B00100
#define GPIO_INPUT_PULL_UP_MODE										0B11000 // ODR REG -> 1
#define GPIO_INPUT_PULL_DOWN_MODE									0B01000 // ODR REG -> 0

/* OUTPUT DIRECTION LOW SPEED CONFIGURATION */
#define GPIO_OUTPUT_2MHz_GEN_PUSH_PULL								0B00010
#define GPIO_OUTPUT_2MHz_GEN_OPEN_DRAIN								0B00110
#define GPIO_OUTPUT_2MHz_ALTER_PUSH_PULL							0B01010
#define GPIO_OUTPUT_2MHz_ALTER_OPEN_DRAIN							0B01110

/* OUTPUT DIRECTION MEDIUM SPEED CONFIGURATION */
#define GPIO_OUTPUT_10MHz_GEN_PUSH_PULL								0B00001
#define GPIO_OUTPUT_10MHz_GEN_OPEN_DRAIN							0B00101
#define GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL							0B01001
#define GPIO_OUTPUT_10MHz_ALTER_OPEN_DRAIN							0B01101

/* OUTPUT DIRECTION HIGH SPEED CONFIGURATION */
#define GPIO_OUTPUT_50MHz_GEN_PUSH_PULL								0B00011
#define GPIO_OUTPUT_50MHz_GEN_OPEN_DRAIN							0B00111
#define GPIO_OUTPUT_50MHz_ALTER_PUSH_PULL							0B01011
#define GPIO_OUTPUT_50MHz_ALTER_OPEN_DRAIN							0B01111

/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/
typedef struct{
	uint8_t cfg;
	uint8_t port;
	uint8_t pin;
}Pin_cfg_t;
/**************** Software Interfaces Declaration ********************/
/*
 * @brief : configure Direction and CFG
 */
void GPIO_Pin_Dir_Cfg(const Pin_cfg_t pin);
/*
 * @brief : Set High to pin
 */
void GPIO_Pin_Set(const Pin_cfg_t _pin);
/*
 * @brief : Set Low to pin
 */
void GPIO_Pin_Clear(const Pin_cfg_t _pin);
/*
 * @brief : Toggle to pin
 */
void GPIO_Pin_Toggle(const Pin_cfg_t _pin);
/*
 * @brief : return state of pin
 */
uint8_t GPIO_Pin_Read(const Pin_cfg_t _pin);
/*
 * @brief : Write logic to pin
 */
void GPIO_Pin_Write_logic(const Pin_cfg_t _pin, uint8_t logic);

#endif /* GPIO_GPIO_H_ */
