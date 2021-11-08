
#include "GC.h"
#include "String.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  // int i = 0, k = 0;

  // int *ary[10];
  // for (i = 0; i < 10; i++)
  //   ary[i] = NULL;

  // for (i = 0; i < MemoryMaxLength * 200; i++) {
  //   int *Garbage = Create(int, NoConstructor)(4);

  //   for (k = 0; k < 10; k++)
  //     if (ary[k] != NULL)
  //       continue;
  //     else {
  //       ary[k] = Garbage;
  //       break;
  //     }

  //   if (k == 10) {

  //     int random = rand() % 10;
  //     // printf("Garbage[%p] = ary[%d]: %p\n", Garbage, random, ary[random]);
  //     Remove(int, ary[random]);
  //     ary[random] = Garbage;
  //   } else
  //     continue;
  // }

  printf("%lu", sizeof(String));

  GC_Clean();
  return 0;
}
