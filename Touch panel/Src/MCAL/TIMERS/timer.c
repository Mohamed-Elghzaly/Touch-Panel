/*
 * timer2.c
 *
 *  Created on: Jul 16, 2024
 *      Author: Mohamed Abdallah Elghzaly
 */


#include "timer.h"



/**************** Macro Declarations ********************/
#define TIMER2_PWM_CHANNEL_1			((Pin_cfg_t){GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL, GPIO_PORTA, GPIO_PIN0})
#define TIMER2_PWM_CHANNEL_2			((Pin_cfg_t){GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL, GPIO_PORTA, GPIO_PIN1})
#define TIMER2_PWM_CHANNEL_3			((Pin_cfg_t){GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL, GPIO_PORTA, GPIO_PIN2})
#define TIMER2_PWM_CHANNEL_4			((Pin_cfg_t){GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL, GPIO_PORTA, GPIO_PIN3})

#define TIMER3_PWM_CHANNEL_1			((Pin_cfg_t){GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL, GPIO_PORTA, GPIO_PIN6})
#define TIMER3_PWM_CHANNEL_2			((Pin_cfg_t){GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL, GPIO_PORTA, GPIO_PIN7})
#define TIMER3_PWM_CHANNEL_3			((Pin_cfg_t){GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL, GPIO_PORTB, GPIO_PIN0})
#define TIMER3_PWM_CHANNEL_4			((Pin_cfg_t){GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL, GPIO_PORTB, GPIO_PIN1})

#define TIMER4_PWM_CHANNEL_1			((Pin_cfg_t){GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL, GPIO_PORTB, GPIO_PIN6})
#define TIMER4_PWM_CHANNEL_2			((Pin_cfg_t){GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL, GPIO_PORTB, GPIO_PIN7})
#define TIMER4_PWM_CHANNEL_3			((Pin_cfg_t){GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL, GPIO_PORTB, GPIO_PIN8})
#define TIMER4_PWM_CHANNEL_4			((Pin_cfg_t){GPIO_OUTPUT_10MHz_ALTER_PUSH_PULL, GPIO_PORTB, GPIO_PIN9})

/**************** Data Type Declaration ********************/
static TIMERx_t *const TIMERS_Registers[] = {MCAL_TIMER2, MCAL_TIMER3, MCAL_TIMER4};
/**************** Software Interfaces Declaration ********************/
static void TIMER_PWM_GPIO_CLK_CFG(const Timer_PWM_t pwm);
static void TIMER_PWM_ChannelSelect(const Timer_PWM_t pwm);
/**************** Software Interfaces Definition ********************/
void TIMER_PWM_Initialize(const Timer_PWM_t pwm){
	uint16_t lPrescaler = pwm.prescaler;
	uint16_t dutyCycleTemp = 0;
		if(pwm.prescaler == 0){
			lPrescaler = 1;
		}
		else{
			lPrescaler = pwm.prescaler;
		}
		/* enable gpio and timer clock */
		TIMER_PWM_GPIO_CLK_CFG(pwm);
		/* set prescaler */
		TIMERS_Registers[pwm.timer]->TIMx_PSC = (uint16_t)((pwm.prescaler));
		/* Frequency */
		TIMERS_Registers[pwm.timer]->TIMx_ARR = (uint16_t)(F_CPU / ((pwm.frequancy) * (lPrescaler)) - 1);
		/* Duty Cycle */
		dutyCycleTemp = ((pwm.dutyCycle)  / 100.0 ) * ((uint16_t)TIMERS_Registers[pwm.timer]->TIMx_ARR);
		if((pwm.channel)&PWM_CHANNEL_1_ENABLE){
			TIMERS_Registers[pwm.timer]->TIMx_CCR1 = (uint16_t) dutyCycleTemp;
		}
		if((pwm.channel)&PWM_CHANNEL_2_ENABLE){
			TIMERS_Registers[pwm.timer]->TIMx_CCR2 = (uint16_t) dutyCycleTemp;
		}
		if((pwm.channel)&PWM_CHANNEL_3_ENABLE){
			TIMERS_Registers[pwm.timer]->TIMx_CCR3 = (uint16_t) dutyCycleTemp;
		}
		if((pwm.channel)&PWM_CHANNEL_4_ENABLE){
			TIMERS_Registers[pwm.timer]->TIMx_CCR4 = (uint16_t) dutyCycleTemp;
		}

		/* Configure channel */
		TIMER_PWM_ChannelSelect(pwm);

		/* UP counter */
		TIMERS_Registers[pwm.timer]->TIMx_CR1.DIR = COUNTER_USED_AS_UPCOUNTER;
		/*  Center-aligned mode or edge mode selection */
		TIMERS_Registers[pwm.timer]->TIMx_CR1.CMS = pwm.mode;
}

