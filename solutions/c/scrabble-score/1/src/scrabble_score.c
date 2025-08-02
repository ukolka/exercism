#include "scrabble_score.h"
#include <ctype.h>
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
  char ch, test_ch;
  
  while ((ch = *input++))
    for (int i = 0; i < SCORE_MAP_SIZE; i++) {
      char *char_list = score_map[i];
      while((test_ch = *char_list++))
        if (toupper(ch) == test_ch)
          sum += i;
    }

  return sum;
}