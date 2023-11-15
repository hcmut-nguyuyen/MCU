/*
 * traffic_light_display.h
 *
 *  Created on: Nov 14, 2023
 *      Author: Nguyuyen
 */

#ifndef INC_TRAFFIC_LIGHT_DISPLAY_H_
#define INC_TRAFFIC_LIGHT_DISPLAY_H_

#include "main.h"

typedef enum
{
  XRED_YGREEN = 0,
  XRED_YAMBER = 1,
  XGREEN_YRED = 2,
  XAMBER_YRED = 3,
  ARED = 4,
  AAMBER = 5,
  AGREEN = 6,
  AALL = 7,
} TrafficLightDisplayState;

extern TrafficLightDisplayState traffic_light_display_state;

void displayTrafficLight();
void activeTrafficLight();
void toggleTrafficLight();

#endif /* INC_TRAFFIC_LIGHT_DISPLAY_H_ */
