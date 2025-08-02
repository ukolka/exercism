#include "phone_number.h"

void invalidate_result(char *result) {
  memset(result, '0', PHONE_NUM_LEN);
  result[PHONE_NUM_LEN] = '\0';
}

char *phone_number_clean(const char *input) {  
  char *result = calloc(PHONE_NUM_LEN * 2, sizeof(char));
  int num_digits = 0;

  const char *cursor = input;
  char ch;
  while ((ch = *cursor++)) {
    if (isdigit(ch)) {
      result[num_digits++] = ch;
    } else if (isalpha(ch)) {
      invalidate_result(result);
      return result;
    }
  }

  if (num_digits < PHONE_NUM_LEN) {
    invalidate_result(result);
  } else if (num_digits == PHONE_NUM_LEN + 1) {
    if (*result == '1')      
      memmove(result, result + 1, PHONE_NUM_LEN + 1);
    else
      invalidate_result(result);
  } else if (num_digits > PHONE_NUM_LEN + 1) {
    invalidate_result(result);
  }
  
  return result;
}

char *phone_number_get_area_code(const char *input) {
  char *clean_no = phone_number_clean(input);
  char *result = calloc(AREA_CODE_LEN + 1, sizeof(char));
  memcpy(result, clean_no, AREA_CODE_LEN);
  free(clean_no);
  return result;
}

// ( 1 2 3 )   4 5 6 - 7  8  9  0  \0
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
char *phone_number_format(const char *input) {
  char *clean_no = phone_number_clean(input);
  char *result = calloc(FORMATTED_PHONE_NUM_LEN + 1, sizeof(char));
  *result = '(';
  memcpy(result + 1, clean_no, 3);
  *(result + 4) = ')';
  *(result + 5) = ' ';
  memcpy(result + 6, clean_no + 3, 3);
  *(result + 9) = '-';
  memcpy(result + 10, clean_no + 6, 4);
  free(clean_no);
  return result;
}