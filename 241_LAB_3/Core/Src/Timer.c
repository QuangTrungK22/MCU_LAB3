#include "Timer.h"
#define num 5
	int TIME_CYCLE;
	int timer_counter[num] ={0};
	int timer_flag[num] = {0};

	void setTimer(int index, int duration){
		timer_counter[index] = duration / TIME_CYCLE;
		timer_flag[index] = 0 ;
	}

	void timerRun(){
		for(int i = 0 ; i < 5 ; i++){
			if(timer_counter[i] > 0)
			{
				timer_counter[i]--;
			}
			else
				timer_flag[i] = 1;

		}
	}

	void ClearTimer(int index){
		timer_flag[index] = 0;
		timer_counter[index] = 0;

	}
