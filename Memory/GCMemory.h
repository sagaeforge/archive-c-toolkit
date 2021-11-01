
#ifndef __NLB_GARBAGECOLLECTION_MEMORY
#define __NLB_GARBAGECOLLECTION_MEMORY

#ifndef __LENGTH
#define __LENGTH
typedef unsigned int Length;
#endif

#define MemoryMaxLength 256

typedef struct GCMemoryPage {
  Length UsedMemory;
  struct {
    void *Value;
    Length MemoryLength;
  } Datas[MemoryMaxLength];
  struct GCMemoryPage *Next;
} MemoryPage;

void *MemoryCreate(Length length);
void MemoryRemove(void **Object);
void MemorySet(void *Base, int Data, Length length);
void MemoryCopy(void *Edit, void *Base, Length length);
void MemoryMove(void *Edit, void *Base, Length length);
int MemoryCompare(void *Object1, void *Object2, Length length);
Length MemoryLength(void *Object);

#endif