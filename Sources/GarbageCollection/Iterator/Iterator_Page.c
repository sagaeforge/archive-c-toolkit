
#include "_GarbageCollecion.h"

#define Macro(Index) &ThisPage->Values[Index]

void Iterator_Page_Set(MemoryPage *ThisPage, Index Index) {
  if (Index < 0 || Index >= ThisPage->UsedMemoryLength)
    return;

  ThisPage->Iterator_Position = Index;
  ThisPage->Iterator = Macro(ThisPage->Iterator_Position);
}
void Iterator_Page_Next(MemoryPage *ThisPage) {
  if (ThisPage->Iterator_Position + 1 >= ThisPage->UsedMemoryLength)
    return;

  ThisPage->Iterator_Position++;
  ThisPage->Iterator = Macro(ThisPage->Iterator_Position);
}
void Iterator_Page_Prev(MemoryPage *ThisPage) {
  if (ThisPage->Iterator_Position - 1 < 0)
    return;

  ThisPage->Iterator_Position--;
  ThisPage->Iterator = Macro(ThisPage->Iterator_Position);
}
void Iterator_Page_Start(MemoryPage *ThisPage) {
  ThisPage->Iterator_Position = 0;
  ThisPage->Iterator = Macro(ThisPage->Iterator_Position);
}
void Iterator_Page_End(MemoryPage *ThisPage) {
  ThisPage->Iterator_Position = ThisPage->UsedMemoryLength;
  ThisPage->Iterator = Macro(ThisPage->Iterator_Position);
}
bool Iterator_Page_IsStart(MemoryPage *ThisPage) {
  return ThisPage->Iterator_Position == 0;
}
bool Iterator_Page_IsEnd(MemoryPage *ThisPage) {
  return ThisPage->Iterator_Position == ThisPage->UsedMemoryLength - 1;
}
void foreach_Page(MemoryPage *page, void (*CallBack)(MemoryPageValue *)) {
  Index backup = page->Iterator_Position;
  page->Iterator_Start(page);
  for (; !page->Iterator_IsEnd(page); page->Iterator_Next(page))
    CallBack(page->Iterator);
  page->Iterator_Set(page, backup);
}