/*
 * Timer.h
 *
 *  Created on: Oct 20, 2024
 *      Author: win
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer_flag[];
extern int TIME_CYCLE;
void setTimer(int index, int duration);
void timerRun();
void ClearTimer(int index);

#endif /* INC_TIMER_H_ */
