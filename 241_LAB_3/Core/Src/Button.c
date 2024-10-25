/*
 * Button.c
 *
 *  Created on: Oct 20, 2024
 *      Author: Quang Trung
 */
#include "Button.h"


	int keyReg0[num_of_Buttons] = {NORMAL_STATE};
	int keyReg1[num_of_Buttons] = {NORMAL_STATE};
	int keyReg2[num_of_Buttons] = {NORMAL_STATE};
	int keyReg3[num_of_Buttons] = {NORMAL_STATE};

	int press_flag[num_of_Buttons] = {0};
	int long_press_flag[num_of_Buttons] = {0};
	int timeOutForKeyPress[num_of_Buttons] = {0};

	int isButtonPressed(int index){
		if(press_flag[index] == 1){
			return 1;
		}
		return 0;
	}
	void subKeyProcess(int index){
		press_flag[index] = 1;
	}

	void getKeyInput(){
		for( int i = 0 ; i < num_of_Buttons; ++i){
			keyReg0[i] = keyReg1[i];
			keyReg1[i] = keyReg2[i];
			if(i == 0){
				keyReg2[i] = HAL_GPIO_ReadPin(Select_Mode_GPIO_Port, Select_Mode_Pin);
			}
			if(i == 1){
				keyReg2[i] = HAL_GPIO_ReadPin(Modify_Mode_GPIO_Port, Modify_Mode_Pin);
			}
			if(i == 2){
				keyReg2[i] = HAL_GPIO_ReadPin(Set_Value_GPIO_Port, Set_Value_Pin);
			}
			if ((keyReg1[i] == keyReg0[i]) && (keyReg1[i] == keyReg2[i]))
					{
						if(keyReg3[i] != keyReg2[i])
						{
							keyReg3[i] = keyReg2[i];
							if(keyReg2[i] == PRESSED_STATE)
							{
								subKeyProcess(i);
								if (long_press_flag[i] == 0)
								{
									timeOutForKeyPress[i] = 2000 / TIME_CYCLE;
								}
								else
								{
									timeOutForKeyPress[i] = 250 / TIME_CYCLE;
								}
							}
						}

						else
						{
							timeOutForKeyPress[i]--;
							if(timeOutForKeyPress[i] == 0)
							{
								keyReg3[i] = NORMAL_STATE;
								long_press_flag[i] = 1;
							}
						}
					}

					else
					{
						long_press_flag[i] = 0;
					}
	   }
	}
