
#ifndef __GARBAGECOLLECTION_PRIVATE_ITERATORS__
#define __GARBAGECOLLECTION_PRIVATE_ITERATORS__

#ifndef __GCType__
#define __GCType__
#include <stdbool.h>
typedef unsigned int Index;
typedef unsigned int Length;
typedef void *MemoryPosition;

#ifndef __GCType_Extend__
#define __GCType_Extend__

#define UseMemoryMax 256

typedef struct {
  bool IsUsed;
  MemoryPosition Value;
  Length Length;
} MemoryPageValue;

typedef struct _MemoryPage {
  Length UsedMemoryLength;
  MemoryPageValue Values[UseMemoryMax];

  MemoryPageValue *Iterator;
  Index Iterator_Position;
  void (*Iterator_Set)(struct _MemoryPage *ThisPage, Index Index);
  void (*Iterator_Next)(struct _MemoryPage *ThisPage);
  void (*Iterator_Prev)(struct _MemoryPage *ThisPage);
  void (*Iterator_Start)(struct _MemoryPage *ThisPage);
  void (*Iterator_End)(struct _MemoryPage *ThisPage);
  void (*Iterator_Foreach)(struct _MemoryPage *,
                           void (*)(struct _MemoryPage *));
  bool (*Iterator_IsStart)(struct _MemoryPage *ThisPage);
  bool (*Iterator_IsEnd)(struct _MemoryPage *ThisPage);

  struct _MemoryPage *Next;
} MemoryPage;

typedef struct {
  Length UsedMemoryPageLength;
  MemoryPage pages;

  MemoryPage *Iterator;
  Index Iterator_Position;
  void (*Iterator_Set)(Index Index);
  void (*Iterator_Next)();
  void (*Iterator_Prev)();
  void (*Iterator_Start)();
  void (*Iterator_End)();
  void (*Iterator_Foreach)(void (*)(MemoryPage *));
  bool (*Iterator_IsStart)();
  bool (*Iterator_IsEnd)();
} _GarbageCollection;

typedef struct {
  bool _IsFounc;
  Index MemoryPageIndex;
  Index MemoryIndex;
} MemoryGCPosition;
#endif
#endif

void foreach_Page(MemoryPage *page, void (*CallBack)(MemoryPageValue *));
void Iterator_Page_Set(MemoryPage *ThisPage, Index Index);
void Iterator_Page_Next(MemoryPage *ThisPage);
void Iterator_Page_Prev(MemoryPage *ThisPage);
void Iterator_Page_Start(MemoryPage *ThisPage);
void Iterator_Page_End(MemoryPage *ThisPage);
bool Iterator_Page_IsStart(MemoryPage *ThisPage);
bool Iterator_Page_IsEnd(MemoryPage *ThisPage);

void foreach_GC(void (*CallBack)(MemoryPage *));
void Iterator_GC_Set(Index Index);
void Iterator_GC_Next();
void Iterator_GC_Prev();
void Iterator_GC_Start();
void Iterator_GC_End();
bool Iterator_GC_IsStart();
bool Iterator_GC_IsEnd();

#endif