void TIMER_PWM_DutyCycle(const Timer_PWM_t pwm, uint32_t channel, uint32_t dutyCycle){
	uint16_t dutyCycleTemp = (dutyCycle / 100.0) * ((uint16_t)TIMERS_Registers[pwm.timer]->TIMx_ARR) ;
	if((channel&PWM_CHANNEL_1_ENABLE) == PWM_CHANNEL_1_ENABLE){
		TIMERS_Registers[pwm.timer]->TIMx_CCR1 = dutyCycleTemp;
	}
	if((channel&PWM_CHANNEL_2_ENABLE) == PWM_CHANNEL_2_ENABLE){
		TIMERS_Registers[pwm.timer]->TIMx_CCR2 = dutyCycleTemp;
	}
	if((channel&PWM_CHANNEL_3_ENABLE) == PWM_CHANNEL_3_ENABLE){
		TIMERS_Registers[pwm.timer]->TIMx_CCR3 = dutyCycleTemp;
	}
	if((channel&PWM_CHANNEL_4_ENABLE) == PWM_CHANNEL_4_ENABLE){
		TIMERS_Registers[pwm.timer]->TIMx_CCR4 = dutyCycleTemp;
	}
}

void TIMER_PWM_Frequency(const Timer_PWM_t pwm, uint32_t freq){
	TIMERS_Registers[pwm.timer]->TIMx_ARR = (uint32_t)(F_CPU / (freq * ((TIMERS_Registers[pwm.timer]->TIMx_PSC)+1)) - 1);
}

static void TIMER_PWM_ChannelSelect(const Timer_PWM_t pwm){
	if((pwm.channel)&PWM_CHANNEL_1_ENABLE){
		TIMERS_Registers[pwm.timer]->TIMx_CCMR1.CC1S = CHANNEL_IS_OUTPUT;
		TIMERS_Registers[pwm.timer]->TIMx_CCMR1.OC1M = PWM_MODE_1;
//		TIMERS_Registers[pwm.timer]->TIMx_CCMR1.OC1PE = PRELOAD_REGISTER_CCRx_ENABLE;
		TIMERS_Registers[pwm.timer]->TIMx_CCER.CC1P = OC_ACTIVE_HIGH;
	}
	if((pwm.channel)&PWM_CHANNEL_2_ENABLE){
		TIMERS_Registers[pwm.timer]->TIMx_CCMR1.CC2S = CHANNEL_IS_OUTPUT;
		TIMERS_Registers[pwm.timer]->TIMx_CCMR1.OC2M = PWM_MODE_1;
//		TIMERS_Registers[pwm.timer]->TIMx_CCMR1.OC2PE = PRELOAD_REGISTER_CCRx_ENABLE;
		TIMERS_Registers[pwm.timer]->TIMx_CCER.CC2P = OC_ACTIVE_HIGH;
	}
	if((pwm.channel)&PWM_CHANNEL_3_ENABLE){
		TIMERS_Registers[pwm.timer]->TIMx_CCMR2.CC3S = CHANNEL_IS_OUTPUT;
		TIMERS_Registers[pwm.timer]->TIMx_CCMR2.OC3M = PWM_MODE_1;
//		TIMERS_Registers[pwm.timer]->TIMx_CCMR2.OC3PE = PRELOAD_REGISTER_CCRx_ENABLE;
		TIMERS_Registers[pwm.timer]->TIMx_CCER.CC3P = OC_ACTIVE_HIGH;
	}
	if((pwm.channel)&PWM_CHANNEL_4_ENABLE){
		TIMERS_Registers[pwm.timer]->TIMx_CCMR2.CC4S = CHANNEL_IS_OUTPUT;
		TIMERS_Registers[pwm.timer]->TIMx_CCMR2.OC4M = PWM_MODE_1;
//		TIMERS_Registers[pwm.timer]->TIMx_CCMR2.OC4PE = PRELOAD_REGISTER_CCRx_ENABLE;
		TIMERS_Registers[pwm.timer]->TIMx_CCER.CC4P = OC_ACTIVE_HIGH;
	}
}

void TIMER_PWM_SetPrescaler(const Timer_PWM_t pwm, uint32_t prescaler){
	TIMERS_Registers[pwm.timer]->TIMx_PSC = (prescaler);
}


