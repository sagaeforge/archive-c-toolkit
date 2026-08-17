
#include "_GarbageCollection.h"
#include "Exception.h"


Length MemoryGetLength(MemoryIndex Index) {
  if (Index.MemoryIndex > MemoryMaxLength ||
      Index.MemoryPageIndex > __Manager__->UsedMemoryPageLength)
    return 0;

  MemoryPage *page = MemoryPageGet(Index);
  return page->Datas[Index.MemoryIndex].Length;
}
void MemoryPageMemoryAppend(void *Obj, Length Length) {
  MemoryIndex index = MemorySearch(Obj);
  if (index.MemoryFound) {
    Warning("등록된 메모리를 등록하려 했습니다. %p\n", Obj);
    return;
  }

  MemoryPage *page = MemoryPageGetEmpty();
  page->Datas[page->UsedMemoryLength].Value = Obj;
  page->Datas[page->UsedMemoryLength].Length = Length;

  if (page->UsedMemoryLength >= 2) {
    int i;
    for (i = page->UsedMemoryLength; i >= 0; i--) {
      if (page->Datas[i].Value < page->Datas[i - 1].Value) {
        SWAP(void *, temp_value, page->Datas[i - 1].Value,
             page->Datas[i].Value);
        SWAP(unsigned, temp_length, page->Datas[i - 1].Length,
             page->Datas[i].Length);
      } else
        break;
    }
  }

  page->UsedMemoryLength++;
  __Manager__->UsedMemoryLength++;
}