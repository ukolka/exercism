#include "nth_prime.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef unsigned short ushort;

bool is_prime(uint candidate, uint *primes, ushort count) {
  bool prime = true;
  for (uint i = 0; i < count; i++) {
    prime = prime && candidate % primes[i] != 0;
  }
  return prime;
}



uint nth(ushort n) {
  if (n == 0) return 0;
  if (n == 1) return 2;
  
  uint *primes = malloc(n * sizeof(uint));
  *primes = 2;  
  uint *next_prime = primes;

  for (uint i = 2; i < UINT_MAX && (next_prime - primes) < n; i++) {
    if (is_prime(i, primes, (next_prime - primes))) {
      *next_prime++ = i;
    }
  }

  uint result = *(next_prime - 1);
  free(primes);
  return result;
}