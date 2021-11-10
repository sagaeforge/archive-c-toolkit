
#include "GarbageCollection.h"
#include "Operator.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int a = 23, b = 812241;
  printf("%d", Operator2(a, "+", b, int (*)(int, int)));

  GC_Clean();
  return 0;
}
