
#include "GarbageCollection.h"
#include "_GarbageCollection.h"
#include "Exception.h"


void *MemoryCreate(Length Length) {
  if (__Manager__ == NULL)
    GC_ManagerInit();
  void *ptr = malloc(Length);
  if (ptr == NULL) {
    Warning("경고 >> 메모리(%u)를 생성할 수 없습니다\n", Length);
    return NULL;
  }
  MemoryPageMemoryAppend(ptr, Length);
  return ptr;
}

void MemoryRemove(void **ptr) {
  MemoryIndex index = MemorySearch((*ptr));
  if (!index.MemoryFound) {
    Warning("등록된 메모리가 아닙니다 %p\n", (*ptr));
    return;
  }
  MemoryPageMemoryRemove((*ptr));
  free((*ptr));
}

void MemorySet(void *Src, int value, Length WordSize, Length Length);
void MemoryCopy(void *Src, void *Data, Length Length);
void MemoryMove(void *Src, void *Data, Length Length);
void MemoryCompare(void *Obj1, void *Obj2, Length Length);
void MemoryLength(void *Obj);