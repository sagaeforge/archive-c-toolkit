
#include "_GarbageCollection.h"

void GC_Clean() {
  if (__Manager__ == NULL)
    return;

  // 페이지 해제
  int i;
  for (i = __Manager__->UsedMemoryPageLength; i > 1; i--) {
    MemoryPageRemove(i);
  }

  for (i = 0; i < __Manager__->Pages.UsedMemoryLength; i++) {
    free(__Manager__->Pages.Datas[i].Value);
  }

  // 메모리 관리자 해제
  free(__Manager__);
}