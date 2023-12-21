/*
 * command_parser.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Nguyuyen
 */

#include "command_parser.h"
#include "uart_communication.h"
#include "main.h"

int command_flag = 0;
CommandData command_data = COMMAND_NONE;
CommandState command_state = COMMAND_INIT;

void command_parser_fsm() {
  switch (command_state) {
    case COMMAND_INIT:
      if(buffer[index_buffer] == '!')
	command_state = COMMAND_BEGIN;
      break;
    case COMMAND_BEGIN:
      command_state = (buffer[index_buffer] == 'R') ? COMMAND_1_R :
		      (buffer[index_buffer] == 'O') ? COMMAND_1_O :
						      COMMAND_INIT;
      break;
    case COMMAND_1_R:
      command_state = (buffer[index_buffer] == 'S') ? COMMAND_2_S :
						      COMMAND_INIT;
      break;
    case COMMAND_2_S:
      command_state = (buffer[index_buffer] == 'T') ? COMMAND_3_T :
						      COMMAND_INIT;
      break;
    case COMMAND_3_T:
      if(buffer[index_buffer] == '#') {
	command_data = COMMAND_RST;
	command_flag = 1;
	command_state = COMMAND_INIT;
      } else
	command_state = COMMAND_INIT;
      break;
    case COMMAND_1_O:
      command_state = (buffer[index_buffer] == 'K') ? COMMAND_2_K :
						      COMMAND_INIT;
      break;
    case COMMAND_2_K:
      if(buffer[index_buffer] == '#') {
	command_data = COMMAND_OK;
	command_flag = 1;
	command_state = COMMAND_INIT;
      } else
	command_state = COMMAND_INIT;
      break;
    default:
      command_state = COMMAND_INIT;
      break;
  }
}
