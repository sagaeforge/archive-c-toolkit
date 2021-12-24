
#include "Exception.h"
#include "GarbageCollection.h"
#include "Private_GarbageCollection.h"
#include <stdlib.h>

void MemoryCopy(void *Src, void *Data, Length Length) {
  if (GC_CreateCheck(Src, Data))
    return;

  char *a = (char *)Src;
  char *b = (char *)Data;

  int i = 0;
  while (i < Length) {
    *a = *b;
    i++, a++, b++;
  }
}