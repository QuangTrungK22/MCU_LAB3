/*
 * display.c
 *
 *  Created on: Oct 20, 2024
 *      Author: win
 */
#include "display.h"
#include "Timer.h"
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
	void updateClockBuffer1(int num_led)
	{
		if(num_led < 10){
			led_buffer[0] = 0 ;
			led_buffer[1] = num_led;
		}
		else if(num_led >= 10){
			led_buffer[0] = num_led / 10;
		    led_buffer[1] = num_led % 10;
		}

	}
	void updateClockBuffer2(int num_led){
		if(num_led < 10){
					led_buffer[2] = 0 ;
					led_buffer[3] = num_led;
				}
				else if(num_led >= 10){
					led_buffer[2] = num_led / 10;
				    led_buffer[3] = num_led % 10;
				}


	}
	//void updateClockBuffer3(){
			//hiển thị mode
		//	led_buffer[0] = 0;
			//led_buffer[1] = 3;

			// hiển thị giả trị của led Yellow

			//led_buffer[2] =  Period_yellow / 10;
		//	led_buffer[3] =  Period_yellow % 10;
	//}
	void Time_Counter(){
		if(timer_flag[1] == 1){
			counter_led_X--;
			updateClockBuffer1(counter_led_X);
			counter_led_Y--;
			updateClockBuffer2(counter_led_Y);
			setTimer(1, 1000);
		}
		if(timer_flag[1] == 0){
			counter_led_X = 1;
			counter_led_Y = 1;
		}

	}
		void UpdateMODE(int MODE , int TIME_COUNTER){

					updateClockBuffer1(TIME_COUNTER);
					updateClockBuffer2(MODE);
	       }
