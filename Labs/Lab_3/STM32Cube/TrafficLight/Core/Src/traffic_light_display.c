/*
 * traffic_light_display.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Nguyuyen
 */

#include "traffic_light_display.h"

TrafficLightDisplayState traffic_light_display_state = XRED_YGREEN;

void displayTrafficLight(){
  switch (traffic_light_display_state) {
    case XRED_YGREEN:
      HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_AMBER_X_GPIO_Port, LED_AMBER_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_AMBER_Y_GPIO_Port, LED_AMBER_Y_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, GPIO_PIN_RESET);
      break;
    case XRED_YAMBER:
      HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_AMBER_X_GPIO_Port, LED_AMBER_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_AMBER_Y_GPIO_Port, LED_AMBER_Y_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, GPIO_PIN_SET);
      break;
    case XGREEN_YRED:
      HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_AMBER_X_GPIO_Port, LED_AMBER_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_AMBER_Y_GPIO_Port, LED_AMBER_Y_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, GPIO_PIN_SET);
      break;
    case XAMBER_YRED:
      HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_AMBER_X_GPIO_Port, LED_AMBER_X_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_AMBER_Y_GPIO_Port, LED_AMBER_Y_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, GPIO_PIN_SET);
      break;
    case ARED:
      HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_AMBER_X_GPIO_Port, LED_AMBER_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_AMBER_Y_GPIO_Port, LED_AMBER_Y_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, GPIO_PIN_SET);
      break;
    case AAMBER:
      HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_AMBER_X_GPIO_Port, LED_AMBER_X_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_AMBER_Y_GPIO_Port, LED_AMBER_Y_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, GPIO_PIN_SET);
      break;
    case AGREEN:
      HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_AMBER_X_GPIO_Port, LED_AMBER_X_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_AMBER_Y_GPIO_Port, LED_AMBER_Y_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, GPIO_PIN_RESET);
      break;
    case AALL:
      HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_AMBER_X_GPIO_Port, LED_AMBER_X_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_AMBER_Y_GPIO_Port, LED_AMBER_Y_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, GPIO_PIN_RESET);
      break;
    default:
      break;
  }
}
void activeTrafficLight(){
  HAL_GPIO_WritePin(EN_TL_GPIO_Port, EN_TL_Pin, GPIO_PIN_RESET);
}
void toggleTrafficLight(){
  HAL_GPIO_TogglePin(EN_TL_GPIO_Port, EN_TL_Pin);
}
