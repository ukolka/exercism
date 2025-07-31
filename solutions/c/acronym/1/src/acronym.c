#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *abbreviate(const char *phrase) {
  if (phrase == NULL) {
    return NULL;
  }

  if (strlen(phrase) == 0) {
    return NULL;
  }
  
  char prev = ' ';
  char *result = malloc(17);
  char *res_cur = result;
  char curr;

  int i = 0;
  while ((curr = *(phrase + i)) != '\0') {
    switch (prev) {
    case ' ':
    case '-':
      *res_cur = toupper(curr);
      res_cur++;
      break;
    default:
      break;
    }
    prev = curr;
    i++;
  }

  *res_cur = '\0';

  return result;
}