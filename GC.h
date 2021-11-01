
#ifndef __NLB_GARBAGECOLLECTION
#define __NLB_GARBAGECOLLECTION

#include "Funcs/GCFuncs.h"
#include "Memory/GCMemory.h"

#ifndef __LENGTH
#define __LENGTH
typedef unsigned int Length;
#endif

typedef struct GCMemoryManager {
  Length TotalUsedMemory;
  Length TotalUsedFuncsNode;
  Length TotalUsedMemoryPageNode;

  FuncsNode *FuncsNode;
  MemoryPage MemoryPageNode;
} GCMemoryManager;

#define Error(format, ...)                                                     \
  do {                                                                         \
    fprintf(stderr, format, ##__VA_ARGS__);                                    \
    exit(-1);                                                                  \
  } while (0)

#define Debug(format, ...) fprintf(stderr, format, ##__VA_ARGS__)

extern GCMemoryManager *__Manager__;

#endif