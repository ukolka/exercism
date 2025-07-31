#ifndef PALINDROME_PRODUCTS_H
#define PALINDROME_PRODUCTS_H

typedef struct factor {
  int factor_a;
  int factor_b;
  struct factor *next;
} factor_t;

typedef struct {
  int smallest;
  int largest;
  factor_t *factors_sm;
  factor_t *factors_lg;
  char *error;
} product_t;

product_t *get_palindrome_product(int, int);
void free_product(product_t *);

#endif