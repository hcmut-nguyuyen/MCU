/*
 * scheduler.h
 *
 *  Created on: Dec 4, 2023
 *      Author: Nguyuyen
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "main.h"

#define TIME_CYCLE 10

typedef struct {
void (*pTask)(void);
uint32_t Delay;
uint32_t Period ;
uint8_t RunMe;
uint32_t TaskID ;
} sTask;

void Timer_Init();
void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
uint8_t SCH_Delete_Task(uint32_t taskID);

#define SCH_MAX_TASKS 10
#define NO_TASK_ID 0
sTask SCH_tasks_G[SCH_MAX_TASKS];

#endif /* INC_SCHEDULER_H_ */
