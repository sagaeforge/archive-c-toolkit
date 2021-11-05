
#include "GC.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int i;
  for (i = 0; i < MemoryMaxLength * 10; i++) {
    int *Garbage = Create(int, NoConstructor)(4);

    int randomValue = rand() % 100;
    if (randomValue > 50)
      Remove(int, Garbage);
  }

  GC_Clear();
  GC_Clean();
  return 0;
}
