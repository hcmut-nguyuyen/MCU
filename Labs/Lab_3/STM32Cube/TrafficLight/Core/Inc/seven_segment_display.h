/*
 * seven_segment_display.h
 *
 *  Created on: Nov 14, 2023
 *      Author: Nguyuyen
 */

#ifndef INC_SEVEN_SEGMENT_DISPLAY_H_
#define INC_SEVEN_SEGMENT_DISPLAY_H_

#include "main.h"

#define SEVEN_SEGMENT_NUMBER 4

#define NUMBER_X_MAX 99
#define NUMBER_X_MIN 0
#define NUMBER_Y_MAX 99
#define NUMBER_Y_MIN 0

extern GPIO_PinState seven_segment_display_pin_state[10][7];
extern GPIO_PinState seven_segment_enable_pin_state[SEVEN_SEGMENT_NUMBER][SEVEN_SEGMENT_NUMBER];
extern int seven_segment_buffer[SEVEN_SEGMENT_NUMBER];
extern int seven_segment_index;

void update7SegBuffer(int number_x, int number_y);
void display7Seg(int number);
void active7Seg(int index);
void update7Seg(int index);

#endif /* INC_SEVEN_SEGMENT_DISPLAY_H_ */
