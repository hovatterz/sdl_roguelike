#include <stdlib.h>

int rand_range(int min, int max) { return rand() % (max - min + 1) + min; }
