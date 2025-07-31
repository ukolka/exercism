#include "isogram.h"
#include <string.h>
#include <ctype.h>
#define ALPHA_LEN 26


bool is_isogram(const char phrase[]) {
  int len = strlen(phrase);
  if (len == 0) {
    return true;
  }
  
  int freq[ALPHA_LEN];
  for (int i = 0; i < ALPHA_LEN; i++) freq[i] = 0;  

  for (int i = 0; i < len; i++) {
    if (!isalpha(phrase[i])) {
      continue;
    }
    
    int idx = tolower(phrase[i]) - 'a';

    freq[idx]++;
    if (freq[idx] > 1) {
      return false;
    }
  }
  return true;
}