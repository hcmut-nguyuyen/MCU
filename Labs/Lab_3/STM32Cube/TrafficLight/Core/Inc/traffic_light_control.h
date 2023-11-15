/*
 * traffic_light_control.h
 *
 *  Created on: Nov 15, 2023
 *      Author: Nguyuyen
 */

#ifndef INC_TRAFFIC_LIGHT_CONTROL_H_
#define INC_TRAFFIC_LIGHT_CONTROL_H_

#include "timer.h"
#include "input_reading.h"
#include "traffic_light_display.h"
#include "seven_segment_display.h"

#define RED_TIME_DEFAULT 5
#define AMBER_TIME_DEFAULT 2
#define GREEN_TIME_DEFAULT 3

#define TIME_STATE_MAX 99
#define TIME_STATE_MIN 1

typedef enum
{
  INIT = 0,
  RED_GREEN = 1,
  RED_AMBER = 2,
  GREEN_RED = 3,
  AMBER_RED = 4,
  MODIFY_RED = 5,
  MODIFY_AMBER = 6,
  MODIFY_GREEN = 7,
  ERROR_CHECK = 8
} TrafficLightState;

extern int traffic_light_time_buffer[3];
extern int traffic_light_time_buffer_next[3];
extern int traffic_light_time_buffer_temp[3];
extern int time_counter_x, time_counter_y;
extern TrafficLightState traffic_light_state;

void controlTrafficLight();

#endif /* INC_TRAFFIC_LIGHT_CONTROL_H_ */
