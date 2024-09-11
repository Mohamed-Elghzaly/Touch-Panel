/*
 * application.c
 *
 *  Created on: Aug 11, 2024
 *      Author: Mohamed Abdallah Elghzaly the new one
 */

#include "application.h"

Button_t Button[3] = {{PORTB_PIN8, 1, 1},{PORTB_PIN8, 1, 1},{PORTB_PIN9, 2, 2}};

typedef struct {
	EEPROM_TP_t Colors_TP;
	BKP_TP_t State_TP;
} TP_t;

TP_t TP1 = {0};


void application(void){
	GPIO_Pin_Dir_Cfg(RGB1_EN);
	GPIO_Pin_Dir_Cfg(RGB2_EN);
	GPIO_Pin_Dir_Cfg(RGB3_EN);
	GPIO_Pin_Clear(RGB1_EN);
	GPIO_Pin_Clear(RGB2_EN);
	GPIO_Pin_Clear(RGB3_EN);

	Button_Init(Button[0]);
	Button_Init(Button[1]);
	Button_Init(Button[2]);

	GPIO_Pin_Dir_Cfg(INDUCTION);
	GPIO_Pin_Set(INDUCTION);

	RGB_Led_Init(RGB1);

	BKP_Init();

/*****************************************/

	Em_EEPROM_TP_Read(&(TP1.Colors_TP));
	if (TP1.Colors_TP.TP_Led_Color[0][0][0] == -1)
	{
	    TP_t temp = {
	        .Colors_TP = {
	            .TP_Led_Color = {
	                {{255, 0, 0},{0, 255, 0}},
					{{255, 0, 0},{0, 255, 0}},
	                {{255, 0, 0},{0, 255, 0}}
	            }
	        },
	        .State_TP = {
	            {0, 0, 0}
	        }
	    };
	    TP1 = temp;
	    Em_EEPROM_TP_Write(&(TP1.Colors_TP));
	    BKP_WriteStruct(&(TP1.State_TP));
	}
	else
	{
		Em_EEPROM_TP_Read(&(TP1.Colors_TP));
		BKP_ReadStruct(&(TP1.State_TP));
	}

/*****************************************/
	uint64_t ButtonReadingTime = 0;
	uint64_t InductionTime=0;

	/* Loop forever */
	while(1)
	{
		if(BKP_ReadButtonState(BUTTON1_STATE))
		{
			Systick_Delay_us(50);
			GPIO_Pin_Set(RGB2_EN);
			GPIO_Pin_Set(RGB3_EN);
			RGB_Led_Set_Color(RGB1,
					TP1.Colors_TP.TP_Led_Color[BUTTON1_SEL][1][RED_POS],
					TP1.Colors_TP.TP_Led_Color[BUTTON1_SEL][1][GREEN_POS],
					TP1.Colors_TP.TP_Led_Color[BUTTON1_SEL][1][BLUE_POS]);
			GPIO_Pin_Clear(RGB1_EN);
		}
		else
		{
			Systick_Delay_us(50);
			GPIO_Pin_Set(RGB2_EN);
			GPIO_Pin_Set(RGB3_EN);
			RGB_Led_Set_Color(RGB1,
					TP1.Colors_TP.TP_Led_Color[BUTTON1_SEL][0][RED_POS],
					TP1.Colors_TP.TP_Led_Color[BUTTON1_SEL][0][GREEN_POS],
					TP1.Colors_TP.TP_Led_Color[BUTTON1_SEL][0][BLUE_POS]);
			GPIO_Pin_Clear(RGB1_EN);
		}



		if(BKP_ReadButtonState(BUTTON2_STATE))
		{
			Systick_Delay_us(50);
			GPIO_Pin_Set(RGB1_EN);
			GPIO_Pin_Set(RGB3_EN);
			RGB_Led_Set_Color(RGB1,
					TP1.Colors_TP.TP_Led_Color[BUTTON2_SEL][1][RED_POS],
					TP1.Colors_TP.TP_Led_Color[BUTTON2_SEL][1][GREEN_POS],
					TP1.Colors_TP.TP_Led_Color[BUTTON2_SEL][1][BLUE_POS]);
			GPIO_Pin_Clear(RGB2_EN);
		}
		else
		{
			Systick_Delay_us(50);
			GPIO_Pin_Set(RGB1_EN);
			GPIO_Pin_Set(RGB3_EN);
			RGB_Led_Set_Color(RGB1,
					TP1.Colors_TP.TP_Led_Color[BUTTON2_SEL][0][RED_POS],
					TP1.Colors_TP.TP_Led_Color[BUTTON2_SEL][0][GREEN_POS],
					TP1.Colors_TP.TP_Led_Color[BUTTON2_SEL][0][BLUE_POS]);
			GPIO_Pin_Clear(RGB2_EN);
		}


		if(BKP_ReadButtonState(BUTTON3_STATE))
		{
			Systick_Delay_us(50);
			GPIO_Pin_Set(RGB1_EN);
			GPIO_Pin_Set(RGB2_EN);
			RGB_Led_Set_Color(RGB1,
					TP1.Colors_TP.TP_Led_Color[BUTTON3_SEL][1][RED_POS],
					TP1.Colors_TP.TP_Led_Color[BUTTON3_SEL][1][GREEN_POS],
					TP1.Colors_TP.TP_Led_Color[BUTTON3_SEL][1][BLUE_POS]);
			GPIO_Pin_Clear(RGB3_EN);
		}
		else
		{
			Systick_Delay_us(50);
			GPIO_Pin_Set(RGB1_EN);
			GPIO_Pin_Set(RGB2_EN);
			RGB_Led_Set_Color(RGB1,
					TP1.Colors_TP.TP_Led_Color[BUTTON3_SEL][0][RED_POS],
					TP1.Colors_TP.TP_Led_Color[BUTTON3_SEL][0][GREEN_POS],
					TP1.Colors_TP.TP_Led_Color[BUTTON3_SEL][0][BLUE_POS]);
			GPIO_Pin_Clear(RGB3_EN);
		}


		if(micros() - InductionTime > 6000000000)
		{
			InductionTime = micros();
			GPIO_Pin_Toggle(INDUCTION);
		}

		if(micros() - ButtonReadingTime > 1000)
		{
			ButtonReadingTime = micros();

			for(uint8_t i = 0; i<3; i++)
			{
				if(Button_Read_State(Button[i]) == BUTTON_PRESSED)
				{
//					toggleFlag[i] = !(toggleFlag[i]);
					BKP_WriteButtonState(BUTTON1_STATE, !(BKP_ReadButtonState(BUTTON1_STATE)));
				}
			}
		}
	}
}
