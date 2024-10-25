/*
 * Button.h
 *
 *  Created on: Oct 20, 2024
 *      Author: Quang Trung Lam
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "Timer.h"

#define NORMAL_STATE  SET
#define PRESSED_STATE RESET

#define num_of_Buttons 3

int isButtonPressed(int index);
void getKeyInput();

#endif /* INC_BUTTON_H_ */
