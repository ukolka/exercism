#include "difference_of_squares.h"

unsigned long square_of_sum(unsigned int n) {
  unsigned long sum = 0;
  for (unsigned int i = 1; i <= n; i++)
    sum += i;
  return sum * sum;
}
unsigned long sum_of_squares(unsigned int n) {
  unsigned long sum = 0;
  for (unsigned int i = 1; i <= n; i++)
    sum += i * i;
  return sum;
}
unsigned long difference_of_squares(unsigned int n) {
  return square_of_sum(n) - sum_of_squares(n); 
}