#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <stddef.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;  
} node_t;

node_t *build_tree(int *, size_t);

int *sorted_data(node_t *);

#endif