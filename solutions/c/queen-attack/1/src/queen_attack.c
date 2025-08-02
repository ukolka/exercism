#include "queen_attack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_on_board(position_t queen) {
  return queen.row < 8 && queen.column < 8;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
  if (!is_on_board(queen_1) || !is_on_board(queen_2))
    return INVALID_POSITION;
  
  if (queen_1.row == queen_2.row && queen_1.column == queen_2.column)
    return INVALID_POSITION;
  
  if (queen_1.row == queen_2.row || queen_1.column == queen_2.column)
    return CAN_ATTACK;

  if (abs(queen_1.row - queen_2.row) == abs(queen_1.column - queen_2.column))
    return CAN_ATTACK;

  
  return CAN_NOT_ATTACK;
}