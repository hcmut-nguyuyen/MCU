/*
 * timer.h
 *
 *  Created on: Nov 13, 2023
 *      Author: Nguyuyen
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIME_CYCLE 10
#define TIMER_NUMBER 4

#define BLINK_LED_TIME 250
#define SCAN_7SEG_TIME 250
#define TRAFFIC_LIGHT_TIME 1000
#define BUTTON_READING_TIME 50

extern int timer_counter[TIMER_NUMBER];
extern int timer_flag[TIMER_NUMBER];

void initTimer();
void setTimer(int index, int duration);
void runTimer();

#endif /* INC_TIMER_H_ */
