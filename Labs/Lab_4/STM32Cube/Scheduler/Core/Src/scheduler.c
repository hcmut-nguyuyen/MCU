/*
 * scheduler.c
 *
 *  Created on: Dec 4, 2023
 *      Author: Nguyuyen
 */

#include "scheduler.h"

void SCH_Init(void){
  for(int i = 0;i < SCH_MAX_TASKS; ++i){
    SCH_tasks_G[i].pTask = 0x0000;
    SCH_tasks_G[i].Delay = 0;
    SCH_tasks_G[i].Period = 0;
    SCH_tasks_G[i].RunMe = 0;
  }
}
void SCH_Update(void){
  for(unsigned char i = 0; i < SCH_MAX_TASKS; i++) {
    if(SCH_tasks_G[i].pTask) {
      if(SCH_tasks_G[i].Delay == 0) {
	SCH_tasks_G[i].RunMe += 1;
	if(SCH_tasks_G[i].Period) {
	  SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
	}
      } else {
	SCH_tasks_G[i].Delay -= 1;
      }
    }
  }
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim ){
  SCH_Update();
}
void SCH_Dispatch_Tasks(void){
  unsigned char i ;
  for (i = 0; i < SCH_MAX_TASKS; i++) {
    if (SCH_tasks_G[i].RunMe > 0) {
      (*SCH_tasks_G[i].pTask)();
      SCH_tasks_G[i].RunMe -= 1;
      if (SCH_tasks_G[i].Period == 0){
        SCH_Delete_Task(i);
      }
    }
  }
}
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
  unsigned char i = 0;
  while ((SCH_tasks_G[i].pTask != 0 ) && (i < SCH_MAX_TASKS)){
    ++i;
  }
  if (i == SCH_MAX_TASKS){
    return SCH_MAX_TASKS;
  }
  SCH_tasks_G[i].pTask = pFunction;
  SCH_tasks_G[i].Delay = DELAY / TIME_CYCLE;
  SCH_tasks_G[i].Period = PERIOD / TIME_CYCLE;
  SCH_tasks_G[i].RunMe = 0;
  return i ;
}
uint8_t SCH_Delete_Task(uint32_t taskID){
  SCH_tasks_G[taskID].pTask = 0x0000;
  SCH_tasks_G[taskID].Delay = 0;
  SCH_tasks_G[taskID].Period = 0;
  SCH_tasks_G[taskID].RunMe = 0;
  return 0;
}
