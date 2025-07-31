#include "grains.h"
#define MAX_SQUARE 64
#define MIN_SQUARE 1
#define RATE 2

unsigned long square(short n) {
  if (n < MIN_SQUARE || n > MAX_SQUARE) return 0;

  unsigned long result = 1;
  short i = 1;
  while (i++ < n)
    result *= RATE;

  return result;  
}

unsigned long total() {
  unsigned long sum = 0;

  for (short i = 1; i <= MAX_SQUARE; i++) sum += square(i);

  return sum;
}