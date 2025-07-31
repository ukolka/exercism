#include "pangram.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define ALPHABET_SIZE 26

int sum(int *freq) {
  int s = 0;
  for (int i = 0; i < ALPHABET_SIZE; i++) s += freq[i];
  return s;
}

bool is_pangram(const char *sentence) {
  if (sentence == NULL) return false;

  int freq[ALPHABET_SIZE];
  for (int i = 0; i < ALPHABET_SIZE; i++) freq[i] = 0;

  char ch;
  while ((ch = *sentence++) != '\0') {
    if (isalpha(ch)) {
      freq[(int) tolower(ch) - (int) 'a'] = 1;

      if (sum(freq) == ALPHABET_SIZE) {
        return true;
      }
    }
  }
  return false;
}