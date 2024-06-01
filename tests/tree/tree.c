#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct Node* new_node(int value) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->value = value;
  node->left = node->right = NULL;
  return node;
}

void add_node(struct Node **node, int value) {
  if (*node == NULL) {
    *node = new_node(value);
    return;
  }
  struct Node *current = *node;
  if (value > current->value) {
    add_node(&current->right, value);
  } else if (value < current->value) {
    add_node(&current->left, value);
  }
}

struct Node* make_tree(int argc, char **argv) {
  struct Node *root = NULL;
  for(int i = 1; i < argc; ++i) {
    add_node(&root, atoi(argv[i]));
  }
  return root;
}

void free_tree(struct Node *node) {
  if (node == NULL) return;

  free_tree(node->left);
  free_tree(node->right);

  free(node);
}
