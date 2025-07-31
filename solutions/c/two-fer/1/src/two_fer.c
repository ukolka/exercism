#include "two_fer.h"
#include <stdlib.h>
#include <stdio.h>

void two_fer(char *result, char *name) {
  *result = '\0';

  sprintf(result,
          "One for %s, one for me.",
          (name == NULL ? "you" : name));
}