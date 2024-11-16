#include <stdio.h>

#include "../src/bsp.c"
#include "../src/bsp.h"
#include "helpers.h"

int testCreate() {
  BSP_Tree *tree = BSP_Tree_Create(0, 0, 100, 100);
  ASSERT(tree, "Failed to create tree");
  return 0;
}

int testSplitNodeHorizontal() {
  BSP_Tree *tree = BSP_Tree_Create(0, 0, 100, 100);
  BSP_Node_SplitHorizontal(tree->head, 30);
  ASSERT(tree->head->a, "Leaf node 'a' does not exist");
  ASSERT(tree->head->b, "Leaf node 'b' does not exist");

  BSP_Node *node = tree->head->a;
  ASSERT(node->x == 0 && node->y == 0 && node->w == 100 && node->h == 30,
         "Leaf node 'a' has bad dimensions");

  node = tree->head->b;
  ASSERT(node->x == 0 && node->y == 30 && node->w == 100 && node->h == 70,
         "Leaf node 'b' has bad dimensions");

  return 0;
}

int testSplitNodeVertical() {
  BSP_Tree *tree = BSP_Tree_Create(0, 0, 100, 100);
  BSP_Node_SplitVertical(tree->head, 30);
  ASSERT(tree->head->a, "Leaf node 'a' does not exist");
  ASSERT(tree->head->b, "Leaf node 'b' does not exist");

  BSP_Node *node = tree->head->a;
  ASSERT(node->x == 0 && node->y == 0 && node->w == 30 && node->h == 100,
         "Leaf node 'a' has bad dimensions");

  node = tree->head->b;
  ASSERT(node->x == 0 && node->y == 0 && node->w == 70 && node->h == 100,
         "Leaf node 'b' has bad dimensions");

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
    int choice = 0;

    if (sscanf(argv[1], "%d", &choice) != 1) {
      fprintf(stderr, "Could not parse test selection as a number!\n");
      return -1;
    }

    switch (choice) {
    case 0:
      return testCreate();
      break;

    case 1:
      return testSplitNodeHorizontal();
      break;

    case 2:
      return testSplitNodeVertical();
      break;
    }

    fprintf(stderr, "Invalid test selection: %d!\n", choice);
    return -1;
  }

  fprintf(stderr, "No test selected!\n");
  return -1;
}
