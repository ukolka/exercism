#include "secret_handshake.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define has_action(in, act) ((in & act) == act)
#define HSHAKE_SIZE (4)

typedef enum hshake {
  HSHAKE_WINK = 0x01,
  HSHAKE_DOUBLE_WINK = 0x02,
  HSHAKE_CLOSE_YOUR_EYES = 0x04,
  HSHAKE_JUMP = 0x08,
  HSHAKE_REVERSE = 0x10
} hshake_t;

hshake_t *reverse() {
  hshake_t *result = malloc(HSHAKE_SIZE * sizeof(hshake_t));
  hshake_t *next_hs = result;
  for (hshake_t hs = HSHAKE_JUMP; hs >= HSHAKE_WINK; hs >>= 1)
    *next_hs++ = hs;
  return result;
}

hshake_t *forward() {
  hshake_t *result = malloc(HSHAKE_SIZE * sizeof(hshake_t));
  hshake_t *next_hs = result;
  for (hshake_t hs = HSHAKE_WINK; hs <= HSHAKE_JUMP; hs <<= 1)
    *next_hs++ = hs;
  return result;
}

char *translate(hshake_t hs, int input) {
  if (!has_action(input, hs))
    return NULL;
  
  switch (hs) {
  case HSHAKE_WINK:
    return "wink";
    break;
  case HSHAKE_DOUBLE_WINK:
    return "double blink";
    break;
  case HSHAKE_CLOSE_YOUR_EYES:
    return "close your eyes";
    break;
  case HSHAKE_JUMP:
    return "jump";
    break;
  default:
    return NULL;
  }
  
  return NULL;
}

const char **commands(int input) {
  const char **result = malloc(HSHAKE_SIZE * sizeof(char *));  
  const char **rv = result;
  *rv = NULL;

  bool do_reverse = has_action(input, HSHAKE_REVERSE);
  hshake_t *sequence = do_reverse ? reverse() : forward();
  char *action;
  
  for (int i = 0; i < HSHAKE_SIZE; i++) {
    action = translate(sequence[i], input);
    if (action != NULL)
      *rv++ = action;
  }

  free(sequence);
  
  return result;
}

#undef has_action
#undef HSHAKE_SIZE