/*
 * GPIO.c
 *
 *  Created on: Jul 2, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#include "GPIO.h"


GPIO_Registers_t *GPIO_Registers[] = {MCAL_GPIOA, MCAL_GPIOB, MCAL_GPIOC, MCAL_GPIOD, MCAL_GPIOE};

void GPIO_Pin_Dir_Cfg(const Pin_cfg_t _pin){
	uint8_t lPin= (_pin.pin);
	uint8_t lCfg= (_pin.cfg) & 0b01111;
	if(_pin.cfg == GPIO_INPUT_PULL_UP_MODE){
		SET_BIT((GPIO_Registers[(_pin.port)]->ODR.ODR_REG), _pin.pin);
	}
	else if(_pin.cfg == GPIO_INPUT_PULL_DOWN_MODE){
		CLEAR_BIT((GPIO_Registers[(_pin.port)]->ODR.ODR_REG), _pin.pin);
	}
	if(7 >= lPin){
		MODIFY_REG((GPIO_Registers[(_pin.port)]->CRL), ((DIRECTION_MASK_CLEAR << (GPIO_PIN_DIRECTION_START*lPin))), (((lCfg) << (GPIO_PIN_DIRECTION_START*lPin))));
				}
	else if(7 < lPin){
		lPin -= 8;
		MODIFY_REG((GPIO_Registers[(_pin.port)]->CRH), ((DIRECTION_MASK_CLEAR << (GPIO_PIN_DIRECTION_START*lPin))), (((lCfg) << (GPIO_PIN_DIRECTION_START*lPin))));
	}
}

void GPIO_Pin_Set(const Pin_cfg_t _pin){
		SET_BIT((GPIO_Registers[(_pin.port)]->ODR.ODR_REG), _pin.pin);
}
void GPIO_Pin_Clear(const Pin_cfg_t _pin){
		CLEAR_BIT((GPIO_Registers[(_pin.port)]->ODR.ODR_REG), _pin.pin);
}
void GPIO_Pin_Toggle(const Pin_cfg_t _pin){
		TOGGLE_BIT((GPIO_Registers[(_pin.port)]->ODR.ODR_REG), (_pin.pin));
}
uint8_t GPIO_Pin_Read(const Pin_cfg_t _pin){
	return (READ_BIT((GPIO_Registers[(_pin.port)]->IDR.IDR_REG), (_pin.pin)));
}

void GPIO_Pin_Write_logic(const Pin_cfg_t _pin, uint8_t logic){
	switch(logic){
		case GPIO_LOW:
			CLEAR_BIT((GPIO_Registers[(_pin.port)]->ODR.ODR_REG), _pin.pin);
		break;
		case GPIO_HIGH:
			SET_BIT((GPIO_Registers[(_pin.port)]->ODR.ODR_REG), _pin.pin);
		break;
		default : ;
	}
}
