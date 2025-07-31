#include "largest_series_product.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int to_digit(char candidate) {
  int rv = candidate - '0';
  if (rv > 9 || rv < 0) return -1;
  return rv;
}

long product(char *input, int width) {
  long result = to_digit(input[0]);
  if (result < 0) return -1;
  
  for (int i = 1; i < width; i++) {
    result *= to_digit(input[i]);
    if (result < 0) return -1;
  }

  return result;
}

long largest_series_product(char *input, int width) {
  int input_len = strlen(input);
  if (input_len < width) return -1;
  if (input_len == 0 || width == 0) return 1;
  
  long result = 0;
  long p;
  
  for (int i = 0; i <= input_len - width; i++)
    if ((p = product(input + i, width)) > result)
      result = p;
    else if (p < 0)
      return -1;
  
  return result;
}