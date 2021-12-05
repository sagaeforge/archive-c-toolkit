
#ifndef __NLB_GARBAGE_COLLECTION__
#define __NLB_GARBAGE_COLLECTION__

#include "DataTypes.h"

#define MemoryMaxLength 256

typedef struct GCMemoryPage {
  unsigned int UsedMemoryLength;
  struct {
    void *Value;
    Length Length;
  } Datas[MemoryMaxLength];
  struct GCMemoryPage *Next;
} MemoryPage;

void *MemoryCreate(Length Length);
void MemoryRemove(void **ptr);

void MemorySet(void *Src, int value, Length WordSize, Length Length);
void MemoryCopy(void *Src, void *Data, Length Length);
void MemoryMove(void *Src, void *Data, Length Length);
void MemoryCompare(void *Obj1, void *Obj2, Length Length);
void MemoryLength(void *Obj);

void GC_Clear();
void GC_Clean();
#endif