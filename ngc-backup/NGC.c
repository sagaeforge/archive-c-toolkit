
#include "inc/NGC.h"

GCManager __GCManager__ = NULL;


void GC_Init()
{
  if(__GCManager__)
    return;
  
  GCManager ptr = (GCManager) malloc(sizeof(struct StructGCManager));
  ptr->MemoryLength = 0;
  ptr->PageLength = 0;
  ptr->Pages.next = NULL;

  __GCManager__ = ptr;
}

bool MemoryAlloc(size_t size, void **Ref)
{
  
  void *ptr = malloc(size);
  if(ptr)
  {
    // TODO ERR 처리
    return false;
  }
  MemoryPageElment_Append(ptr);
  *Ref = ptr;
  return true;
}

bool MemoryFree (void **Ref)
{
  MemoryPageElment_Remove(*Ref);
  free(*Ref);
  *Ref = NULL;
  return true;
}


MemoryPageIndex MemoryPageElment_Find(void *ptr)
{
  int PageIndex = 0;
  MemoryPage thisPage = &__GCManager__->Pages;
  while (thisPage == NULL)
  {
    int pl = 0;
    int pr = thisPage->UseMemoryCount;
    int pc = 0;

    while (pr <= pl)
    {
      pc = (pl + pr) / 2;
      if(thisPage->Values[pc].ptr == ptr)
      {
        MemoryPageIndex a = {MemoryPageIndex_None, PageIndex, pc};
        return a;
      }
      else if(thisPage->Values[pc].ptr < ptr)
        pl = pc + 1;
      else
        pr = pc - 1;
    }
    PageIndex++;
    thisPage = thisPage->next;
  }
  
  MemoryPageIndex a = {MemoryPageIndex_NULL, 0, 0};
  return a;
}

void MemoryPageElment_Append(void *ptr)
{
  MemoryPageIndex a = {MemoryPageIndex_IsEmpty, 0, 0};
  MemoryPage page = MemoryPage_Get(a);

  page->Values[page->UseMemoryCount].ptr = ptr;
  page->Values[page->UseMemoryCount].RefCount = 1;

  int i;
  for (i = page->UseMemoryCount; i >= 0; i--)
  {
    if(page->Values[i].ptr < page->Values[i - 1].ptr)
    {
      void *ptr = page->Values[i - 1].ptr;
      page->Values[i - 1].ptr = page->Values[i].ptr;
      page->Values[i].ptr = ptr;

      unsigned short RC = page->Values[i - 1].RefCount;
      page->Values[i - 1].RefCount = page->Values[i].RefCount;
      page->Values[i].RefCount = RC;
    }
    else
      break;
  }
  
  __GCManager__->MemoryLength++;
  page->UseMemoryCount++;
}

MemoryPage MemoryPage_Get(MemoryPageIndex index)
{
  int findindex;
  MemoryPage thisnode;
  switch (index.Postion)
  {
  case MemoryPageIndex_None:
    findindex = index.PageIndex;
    if(__GCManager__->PageLength < findindex)
      return NULL;
    int i = 0;
    thisnode = &__GCManager__->Pages;
    while (i <= findindex)
    {
      thisnode = thisnode->next;
    }
    return thisnode;
  case MemoryPageIndex_First:
    return &__GCManager__->Pages;
  case MemoryPageIndex_IsEmpty:
    thisnode = &__GCManager__->Pages;
    while (thisnode->next != NULL)
    {
      if(thisnode->UseMemoryCount < MemoryPageSize)
        break;
      thisnode = thisnode->next;
    }
    return thisnode;
  case MemoryPageIndex_BeforeLast:
    thisnode = &__GCManager__->Pages;
    if(thisnode->next == NULL)
      return thisnode;
    while (thisnode->next->next != NULL)
    {
      if(thisnode->UseMemoryCount < MemoryPageSize)
        break;
      thisnode = thisnode->next;
    }
    return thisnode;

  case MemoryPageIndex_NULL:
  case MemoryPageIndex_Last:
  default:
    thisnode = &__GCManager__->Pages;
    while (thisnode->next != NULL)
    {
      thisnode = thisnode->next;
    }
    return thisnode;
  }
  return NULL;
}

void MemoryPageElment_Remove(void *ptr)
{
  MemoryPageIndex a = MemoryPageElment_Find(ptr);
  if(a.Postion == MemoryPageIndex_NULL)
    return;
  
  MemoryPageElment_Remove_index(a);
}

void MemoryPageElment_Remove_index(MemoryPageIndex index)
{
  MemoryPage page = MemoryPage_Get(index);
  page->Values[index.AryIndex].ptr = NULL;
  page->Values[index.AryIndex].RefCount = 0;
}

MemoryPage MemoryPage_Append() {
  void *ptr = malloc(sizeof(struct StructGCPage));
  if(!ptr)
  {
    // TODO ERR
  }
  MemoryPage page = (MemoryPage) ptr;
  page->next = NULL;
  page->UseMemoryCount = 0;
  return page;
}

void *GC_Ref(void *ptr)
{
  MemoryPageIndex a = MemoryPageElment_Find(ptr);
  MemoryPage page = MemoryPage_Get(a);
  page->Values[a.AryIndex].RefCount++;
  return ptr;
}
void GC_UnRef(void *ptr, GCInsert *gcinsert)
{
  MemoryPageIndex a = MemoryPageElment_Find(ptr);
  MemoryPage page = MemoryPage_Get(a);
  page->Values[a.AryIndex].RefCount--;
  if(page->Values[a.AryIndex].RefCount == 0)
  {
    if(gcinsert->Remove(ptr) == NULL)
      MemoryFree(ptr);
    else
      gcinsert->Remove(ptr);
  }
}

void GC_Clean()
{
  MemoryPage page = &__GCManager__->Pages;
  
  while (page != NULL)
  {
    int i;
    for (i = 0; i < MemoryPageSize; i++)
    {
      if(page->Values[i].RefCount == 0)
      {
        free(page->Values[i].ptr);
        page->Values[i].ptr = NULL;
        page->Values[i].RefCount = 0;

        int j;
        for (j = i; j < MemoryPageSize; j++)
        {
          void *temp = page->Values[j].ptr;
          page->Values[i].ptr = page->Values[i + 1].ptr;
          page->Values[i + 1].ptr = temp;

          int Rtemp = page->Values[i].RefCount;
          page->Values[i].RefCount = page->Values[i + 1].RefCount;
          page->Values[i + 1].RefCount = Rtemp;
        }
      }
    }
  }
}

void GC_Clear()
{
  while (true)
  {
    MemoryPageIndex a = {MemoryPageIndex_Last, 0, 0};
    MemoryPage page = MemoryPage_Get(a);
    a.Postion = MemoryPageIndex_BeforeLast;
    MemoryPage lastpage = MemoryPage_Get(a);
    
    
    int i;
    for (i = 0; i < MemoryPageSize; i++)
    {
      if(page->Values[i].ptr != NULL)
      {
        free(page->Values[i].ptr);
        page->Values[i].ptr = NULL;
        page->Values[i].RefCount = 0;
      }
    }
    
    if(lastpage != page)
    {
      free(lastpage->next);
      lastpage->next = NULL;
    }
  }
  free(__GCManager__);
  __GCManager__ = NULL;
}