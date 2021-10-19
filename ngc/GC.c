
#include "GC.h"
#include "__GC__.h"
#include <stdio.h>
#include <stdlib.h>

GC_Manager __Manager__ = NULL;

void GC_Init()
{
  GC_Manager temp = malloc(sizeof(struct GCManagerStruct)); // malloc
  NullCheck(temp)
  {printf("메모리 관리자 생성 실패"); return;}

  temp->TotalUsedMemoryLength = 0;
  temp->TotalUsedMemoryPageLength = 1;
  
  GC_Page page = malloc(sizeof(struct GCManagerPageStruct)); // malloc
  NullCheck(page)
  {printf("메모리 페이지 생성 실패"); return;}
  page->UnUsedPage = PageUsedSize;
  page->UsedPage = 0;
  page->next = NULL;
  temp->page = page;
  __Manager__ = temp;
}
void GC_Clear()
{
  // TODO 구현해야함.
}
void GC_Clean()
{
  //TODO 구현해야함.
}

Memory MemoryCreate(Length length)
{
  NullCheck(__Manager__)
    GC_Init();
  Memory a = {NULL, false};
  
  void *ptr = malloc(length); // malloc
  NullCheck(ptr) 
  { printf("메모리 생성 실패"); return a; }  



  a.IsAlloc = true;
  a.ptr = ptr;
  return a;
}
void MemoryRemove(void **ptr)
{
  free((*ptr));
  (*ptr) = NULL;
}