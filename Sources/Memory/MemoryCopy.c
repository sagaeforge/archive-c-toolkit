
#include "Exception.h"
#include "GarbageCollection.h"
#include "Private_GarbageCollection.h"
#include <stdlib.h>

void MemoryCopy(void *Src, void *Data, Length Length) {
  if (GC_CreateCheck(Src, Data))
    return;
  if (Policey(Src, Not_MemoryCopy) || Policey(Data, Not_MemoryCopy))
    return;
  if (GC_IndexOfExceptionCheck(Src, Length) ||
      GC_IndexOfExceptionCheck(Data, Length))
    return;

  char *a = (char *)Src;
  char *b = (char *)Data;

  int i = 0;
  while (i < Length) {
    *a = *b;
    i++, a++, b++;
  }
}