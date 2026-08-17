
#include "_GarbageCollection.h"

void MemoryPageRemove(Index Index) {
  // TODO 조건 검사
  MemoryIndex index = {0, 0, Index};
  MemoryIndex lastIndex = {0, 0, Index - 1};
  MemoryPage *page = MemoryPageGet(index);
  MemoryPage *Last = MemoryPageGet(lastIndex);

  Last->Next = page->Next;
  __Manager__->UsedMemoryPageLength--;
  __Manager__->UsedMemoryLength -= page->UsedMemoryLength;

  int i;
  for (i = 0; i < page->UsedMemoryLength; i++) {
    free(page->Datas[i].Value);
  }

  free(page);
}