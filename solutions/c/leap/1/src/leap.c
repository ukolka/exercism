#include "leap.h"

bool is_leap_year(int year) {
  bool multiple_of_4 = year % 4 == 0;
  bool multiple_of_100 = year % 100 == 0;
  bool multiple_of_400 = year % 400 == 0;

  if (multiple_of_400)
    return true;
  else if (multiple_of_100)
    return false;
  return multiple_of_4;
}