/*
 * Common.h
 *
 *  Created on: Jul 3, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef COMMON_H_
#define COMMON_H_


/**************** Includes ********************/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
/**************** Macro Declarations ********************/
/***********************************/
#define HDREG32(_X)   (*((volatile uint32_t *)(_X)))

#define MASK		1

/*********************************/
#define SET_BIT(REG,BIT)						((REG |= (MASK << BIT)))
#define CLEAR_BIT(REG,BIT)						(REG &= ~(MASK << BIT))
#define TOGGLE_BIT(REG,BIT)						(REG ^= (MASK << BIT))
#define READ_BIT(REG, BIT)						((REG >> BIT) & MASK)

#define READ_REG(REG)							((REG))
#define WRITE_REG(REG, VAL)						((REG) = (VAL))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)		WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/*******************************/
typedef uint8_t Std_ReturnType;

#define E_OK            (Std_ReturnType)0X01
#define E_NOT_OK        (Std_ReturnType)0X00

/***********************/
#define F_CPU			72000000UL


#define PI					3.14159265

/***********************************/
#define ENABLE		1U
#define DISABLE		0U



/**************** Macro Function Declarations ********************/

/**************** Data Type Declaration ********************/

/**************** Software Interfaces Declaration ********************/
int string_to_intger(char *str);

#endif /* COMMON_H_ */
