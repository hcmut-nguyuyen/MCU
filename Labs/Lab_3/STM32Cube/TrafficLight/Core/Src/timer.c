/*
 * timer.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Nguyuyen
 */

#include "timer.h"
#include "main.h"
#include "input_reading.h"

/*
 * timer0: blink led
 * timer1: scan 7seg
 * timer2: traffic light
 * timer3: read button
 */
int timer_counter[TIMER_NUMBER];
/*
 * timer0: blink led
 * timer1: scan 7seg
 * timer2: traffic light
 * timer3: read button
 */
int timer_flag[TIMER_NUMBER];

void initTimer(){
  setTimer(0, BLINK_LED_TIME);
  setTimer(1, SCAN_7SEG_TIME);
  setTimer(2, TRAFFIC_LIGHT_TIME);
  setTimer(3, BUTTON_READING_TIME);
}
/*
 * timer0: blink led
 * timer1: scan 7seg
 * timer2: traffic light
 * timer3: read button
 */
void setTimer(int index, int duration){
  timer_counter[index] = duration / TIME_CYCLE;
  timer_flag[index] = 0;
}
void runTimer(){
  for(int i = 0; i < TIMER_NUMBER; ++i){
    if(timer_counter[i] > 0){
      --timer_counter[i];
      if(timer_counter[i] == 0)
	timer_flag[i] = 1;
    }
  }
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
  runTimer();
}
