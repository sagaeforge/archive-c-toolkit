#ifndef __NLB_GARBAGE_COLLECTION_PRIVATE__
#define __NLB_GARBAGE_COLLECTION_PRIVATE__

#include "DataTypes.h"

typedef struct GCMemoryIndex {
  unsigned int MemoryFound;
  unsigned int MemoryIndex;
  unsigned int MemoryPageIndex;
} MemoryIndex;

typedef struct GCMemoryManager {
  Length UsedMemoryLength;
  Length UsedMemoryPageLength;

  MemoryPage Pages;
} MemoryManager;

extern MemoryManager *__Manager__;


#define SWAP(DT, TempVarName, A1, A2)                                          \
  DT TempVarName = A1;                                                         \
  A1 = A2;                                                                     \
  A2 = TempVarName


MemoryIndex MemorySearch(void *Ptr);
void *MemoryGet(MemoryIndex Index);
Length MemoryGetLength(MemoryIndex Index);
void MemoryPageMemoryAppend(void *Obj, Length Length);
void MemoryPageMemoryRemove(void *Obj);
void MemoryPageAppend();
void MemoryPageRemove(Index Index);
MemoryPage *MemoryPageGet(MemoryIndex Index);
MemoryPage *MemoryPageGetLast();
MemoryPage *MemoryPageGetEmpty();


void GC_Init();
void GC_ManagerInit();

#endif