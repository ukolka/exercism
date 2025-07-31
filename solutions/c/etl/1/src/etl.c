#include "etl.h"
#include <stdlib.h>
#include <ctype.h>
#define MAX_OUTPUT (26)

void add_to_map(new_map *item, new_map **map, int position) {
  if (position == 0) {
    (*map)[position] = *item;
    return;
  }

  position--;
  
  while (position >= 0 && item->key < (*map)[position].key) {
    (*map)[position + 1] = (*map)[position];
    position--;
  }
  
  (*map)[position + 1] = *item; 
}

int convert(legacy_map *input, int input_len, new_map **output) {
  *output = (new_map *) malloc(MAX_OUTPUT * sizeof(new_map));
  int count = 0;
  
  for (int i = 0; i < input_len; i++) {
    char *keys = input[i].keys;
    int val = input[i].value;
    while (*keys) {
      new_map entry = (new_map) { tolower(*keys++), val };
      add_to_map(&entry, output, count++);
    }
  }
  
  return count;
}