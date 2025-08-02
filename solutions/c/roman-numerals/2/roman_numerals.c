#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>
#define MAX_NUMERAL_LEN 32

char *to_roman_numeral(unsigned int n) {
  if (n > 3000 || n < 1) return NULL;
  
  char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
  char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXXX", "XC"};
  char *hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  char *thousands[] = {"", "M", "MM", "MMM"};

  char *result = calloc(MAX_NUMERAL_LEN, sizeof(char));

  if (n / 1000 > 0) {
    strcat(result, thousands[n / 1000]);
    n %= 1000;
  }
  if (n / 100 > 0) {
    strcat(result, hundreds[n / 100]);
    n %= 100;
  }
  if (n / 10 > 0) {
    strcat(result, tens[n / 10]);
    n %= 10;
  }
  if (n > 0) {
    strcat(result, ones[n]);
  }

  return result;
}