void TIMER_PWM_Start(const Timer_PWM_t pwm, uint32_t channel){
	if(channel & PWM_CHANNEL_1_ENABLE){
		/* Capture/Compare 1 output enable */
		TIMERS_Registers[pwm.timer]->TIMx_CCER.CC1E = OUTPUT_COMPARE_ENABLE;
	}
	if(channel & PWM_CHANNEL_2_ENABLE){
		/* Capture/Compare 2 output enable */
		TIMERS_Registers[pwm.timer]->TIMx_CCER.CC2E = OUTPUT_COMPARE_ENABLE;
	}
	if(channel & PWM_CHANNEL_3_ENABLE){
		/* Capture/Compare 3 output enable */
		TIMERS_Registers[pwm.timer]->TIMx_CCER.CC3E = OUTPUT_COMPARE_ENABLE;
	}
	if(channel & PWM_CHANNEL_4_ENABLE){
		/* Capture/Compare 4 output enable */
		TIMERS_Registers[pwm.timer]->TIMx_CCER.CC4E = OUTPUT_COMPARE_ENABLE;
	}
	TIMERS_Registers[pwm.timer]->TIMx_CR1.CEN = COUNTER_ENABLE;
}

void TIMER_PWM_Stop(const Timer_PWM_t pwm, uint32_t channel){
	if(channel == PWM_CHANNEL_1_ENABLE){
		/* Capture/Compare 1 output disable */
		TIMERS_Registers[pwm.timer]->TIMx_CCER.CC1E = OUTPUT_COMPARE_DISABLE;
	}
	if(channel == PWM_CHANNEL_2_ENABLE){
		/* Capture/Compare 2 output disable */
		TIMERS_Registers[pwm.timer]->TIMx_CCER.CC2E = OUTPUT_COMPARE_DISABLE;
	}
	if(channel == PWM_CHANNEL_3_ENABLE){
		/* Capture/Compare 3 output disable */
		TIMERS_Registers[pwm.timer]->TIMx_CCER.CC3E = OUTPUT_COMPARE_DISABLE;
	}
	if(channel == PWM_CHANNEL_4_ENABLE){
		/* Capture/Compare 4 output disable */
		TIMERS_Registers[pwm.timer]->TIMx_CCER.CC4E = OUTPUT_COMPARE_DISABLE;
	}
}

static void TIMER_PWM_GPIO_CLK_CFG(const Timer_PWM_t pwm){
	if(pwm.timer == TIMER2_PWM_EN){
		RCC_Enable_Peripheral_APB1(TIM2EN);
		RCC_Enable_Peripheral_APB2(IOPAEN);
 		if((pwm.channel)&PWM_CHANNEL_1_ENABLE){
 			GPIO_Pin_Dir_Cfg(TIMER2_PWM_CHANNEL_1);
		}
		if((pwm.channel)&PWM_CHANNEL_2_ENABLE){
			GPIO_Pin_Dir_Cfg(TIMER2_PWM_CHANNEL_2);
		}
		if((pwm.channel)&PWM_CHANNEL_3_ENABLE){
			GPIO_Pin_Dir_Cfg(TIMER2_PWM_CHANNEL_3);
		}
		if((pwm.channel)&PWM_CHANNEL_4_ENABLE){
			GPIO_Pin_Dir_Cfg(TIMER2_PWM_CHANNEL_4);
		}else{}
	}
	else if(pwm.timer == TIMER3_PWM_EN){
		RCC_Enable_Peripheral_APB1(TIM3EN);
		RCC_Enable_Peripheral_APB2(IOPAEN);
		RCC_Enable_Peripheral_APB2(IOPBEN);
 		if((pwm.channel)&PWM_CHANNEL_1_ENABLE){
 			GPIO_Pin_Dir_Cfg(TIMER3_PWM_CHANNEL_1);
		}
		if((pwm.channel)&PWM_CHANNEL_2_ENABLE){
			GPIO_Pin_Dir_Cfg(TIMER3_PWM_CHANNEL_2);
		}
		if((pwm.channel)&PWM_CHANNEL_3_ENABLE){
			GPIO_Pin_Dir_Cfg(TIMER3_PWM_CHANNEL_3);
		}
		if((pwm.channel)&PWM_CHANNEL_4_ENABLE){
			GPIO_Pin_Dir_Cfg(TIMER3_PWM_CHANNEL_4);
		}else{}
	}
	else if(pwm.timer == TIMER4_PWM_EN){
		RCC_Enable_Peripheral_APB1(TIM4EN);
		RCC_Enable_Peripheral_APB2(IOPBEN);
 		if((pwm.channel)&PWM_CHANNEL_1_ENABLE){
 			GPIO_Pin_Dir_Cfg(TIMER4_PWM_CHANNEL_1);
		}
		if((pwm.channel)&PWM_CHANNEL_2_ENABLE){
			GPIO_Pin_Dir_Cfg(TIMER4_PWM_CHANNEL_2);
		}
		if((pwm.channel)&PWM_CHANNEL_3_ENABLE){
			GPIO_Pin_Dir_Cfg(TIMER4_PWM_CHANNEL_3);
		}
		if((pwm.channel)&PWM_CHANNEL_4_ENABLE){
			GPIO_Pin_Dir_Cfg(TIMER4_PWM_CHANNEL_4);
		}else{}
	}
	else{}
}

