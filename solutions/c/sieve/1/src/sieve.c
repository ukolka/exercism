#include "sieve.h"
#include <string.h>
#include <stdbool.h>

unsigned int sieve(const unsigned int limit, primes_array_t primes) {  
  memset(primes, 0, MAX_LIMIT_TESTED);

  unsigned int count = 0;
  
  if (limit < 2 || limit > MAX_LIMIT_TESTED)
    return count;

  primes[0] = 2;
  count++;
  
  if (limit == 2)
    return count;

  unsigned int *next_prime = &primes[1];

  for (unsigned int candidate = 3; candidate <= limit; candidate++) {
    
    bool is_prime = true;
    
    for (unsigned int prime_idx = 0; prime_idx < count; prime_idx++) {
      
      unsigned int prime = primes[prime_idx];
      is_prime &= candidate % prime != 0;
    }
    
    if (is_prime) {
      *next_prime++ = candidate;
      count++;
    }
  }

  return count;
}