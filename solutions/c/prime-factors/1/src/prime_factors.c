#include "prime_factors.h"
#include <stdio.h>

size_t find_factors(unsigned long input, uint64_t *result) {
  size_t count = 0;
  unsigned int factor = 2;

  while (input > 1) {
    if (input % factor == 0) {
      result[count++] = factor;
      input /= factor;
    } else {
      factor++;
    }
  }
  
  return count;
}