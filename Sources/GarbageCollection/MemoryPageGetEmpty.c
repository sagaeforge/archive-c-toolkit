
#include "_GarbageCollection.h"

MemoryPage *MemoryPageGetEmpty() {
  MemoryPage *page = &__Manager__->Pages;
  while (page != NULL) {
    if (page->UsedMemoryLength < MemoryMaxLength)
      return page;
    page = page->Next;
  }

  MemoryPageAppend();
  return MemoryPageGetLast();
}