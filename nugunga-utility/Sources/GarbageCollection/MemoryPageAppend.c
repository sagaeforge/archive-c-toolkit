
#include "_GarbageCollection.h"
#include "Exception.h"

void MemoryPageAppend() {
  MemoryPage *page = MemoryPageGetLast();
  MemoryPage *NewPage = (MemoryPage *)malloc(sizeof(MemoryPage));
  if (NewPage == NULL) {
    Error("메모리 페이지를 생성하지 못했습니다.\n");
    return;
  }

  page->Next = NewPage;
  NewPage->Next = NULL;
  NewPage->UsedMemoryLength = 0;
  __Manager__->UsedMemoryPageLength++;
  int i;
  for (i = 0; i < MemoryMaxLength; i++) {
    NewPage->Datas[i].Length = 0;
    NewPage->Datas[i].Value = NULL;
  }
}