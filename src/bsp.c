#include <stdlib.h>

#include "bsp.h"

BSP_Node *BSP_Node_create(BSP_Node *parent, int x, int y, int w, int h) {
  BSP_Node *node = malloc(sizeof(BSP_Node));
  if (!node) {
    return NULL;
  }

  node->parent = parent;
  node->x = x;
  node->y = y;
  node->w = w;
  node->h = h;

  return node;
}

void BSP_Node_SplitHorizontal(BSP_Node *node, int y) {
  if (node->a != NULL || node->b != NULL) {
    return;
  }

  node->a = BSP_Node_create(node, node->x, node->y, node->w, y);
  node->b = BSP_Node_create(node, node->x, y, node->w, node->h - y);
}

void BSP_Node_SplitVertical(BSP_Node *node, int x) {
  if (node->a != NULL || node->b != NULL) {
    return;
  }

  node->a = BSP_Node_create(node, node->x, node->y, x, node->h);
  node->b = BSP_Node_create(node, x, node->y, node->w - x, node->h);
}

void BSP_Node_Free(BSP_Node *node) {
  if (node->a != NULL) {
    BSP_Node_Free(node->a);
  }

  if (node->b != NULL) {
    BSP_Node_Free(node->a);
  }

  free(node);
}

BSP_Tree *BSP_Tree_Create(int x, int y, int w, int h) {
  BSP_Tree *tree = malloc(sizeof(BSP_Tree));
  if (!tree) {
    return NULL;
  }

  tree->head = BSP_Node_create(NULL, x, y, w, h);

  return tree;
}

void BSP_Tree_Free(BSP_Tree *tree) {
  BSP_Node_Free(tree->head);
  free(tree);
}
