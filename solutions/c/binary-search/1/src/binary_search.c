#include "binary_search.h"
#include <stdlib.h>

int *binary_search(int needle, int haystack[], size_t len) {
  if (haystack == NULL) return NULL;
  
  int lo = 0;
  int hi = len - 1;
  
  while (lo < hi) {
    int mid = (hi - lo) / 2 + lo;
    
    if (haystack[mid] == needle)
      return &haystack[mid];

    if (needle < haystack[mid]) {
      hi = mid;
    }
      
    if (haystack[mid] < needle) {
      lo = mid + 1;
    }
  }

  if (lo == hi && haystack[lo] == needle)
    return &haystack[lo];

  return NULL;
}