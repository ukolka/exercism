#include "diamond.h"
#include <stdlib.h>
#include <string.h>

char *make_row(char ch, int half_width) {
  int width = half_width * 2 - 1;
  char *row = calloc(width + 1, sizeof(char));
  memset(row, ' ', width);
  
  int offset = ch - 'A';

  int center = half_width - 1;
  row[center + offset] = ch;
  row[center - offset] = ch;
  return row;
}

char **make_diamond(char input) {
  if (input < 'A' || input > 'Z') return NULL;

  int half_width = input - 'A' + 1;
  
  if (half_width == 1) {
    char **result = malloc(sizeof(char *));
    *result = calloc(2, sizeof(char));
    **result = 'A';
    return result;
  }

  char **result = malloc((half_width * 2 - 1) * sizeof(char *));
  int result_idx = 0;
  
  for (char ch = 'A'; ch <= input; ch++)
    result[result_idx++] = make_row(ch, half_width);

  for (char ch = input - 1; ch >= 'A'; ch--)
    result[result_idx++] = make_row(ch, half_width);

  return result;
}