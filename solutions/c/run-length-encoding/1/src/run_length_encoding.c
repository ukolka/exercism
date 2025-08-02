#include "run_length_encoding.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_BUFFER (1000)

char *encode(const char *input) {
  char *result = malloc(MAX_BUFFER * sizeof(char));
  *result = '\0';

  if (input == NULL || !*input)
    return result;

  char tmp_string[16];
  char prev_ch = *input;
  char ch;
  int count = 0;
  int in_len = strlen(input);
  
  for (int i = 0; i <= in_len; i++) {
    ch = input[i];
    
    if (ch == prev_ch) count++;
    else {
      *tmp_string = '\0';
      if (count > 1) {
        sprintf(tmp_string, "%d%c", count, prev_ch);
      } else {
        sprintf(tmp_string, "%c", prev_ch);
      }
      strcat(result, tmp_string);
      count = 1;
    }
      
    prev_ch = ch;
  }
  return result;
}

char *decode(const char *input) {
  char *result = malloc(MAX_BUFFER * sizeof(char));
  *result = '\0';

  if (input == NULL || !*input)
    return result;

  char *rv = result;
  char ch;
  int times = 0;
  while ((ch = *input++)) {
    while (isdigit(ch)) {
      times = times * 10 + (ch - '0');
      ch = *input++;
    }

    while (--times > 0)
      *rv++ = ch;
    *rv++ = ch;
    times = 0;
  }
  
  *rv = '\0';
  return result;
}

#undef MAX_BUFFER