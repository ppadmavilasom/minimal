#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void print_in_order(struct Node *node) {
  if (!node) return;

  if (node->left) {
    print_in_order(node->left);
  }
  printf("%d ", node->value);
  if (node->right) {
    print_in_order(node->right);
  }
}

void print_post_order(struct Node *node) {
  if (!node) return;

  if (node->right) {
    print_post_order(node->right);
  }
  printf("%d ", node->value);
  if (node->left) {
    print_post_order(node->left);
  }
}

int main(int argc, char **argv) {
  if(argc < 2) {
    printf("Usage: %s <val1> <val2>...\n", argv[0]);
    exit(1);
  }
  struct Node* root = make_tree(argc, argv);
  print_in_order(root);
  free_tree(root);
  return 0;
}
