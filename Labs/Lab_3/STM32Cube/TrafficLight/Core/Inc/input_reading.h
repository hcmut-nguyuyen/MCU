/*
 * input_reading.h
 *
 *  Created on: Nov 13, 2023
 *      Author: Nguyuyen
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"

#define BUTTON_NUMBER 3
#define BUTTON_PORT GPIOA
extern const uint16_t BUTTON_PIN[BUTTON_NUMBER];

#define BUTTON_PRESSED GPIO_PIN_RESET
#define BUTTON_RELEASED GPIO_PIN_SET

extern GPIO_PinState button_buffer[BUTTON_NUMBER];
extern GPIO_PinState button_buffer_press_then_release[BUTTON_NUMBER];
extern GPIO_PinState debounce_button_buffer_now[BUTTON_NUMBER];
extern GPIO_PinState debounce_button_buffer_pre[BUTTON_NUMBER];

void initButton();
void buttonReading();
unsigned char isButtonPressed(unsigned char index);
unsigned char isButtonPressedThenReleased(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
