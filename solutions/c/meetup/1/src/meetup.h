#ifndef MEETUP_H
#define MEETUP_H
#include <time.h>

enum WeekDay {
  Sunday,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
};

int meetup_day_of_month(int year,
                        short month,
                        char *spec,
                        char *dow);

#endif