#include "robot_simulator.h"

static robot_grid_status_t robot;

robot_grid_status_t robot_init(void) {
  robot.bearing = DEFAULT_BEARING;
  robot.grid.x_position = DEFAULT_X_COORDINATE;
  robot.grid.y_position = DEFAULT_Y_COORDINATE;
  return robot;
}

robot_grid_status_t robot_init_with_position(int bearing, int x, int y) {
  if (bearing >= HEADING_NORTH && bearing < HEADING_MAX)
    robot.bearing = bearing;
  else
    robot.bearing = DEFAULT_BEARING;
  robot.grid.x_position = x;
  robot.grid.y_position = y;
  return robot;
}

void robot_turn_right(robot_grid_status_t *r) {
  bearing_t b = r->bearing + 1;
  if (b == HEADING_MAX)
    r->bearing = HEADING_NORTH;
  else
    r->bearing = b;
}

void robot_turn_left(robot_grid_status_t *r) {
  int b = (int) r->bearing - 1;
  if (b < HEADING_NORTH)
    r->bearing = HEADING_WEST;
  else
    r->bearing = (bearing_t) b;
}

void robot_advance(robot_grid_status_t *r) {
  switch (r->bearing) {
  case HEADING_NORTH:
    r->grid.y_position++;
    break;
  case HEADING_EAST:
    r->grid.x_position++;
    break;
  case HEADING_SOUTH:
    r->grid.y_position--;
    break;
  case HEADING_WEST:
    r->grid.x_position--;
    break;
  default:
    break;
  }
}

void robot_simulator(robot_grid_status_t *r, const char *commands) {
  char ch;
  while ((ch = *commands++)) {
    switch (ch) {
    case COMMAND_LEFT:
      robot_turn_left(r);
      break;
    case COMMAND_RIGHT:
      robot_turn_right(r);
      break;
    case COMMAND_ADVANCE:
      robot_advance(r);
      break;
    default:
      break;
    }
  }
}