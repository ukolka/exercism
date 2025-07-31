#include "raindrops.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void convert(char *result, int drops) {
  bool multiple_of_3 = drops % 3 == 0;
  bool multiple_of_5 = drops % 5 == 0;
  bool multiple_of_7 = drops % 7 == 0;

  if (multiple_of_3)
    strcat(result, "Pling");
  if (multiple_of_5)
    strcat(result, "Plang");
  if (multiple_of_7)
    strcat(result, "Plong");
  if (!multiple_of_3 && !multiple_of_5 && !multiple_of_7) {
    sprintf(result, "%d", drops);
  }
}