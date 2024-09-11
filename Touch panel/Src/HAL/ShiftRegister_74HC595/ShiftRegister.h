/*
 * ShiftRegister.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef SHIFTREGISTER_H
#define	SHIFTREGISTER_H


/*------------------- Includes -------------------*/
#include "../Src/MCAL/GPIO/GPIO.h"
#include "../Src/MCAL/SysTick/SysTick.h"

/*------------------- Macro Declarations -------------------*/
#define SR_HIGH   1
#define SR_LOW    0
/*------------------- Macro Functions Declarations -------------------*/

/*------------------- Data Type Declarations -------------------*/
typedef struct{
	Pin_cfg_t RCLK;
	Pin_cfg_t SRCLK;
	Pin_cfg_t SER;
}ShiftRegister_t;

/*------------------- Software Interfaces Declarations -------------------*/
void ShiftRegister_Initialize(const ShiftRegister_t shift_register);
void ShiftRegister_Shift_8Bits(const ShiftRegister_t shift_register, uint8_t data);
void ShiftRegister_Shift_4Bits(const ShiftRegister_t shift_reg, uint8_t data);
void ShiftRegister_Digial_Edit_Bit(ShiftRegister_t shift_register, uint8_t bitNumber, uint8_t state);
void ShiftRegister_shift_N_Byte(ShiftRegister_t shift_register, uint8_t *data);
void ShiftRegister_shift_N_Bits(ShiftRegister_t shift_reg, uint32_t data, uint32_t length);
void ShiftRegister_shift_1_Bits(ShiftRegister_t shift_reg, uint8_t data);


#endif	/* SHIFTREGISTER_H */

