#ifndef HELPERS_H_
#define HELPERS_H_

#include <stdio.h>

#define ASSERT(condition, msg)                                                 \
  if (!(condition)) {                                                          \
    fprintf(stderr, "%s\n", msg);                                              \
    return -1;                                                                 \
  }

#define TEST_CASE(index, method)                                               \
  case index:                                                                  \
    return method();

#define TEST_START()                                                           \
  int main(int argc, char *argv[]) {                                           \
    if (argc > 1) {                                                            \
      int choice = 0;                                                          \
      if (sscanf(argv[1], "%d", &choice) != 1) {                               \
        fprintf(stderr, "Could not parse test selection as a number!\n");      \
        return -1;                                                             \
      }                                                                        \
      switch (choice) {

#define TEST_END()                                                             \
  }                                                                            \
  fprintf(stderr, "Invalid test selection: %d!\n", choice);                    \
  return -1;                                                                   \
  }                                                                            \
  fprintf(stderr, "No test selected!\n");                                      \
  return -1;                                                                   \
  }

#endif
