#include "binary.h"
#include <string.h>

unsigned int convert(char *binary) {
  int len = strlen(binary);
  int result = 0;
  int current_power_of_2 = 0;
  
  for (int i = len - 1; i >= 0; i--)
    switch (binary[i]) {
    case '0':
      current_power_of_2++;
      break;
    case '1':
      result += 1 << current_power_of_2;
      current_power_of_2++;
      break;
    default:
      return INVALID;
      break;
    }
      
  return result;
}