#ifndef HELPERS_H_
#define HELPERS_H_

#include <stdio.h>

#define ASSERT(condition, msg)                                                 \
  if (!(condition)) {                                                          \
    fprintf(stderr, "%s\n", msg);                                              \
    return -1;                                                                 \
  }

#endif
