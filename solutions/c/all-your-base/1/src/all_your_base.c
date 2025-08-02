#include "all_your_base.h"

enum {
 NEGATIVE_DIGIT = -1,
 INVALID_DIGIT = -2
} Error;

unsigned int my_pow(unsigned int, unsigned int);
int parse(int8_t *, int16_t, size_t);
void reverse(int8_t *, size_t);
void print_digits(int8_t *, size_t);

size_t rebase(int8_t *digits, int16_t in_base, int16_t out_base, size_t in_len) {
  if (in_base <= 1 || out_base <= 1 || digits[0] == 0)
    return 0;
  
  int parsed = parse(digits, in_base, in_len);
  
  if (parsed == NEGATIVE_DIGIT || parsed == INVALID_DIGIT)
    return 0;
  
  size_t out_len = 0;
  while (parsed > 0 && out_len < DIGITS_ARRAY_SIZE) {
    digits[out_len++] = parsed % out_base;
    parsed /= out_base;
  }

  reverse(digits, out_len);
  
  return out_len;
}

void reverse(int8_t *digits, size_t length) {
  for (int i = 0, j = length - 1; i < j; i++, j--) {
    int8_t tmp = digits[i];
    digits[i] = digits[j];
    digits[j] = tmp;
  }
}

int parse(int8_t *digits, int16_t base, size_t in_len) {
  unsigned int sum = 0;
  for (int i = in_len - 1, idx = 0; i >= 0; i--, idx++) {
    int8_t digit = digits[i];
    if (digit < 0)
      return NEGATIVE_DIGIT;
    if (digit >= base)
      return INVALID_DIGIT;
    sum += digit * my_pow(base, idx);
  }
  return sum;
}

unsigned int my_pow(unsigned int x, unsigned int e) {
  unsigned int rv = 1;
  for (unsigned int i = 0; i < e; i++)
    rv *= x;
  return rv;
}