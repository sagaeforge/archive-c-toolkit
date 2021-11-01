
#ifndef __NLB_GARBAGECOLLECTION_MEMORY_
#define __NLB_GARBAGECOLLECTION_MEMORY_

#include "GCMemory.h"

typedef struct GCMemoryIndex {
  unsigned int MemoryPageIndex;
  unsigned int MemoryIndex;
  int NotFound;
} MemoryIndex;

MemoryPage *MemoryPage_Get(MemoryIndex index);
void MemoryPage_Insert();
void Memory_Append(void *ptr, Length length);
void Memory_Remove(void *ptr);
MemoryIndex Memory_Search(void *ptr);

#endif