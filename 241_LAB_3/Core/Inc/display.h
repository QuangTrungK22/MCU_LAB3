/*
 * display.h
 *
 *  Created on: Oct 20, 2024
 *      Author: Tê liệt con
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "main.h"
#include "global_ban.h"

extern int index_led;
extern int counter_led_X;
extern int counter_led_Y;
void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer1();
void updateClockBuffer2();
void updateClockBuffer3();
void updateClockBuffer4();

#endif /* INC_DISPLAY_H_ */
