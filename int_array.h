#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <stddef.h>

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} IntArray;

void init_array(IntArray *arr);
void free_array(IntArray *arr);
void push_back(IntArray *arr, int value);
void print_array(const IntArray *arr);

static inline int square(int x) { return x * x; }

#endif // INT_ARRAY_H
