#include <stdio.h>
#include <string.h>

#include "../src/slist.c"
#include "../src/slist.h"
#include "helpers.h"

int testCreate() {
  SList *list = SList_Create();
  ASSERT(list, "Failed to create list");

  return 0;
}

int testAdd() {
  SList *list = SList_Create();
  SList_Add(list, "One");
  SList_Add(list, "Two");
  SList_Add(list, "Three");

  SList_Node *node = list->head;
  ASSERT(node && strcmp(node->data, "One") == 0, "Node at 0 should be 'One'\n");

  node = node->next;
  ASSERT(node && strcmp(node->data, "Two") == 0, "Node at 0 should be 'Two'\n");

  node = node->next;
  ASSERT(node && strcmp(node->data, "Three") == 0,
         "Node at 0 should be 'Three'\n");

  return 0;
}

int testDelete() {
  SList *list = SList_Create();
  char *two = "Two";

  SList_Add(list, "One");
  SList_Add(list, two);
  SList_Add(list, "Three");
  SList_Delete(list, two);

  SList_Node *current = list->head;
  while (current != NULL) {
    ASSERT(current->data != two, "Node at 1 not removed");
    current = current->next;
  }

  return 0;
}

int testCount() {
  SList *list = SList_Create();
  SList_Add(list, "One");
  SList_Add(list, "Two");
  SList_Add(list, "Three");

  ASSERT(SList_Count(list) == 3, "Count should be equal to 3");

  return 0;
}

TEST_START()
TEST_CASE(0, testCreate)
TEST_CASE(1, testAdd)
TEST_CASE(2, testDelete)
TEST_CASE(3, testCount)
TEST_END()
