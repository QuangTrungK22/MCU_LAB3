#include "fsm_traffic_lights.h"

	void fsm_traffic_lights(){
			switch(status)
	{
				case MODE_1:
				status = REDX_GREENY;
				counter_led_X = 5;
				counter_led_Y = 3;
				index_led = 0 ;
				update7SEG(index_led);
				setTimer(0, Period_green * 1000); // timer for case REDX_GREENY đỏ sáng 3s xanh sáng 3 ( đỏ 2 chu kì tổng là 5s)
				setTimer(1, 1000);    // timer for updateClockBuffer1
				setTimer(2, 250);     // timer for quét led
				ClearTimer(3);
				break;
			case REDX_GREENY :

				HAL_GPIO_WritePin(LED_RED_X1_GPIO_Port, LED_RED_X1_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN_X1_GPIO_Port, LED_GREEN_X1_Pin, SET);
				HAL_GPIO_WritePin(LED_RED_Y2_GPIO_Port, LED_RED_Y2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN_Y2_GPIO_Port, LED_GREEN_Y2_Pin, RESET);
				HAL_GPIO_WritePin(LED_YELLOW_X1_GPIO_Port, LED_YELLOW_X1_Pin, SET);
				if(timer_flag[0] == 1) {
					status = REDX_YELLOWY ;
					counter_led_Y = 2;
					setTimer(0,Period_yellow * 1000);

				}
				Time_Counter();

				if(timer_flag[2] == 1){
					update7SEG(index_led);
					setTimer(2,100);
				}
				if(isButtonPressed(0) == 1){
					status = MODE_2;
				}

				break;

			case REDX_YELLOWY:
     			HAL_GPIO_WritePin(LED_YELLOW_X1_GPIO_Port, LED_YELLOW_Y2_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN_Y2_GPIO_Port, LED_GREEN_Y2_Pin, SET);
				if(timer_flag[0] == 1){
					status = GREENX_REDY;
					setTimer(0,Period_green * 1000);
					counter_led_X = 3;
					counter_led_Y = 5;

				}
				Time_Counter();
				if(timer_flag[2] == 1){
					update7SEG(index_led);
					setTimer(2, 250);
				}
				if(isButtonPressed(0) == 1){
					status = MODE_2;
				}
				break;

			case GREENX_REDY:

				HAL_GPIO_WritePin(LED_RED_X1_GPIO_Port, LED_RED_X1_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN_X1_GPIO_Port, LED_GREEN_X1_Pin, RESET);
				HAL_GPIO_WritePin(LED_RED_Y2_GPIO_Port, LED_RED_Y2_Pin, RESET);
				HAL_GPIO_WritePin(LED_YELLOW_Y2_GPIO_Port, LED_YELLOW_Y2_Pin, SET);
				if(timer_flag[0] == 1){
					status = YELLOWX_REDY;
					setTimer(0, Period_red * 1000);
					counter_led_X = 2;
					counter_led_Y = 2;

				}
				Time_Counter();
				if(timer_flag[2] == 1){
					update7SEG(index_led);
					setTimer(2,250);
				}
				if(isButtonPressed(0) == 1){
					status = MODE_2;
				}
				break;
			case YELLOWX_REDY:
				 HAL_GPIO_WritePin(LED_GREEN_X1_GPIO_Port, LED_GREEN_X1_Pin, SET);
				 HAL_GPIO_WritePin(LED_YELLOW_X1_GPIO_Port, LED_YELLOW_X1_Pin, RESET);

				 if(timer_flag[0] == 1){
					 status = REDX_GREENY;
					 setTimer(0, Period_yellow * 1000);
					 counter_led_X = 5;
					 counter_led_Y = 3;

				 }
				 Time_Counter();

				 if(timer_flag[2] == 1){
					 update7SEG(index_led);
					 setTimer(2, 250);
				 }
				 if(isButtonPressed(0) == 1){
					 status = MODE_2;
				 }
				 break;

				 //mode 2
			case MODE_2:
				status = AUTO_RED;
				HAL_GPIO_WritePin(LED_RED_X1_GPIO_Port, LED_RED_X1_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW_X1_GPIO_Port, LED_YELLOW_X1_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN_X1_GPIO_Port, LED_GREEN_X1_Pin, SET);

				HAL_GPIO_WritePin(LED_RED_Y2_GPIO_Port, LED_RED_Y2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW_Y2_GPIO_Port, LED_RED_Y2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN_Y2_GPIO_Port, LED_GREEN_Y2_Pin, SET);


				update7SEG(index_led);
				setTimer(2, 250);
				setTimer(3, 500);
				ClearTimer(0);
				ClearTimer(1);
				break;
			case AUTO_RED:
				UpdateMODE(2, Period_red);
				if(timer_flag[3] == 1){
				HAL_GPIO_TogglePin(LED_RED_X1_GPIO_Port, LED_RED_X1_Pin);
				HAL_GPIO_TogglePin(LED_RED_Y2_GPIO_Port, LED_RED_Y2_Pin);
				setTimer(3, 500);
				}
				if(timer_flag[2] == 1){
					update7SEG(index_led);

					setTimer(2, 250);
				}
				if(isButtonPressed(0) == 1){
					status = MODE_3;
				}
				if(isButtonPressed(1) == 1){     // modify button is pressed
					status = INC_RED ;
				    if(Period_red < 99){Period_red++;}
				    else Period_red = Period_yellow + 1;
				}

				break;
			case INC_RED:
				if(timer_flag[3] == 1){
					HAL_GPIO_TogglePin(LED_RED_X1_GPIO_Port, LED_RED_X1_Pin);
					HAL_GPIO_TogglePin(LED_RED_Y2_GPIO_Port, LED_RED_Y2_Pin);
					setTimer(3, 500);
				}
				if(timer_flag[2] == 1){

					update7SEG(index_led);
					setTimer(2, 250);
				}
				if(isButtonPressed(1) == 1 ){
					if(Period_red < 99) Period_red++ ;
					else Period_red = Period_yellow + 1;
				}
				if(isButtonPressed(2) == 1) {
					status = AUTO_RED;
					Period_green = Period_red - Period_yellow;
				}
				break;
			case MODE_3:
				status = AUTO_YELLOW;
				HAL_GPIO_WritePin(LED_RED_X1_GPIO_Port, LED_RED_X1_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW_X1_GPIO_Port, LED_YELLOW_X1_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN_X1_GPIO_Port, LED_GREEN_X1_Pin, SET);

				HAL_GPIO_WritePin(LED_RED_Y2_GPIO_Port, LED_RED_Y2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW_Y2_GPIO_Port, LED_RED_Y2_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN_Y2_GPIO_Port, LED_GREEN_Y2_Pin, SET);

				update7SEG(index_led);
				setTimer(2,250);
				setTimer(3,500);
				index_led = 0 ;
				ClearTimer(0);
				ClearTimer(1);
				break;
			case AUTO_YELLOW:
				if(timer_flag[3] == 1){
					HAL_GPIO_WritePin(LED_YELLOW_X1_GPIO_Port, LED_YELLOW_X1_Pin, RESET);
					HAL_GPIO_WritePin(LED_YELLOW_Y2_GPIO_Port, LED_RED_Y2_Pin, RESET);
					setTimer(3, 500);
				}
				if(timer_flag[2] == 1 ){
					update7SEG(index_led);

					setTimer(2, 250);
				}
				if(isButtonPressed(0) == 1){   // button_selec is pressed
						status = MODE_4;
				}
				if(isButtonPressed(1) == 1) {
					status = INC_YELLOW;
					if(Period_yellow >= 5) Period_yellow = 1;
					else Period_yellow++;
				}
				break;
			case INC_YELLOW:
				if(timer_flag[3] == 1){
					HAL_GPIO_WritePin(LED_YELLOW_X1_GPIO_Port, LED_YELLOW_X1_Pin, RESET);
					HAL_GPIO_WritePin(LED_YELLOW_Y2_GPIO_Port, LED_RED_Y2_Pin, RESET);
					setTimer(3, 500);
				}
			    if(timer_flag[2] == 1){

				    update7SEG(index_led);
				    setTimer(2, 250);
			    }
			    if(isButtonPressed(1) == 1){
			    	if(Period_yellow >=5) Period_yellow = 1;
			    	else Period_yellow++;
			    }
				if(isButtonPressed(2) == 1 ){ // button_3 is pressed ( choose Value )
					status = AUTO_YELLOW;
					if(Period_red <= Period_yellow){
						Period_red = Period_yellow + 1;
					}else Period_green = Period_red - Period_yellow;
            	}
				break;

			case MODE_4:
				status = AUTO_GREEN;
				HAL_GPIO_WritePin(LED_RED_X1_GPIO_Port, LED_RED_X1_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW_X1_GPIO_Port, LED_YELLOW_X1_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN_X1_GPIO_Port, LED_GREEN_X1_Pin, RESET);

				HAL_GPIO_WritePin(LED_RED_Y2_GPIO_Port, LED_RED_Y2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW_Y2_GPIO_Port, LED_RED_Y2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN_Y2_GPIO_Port, LED_GREEN_Y2_Pin, RESET);


				update7SEG(index_led);
				setTimer(2,250);
				setTimer(3,500);
				index_led = 0 ;
				ClearTimer(0);
				ClearTimer(1);
				break;
			case AUTO_GREEN:
				if(timer_flag[3] == 1){
					HAL_GPIO_WritePin(LED_GREEN_X1_GPIO_Port, LED_GREEN_X1_Pin, RESET);
					HAL_GPIO_WritePin(LED_GREEN_Y2_GPIO_Port, LED_GREEN_Y2_Pin, RESET);
					setTimer(3, 500);
				}
				if(timer_flag[2] == 1){

					update7SEG(index_led);
					setTimer(2, 250);
				}
				if(isButtonPressed(0) == 1){
					status = MODE_1;
				}
				if(isButtonPressed(1) == 1) {
					status = INC_GREEN;
					if(Period_green >= Period_red - Period_yellow){
						Period_green = 1;
					} else Period_green++;
				}
				break;
			case INC_GREEN:
				if(timer_flag[3] == 1){
				  HAL_GPIO_WritePin(LED_GREEN_X1_GPIO_Port, LED_GREEN_X1_Pin, RESET);
				  HAL_GPIO_WritePin(LED_GREEN_Y2_GPIO_Port, LED_GREEN_Y2_Pin, RESET);
				  setTimer(3, 500);
				}
				if(timer_flag[2] == 1){

					update7SEG(index_led);
					index_led = 0;
					setTimer(2, 250);
				}
				if(isButtonPressed(1) == 1){
					if(Period_green >= Period_red - Period_yellow){
						Period_green = 1;
					} else Period_green++;
				}
				if(isButtonPressed(2) == 1){
					status = AUTO_GREEN;
					Period_red = Period_green + Period_yellow;
				}
				break;
			default:
			break;
	}
}
