#include "sum_of_multiples.h"
#include <stdbool.h>
#include <stdlib.h>

unsigned long sum_of_multiples(const unsigned int multiples[],
                              unsigned int size,
                              unsigned int ubound) {
  if (multiples == NULL) return 0;

  unsigned long sum = 0;
  
  for (unsigned n = 1; n < ubound; n += 1) {
    bool at_least_one_multiple = false;

    for (unsigned int idx = 0; idx < size; idx++) {
      if (multiples[idx] == 0) return 0;
      at_least_one_multiple = at_least_one_multiple || n % multiples[idx] == 0;
    }


    if (at_least_one_multiple)
      sum += n;
  }

  return sum;
}