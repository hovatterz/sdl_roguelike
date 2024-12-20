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
void SList_Add(SList *list, void *data);
void SList_Delete(SList *list, void *data);
unsigned int SList_Count(SList *list);
void SList_Free(SList *list);

#define SList_ForEach(list, func)                                              \
  SList_Node *current = list->head;                                            \
  while (current != NULL) {                                                    \
    func;                                                                      \
    current = current->next;                                                   \
  }

#endif
