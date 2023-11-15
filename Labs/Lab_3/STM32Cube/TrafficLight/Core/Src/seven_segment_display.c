/*
 * seven_segment_display.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Nguyuyen
 */

#include "seven_segment_display.h"

GPIO_PinState seven_segment_display_pin_state[10][7] = {
  {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  },
  {GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_SET  },
  {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_RESET},
  {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_RESET},
  {GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET},
  {GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET},
  {GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET},
  {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_SET  },
  {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET},
  {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_RESET}
};
GPIO_PinState seven_segment_enable_pin_state[SEVEN_SEGMENT_NUMBER][SEVEN_SEGMENT_NUMBER] = {
  {GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_SET  },
  {GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_SET  , GPIO_PIN_SET  },
  {GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_RESET, GPIO_PIN_SET  },
  {GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_SET  , GPIO_PIN_RESET}
};
int seven_segment_buffer[SEVEN_SEGMENT_NUMBER] = {0, 0, 0, 0};
int seven_segment_index = 0;

void update7SegBuffer(int number_x, int number_y){
  if(number_x < NUMBER_X_MIN || number_x > NUMBER_X_MAX || number_y < NUMBER_Y_MIN || number_y > NUMBER_Y_MAX)
    return;
  seven_segment_buffer[0] = number_x % 10;
  seven_segment_buffer[1] = number_x / 10;
  seven_segment_buffer[2] = number_y % 10;
  seven_segment_buffer[3] = number_y / 10;
}
void display7Seg(int number){
  if(number >= 0 && number <= 9){
    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, seven_segment_display_pin_state[number][0]);
    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, seven_segment_display_pin_state[number][1]);
    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, seven_segment_display_pin_state[number][2]);
    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, seven_segment_display_pin_state[number][3]);
    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, seven_segment_display_pin_state[number][4]);
    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, seven_segment_display_pin_state[number][5]);
    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, seven_segment_display_pin_state[number][6]);
  }
}
void active7Seg(int index){
  HAL_GPIO_WritePin(EN_7SEG_X0_GPIO_Port, EN_7SEG_X0_Pin, seven_segment_enable_pin_state[index][0]);
  HAL_GPIO_WritePin(EN_7SEG_X1_GPIO_Port, EN_7SEG_X1_Pin, seven_segment_enable_pin_state[index][1]);
  HAL_GPIO_WritePin(EN_7SEG_Y0_GPIO_Port, EN_7SEG_Y0_Pin, seven_segment_enable_pin_state[index][2]);
  HAL_GPIO_WritePin(EN_7SEG_Y1_GPIO_Port, EN_7SEG_Y1_Pin, seven_segment_enable_pin_state[index][3]);
}
void update7Seg(int index){
  if(index >= 0 && index < SEVEN_SEGMENT_NUMBER){
    active7Seg(index);
    display7Seg(seven_segment_buffer[index]);
  }
}
