
#include "_GarbageCollection.h"

MemoryPage *MemoryPageGetLast() {
  MemoryIndex index = {false, 0, __Manager__->UsedMemoryPageLength};
  return MemoryPageGet(index);
}