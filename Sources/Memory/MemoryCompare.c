
#include "Exception.h"
#include "GarbageCollection.h"
#include "Private_GarbageCollection.h"
#include "ProgramManager.h"
#include <stdlib.h>

bool MemoryCompare(void *Obj1, void *Obj2, Length Length) {
  if (GC_CreateCheck(Obj1, Obj2))
    return false;
  if (Policey(Obj1, Not_MemoryCompare) || Policey(Obj1, Not_MemoryCompare))
    return false;
  if (GC_IndexOfExceptionCheck(Obj1, Length) ||
      GC_IndexOfExceptionCheck(Obj2, Length))
    return false;

  char *a = (char *)Obj1;
  char *b = (char *)Obj2;
  int i = 0;
  while (i < Length) {
    if (*a != *b)
      return false;
    a++, b++, i++;
  }
  return true;
}