void TIMER_PWM_Start_DMA(const Timer_PWM_t pwm, const DMA_t _dma, uint32_t Channel, const uint32_t *pData, uint16_t Length){
	 switch (Channel)
	  {
	    case PWM_CHANNEL_1_ENABLE:
	    	HAL_DMA_Start_IT(_dma, (uint32_t)pData, (uint32_t)&(TIMERS_Registers[pwm.timer]->TIMx_CCR1), Length);
			TIMERS_Registers[pwm.timer]->TIMx_CCMR1.OC1PE = PRELOAD_REGISTER_CCRx_ENABLE;
	        /* Enable the TIM Capture/Compare 1 DMA request */
	    	TIMERS_Registers[pwm.timer]->TIMx_DIER.CC1DE = ENABLE;
	    	break;
	    case PWM_CHANNEL_2_ENABLE:
	    	HAL_DMA_Start_IT(_dma, (uint32_t)pData, (uint32_t)&(TIMERS_Registers[pwm.timer]->TIMx_CCR2), Length);
			TIMERS_Registers[pwm.timer]->TIMx_CCMR1.OC2PE = PRELOAD_REGISTER_CCRx_ENABLE;
	        /* Enable the TIM Capture/Compare 2 DMA request */
	    	TIMERS_Registers[pwm.timer]->TIMx_DIER.CC2DE = ENABLE;
	    	break;
	    case PWM_CHANNEL_3_ENABLE:
	    	HAL_DMA_Start_IT(_dma, (uint32_t)pData, (uint32_t)&(TIMERS_Registers[pwm.timer]->TIMx_CCR3), Length);
			TIMERS_Registers[pwm.timer]->TIMx_CCMR2.OC3PE = PRELOAD_REGISTER_CCRx_ENABLE;
	        /* Enable the TIM Capture/Compare 3 DMA request */
	    	TIMERS_Registers[pwm.timer]->TIMx_DIER.CC3DE = ENABLE;
	    	break;
	    case PWM_CHANNEL_4_ENABLE:
	    	HAL_DMA_Start_IT(_dma, (uint32_t)pData, (uint32_t)&(TIMERS_Registers[pwm.timer]->TIMx_CCR4), Length);
			TIMERS_Registers[pwm.timer]->TIMx_CCMR2.OC4PE = PRELOAD_REGISTER_CCRx_ENABLE;
	        /* Enable the TIM Capture/Compare 4 DMA request */
	    	TIMERS_Registers[pwm.timer]->TIMx_DIER.CC4DE = ENABLE;
	    	break;
	    default:;
	  };
	 TIMER_PWM_Start(pwm, Channel);
}


void TIMER_PWM_Stop_DMA(const Timer_PWM_t pwm, const DMA_t _dma, uint32_t Channel) {
	switch (Channel) {
		case PWM_CHANNEL_1_ENABLE:
			/* Disable the TIM Capture/Compare 1 DMA request */
			TIMERS_Registers[pwm.timer]->TIMx_DIER.CC1DE = DISABLE;
			break;
		case PWM_CHANNEL_2_ENABLE:
			/* Disable the TIM Capture/Compare 2 DMA request */
			TIMERS_Registers[pwm.timer]->TIMx_DIER.CC2DE = DISABLE;
			break;
		case PWM_CHANNEL_3_ENABLE:
			/* Disable the TIM Capture/Compare 3 DMA request */
			TIMERS_Registers[pwm.timer]->TIMx_DIER.CC3DE = DISABLE;
			break;
		case PWM_CHANNEL_4_ENABLE:
			/* Disable the TIM Capture/Compare 4 interrupt */
			TIMERS_Registers[pwm.timer]->TIMx_DIER.CC4DE = DISABLE;
			break;
		default:;
	};

	HAL_DMA_Abort_IT(_dma);

	/* Disable the Capture compare channel */
	TIMER_PWM_Stop(pwm, Channel);

	/* Disable the Peripheral */
	TIMERS_Registers[pwm.timer]->TIMx_CR1.CEN = COUNTER_DISABLE;

}

