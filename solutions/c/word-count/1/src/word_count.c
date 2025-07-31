#include "word_count.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

int find_word(char *word, word_count_word_t *words) {
  for (int i = 0; i < MAX_WORDS; i++) {
    if (!strncmp(words[i].text, word, MAX_WORD_LENGTH)) {
      return i;
    }
  }
  return -1;
}

void copy(char* dest, char *src) {
  int len = strnlen(src, MAX_WORD_LENGTH);
  if (src[0] == '\'' && src[len - 1] == '\'') {
    strncpy(dest, &src[1], len - 2);
  } else {
    strncpy(dest, src, len);
  }
}

void increment(char *word, word_count_word_t *words, int unique, bool *found) {
  int idx = find_word(word, words);

  if (idx < 0) {
    copy(words[unique].text, word);
    words[unique].count = 1;
    *found = false;
  } else {
    words[idx].count++;
    *found = true;
  }
}

void print_words(word_count_word_t *words, int unique) {
  for (int i = 0; i < unique; i++) {
    printf("\ttext: %s, count: %d\n", words[i].text, words[i].count);
  }
}

typedef struct {
  char text[MAX_WORD_LENGTH];
  char *ptr;
  int len;
} Word;

int word_count(const char *input_text, word_count_word_t * words) {
  memset(words, 0, MAX_WORDS * sizeof(word_count_word_t));
  
  Word tmp_word;
  tmp_word.ptr = &tmp_word.text[0];
  tmp_word.len = 0;
  
  char curr_char;
  int unique = 0;
  bool found;

  while (true) {
    curr_char = *input_text++;
    
    if (isspace(curr_char) || curr_char == ',' || curr_char == '\0') {
      *tmp_word.ptr = '\0';

      if (unique == MAX_WORDS) {
        return EXCESSIVE_NUMBER_OF_WORDS;
      }

      if (tmp_word.len > 0) {
        increment(tmp_word.text, words, unique, &found);
        if (!found) {
          unique += 1;
        }
      }
      
      tmp_word.len = 0;
      tmp_word.ptr = &tmp_word.text[0];
      
    } else if (isalpha(curr_char) || isnumber(curr_char) || curr_char == '\'') {

      if (tmp_word.len == MAX_WORD_LENGTH) {
        return EXCESSIVE_LENGTH_WORD;
      }
      
      *tmp_word.ptr++ = tolower(curr_char);
      tmp_word.len++;
    }

    if (curr_char == '\0') {
      break;
    }
  }

  //print_words(words, MAX_WORDS);
  
  return unique;
}