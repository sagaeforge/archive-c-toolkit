
#include "_GarbageCollection.h"

void *MemoryGet(MemoryIndex Index) {
  if (Index.MemoryIndex > MemoryMaxLength ||
      Index.MemoryPageIndex > __Manager__->UsedMemoryPageLength)
    return NULL;

  MemoryPage *page = MemoryPageGet(Index);
  return page->Datas[Index.MemoryIndex].Value;
}