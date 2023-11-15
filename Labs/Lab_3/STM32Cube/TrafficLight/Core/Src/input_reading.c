/*
 * input_reading.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Nguyuyen
 */

#include "input_reading.h"

const uint16_t BUTTON_PIN[BUTTON_NUMBER] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};

GPIO_PinState button_buffer[BUTTON_NUMBER];
GPIO_PinState button_buffer_press_then_release[BUTTON_NUMBER];
GPIO_PinState debounce_button_buffer_now[BUTTON_NUMBER];
GPIO_PinState debounce_button_buffer_pre[BUTTON_NUMBER];

void initButton(){
  for(char i = 0; i < BUTTON_NUMBER; ++i){
    button_buffer[i] = BUTTON_RELEASED;
    button_buffer_press_then_release[i] = BUTTON_RELEASED;
    debounce_button_buffer_now[i] = BUTTON_RELEASED;
    debounce_button_buffer_pre[i] = BUTTON_RELEASED;
  }
}
void buttonReading(){
  for(char i = 0; i < BUTTON_NUMBER; ++i){
    debounce_button_buffer_pre[i] = debounce_button_buffer_now[i];
    debounce_button_buffer_now[i] = HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN[i]);
    if(debounce_button_buffer_now[i] == debounce_button_buffer_pre[i]){
      if(button_buffer[i] == BUTTON_PRESSED && debounce_button_buffer_now[i] == BUTTON_RELEASED)
	button_buffer_press_then_release[i] = BUTTON_PRESSED;
      else
	button_buffer_press_then_release[i] = BUTTON_RELEASED;
      button_buffer[i] = debounce_button_buffer_now[i];
    }
  }
}
unsigned char isButtonPressed(unsigned char index){
  if (index >= BUTTON_NUMBER)
    return 0;
  return (button_buffer[index] == BUTTON_PRESSED);
}
unsigned char isButtonPressedThenReleased(unsigned char index){
  if (index >= BUTTON_NUMBER)
    return 0;
  return (button_buffer_press_then_release[index] == BUTTON_PRESSED);
}
