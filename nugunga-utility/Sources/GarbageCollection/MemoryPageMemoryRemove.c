
#include "_GarbageCollection.h"
#include "Exception.h"

void MemoryPageMemoryRemove(void *Obj) {
  MemoryIndex index = MemorySearch(Obj);
  if (!index.MemoryFound) {
    Warning("잘못된 메모리를 지정했습니다 %p\n", Obj);
    return;
  }

  MemoryPage *page = MemoryPageGet(index);
  page->Datas[index.MemoryIndex].Value = NULL;
  page->Datas[index.MemoryIndex].Length = 0;

  int i;
  for (i = index.MemoryIndex; i < page->UsedMemoryLength; i++) {
    SWAP(void *, temp_value, page->Datas[i].Value, page->Datas[i + 1].Value);
    SWAP(unsigned int, temp_Length, page->Datas[i].Length,
         page->Datas[i + 1].Length);
  }

  page->UsedMemoryLength--;
  __Manager__->UsedMemoryLength--;
}