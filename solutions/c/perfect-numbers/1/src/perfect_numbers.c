#include "perfect_numbers.h"

kind classify_number(int n) {
  if (n <= 0) return ERROR;
  if (n == 1) return DEFICIENT_NUMBER;
  
  int factors_sum = 1;
  for (int i = 2; i < (n / 2) + 1; i++)
    if (n % i == 0)
      factors_sum += i;

  if (factors_sum == n)
    return PERFECT_NUMBER;
  if (factors_sum > n)
    return ABUNDANT_NUMBER;
  if (factors_sum < n)
    return DEFICIENT_NUMBER;
  
  return ERROR;
}