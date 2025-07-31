#include "bracket_push.h"
#include <stdlib.h>
#define MAX_BRACKETS (1000)

typedef struct {
  char *stack;
  int size;
} bracket_stack_t;


bracket_stack_t *init_stack() {
  bracket_stack_t *s = malloc(sizeof(bracket_stack_t));
  s->stack = malloc(MAX_BRACKETS * sizeof(char));
  s->size = 0;
  return s;
}

void destroy_stack(bracket_stack_t *s) {
  free(s->stack);
  free(s);
}

void push(char ch, bracket_stack_t *s) {
  if (s->size < MAX_BRACKETS)
    s->stack[s->size++] = ch;
}

bool pop(bracket_stack_t *s, char *output) {
  if (s->size > 0)
    *output = s->stack[--s->size];
  else
    output = NULL;
  
  return output != NULL;
}

bool is_top_equal_to(bracket_stack_t *s, char ch) {
  char top;
  bool status = pop(s, &top);
  if (status) {
    return ch == top;
  }
  return false;
}

bool not_paired(bracket_stack_t *s) {
  destroy_stack(s);
  return false;
}

bool is_empty(bracket_stack_t *s) {
  bool rv = s->size == 0;
  destroy_stack(s);
  return rv;
}

char opening(char closing) {
  switch (closing) {
  case '}':
    return '{';
  case ')':
    return '(';
  case ']':
    return '[';
  default:
    break;
  }
  return '\0';
}

bool is_paired(const char *input) {
  bracket_stack_t *stack = init_stack();
  
  char ch;
  while ((ch = *input++)) {
    switch (ch) {
    case '[':
    case '{':
    case '(':
      push(ch, stack);
      break;
    case ']':
    case '}':
    case ')':
      if (!is_top_equal_to(stack, opening(ch))) return not_paired(stack);
      break;
    default:
      break;
    }
  }

  return is_empty(stack);
}