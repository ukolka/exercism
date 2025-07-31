#include "binary_search.h"
#include <stdlib.h>

int *binary_search(int needle, int haystack[], size_t len) {
  if (haystack == NULL) return NULL;
  
  int lo = 0;
  int hi = len - 1;
  
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    
    if (haystack[mid] == needle)
      return &haystack[mid];

    if (needle < haystack[mid]) {
      hi = mid - 1;
    }
      
    if (haystack[mid] < needle) {
      lo = mid + 1;
    }
  }

  return NULL;
}