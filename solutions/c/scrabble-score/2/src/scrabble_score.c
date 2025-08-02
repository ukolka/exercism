#include "scrabble_score.h"
#include <ctype.h>
#include <string.h>
#define SCORE_MAP_SIZE (11)

char *score_map[SCORE_MAP_SIZE] = {
  "",
  "AEIOULNRST",
  "DG",
  "BCMP",
  "FHVWY",
  "K",
  "",
  "",
  "JX",
  "",
  "QZ"
};

int score(char *input) {
  int sum = 0;
  char ch;
  
  while ((ch = *input++))
    for (int i = 0; i < SCORE_MAP_SIZE; i++)
      if (strchr(score_map[i], toupper(ch)))
          sum += i;

  return sum;
}