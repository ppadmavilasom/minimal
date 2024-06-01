#pragma once

struct Node {
  int value;
  struct Node *left;
  struct Node *right;
};

struct Node *make_tree(int argc, char **argv);
void free_tree(struct Node *node);
