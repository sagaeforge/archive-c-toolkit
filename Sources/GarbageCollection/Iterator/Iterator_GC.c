
#include "_GarbageCollecion.h"

static MemoryPage *GetNode(Index Index) {
  int index = 0;
  MemoryPage *node = &GarbageCollection->pages;
  while (index <= GarbageCollection->Iterator_Position) {
    node = node->Next;
  }
  return node;
}

void Iterator_GC_Set(Index Index) {
  if (Index < 0 || Index >= GarbageCollection->UsedMemoryPageLength)
    return;

  GarbageCollection->Iterator_Position = Index;
  GarbageCollection->Iterator = GetNode(GarbageCollection->Iterator_Position);
}
void Iterator_GC_Next() {
  if (GarbageCollection->Iterator_Position + 1 >=
      GarbageCollection->UsedMemoryPageLength)
    return;

  GarbageCollection->Iterator_Position++;
  GarbageCollection->Iterator = GetNode(GarbageCollection->Iterator_Position);
}
void Iterator_GC_Prev() {
  if (GarbageCollection->Iterator_Position - 1 < 0)
    return;

  GarbageCollection->Iterator_Position++;
  GarbageCollection->Iterator = GetNode(GarbageCollection->Iterator_Position);
}
void Iterator_GC_Start() {
  GarbageCollection->Iterator_Position = 0;
  GarbageCollection->Iterator = GetNode(GarbageCollection->Iterator_Position);
}
void Iterator_GC_End() {
  GarbageCollection->Iterator_Position =
      GarbageCollection->UsedMemoryPageLength;
  GarbageCollection->Iterator = GetNode(GarbageCollection->Iterator_Position);
}
bool Iterator_GC_IsStart() { return GarbageCollection->Iterator_Position == 0; }
bool Iterator_GC_IsEnd() {
  return GarbageCollection->Iterator_Position ==
         GarbageCollection->UsedMemoryPageLength - 1;
}
void foreach_GC(void (*CallBack)(MemoryPage *)) {
  Index backup = GarbageCollection->Iterator_Position;
  GarbageCollection->Iterator_Start();
  for (; !GarbageCollection->Iterator_IsEnd();
       GarbageCollection->Iterator_Next())
    CallBack(GarbageCollection->Iterator);
  GarbageCollection->Iterator_Set(backup);
}
