
#ifndef __GARBAGECOLLECTION_PRIVATE__
#define __GARBAGECOLLECTION_PRIVATE__

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

extern _GarbageCollection *GarbageCollection;

#include "_GarbageCollectionIterators.h"

// MemoryIndex MemorySearch(void *Ptr);
// void *MemoryGet(MemoryIndex Index);
// Length MemoryGetLength(MemoryIndex Index);
// void MemoryPageMemoryAppend(void *Obj, Length Length);
// void MemoryPageMemoryRemove(void *Obj);
// void MemoryPageAppend();
// void MemoryPageRemove(Index Index);
// MemoryPage *MemoryPageGet(MemoryIndex Index);
// MemoryPage *MemoryPageGetLast();
// MemoryPage *MemoryPageGetEmpty();

#endif