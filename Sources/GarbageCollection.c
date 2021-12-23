
#include "GarbageCollection.h"
#include "Exception.h"
#include <stdlib.h>

/*
  [*] 파라미터 사양이 변경될 수 있음.
  [+] MemorySet
  [+] MemoryCopy
  [+] MemoryMove
  [+] MemorySwap
  [+] MemoryCompare
  [+] MemoryLength

  [*] 관련 기능을 만들고 나서 수정될 가능성이 있는 함수들
  [+] MemoryCreate
  [+] MemoryRemove
  [+] MemorySet
  [+] MemoryCopy
  [+] MemoryMove
  [+] MemorySwap
  [+] MemoryCompare
  [+] MemoryLength

  [*] 조건 확인에 대한 부분
  [+] MemoryRemove - 메모리를 GC에서 할당했는가?
  [+] MemorySet - 메모리를 GC에서 할당 했는가?
  [+]           - 세팅할 크기가 Src의 크기보다 크다면
  [+] MemorySwap  - 메모리를 GC에서 할당 했는가?
  [+]             - 스왑할 메모리의 크기가 Src와 Data보다 크다면?
  [+] MemoryCopy, MemoryMove  - 메모리를 GC에서 할당 했는가?
  [+]                         - 스왑할 메모리의 크기가 Src와 Data보다 크다면?
  [+] MemoryCompare - 메모리를 GC에서 할당 했는가?
  [+]               - 검사할 메모리 크기가 할당한 크기보다 크다면
  [+] MemoryLength - 메모리를 GC에서 할당 했는가?

  [*] 추후 발표후에 추가 가능 기능
  [+] Const
  [-] ReadOnly
  [-] GetPolish

*/
static void Swap(void *ptr1, void *ptr2, Length length) {
  char *a = (char *)ptr1;
  char *b = (char *)ptr2;

  int i = 0;
  char t = '\0';
  while (i < length) {
    t = *a;
    *a = *b;
    *b = t;
    i++, a++, b++;
  }
}

void *MemoryCreate(Length Length) {
  // TODO 조건 확인
  void *ptr = malloc(Length);
  if (ptr == NULL)
    Warning("지정된 메모리를 생성할 수 없습니다.");
  return ptr;
}
void MemoryRemove(void **ptr) {
  // TODO 조건 확인

  free((*ptr));
  (*ptr) = NULL;
}
void MemorySet(void *Src, int value, Length WordSize, Length Length) {
  // TODO 조건 확인

  if (WordSize == 0 || WordSize == 3 || WordSize > 4)
    return;

  Length *= WordSize;
  char *a = (char *)Src;
  char *b = (char *)&value;
  const char *backup = b;
  int i = 0, j = 0;
  while (i < Length) {
    while (j < WordSize) {
      *a = *b;
      a++, b++, i++, j++;
    }
    j = 0;
    b = backup;
  }
}
void MemorySwap(void *Src, void *Data, Length Length) {
  // TODO 조건 확인

  Swap(Src, Data, Length);
}
void MemoryCopy(void *Src, void *Data, Length Length) {
  // TODO 조건 확인

  char *a = (char *)Src;
  char *b = (char *)Data;

  int i = 0;
  while (i < Length) {
    *a = *b;
    i++, a++, b++;
  }
}
void MemoryMove(void *Src, void *Data, Length Length) {
  // TODO 조건 확인

  char *a = (char *)Src;
  char *b = (char *)Data;
  const char *backup = b;
  char *buf = (char *)malloc(Length);
  if (buf == NULL) {
    Warning("버퍼 메모리를 확보할 수 없었습니다.");
    return;
  }

  int i = 0;
  while (i < Length) {
    *buf = *b;
    i++, buf++, b++;
  }

  i = 0;
  while (i < Length) {
    *a = *buf;
    i++, a++, buf++;
  }

  free(buf);
}
bool MemoryCompare(void *Obj1, void *Obj2, Length Length) {
  // TODO 조건 확인

  char *a = (char *)Obj1;
  char *b = (char *)Obj2;
  int i = 0;
  while (i < Length) {
    if (*a != *b)
      return false;
    a++, b++, i++;
  }
  return true;
}
Length MemoryLength(void *Obj) { return 0; }