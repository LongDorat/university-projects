#ifndef BIG_INT_H
#define BIG_INT_H

#include <stdlib.h>
#include <string.h>

typedef struct big_int {
    int *digits;
    int size;
    int capacity;
    int isNegative;
} big_int;

big_int big_int_init(int size, int capacity);
big_int big_int_from_cstr(const char *s);

#endif