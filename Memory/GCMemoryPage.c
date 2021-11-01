
#include "../GC.h"
#include "_GCMemoryPage.h"
#include <stdlib.h>

static MemoryPage *MemoryPage_LastGet() {
  MemoryPage *page = &__Manager__->MemoryPageNode;
  int i;
  for (i = 0; i < __Manager__->TotalUsedMemoryPageNode; i++) {
    page = page->Next;
  }
  return page;
}

static MemoryPage *MemoryPage_LastEmptyGet() {
  MemoryPage *page = &__Manager__->MemoryPageNode;

  int i;
  for (i = 0; i < __Manager__->TotalUsedMemoryPageNode; i++) {
    if (page->UsedMemory < MemoryMaxLength)
      return page;
    page = page->Next;
  }

  MemoryPage_Insert();
  return page->Next;
}

MemoryPage *MemoryPage_Get(MemoryIndex index) {
  if (index.MemoryPageIndex == 0)
    return &__Manager__->MemoryPageNode;

  if (index.MemoryPageIndex > __Manager__->TotalUsedMemoryPageNode)
    return MemoryPage_LastGet();

  MemoryPage *page = &__Manager__->MemoryPageNode;
  int i;
  for (i = 0; i < index.MemoryPageIndex; i++) {
    page = page->Next;
  }

  return page;
}

void MemoryPage_Insert() {
  MemoryPage *InsertPage = MemoryPage_LastGet();
  MemoryPage *NewPage = (MemoryPage *)malloc(sizeof(MemoryPage));

  InsertPage->Next = NewPage;
  NewPage->Next = NULL;
  NewPage->UsedMemory = 0;

  __Manager__->TotalUsedMemoryPageNode++;

  int i;
  for (i = 0; i < MemoryMaxLength; i++) {
    NewPage->Datas[i].MemoryLength = 0;
    NewPage->Datas[i].Value = NULL;
  }
}
void Memory_Append(void *ptr, Length length) {
  MemoryPage *page = MemoryPage_LastEmptyGet();

  page->Datas[page->UsedMemory].MemoryLength = length;
  page->Datas[page->UsedMemory].Value = ptr;

  __Manager__->TotalUsedMemory++;
  page->UsedMemory++;
}
void Memory_Remove(void *ptr) {
  MemoryIndex index = Memory_Search(ptr);
  MemoryPage *page = MemoryPage_Get(index);
  page->Datas[index.MemoryIndex].MemoryLength = 0;
  page->Datas[index.MemoryIndex].Value = NULL;

  int i;
  for (i = index.MemoryIndex; i < page->UsedMemory; i++) {
    void *temp_ptr = page->Datas[i].Value;
    page->Datas[i].Value = page->Datas[i + 1].Value;
    page->Datas[i + 1].Value = temp_ptr;

    Length temp_l = page->Datas[i].MemoryLength;
    page->Datas[i].MemoryLength = page->Datas[i + 1].MemoryLength;
    page->Datas[i + 1].MemoryLength = temp_l;
  }

  __Manager__->TotalUsedMemory--;
  page->UsedMemory--;
}

MemoryIndex Memory_Search(void *ptr) {
  MemoryPage *page = &__Manager__->MemoryPageNode;
  MemoryIndex index = {
      0,
  };
  int pageindex = 0;
  while (pageindex < __Manager__->TotalUsedMemoryPageNode) {

    int pl = 0;
    int pr = page->UsedMemory;

    do {
      int pc = (pl + pr) / 2;
      if (page->Datas[pc].Value == ptr) {
        index.MemoryIndex = pc;
        index.MemoryPageIndex = pageindex;
        index.NotFound = 0;
        return index;
      } else if (page->Datas[pc].Value < ptr)
        pl = pc + 1;
      else
        pr = pc - 1;

    } while (pl <= pr);
  }
  index.NotFound = 1;
  return index;
}