/*
 * uart_communication.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Nguyuyen
 */

#ifndef INC_UART_COMMUNICATION_H_
#define INC_UART_COMMUNICATION_H_

#include "main.h"

#define MAX_BUFFER_SIZE 30
extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;

extern int buffer_flag;
extern uint32_t ADC_value;
extern uint32_t ADC_value_out;

extern char str[50];

typedef enum {
  UART_WAIT = 0,
  UART_RESPONSE
} UARTCommunicationState;

extern UARTCommunicationState uart_communication_state;

void uart_communication_fsm();

#endif /* INC_UART_COMMUNICATION_H_ */
