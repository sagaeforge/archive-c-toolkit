
#include "Exception.h"
#include "GarbageCollection.h"
#include <stdlib.h>

void *MemoryCreate(Length Length) {
  void *ptr = malloc(Length);
  if (ptr == NULL)
    Warning("지정된 메모리를 생성할 수 없습니다.");
  return ptr;
}
void MemoryRemove(void **ptr) { return; }
void MemorySet(void *Src, int value, Length WordSize, Length Length) { return; }
void MemoryCopy(void *Src, void *Data, Length Length) { return; }
void MemoryMove(void *Src, void *Data, Length Length) { return; }
bool MemoryCompare(void *Obj1, void *Obj2, Length Length) { return false; }
Length MemoryLength(void *Obj) { return 0; }