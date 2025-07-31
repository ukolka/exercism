#include "clock.h"
#define DAY (24 * 60)
#define HOUR (60)

int mod(int a, int b) {
  return ((a % b) + b) % b;
}

void clock(time_text_t time_text, int hour, int minute) {
  int minutes = mod(hour * HOUR + minute, DAY);
  sprintf(time_text, "%02d:%02d", minutes / HOUR, minutes % HOUR);
}

void clock_add(time_text_t time_text, int minute_offset) {
  int hour;
  int minute;
  sscanf(time_text, "%d:%d", &hour, &minute);
  clock(time_text, hour, minute + minute_offset);
}