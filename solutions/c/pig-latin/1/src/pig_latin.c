#include "pig_latin.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

bool is_vowel(char ch) {
  if (isalpha(ch))
    return (bool) strchr("aeiou", ch);
  return false;
}

bool is_consonant(char ch) {
  return !is_vowel(ch);
}


char *translate_word(const char *input) {
  int in_len = strlen(input);
  char *result = calloc(in_len * 3, sizeof(char));
  int offset = 0;
  
  if (strstr(input, "xr") == input ||
      strstr(input, "yt") == input) {
    offset = 0;
  } else if (is_consonant(input[0])) {
    if (strstr(input, "qu") == input) {
      offset = 2;
    } else if (strstr(&input[1], "qu") == &input[1]) {
      offset = 3;
    } else if (input[0] == 'y') {
      offset = 1;
    } else {
      while (input[offset] != 'y' && is_consonant(input[offset])) offset++;
    }
  }
  strcat(result, input + offset);
  strncat(result, input, offset);
  strcat(result, "ay");

  return result;
}

char *translate(const char *input) {
  char *input_copy = strdup(input);
  char *result = calloc(strlen(input) * 3, sizeof(char));
  char *word = strtok(input_copy, " ");
  char *translated_word;
  while (word != NULL) {
    translated_word = translate_word(word);
    strcat(result, translated_word);
    free(translated_word);
    strcat(result, " ");
    word = strtok(NULL, " ");
  }
  free(input_copy);
  result[strlen(result) - 1] = '\0';
  return result;
}