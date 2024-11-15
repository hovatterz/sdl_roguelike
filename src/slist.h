#ifndef SLIST_H_
#define SLIST_H_

typedef struct slist_node {
  void *data;
  struct slist_node *next;
} SList_Node;

typedef struct slist {
  SList_Node *head;
} SList;

SList *SList_Create();
void SList_Add(SList *list, const void *data);
void SList_Delete(SList *list, const void *data);
void SList_Destroy(SList *list);

#endif
