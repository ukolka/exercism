#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "meetup.h"

#define DAYS_IN_MONTH 31
#define TEEN_LOWER 13
#define TEEN_UPPER 19
#define SIGNIFICANT_SPEC_LEN 4
#define SIGNIFICANT_DAYS_OF_WEEK_LEN 6
#define MAX_WEEKS 5
#define DAYS_OF_WEEK 7
#define INVALID_DAY_OF_THE_WEEK 0

struct tm* gettime(int year, int month, int day) {
  struct tm date;
  date.tm_sec = 0;     /* seconds (0 - 60) */
  date.tm_min = 0;     /* minutes (0 - 59) */
  date.tm_hour = 0;    /* hours (0 - 23) */
  date.tm_mday = day;    /* day of month (1 - 31) */
  date.tm_mon = month - 1;     /* month of year (0 - 11) */
  date.tm_year = year - 1900;    /* year - 1900 */
  //date.tm_wday = dow;    /* day of week (Sunday = 0) */
  //date.tm_yday;    /* day of year (0 - 365) */
  //date.tm_isdst;   /* is summer time in effect? */
  //date.tm_zone;  /* abbreviation of timezone name */
  date.tm_gmtoff = 0; /* offset from UTC in seconds */

  const time_t timestamp = mktime(&date);
  
  struct tm *normalized = gmtime(&timestamp);
  return normalized;
}

enum WeekDay day_of_the_week(int year, int month, int day) {
  struct tm* normalized = gettime(year, month, day);
  return normalized->tm_wday;
}

bool day_from_string(char *dow, enum WeekDay *result) {
  char *days_of_the_week[] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
  };

  for (int i = 0; i < DAYS_OF_WEEK; i++) {
    if (!strncmp(dow, days_of_the_week[i], SIGNIFICANT_DAYS_OF_WEEK_LEN)) {
      *result = i;
      return true;
    }
  }
  return false;
}

int spec_from_string(char *spec) {
  char *specs[] = {
    "first",
    "second",
    "third",
    "fourth",
    "fifth"
  };

  for (int i = 0; i < MAX_WEEKS; i++) {
    if (!strncmp(spec, specs[i], SIGNIFICANT_SPEC_LEN)) {
      return i;
    }
  }
  return -1;
}

int first_day(enum WeekDay target_week_day, int year, int month) {
  for (int i = 1; i < DAYS_IN_MONTH; i++) {
    enum WeekDay candidate_week_day = day_of_the_week(year, month, i);
    if (candidate_week_day == target_week_day) {
      return i;
    }
  }
  return -1;
}

int nth_day_of_the_week(enum WeekDay target_week_day, int year, int month, int n) {
  int first = first_day(target_week_day, year, month);
  
  int current_month = month - 1;
  int counter = 0;
  struct tm* tmp_time;

  for (int i = first; i <= DAYS_IN_MONTH && counter <= n; i += DAYS_OF_WEEK) {
    tmp_time = gettime(year, month, i);
    if (tmp_time->tm_mon > current_month) {
      return INVALID_DAY_OF_THE_WEEK;
    }

    if (counter == n) {
      return tmp_time->tm_mday;
    }
    counter++;
  }
  return INVALID_DAY_OF_THE_WEEK;
}

int find_teenth(int year, short month, enum WeekDay target_week_day) {
  int teenth_test;
  for (int i = 1; i < MAX_WEEKS; i++) {
    
    teenth_test = nth_day_of_the_week(target_week_day, year, month, i);
    if (teenth_test >= TEEN_LOWER && teenth_test <= TEEN_UPPER) {
      return teenth_test;
    }
  }
  return INVALID_DAY_OF_THE_WEEK;
}

int find_last(int year, short month, enum WeekDay target_week_day) {
  int last_test;
  int prev;
  prev = nth_day_of_the_week(target_week_day, year, month, 1);
  for (int i = 2; i < MAX_WEEKS + 1; i++) {
    last_test = nth_day_of_the_week(target_week_day, year, month, i);
    
    if (last_test == INVALID_DAY_OF_THE_WEEK) {
      return prev;
    }
    prev = last_test;
  }
  return INVALID_DAY_OF_THE_WEEK;
}

int meetup_day_of_month(int year,
                        short month,
                        char *spec,
                        char *dow) {

  enum WeekDay target_week_day;
  day_from_string(dow, &target_week_day);

  if (!strncmp(spec, "teenth", SIGNIFICANT_SPEC_LEN)) {
    
    return find_teenth(year, month, target_week_day);
    
  } else if (!strncmp(spec, "last", SIGNIFICANT_SPEC_LEN)) {
    
    return find_last(year, month, target_week_day);
    
  } else {
    
    return nth_day_of_the_week(
                               target_week_day,
                               year,
                               month,
                               spec_from_string(spec));
  }
  
  return 0;
}