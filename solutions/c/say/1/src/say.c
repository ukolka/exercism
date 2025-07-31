#include "say.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ANSWER_LEN (256)
#define say_over_999(start, name) say(n / start, answer); strcat(*answer, " "); strcat(*answer, name); if (n % start) { strcat(*answer, " "); say(n % start, answer); }


static char *under_20[] = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine",
  "ten",
  "eleven",
  "twelve",
  "thirteen",
  "fourteen",
  "fifteen",
  "sixteen",
  "seventeen",
  "nineteen"
};

static char *tens[] = {
  "",
  "",
  "twenty",
  "thirty",
  "forty",
  "fifty",
  "sixty",
  "seventy",
  "eighty",
  "ninety",
};

int say(long long n, char **answer) {
  if (n < 0 || n > 999999999999)
    return -1;
  
  if (*answer == NULL)
    *answer = calloc(MAX_ANSWER_LEN, sizeof(char));
  
  if (n < 20)
    strcat(*answer, under_20[n]);
  else if (n >= 20 && n < 100) {
    strcat(*answer, tens[n / 10]);
    if (n % 10) {
      strcat(*answer, "-");
      strcat(*answer, under_20[n % 10]);
    }
  } else if (n >= 100 && n < 1000) {
    strcat(*answer, under_20[n / 100]);
    strcat(*answer, " hundred");
    if (n % 100) {
      strcat(*answer, " ");
      say(n % 100, answer);
    }
  } else if (n >= 1000 && n < 1000000) {
    say_over_999(1000, "thousand");
  } else if (n >= 1000000 && n < 1000000000) {
    say_over_999(1000000, "million");
  } else if (n >= 1000000000 && n < 1000000000000) {
    say_over_999(1000000000, "billion");
  }
  
  return 0;
}

#undef MAX_ANSWER_LEN
#undef say_over_999