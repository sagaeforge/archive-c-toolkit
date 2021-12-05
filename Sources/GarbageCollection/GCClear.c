
#include "_GarbageCollection.h"

void GC_Clear() {
  if (__Manager__ == NULL)
    return;
  if (__Manager__->UsedMemoryPageLength == 1)
    return;

  int i1, i2, i3;
  MemoryPage *Buffer = (MemoryPage *)malloc(sizeof(MemoryPage));
  for (i1 = 0; i1 < __Manager__->UsedMemoryPageLength - 1; i1++) {
    MemoryIndex index = {false, 0, i1};
    MemoryIndex nextIndex = {false, 0, i1 + 1};
    MemoryPage *page = MemoryPageGet(index);
    MemoryPage *next = MemoryPageGet(nextIndex);

    // 여유 공간 확인
    int freeSize = MemoryMaxLength - page->UsedMemoryLength;

    if (freeSize == 0)
      continue;

    // 버퍼에 값 옮기기
    for (i2 = 0; i2 < freeSize; i2++) {
      Buffer->Datas[i2].Value = next->Datas[0].Value;
      Buffer->Datas[i2].Length = next->Datas[0].Length;

      next->Datas[0].Value = NULL;
      next->Datas[0].Length = 0;

      Buffer->UsedMemoryLength++;

      for (i3 = 0; i3 < next->UsedMemoryLength; i3++) {
        SWAP(void *, temp_value, next->Datas[i3].Value,
             next->Datas[i3 + 1].Value);
        SWAP(unsigned int, temp_Length, next->Datas[i3].Length,
             next->Datas[i3 + 1].Length);
      }
      next->UsedMemoryLength--;
    }
    // 여유 공간에 버퍼 값을 복사
    for (i2 = page->UsedMemoryLength; i2 < Buffer->UsedMemoryLength; i2++) {
      SWAP(void *, temp_value, page->Datas[i2].Value,
           Buffer->Datas[i2 - page->UsedMemoryLength].Value);
      SWAP(unsigned int, temp_Length, page->Datas[i2].Length,
           Buffer->Datas[i2 - page->UsedMemoryLength].Length);
      page->UsedMemoryLength++;
    }

    Buffer->UsedMemoryLength = 0;
  }
  int isEnd = false;
  while (!isEnd) {
    MemoryPage *page = MemoryPageGetLast();
    if (page->UsedMemoryLength == 0)
      MemoryPageRemove(__Manager__->UsedMemoryPageLength);
    else
      isEnd = true;
  }
  free(Buffer);
}