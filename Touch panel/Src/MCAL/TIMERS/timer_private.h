/*
 * timer2_private.h
 *
 *  Created on: Jul 16, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */

#ifndef TIMERS_TIM2_TIMER2_PRIVATE_H_
#define TIMERS_TIM2_TIMER2_PRIVATE_H_




/**************** Includes ********************/
#include <stdint.h>
#include "../Inc/Common.h"

/**************** Macro Declarations ********************/
#define TIMER2_BASE		(0x40000000)
#define MCAL_TIMER2			((TIMERx_t *) TIMER2_BASE)

#define TIMER3_BASE		(0x40000400UL)
#define MCAL_TIMER3			((TIMERx_t *) TIMER3_BASE)

#define TIMER4_BASE		(0x40000800UL)
#define MCAL_TIMER4			((TIMERx_t *) TIMER4_BASE)
/**************** Macro Function Declarations ********************/

typedef union{
	struct{
		volatile uint32_t CEN			:1;
		volatile uint32_t UDIS			:1;
		volatile uint32_t URS			:1;
		volatile uint32_t OPM			:1;
		volatile uint32_t DIR			:1;
		volatile uint32_t CMS			:2;
		volatile uint32_t ARPE			:1;
		volatile uint32_t OPCKDM		:2;
		volatile uint32_t RESERVED0		:22;
	};
	volatile uint32_t TIMx_CR1_REG;
}TIMx_CR1_t;

typedef union{
	struct{
		volatile uint32_t RESERVED0		:3;
		volatile uint32_t CCDS			:1;
		volatile uint32_t MMS			:3;
		volatile uint32_t TI1S			:1;
		volatile uint32_t RESERVED1		:24;
	};
	volatile uint32_t TIMx_CR2_REG;
}TIMx_CR2_t;
typedef union{
	struct{
		volatile uint32_t SMS			:3;
		volatile uint32_t RESERVED0		:1;
		volatile uint32_t TS			:3;
		volatile uint32_t MSM			:1;
		volatile uint32_t ETF			:4;
		volatile uint32_t ETPS			:2;
		volatile uint32_t ECE			:1;
		volatile uint32_t ETP			:1;
		volatile uint32_t RESERVED1		:16;
	};
	volatile uint32_t TIMx_SMCR_REG;
}TIMx_SMCR_t;
typedef union{
	struct{
		volatile uint32_t UIE			:1;
		volatile uint32_t CC1IE			:1;
		volatile uint32_t CC2IE			:1;
		volatile uint32_t CC3IE			:1;
		volatile uint32_t CC4IE			:1;
		volatile uint32_t RESERVED0		:1;
		volatile uint32_t TIE			:1;
		volatile uint32_t RESERVED1		:1;
		volatile uint32_t UDE			:1;
		volatile uint32_t CC1DE			:1;
		volatile uint32_t CC2DE			:1;
		volatile uint32_t CC3DE			:1;
		volatile uint32_t CC4DE			:1;
		volatile uint32_t RESERVED2		:1;
		volatile uint32_t TDE			:1;
		volatile uint32_t RESERVED3		:17;
	};
	volatile uint32_t TIMx_DIER_REG;
}TIMx_DIER_t;
typedef union{
	struct{
		volatile uint32_t UIF			:1;
		volatile uint32_t CC1IF			:1;
		volatile uint32_t CC2IF			:1;
		volatile uint32_t CC3IF			:1;
		volatile uint32_t CC4IF			:1;
		volatile uint32_t RESERVED0		:1;
		volatile uint32_t TIF			:1;
		volatile uint32_t RESERVED1		:2;
		volatile uint32_t CC1OF			:1;
		volatile uint32_t CC2OF			:1;
		volatile uint32_t CC3OF			:1;
		volatile uint32_t CC4OF			:1;
		volatile uint32_t RESERVED2		:19;
	};
	volatile uint32_t TIMx_SR_REG;
}TIMx_SR_t;
typedef union{
	struct{
		volatile uint32_t UG			:1;
		volatile uint32_t CC1G			:1;
		volatile uint32_t CC2G			:1;
		volatile uint32_t CC3G			:1;
		volatile uint32_t CC4G			:1;
		volatile uint32_t RESERVED0		:1;
		volatile uint32_t TG			:1;
		volatile uint32_t RESERVED1		:25;
	};
	volatile uint32_t TIMx_EGR_REG;
}TIMx_EGR_t;


