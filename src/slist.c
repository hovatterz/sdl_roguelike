#include <stdlib.h>

#include "slist.h"

SList_Node *createNode(void *data) {
  SList_Node *node = malloc(sizeof(SList_Node));
  if (!node) {
    return NULL;
  }

  node->data = data;
  node->next = NULL;
  return node;
}

SList *SList_Create() {
  SList *list = malloc(sizeof(SList));
  if (!list) {
    return NULL;
  }

  list->head = NULL;
  return list;
}

void SList_Add(SList *list, void *data) {
  SList_Node *current = NULL;
  if (list->head == NULL) {
    list->head = createNode(data);
  } else {
    current = list->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = createNode(data);
  }
}

void SList_Delete(SList *list, void *data) {
  SList_Node *current = list->head;
  SList_Node *previous = current;
  while (current != NULL) {
    if (current->data == data) {
      previous->next = current->next;
      if (current == list->head)
        list->head = current->next;
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

unsigned int SList_Count(SList *list) {
  unsigned int count = 0;
  SList_Node *current = list->head;
  while (current != NULL) {
    count++;
    current = current->next;
  }

  return count;
}

void SList_Free(SList *list) {
  SList_Node *current = list->head;
  SList_Node *next = current;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}
