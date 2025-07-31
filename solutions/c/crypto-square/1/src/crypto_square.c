#include "crypto_square.h"
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>


char *sanitize(const char *input) {
 char *result = calloc(strlen(input) + 1, sizeof(char));
 char *rv = result;
 char ch;
 
 while ((ch = *input++)) {
   if (isalpha(ch))
     *rv++ = tolower(ch);
   else if (isdigit(ch))
     *rv++ = ch;
 }

 return result;
}

char *ciphertext(const char *input) {
  char *sanitized = sanitize(input);
  int s_len = strlen(sanitized);
  
  int r =  (int) roundf(sqrtf(s_len));
  int c = (r * r < s_len) ? r + 1 : r;
  
  char *output = calloc((c * (r + 1)) + 1, sizeof(char));
  char *ov = output;

  for (int t_row = 0; t_row < c; t_row++) {
    for (int t_col = 0; t_col < r; t_col++) {
      int sanitized_idx = t_col * c + t_row;

      if (sanitized_idx < s_len)
	*ov++ = sanitized[sanitized_idx];
      else
	*ov++ = ' ';
    }
    *ov++ = ' ';
  }

  if (ov - output)
    *(--ov) = '\0';
  
  free(sanitized);
  return output;
}