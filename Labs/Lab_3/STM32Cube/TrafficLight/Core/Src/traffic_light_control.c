/*
 * traffic_light_control.c
 *
 *  Created on: Nov 15, 2023
 *      Author: Nguyuyen
 */

#include "traffic_light_control.h"

TrafficLightState traffic_light_state = INIT;
/*
 * 0: red
 * 1: amber
 * 2: green
 */
int traffic_light_time_buffer[3] = {RED_TIME_DEFAULT, AMBER_TIME_DEFAULT, GREEN_TIME_DEFAULT};
/*
 * 0: red
 * 1: amber
 * 2: green
 */
int traffic_light_time_buffer_next[3] = {RED_TIME_DEFAULT, AMBER_TIME_DEFAULT, GREEN_TIME_DEFAULT};
/*
 * 0: red
 * 1: amber
 * 2: green
 */
int traffic_light_time_buffer_temp[3] = {RED_TIME_DEFAULT, AMBER_TIME_DEFAULT, GREEN_TIME_DEFAULT};
int time_counter_x, time_counter_y;

void controlTrafficLight(){
  switch (traffic_light_state) {
    case INIT:
      traffic_light_state = RED_GREEN;
      activeTrafficLight();
      traffic_light_display_state = XRED_YGREEN;
      time_counter_x = traffic_light_time_buffer[0];
      time_counter_y = traffic_light_time_buffer[2];
      update7SegBuffer(--time_counter_x, --time_counter_y);
      setTimer(0, TRAFFIC_LIGHT_TIME);
      break;
    case RED_GREEN:
      if(isButtonPressed(0) == 1){
	traffic_light_state = MODIFY_RED;
	traffic_light_display_state = ARED;
	update7SegBuffer(traffic_light_time_buffer_temp[0], 2);
	setTimer(0, BLINK_LED_TIME);
      } else {
	if(timer_flag[2] == 1){
	  setTimer(2, TRAFFIC_LIGHT_TIME);
	  if(time_counter_y <= 0){
	    traffic_light_state = RED_AMBER;
	    activeTrafficLight();
	    traffic_light_display_state = XRED_YAMBER;
	    time_counter_y = traffic_light_time_buffer[1];
	  }
	  update7SegBuffer(--time_counter_x, --time_counter_y);
	}
      }
      break;
    case RED_AMBER:
      if(isButtonPressed(0) == 1){
      	traffic_light_state = MODIFY_RED;
      	traffic_light_display_state = ARED;
	update7SegBuffer(traffic_light_time_buffer_temp[0], 2);
	setTimer(0, BLINK_LED_TIME);
      } else {
	if(timer_flag[2] == 1){
	  setTimer(2, TRAFFIC_LIGHT_TIME);
	  if(time_counter_y <= 0){
	    traffic_light_state = GREEN_RED;
	    activeTrafficLight();
	    traffic_light_display_state = XGREEN_YRED;
	    time_counter_x = traffic_light_time_buffer[2];
	    time_counter_y = traffic_light_time_buffer[0];
	  }
	  update7SegBuffer(--time_counter_x, --time_counter_y);
	}
      }
      break;
    case GREEN_RED:
      if(isButtonPressed(0) == 1){
      	traffic_light_state = MODIFY_RED;
      	traffic_light_display_state = ARED;
	update7SegBuffer(traffic_light_time_buffer_temp[0], 2);
	setTimer(0, BLINK_LED_TIME);
      } else {
	if(timer_flag[2] == 1){
	  setTimer(2, TRAFFIC_LIGHT_TIME);
	  if(time_counter_x <= 0){
	    traffic_light_state = AMBER_RED;
	    activeTrafficLight();
	    traffic_light_display_state = XAMBER_YRED;
	    time_counter_x = traffic_light_time_buffer[1];
	  }
	  update7SegBuffer(--time_counter_x, --time_counter_y);
	}
      }
      break;
    case AMBER_RED:
      if(isButtonPressed(0) == 1){
      	traffic_light_state = MODIFY_RED;
      	traffic_light_display_state = ARED;
	update7SegBuffer(traffic_light_time_buffer_temp[0], 2);
	setTimer(0, BLINK_LED_TIME);
      } else {
	if(timer_flag[2] == 1){
	  setTimer(2, TRAFFIC_LIGHT_TIME);
	  if(time_counter_x <= 0){
	    traffic_light_state = RED_GREEN;
	    activeTrafficLight();
	    traffic_light_display_state = XRED_YGREEN;
	    time_counter_x = traffic_light_time_buffer[0];
	    time_counter_y = traffic_light_time_buffer[2];
	  }
	  update7SegBuffer(--time_counter_x, --time_counter_y);
	}
      }
      break;
    case MODIFY_RED:
      if(isButtonPressed(0) == 1){
      	traffic_light_state = MODIFY_AMBER;
      	traffic_light_display_state = AAMBER;
	update7SegBuffer(traffic_light_time_buffer_temp[1], 3);
      } else {
	if(timer_flag[0] == 1){
	  setTimer(0, BLINK_LED_TIME);
	  toggleTrafficLight();
	}
	if(isButtonPressed(1) == 1){
	  ++traffic_light_time_buffer_temp[0];
	  if(traffic_light_time_buffer_temp[0] > TIME_STATE_MAX)
	    traffic_light_time_buffer_temp[0] = TIME_STATE_MIN;
	  update7SegBuffer(traffic_light_time_buffer_temp[0], 2);
	}
	if(isButtonPressed(2) == 1){
	  traffic_light_time_buffer_next[0] = traffic_light_time_buffer_temp[0];
	}
      }
      break;
    case MODIFY_AMBER:
      if(isButtonPressed(0) == 1){
      	traffic_light_state = MODIFY_GREEN;
      	traffic_light_display_state = AGREEN;
	update7SegBuffer(traffic_light_time_buffer_temp[2], 4);
      } else {
	if(timer_flag[0] == 1){
	  setTimer(0, BLINK_LED_TIME);
	  toggleTrafficLight();
	}
	if(isButtonPressed(1) == 1){
	  ++traffic_light_time_buffer_temp[1];
	  if(traffic_light_time_buffer_temp[1] > TIME_STATE_MAX)
	    traffic_light_time_buffer_temp[1] = TIME_STATE_MIN;
	  update7SegBuffer(traffic_light_time_buffer_temp[1], 3);
	}
	if(isButtonPressed(2) == 1){
	  traffic_light_time_buffer_next[1] = traffic_light_time_buffer_temp[1];
	}
      }
      break;
    case MODIFY_GREEN:
      if(isButtonPressed(0) == 1){
      	traffic_light_state = ERROR_CHECK;
      	traffic_light_display_state = AALL;
	update7SegBuffer(0, 0);
      } else {
	if(timer_flag[0] == 1){
	  setTimer(0, BLINK_LED_TIME);
	  toggleTrafficLight();
	}
	if(isButtonPressed(1) == 1){
	  ++traffic_light_time_buffer_temp[2];
	  if(traffic_light_time_buffer_temp[2] > TIME_STATE_MAX)
	    traffic_light_time_buffer_temp[2] = TIME_STATE_MIN;
	  update7SegBuffer(traffic_light_time_buffer_temp[2], 4);
	}
	if(isButtonPressed(2) == 1){
	  traffic_light_time_buffer_next[2] = traffic_light_time_buffer_temp[2];
	}
      }
      break;
    case ERROR_CHECK:
      if(traffic_light_time_buffer_next[0] == traffic_light_time_buffer[1] + traffic_light_time_buffer[2]){
	traffic_light_time_buffer[0] = traffic_light_time_buffer_next[0];
	traffic_light_time_buffer[1] = traffic_light_time_buffer_next[1];
	traffic_light_time_buffer[2] = traffic_light_time_buffer_next[2];
      }
      traffic_light_time_buffer_temp[0] = traffic_light_time_buffer[0];
      traffic_light_time_buffer_temp[1] = traffic_light_time_buffer[1];
      traffic_light_time_buffer_temp[2] = traffic_light_time_buffer[2];
      traffic_light_state = RED_GREEN;
      activeTrafficLight();
      traffic_light_display_state = XRED_YGREEN;
      time_counter_x = traffic_light_time_buffer[0];
      time_counter_y = traffic_light_time_buffer[2];
      update7SegBuffer(--time_counter_x, --time_counter_y);
      setTimer(2, TRAFFIC_LIGHT_TIME);
      break;
    default:
      break;
  }
  displayTrafficLight();
}
