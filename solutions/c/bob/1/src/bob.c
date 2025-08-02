#include "bob.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char *hey_bob(char *input) {
  bool all_alphas_are_caps = true;
  bool is_question = false;
  bool no_alphas = true;
  bool all_space = true;

  char last_ch;
  char ch;
  while ((ch = *input++)) {
    
    if (isalpha(ch)) {
      no_alphas = false;
      
      if (islower(ch))
        all_alphas_are_caps = false;
    }

    if (!isspace(ch)) {
      all_space = false;
      last_ch = ch;
    }
  }

  all_alphas_are_caps = all_alphas_are_caps && !no_alphas;

  is_question = last_ch == '?';

  if (all_space)
    return "Fine. Be that way!";
  if (all_alphas_are_caps && is_question)
    return "Calm down, I know what I'm doing!";
  if (all_alphas_are_caps)
    return "Whoa, chill out!";
  if (is_question)
    return "Sure.";

  return "Whatever.";
}