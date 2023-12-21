/*
 * timer.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Nguyuyen
 */

#include "timer.h"
#include "main.h"

/*
 * timer0: blink led
 * timer1: response
 */
int timer_counter[TIMER_NUMBER];
/*
 * timer0: blink led
 * timer1: response
 */
int timer_flag[TIMER_NUMBER];

void initTimer(){
  setTimer(0, BLINK_LED_TIME);
  setTimer(1, RESPONSE_CYCLE);
}
/*
 * timer0: blink led
 * timer1: response
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
  if (htim->Instance == TIM2) {
    runTimer();
  }
}
