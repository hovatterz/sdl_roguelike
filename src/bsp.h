#ifndef BSP_H_
#define BSP_H_

typedef struct bsp_node {
  int x, y;
  int w, h;
  struct bsp_node *parent;
  struct bsp_node *a;
  struct bsp_node *b;
} BSP_Node;

void BSP_Node_SplitHorizontal(BSP_Node *node, int y);
void BSP_Node_SplitVertical(BSP_Node *node, int x);

typedef struct bsp_tree {
  BSP_Node *head;
} BSP_Tree;

BSP_Tree *BSP_Tree_Create(int x, int y, int w, int h);
void BSP_Tree_Free(BSP_Tree *tree);

#endif
