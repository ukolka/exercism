#include "palindrome_products.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX_DIGITS (9)
#define MAX_ERROR_LEN (1000)

product_t *init_palindrome_product(int, int);
void process_candidate(product_t *, int, int);
void free_factors(factor_t *);

product_t *get_palindrome_product(int start, int end) {
  product_t *p = init_palindrome_product(start, end);

  if (start > end) {
    p->error = (char *) malloc(MAX_ERROR_LEN * sizeof(char));
    sprintf(p->error, "invalid input: min is %d and max is %d", start, end);
    return p;
  }
  
  for (int a = start; a <= end; a++)
    for (int b = a; b <= end; b++)
      process_candidate(p, a, b);
  

  if (!p->factors_sm) {
    p->error = (char *) malloc(MAX_ERROR_LEN * sizeof(char));
    sprintf(p->error, "no palindrome with factors in the range %d to %d", start, end);
  }
  
  return p;
}

typedef struct {
  int digits[MAX_DIGITS];
  int count;
} product_digits_t;

product_digits_t *get_digits(unsigned long input) {
  product_digits_t *d = malloc(sizeof(product_digits_t));
  d->count = 0;

  while (input > 0) {
    d->digits[d->count++] = input % 10;
    input /= 10;
  }

  return d;
}

bool is_palindrome(int input) {
  product_digits_t *d = get_digits(input);
  bool palindrome = true;

  for (int i = 0; i < d->count / 2; i++) {
    if (!palindrome) break;
    palindrome = palindrome && (d->digits[i] == d->digits[d->count - 1 - i]);
  }

  free(d);
  return palindrome;
}

factor_t *create_factor(int a, int b) {
  factor_t *f = (factor_t *) malloc(sizeof(factor_t));
  f->factor_a = a;
  f->factor_b = b;
  f->next = NULL;
  return f;
}

void add_smallest(product_t *p, factor_t *factor_sm) {
  if (factor_sm == NULL) return;
  
  if (p->factors_sm == NULL)
    p->factors_sm = factor_sm;
  else {
    factor_sm->next = p->factors_sm;
    p->factors_sm = factor_sm;
  }
}

void add_largest(product_t *p, factor_t *factor_lg) {
  if (factor_lg == NULL) return;
  
  if (p->factors_lg == NULL)
    p->factors_lg = factor_lg;
  else {
    factor_lg->next = p->factors_lg;
    p->factors_lg = factor_lg;
  }
}

void process_smallest(product_t *p, int a, int b) {
  int p_ab = a * b;
  if (p_ab > p->smallest) return;
  if (p_ab < p->smallest) {
    free_factors(p->factors_sm);
    p->smallest = p_ab;
    p->factors_sm = create_factor(a, b);
  }
  else if (p_ab == p->smallest) {
    add_smallest(p, create_factor(a, b));
  }
}

void process_largest(product_t *p, int a, int b) {
  int p_ab = a * b;
  if (p_ab < p->largest) return;

  if (p_ab > p->largest) {

    free_factors(p->factors_lg);
    p->largest = p_ab;
    p->factors_lg = create_factor(a, b);
  }
  else if (p_ab == p->largest) {

    add_largest(p, create_factor(a, b));
  }
}

void process_candidate(product_t *p, int a, int b) {
  unsigned long p_ab = a * b;
  if (!is_palindrome(p_ab))
    return;

  process_smallest(p, a, b);
  process_largest(p, a, b);
}

product_t *init_palindrome_product(int start, int end) {
  product_t *p = malloc(sizeof(product_t));

  p->smallest = end * end + 1;  
  p->factors_sm = NULL;

  p->largest = start * start - 1;
  p->factors_lg = NULL;

  p->error = NULL;

  return p;
}

void free_factors(factor_t *f) {
  if (f == NULL) return;
  
  if (f->next != NULL)
    free_factors(f->next);
  
  free(f);
}

void free_product(product_t *p) {
  free(p->error);
  free_factors(p->factors_sm);
  free_factors(p->factors_lg);
  free(p);
}