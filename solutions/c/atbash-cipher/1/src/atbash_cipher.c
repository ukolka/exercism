#include "atbash_cipher.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define GROUP_SIZE (5)
#define atbash_transpose(ch) ('z' - (tolower(ch) - 'a'))

char *atbash_encode(const char *input) {
  char *out = calloc(strlen(input) * 2, sizeof(char));
  char *op = out;
  
  int counter = 0;
  char ch;
  while ((ch = *input++)) {
    if (isalpha(ch)) {
      *op++ = atbash_transpose(ch);
      counter++;
    } else if (isnumber(ch)) {
      *op++ = ch;
      counter++;
    }

    if (counter > 0 && counter % GROUP_SIZE == 0) {
      counter = 0;
      *op++ = ' ';
    }
  }

  op--;
  if (*op == ' ') *op = '\0';

  return out;
}

char *atbash_decode(const char *input) {
  char *out = calloc(strlen(input), sizeof(char));
  char *op = out;

  char ch;
  while((ch = *input++)) {
    if (isalpha(ch)) {
      *op++ = atbash_transpose(ch);
    } else if (isnumber(ch)) {
      *op++ = ch;
    }
  }

  return out;
}