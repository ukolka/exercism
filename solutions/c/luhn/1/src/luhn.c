#include "luhn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int once(char ch) {
  return ch - '0';
}

int twice(char ch) {
  int rv = once(ch);
  rv <<= 1;
  if (rv > 9) rv -= 9;
  return rv;
}

char *sanitize(char *input) {
  char *rv = calloc(strlen(input) + 1, sizeof(char));
  int size = 0;
  char ch;
  while ((ch = *input++)) {
    if (isspace(ch)) {
      continue;
    }
    if (isdigit(ch)) {
      rv[size++] = ch;
    } else {
      free(rv);
      return NULL;
    }
  }

  if (size < 2) {
    free(rv);
    rv = NULL;
  }
  
  return rv;
}

bool luhn(char *input) {
  char *s_input = sanitize(input);
  if (s_input == NULL) return false;
  
  int len = strlen(s_input);

  int sum = 0;
  for (int i = len - 1; i >= 0; i -= 1)
    if ((len - i) % 2 == 0)
      sum += twice(s_input[i]);
    else
      sum += once(s_input[i]);

  free(s_input);
  return sum % 10 == 0;
}