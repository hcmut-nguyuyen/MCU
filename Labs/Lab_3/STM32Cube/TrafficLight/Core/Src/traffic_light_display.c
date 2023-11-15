/*
 * traffic_light_display.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Nguyuyen
 */

#include "traffic_light_display.h"

void display_traffic_light(){
  switch (traffic_light_state) {
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
    default:
      break;
  }
}
