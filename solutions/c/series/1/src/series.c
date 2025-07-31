#include "series.h"
#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <string.h>

series_results_t series(char *input_text, unsigned int substring_length) {  
  unsigned int input_len = strnlen(input_text, MAX_INPUT_TEXT_LENGTH);
  
  if (input_len < substring_length || !substring_length)
    return (series_results_t) { 0, NULL };
  if (input_len == substring_length) {
    series_results_t out = { 1, malloc(sizeof(char **)) };
    *out.substring = strndup(input_text, input_len);
    return out;
  }

  series_results_t out = {
    0,
    malloc((input_len - substring_length + 1) * sizeof(char **))
  };
  char **subst_p = out.substring; 
    
  for (unsigned int i = 0; i <= input_len - substring_length; i++) {
    
    *subst_p = calloc((substring_length + 1), sizeof(char));
    strncpy(*subst_p, &input_text[i], substring_length);
    
    subst_p++;
    out.substring_count++;
  }

  return out;
}