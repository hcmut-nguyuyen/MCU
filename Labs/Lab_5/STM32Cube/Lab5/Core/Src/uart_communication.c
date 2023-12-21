/*
 * uart_communication.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Nguyuyen
 */

#include "uart_communication.h"
#include "command_parser.h"
#include "timer.h"

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;

int buffer_flag = 0;
uint32_t ADC_value = 0;
uint32_t ADC_value_out = 0;

char str[50];
