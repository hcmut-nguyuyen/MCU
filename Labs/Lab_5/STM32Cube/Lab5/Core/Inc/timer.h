/*
 * timer.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Nguyuyen
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIME_CYCLE 10
#define TIMER_NUMBER 2

#define BLINK_LED_TIME 500
#define RESPONSE_CYCLE 3000

extern int timer_counter[TIMER_NUMBER];
extern int timer_flag[TIMER_NUMBER];

void initTimer();
void setTimer(int index, int duration);
void runTimer();

#endif /* INC_TIMER_H_ */
