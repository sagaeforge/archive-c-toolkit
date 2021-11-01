
#include "GC.h"
#include "_GC.h"

struct GCInitialization {
  void (*CallFuncs)(void);
} Initialization[] = {GCManager_Init};

void GC_Init() {
  Length TotalSize = sizeof(Initialization) / 8;
  int i;
  for (i = 0; i < TotalSize; i++)
    Initialization[i].CallFuncs();
}
