
#include "GarbageCollection.h"
#include "_GarbageCollection.h"

MemoryIndex MemorySearch(void *Ptr) {
  MemoryPage *page = &__Manager__->Pages;
  MemoryIndex index = {
      0,
  };

  if (Ptr == NULL)
    return index;

  int i;
  for (i = 0; page != NULL; i++) {

    int pl = 0;
    int pr = page->UsedMemoryLength;
    int pc = 0;

    do {
      pc = (pl + pr) / 2;

      if (page->Datas[pc].Value == Ptr) {
        index.MemoryIndex = pc;
        index.MemoryPageIndex = i + 1;
        index.MemoryFound = true;
        return index;
      } else if (page->Datas[pc].Value < Ptr) // 1 2 3 4 5 6
        pl = pc + 1;
      else
        pr = pc - 1;

    } while (pl <= pr);

    page = page->Next;
  }
  return index;
}