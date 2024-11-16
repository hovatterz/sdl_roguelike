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

TEST_START()
TEST_CASE(0, testCreate)
TEST_CASE(1, testSplitNodeHorizontal)
TEST_CASE(2, testSplitNodeVertical)
TEST_END()
