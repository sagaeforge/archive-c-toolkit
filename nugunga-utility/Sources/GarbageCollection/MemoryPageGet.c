
#include "_GarbageCollection.h"

MemoryPage *MemoryPageGet(MemoryIndex Index) {
  // TODO 조건 검사

  if (Index.MemoryPageIndex > __Manager__->UsedMemoryPageLength)
    return MemoryPageGetLast();

  MemoryPage *page = &__Manager__->Pages;

  int i;
  for (i = 1; i < Index.MemoryPageIndex; i++) {
    page = page->Next;
  }

  return page;
}