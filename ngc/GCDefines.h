#ifndef __NUGUNGA_LIBARY_GARBAGE_COLLECTION_DATAS__
#define __NUGUNGA_LIBARY_GARBAGE_COLLECTION_DATAS__

#define Length unsigned int
#define GC_Page struct GCManagerPageStruct *
#define GC_Manager struct GCManagerStruct *
#define Memory struct GCMemory
#define false 0
#define true 1
#define PageUsedSize 510

#define NullCheck(ptr) if(!(ptr))

typedef struct GCPosititon
{
  unsigned int PageIndex;
  unsigned int MemoryIndex;
} MemoryPosition;

struct GCManagerPageStruct
{
  Length UsedPage;
  Length UnUsedPage;
  void *Values[PageUsedSize];
  GC_Page next;
};

struct GCManagerStruct
{
  Length TotalUsedMemoryLength;
  Length TotalUsedMemoryPageLength;
  GC_Page page;
};

struct GCMemory
{
  void *ptr;
  int IsAlloc;
};



#endif