
#include "Exception.h"
#include "GarbageCollection.h"
#include "Private_GarbageCollection.h"
#include <stdlib.h>

void MemoryRemove(void **ptr) {
  MemoryInfo info = Info((*ptr));
  if (!info.IsFounded)
    Warning("GC에서 생성된 메모리가 아닙니다. --> %p", (*ptr));

  GC_Remove((*ptr));
  free((*ptr));
  (*ptr) = NULL;
}
