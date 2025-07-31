#include "hamming.h"
#include <string.h>

int compute(char *a, char *b) {
  if (a == NULL || b == NULL || strlen(a) != strlen(b)) {
    return INVALID_INPUT;
  }

  int sum = 0;
  char ch_a;
  char ch_b;
  while ((ch_a = *a++) && (ch_b = *b++))
    if (ch_a != ch_b) sum++;
  
  return sum;
}