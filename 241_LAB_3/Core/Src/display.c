/*
 * display.c
 *
 *  Created on: Oct 20, 2024
 *      Author: win
 */
#include "display.h"
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4]={1,2,3,4};
int counter_led_X = 1;
int counter_led_Y = 1;

void display7SEG(int num){
		switch(num){
		case 0:
	           HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			   HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			   HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			   HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			   HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			   HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			   HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			   break;
		case 1:
		   	   HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			   HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			   HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
	           HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			   HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			   HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			   HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);

			   break;

		case 2:
		       HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			   HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			   HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
			   HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			   HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			   HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			   HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);

			  break;
		case 3:
			   HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
	           HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		       HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		       HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			   HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		       HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			   HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);

		    break;
		case 4:
			   HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			   HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			   HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			   HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			   HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			   HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			   HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);

		    break;
		case 5:
			   HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			   HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			   HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			   HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			   HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			   HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			   HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);


			break;
		case 6:

			   HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			   HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			   HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			   HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			   HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			   HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			   HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);


			break;
		case 7:
		   	   HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			   HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			   HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			   HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			   HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			   HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			   HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);


			break;
		case 8:
			   HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			   HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			   HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			   HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			   HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			   HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			   HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);


			break;
		case 9:
			   HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			   HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			   HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			   HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			   HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			   HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			   HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);

			break;

		}
	}


	void update7SEG(int index){
		display7SEG(led_buffer[index]);
   			switch(index){
   			case 0:
   				index_led = 1;

   				HAL_GPIO_WritePin(Light_Y1_GPIO_Port, Light_Y1_Pin, RESET);
   				HAL_GPIO_WritePin(Light_Y2_GPIO_Port, Light_Y2_Pin, SET);
   				HAL_GPIO_WritePin(Light_X1_GPIO_Port, Light_X1_Pin, SET);
   			    HAL_GPIO_WritePin(Light_X2_GPIO_Port, Light_X2_Pin, SET);

   				break;
   			case 1:
   				index_led = 2;
   				HAL_GPIO_WritePin(Light_Y1_GPIO_Port, Light_Y1_Pin, SET);
				HAL_GPIO_WritePin(Light_Y2_GPIO_Port, Light_Y2_Pin, RESET);
				HAL_GPIO_WritePin(Light_X1_GPIO_Port, Light_X1_Pin, SET);
				HAL_GPIO_WritePin(Light_X2_GPIO_Port, Light_X2_Pin, SET);


   				break;
   			case 2:
   				index_led = 3;
   				HAL_GPIO_WritePin(Light_Y1_GPIO_Port, Light_Y1_Pin, SET);
				HAL_GPIO_WritePin(Light_Y2_GPIO_Port, Light_Y2_Pin, SET);
				HAL_GPIO_WritePin(Light_X1_GPIO_Port, Light_X1_Pin, RESET);
				HAL_GPIO_WritePin(Light_X2_GPIO_Port, Light_X2_Pin, SET);

   				break;
   			case 3:
   				index_led = 0;
   				HAL_GPIO_WritePin(Light_Y1_GPIO_Port, Light_Y1_Pin, SET);
				HAL_GPIO_WritePin(Light_Y2_GPIO_Port, Light_Y2_Pin, SET);
				HAL_GPIO_WritePin(Light_X1_GPIO_Port, Light_X1_Pin, SET);
				HAL_GPIO_WritePin(Light_X2_GPIO_Port, Light_X2_Pin, RESET);

   				break;
   			default:
   				break;
   			}
   		}
	/* với 2 led 7 đoạn của trục ngang OX , Ta có đèn đỏ sẽ được đếm ngược Với công thức Period_RED - 1 về 0;
	 * tương tự với 2 đèn còn lại.
	 * nếu thời gian của đèn vàng kết thúc, quay lại set up time cho đèn đỏ.
	 */
	void updateClockBuffer1()
	{
		if(counter_led_X <= Period_red){
			led_buffer[0] = (Period_red - counter_led_X) / 10;
			led_buffer[1] = (Period_red - counter_led_X) % 10;
		}
		else if((Period_red + Period_green) >= counter_led_X){
			led_buffer[0] = ((Period_red + Period_green) - counter_led_X) / 10;
			led_buffer[1] = ((Period_red + Period_green) - counter_led_X) % 10;
		}
		else
		{
			led_buffer[0] = ((Period_red + Period_green + Period_yellow) - counter_led_X) / 10;
			led_buffer[1] = ((Period_red + Period_green + Period_yellow) - counter_led_X) % 10;
		}
		counter_led_X++;
		if(counter_led_X > (Period_red + Period_green + Period_yellow)){
			counter_led_X = 1;
		}

		if(counter_led_Y <= Period_green){
					led_buffer[2] = (Period_green - counter_led_Y) / 10;
					led_buffer[3] = (Period_green - counter_led_Y) % 10;
				}
				else if((Period_yellow + Period_green) >= counter_led_Y){
					led_buffer[2] = ((Period_yellow + Period_green) - counter_led_Y) / 10;
					led_buffer[3] = ((Period_yellow + Period_green) - counter_led_Y) % 10;
				}
				else
				{
					led_buffer[2] = ((Period_red + Period_green + Period_yellow) - counter_led_Y) / 10;
					led_buffer[3] = ((Period_red + Period_green + Period_yellow) - counter_led_Y) % 10;
				}
				counter_led_Y++;
				if(counter_led_Y > (Period_red + Period_green + Period_yellow)){
					counter_led_Y = 1;
				}

	}
	void updateClockBuffer2(){
		//hiển thị mode
		led_buffer[0] = 0;
		led_buffer[1] = 2;

		// hiển thị giả trị của led Red

		led_buffer[2] = Period_red / 10;
		led_buffer[3] = Period_red % 10;

	}
	void updateClockBuffer3(){
			//hiển thị mode
			led_buffer[0] = 0;
			led_buffer[1] = 3;

			// hiển thị giả trị của led Yellow

			led_buffer[2] =  Period_yellow / 10;
			led_buffer[3] =  Period_yellow % 10;
	}
	void updateClockBuffer4(){
				//hiển thị mode
				led_buffer[0] = 0;
				led_buffer[1] = 4;

				// hiển thị giả trị của led Yellow

				led_buffer[2] =  Period_green / 10;
				led_buffer[3] =  Period_green % 10;


	}
