#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int max(int x, int y) {
  return x > y ? x : y;
}

int tree_height(struct Node *node) {
  if (node == NULL) return 0;
  return max(tree_height(node->left), tree_height(node->right)) + 1;
}

int main(int argc, char **argv) {
  if(argc < 2) {
    printf("Usage: %s <val1> <val2>...\n", argv[0]);
    exit(1);
  }
  struct Node* root = make_tree(argc, argv);
  printf("%d", tree_height(root));
  free_tree(root);
  return 0;
}
