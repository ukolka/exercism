#include "wordy.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static char *delimiters = " ?";

typedef enum operations {
  OP_PLUS,
  OP_MINUS,
  OP_MUL,
  OP_DIV
} op_t;

typedef struct {
  int stack[100];
  int size;
} operands_t;

typedef struct {
  op_t stack[99];
  int size;
} operators_t;

bool is_operator(char *token, op_t *result) {
  if (!strcmp(token, "plus")) {
    *result = OP_PLUS;
    return true;
  } else if (!strcmp(token, "minus")) {
    *result = OP_MINUS;
    return true;
  } else if (!strcmp(token, "multiplied")) {
    *result = OP_MUL;
    return true;
  } else if (!strcmp(token, "divided")) {
    *result = OP_DIV;
    return true;
  }
  return false;
}

bool is_operand(char *token, int *result) {
  char *first_invalid = token;
  int rv = (int) strtol(token, &first_invalid, 10);
  if (first_invalid == token) {
    return false;
  }
  *result = rv;
  return true;
}

void push_operator(operators_t *ops, op_t op) {
  ops->stack[ops->size++] = op;
}

op_t *pop_operator(operators_t *ops) {
  if (!ops->size) return NULL;
  return &ops->stack[--ops->size];
}

void push_operand(operands_t *operands, int operand) {
  operands->stack[operands->size++] = operand;
}

int *pop_operand(operands_t *operands) {
  if (!operands->size) return NULL;
  return &operands->stack[--operands->size];
}

int apply(op_t op, int lhs, int rhs) {
  switch (op) {
  case OP_PLUS:
    return lhs + rhs;
    break;
  case OP_MINUS:
    return lhs - rhs;
    break;
  case OP_MUL:
    return lhs * rhs;
  case OP_DIV:
    return lhs / rhs;
  }
  return 0;
}

void print_operands(operands_t *operands) {
  puts("---- operands -----");
  for (int i = operands->size - 1; i > 0; i--)
    printf("%d\n", operands->stack[i]);
  puts("---- end operands -----");
}

bool answer(const char *question, int *result) {
  char *q = strdup(question);
  char *token = strtok(q, delimiters);
  *result = 0;

  operands_t *operands = malloc(sizeof(operands_t));
  operands->size = 0;

  operators_t *operators = malloc(sizeof(operators_t));
  operators->size = 0;

  op_t operator;
  int rhs;
  bool encountered_operators = false;
  
  while (token != NULL) {
    if (is_operator(token, &operator)) {
      encountered_operators = true;
      push_operator(operators, operator);
    } else if (is_operand(token, &rhs)) {
      op_t *op = pop_operator(operators);
      int *lhs = NULL;

      if (op != NULL) {
        lhs = pop_operand(operands);
        push_operand(operands, apply(*op, *lhs, rhs));
      } else {
        push_operand(operands, rhs);
      }
    }
    
    token = strtok(NULL, delimiters);
  }
  
  int *rv = pop_operand(operands);
  bool success = rv != NULL && encountered_operators;
  if (success)
    *result = *rv;

  free(operands);
  free(operators);
  free(q);
  
  return success;
}