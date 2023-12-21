/*
 * command_parser.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Nguyuyen
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

typedef enum {
  COMMAND_NONE = 0,
  COMMAND_RST,
  COMMAND_OK
} CommandData;

typedef enum {
  COMMAND_INIT = 0,
  COMMAND_BEGIN,
  COMMAND_1_R,
  COMMAND_1_O,
  COMMAND_2_S,
  COMMAND_2_K,
  COMMAND_3_T
} CommandState;

extern int command_flag;
extern CommandData command_data;
extern CommandState command_state;

void command_parser_fsm();

#endif /* INC_COMMAND_PARSER_H_ */
