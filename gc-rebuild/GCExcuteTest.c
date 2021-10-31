#include "Tuple/Tuple.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  printf("Test World\n");

  Tuple2 tuples = Tuple2(int, 213, float, 3.14f);

  int a = 0;
  float b = 0.0f;
  Tuple2_Get(tuples, a, b);
  printf("%d, %f\n", a, b);

  return 0;
}
