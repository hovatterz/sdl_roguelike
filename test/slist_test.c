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
      return testAdd();
      break;

    case 2:
      return testDelete();
      break;

    case 3:
      return testCount();
      break;
    }

    fprintf(stderr, "Invalid test selection: %d!\n", choice);
    return -1;
  }

  fprintf(stderr, "No test selected!\n");
  return -1;
}