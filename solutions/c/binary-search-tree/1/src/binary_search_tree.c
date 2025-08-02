#include "binary_search_tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

node_t *init_node(int value) {
  node_t *tree = malloc(sizeof(node_t));
  tree->data = value;
  tree->left = NULL;
  tree->right = NULL;
  return tree;
}

void add_node(node_t *tree, int value) {
  if (tree->data >= value) {
    if (tree->left != NULL) {
      add_node(tree->left, value);
    } else {
      tree->left = init_node(value);
    }
  } else if (tree->data < value) {
    if (tree->right != NULL) {
      add_node(tree->right, value);
    } else {
      tree->right = init_node(value);
    }
  }
}

node_t *build_tree(int *input, size_t len) {
  if (!len) return NULL;

  node_t *tree = init_node(*input);
  
  for (size_t i = 1; i < len; i++) {
    add_node(tree, input[i]);
  }

  return tree;
}

typedef struct {
  int data[1024];
  size_t size;
} list_t;

list_t *init_list() {
  list_t *list = malloc(sizeof(list_t));
  list->size = 0;
  return list;
}

void visit_node(node_t *node, list_t *result) {
  result->data[result->size++] = node->data;
}

void inorder(node_t *node, list_t *result) {
  if (node == NULL) return;
  inorder(node->left, result);
  visit_node(node, result);
  inorder(node->right, result);
}

int *sorted_data(node_t *tree) {
  list_t *result = init_list();
  inorder(tree, result);
  int *sorted = malloc(result->size * sizeof(int));
  memcpy(sorted,
         result->data,
         sizeof(result->data[0]) * result->size);
  free(result);
  return sorted;
}