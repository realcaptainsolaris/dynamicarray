#include "int_array.h"

int main(void) {
  IntArray arr;
  init_array(&arr);

  for (int i = 0; i < 10; ++i) {
    push_back(&arr, square(i));
  }

  print_array(&arr);
  free_array(&arr);
  return 0;
}
