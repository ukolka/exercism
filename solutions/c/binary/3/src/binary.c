#include "binary.h"

unsigned int convert(char *binary) {
  unsigned int result = 0;
  
  while (*binary) {
    result <<= 1;
    switch (*binary++) {
    case '0':
      break;
    case '1':
      result |= 1; 
      break;
    default:
      return INVALID;
      break;
    }
  }
      
  return result;
}