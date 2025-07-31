#include "anagram.h"
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include <stdbool.h>
#include <locale.h>

int mystrcmp(const void *a, const void *b) {
  return wcscmp((const wchar_t *) a, (const wchar_t *) b);
}

wchar_t *towcs(const char *word) {
  size_t len = strlen(word) + 1;
  wchar_t* wcword = calloc(strlen(word) + 1, sizeof(wchar_t)); 
  mbstowcs(wcword, word, len - 1);
  return wcword;
}

wchar_t *strtolower(const char *word) {
  wchar_t *result = towcs(word);
  size_t result_len = wcslen(result);

  for (size_t i = 0; i < result_len; i++) {
    result[i] = towlower(result[i]);
  }

  return result;
}

void sort(wchar_t *word) {
  qsort((void *) word, wcslen(word), sizeof(wchar_t), mystrcmp);  
}

void anagrams_for(const char *word, struct candidates *candidates) {
  wchar_t *lc_word = strtolower(word);
  wchar_t *sorted_word = strtolower(word);
  sort(sorted_word);

  
  for (size_t i = 0; i < candidates->count; i++) {
    struct candidate *c = &candidates->candidate[i];
    wchar_t *lc_cword = strtolower(c->candidate);

    bool different_len = wcslen(lc_word) != wcslen(lc_cword);
    bool same_word = !wcscmp(lc_word, lc_cword);
    
    if (different_len || same_word) {
      c->is_anagram = NOT_ANAGRAM;
      free(lc_cword);
      continue;
    } else {
      free(lc_cword);      
    }

    wchar_t *sorted_cword = strtolower(c->candidate);
    sort(sorted_cword);

    if (!wcscmp(sorted_word, sorted_cword))
      c->is_anagram = IS_ANAGRAM;
    else
      c->is_anagram = NOT_ANAGRAM;

    free(sorted_cword);
  }
  
  free(lc_word);
  free(sorted_word);
}