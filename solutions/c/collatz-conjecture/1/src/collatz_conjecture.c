#include "collatz_conjecture.h"

int steps(int start) {
  if (start < 1) return ERROR_VALUE;
  if (start == 1) return 0;

  if (start % 2 == 0)
    return steps(start / 2) + 1;
  
  return steps(start * 3 + 1) + 1;
}