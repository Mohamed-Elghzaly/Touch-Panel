/*
 * ShiftRegister.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#include "ShiftRegister.h"

static uint32_t value = 0;

void ShiftRegister_Initialize(const ShiftRegister_t shift_reg){
	GPIO_Pin_Dir_Cfg(shift_reg.RCLK);
	GPIO_Pin_Clear(shift_reg.RCLK);

	GPIO_Pin_Dir_Cfg(shift_reg.SER);
	GPIO_Pin_Clear(shift_reg.SER);

	GPIO_Pin_Dir_Cfg(shift_reg.SRCLK);
	GPIO_Pin_Clear(shift_reg.SRCLK);
}

void ShiftRegister_Shift_8Bits(const ShiftRegister_t shift_reg, uint8_t data){
    	value = data;
//		GPIO_Pin_Set2(&(shift_reg.SRCLR));
		for(int8_t i=7; i>=0; i--){
			GPIO_Pin_Write_logic(shift_reg.SER, (READ_BIT(value,i)));
			GPIO_Pin_Clear(shift_reg.SRCLK);
			GPIO_Pin_Set(shift_reg.SRCLK);
		}
		GPIO_Pin_Clear(shift_reg.RCLK);
		GPIO_Pin_Set(shift_reg.RCLK);
}
void ShiftRegister_Shift_4Bits(const ShiftRegister_t shift_reg, uint8_t data){
    	value = data;
//		GPIO_Pin_Set2(&(shift_reg.SRCLR));
		for(int8_t i=3; i>=0; i--){
			GPIO_Pin_Write_logic(shift_reg.SER, (READ_BIT(value,i)));
			GPIO_Pin_Clear(shift_reg.SRCLK);
			GPIO_Pin_Set(shift_reg.SRCLK);
		}
		GPIO_Pin_Clear(shift_reg.RCLK);
		GPIO_Pin_Set(shift_reg.RCLK);
}


void ShiftRegister_Digial_Edit_Bit(ShiftRegister_t shift_reg, uint8_t bitNumber, uint8_t state){

        if(state){
            SET_BIT(value,bitNumber);
        }else{
            CLEAR_BIT(value,bitNumber);
        }
		for(int i=7; i>=0; i--){
			GPIO_Pin_Write_logic(shift_reg.SER, (READ_BIT(value,i)));
			GPIO_Pin_Clear(shift_reg.SRCLK);
			GPIO_Pin_Set(shift_reg.SRCLK);
		}
		GPIO_Pin_Clear(shift_reg.RCLK);
		GPIO_Pin_Set(shift_reg.RCLK);
}

void ShiftRegister_shift_N_Byte(ShiftRegister_t shift_reg, uint8_t *data){
    if(NULL == data){

    }
    else{
    	while(*data){
        	ShiftRegister_Shift_8Bits(shift_reg, *data);
        	data++;
    	}
    }
}

void ShiftRegister_shift_N_Bits(ShiftRegister_t shift_reg, uint32_t data, uint32_t length){

    	value = data;
		for(int8_t i=length-1; i>=0; i--){
			GPIO_Pin_Write_logic(shift_reg.SER, (READ_BIT(value,i)));
			GPIO_Pin_Clear(shift_reg.SRCLK);
			GPIO_Pin_Set(shift_reg.SRCLK);
		}
		GPIO_Pin_Clear(shift_reg.RCLK);
		GPIO_Pin_Set(shift_reg.RCLK);
}

void ShiftRegister_shift_1_Bits(ShiftRegister_t shift_reg, uint8_t data){
	value = data;
	GPIO_Pin_Write_logic(shift_reg.SER, (READ_BIT(value,data)));
	GPIO_Pin_Clear(shift_reg.SRCLK);
	GPIO_Pin_Set(shift_reg.SRCLK);
	GPIO_Pin_Clear(shift_reg.RCLK);
	GPIO_Pin_Set(shift_reg.RCLK);
}