typedef union{
	struct{
		volatile uint32_t CC1S			:2;
		volatile uint32_t OC1FE			:1;
		volatile uint32_t OC1PE			:1;
		volatile uint32_t OC1M			:3;
		volatile uint32_t OC1CE			:1;
		volatile uint32_t CC2S			:2;
		volatile uint32_t OC2FE			:1;
		volatile uint32_t OC2PE			:1;
		volatile uint32_t OC2M			:3;
		volatile uint32_t OC2CE			:1;
		volatile uint32_t RESERVED0		:16;
	};
//	struct{
//		volatile uint32_t 				:2;
//		volatile uint32_t IC1PSC		:2;
//		volatile uint32_t IC1F			:4;
//		volatile uint32_t				:2;
//		volatile uint32_t IC2PSC		:2;
//		volatile uint32_t IC2F			:4;
//		volatile uint32_t RESERVED1		:16;
//	};
	volatile uint32_t TIMx_CCMR1_REG;
}TIMx_CCMR1_t;
typedef union{
	struct{
		volatile uint32_t CC3S			:2;
		volatile uint32_t OC3FE			:1;
		volatile uint32_t OC3PE			:1;
		volatile uint32_t OC3M			:3;
		volatile uint32_t OC3CE			:1;
		volatile uint32_t CC4S			:2;
		volatile uint32_t OC4FE			:1;
		volatile uint32_t OC4PE			:1;
		volatile uint32_t OC4M			:3;
		volatile uint32_t OC4CE			:1;
		volatile uint32_t RESERVED0		:16;
	};
//	struct{
//		volatile uint32_t 				:2;
//		volatile uint32_t IC3PSC		:2;
//		volatile uint32_t IC3F			:4;
//		volatile uint32_t 				:2;
//		volatile uint32_t IC4PSC		:2;
//		volatile uint32_t IC4F			:4;
//		volatile uint32_t RESERVED1		:16;
//	};
	volatile uint32_t TIMx_CCMR2_REG;
}TIMx_CCMR2_t;

typedef union{
	struct{
		volatile uint32_t	CC1E			:1;
		volatile uint32_t	CC1P			:1;
		volatile uint32_t	RESERVED0		:2;
		volatile uint32_t	CC2E			:1;
		volatile uint32_t	CC2P			:1;
		volatile uint32_t	RESERVED1		:2;
		volatile uint32_t	CC3E			:1;
		volatile uint32_t	CC3P			:1;
		volatile uint32_t	RESERVED2		:2;
		volatile uint32_t	CC4E			:1;
		volatile uint32_t	CC4P			:1;
		volatile uint32_t	RESERVED3		:18;
	};
	volatile uint32_t TIMx_CCER_REG;
}TIMx_CCER_t;

typedef union{
	struct{
		volatile uint32_t DBA		:5;
		volatile uint32_t RESERVED0	:3;
		volatile uint32_t DBL		:5;
		volatile uint32_t RESERVED1	:19;
	};
	volatile uint32_t TIMx_DCR_REG;
}TIMx_DCR_t;

/**************** Data Type Declaration ********************/

typedef struct{
	volatile TIMx_CR1_t 	TIMx_CR1;
	volatile TIMx_CR2_t 	TIMx_CR2;
	volatile TIMx_SMCR_t 	TIMx_SMCR;
	volatile TIMx_DIER_t 	TIMx_DIER;
	volatile TIMx_SR_t 		TIMx_SR;
	volatile TIMx_EGR_t		TIMx_EGR;
	volatile TIMx_CCMR1_t	TIMx_CCMR1;
	volatile TIMx_CCMR2_t	TIMx_CCMR2;
	volatile TIMx_CCER_t	TIMx_CCER;
	volatile uint32_t		TIMx_CNT;
	volatile uint32_t		TIMx_PSC;
	volatile uint32_t		TIMx_ARR;
	volatile uint32_t		TIMx_Reserved;
	volatile uint32_t		TIMx_CCR1;
	volatile uint32_t		TIMx_CCR2;
	volatile uint32_t		TIMx_CCR3;
	volatile uint32_t		TIMx_CCR4;
	volatile TIMx_DCR_t		TIMx_DCR;
	volatile uint32_t		TIMx_DMAR;
}TIMERx_t;


/**************** Software Interfaces Declaration ********************/


#endif /* TIMERS_TIM2_TIMER2_PRIVATE_H_ */
