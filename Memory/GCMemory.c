
#include "GCMemory.h"
#include "../GC.h"
#include "_GCMemoryPage.h"

#include <stdio.h>
#include <stdlib.h>

void *MemoryCreate(Length length) {
  void *ptr = malloc(length);
  if (!ptr)
    Error("%u만큼의 메모리를 생성하지 못했습니다.", length);

  Memory_Append(ptr, length);

  return ptr;
}

void MemoryRemove(void **Object) {
  if (!(*Object))
    (*Object) = NULL;
  Memory_Remove((*Object));

  free(*Object);
}

void MemorySet(void *Base, int Data, Length length) {
  // * 조건 비교
  MemoryIndex index = Memory_Search(Base);
  if (index.NotFound)
    Error("GC에서 할당한 메모리가 아닙니다.");

  if (MemoryLength(Base) < length)
    Error("저장할 수 있는 메모리 크기를 벗어났습니다.");

  char *BasePtr = (char *)Base;
  int i;
  for (i = 0; i < length; i++) {
    BasePtr[i] = Data;
  }
}

void MemoryCopy(void *Edit, void *Base, Length length) {
  // * 조건 비교
  MemoryIndex index = Memory_Search(Edit);
  if (index.NotFound)
    Error("GC에서 할당한 메모리가 아닙니다.");

  if (MemoryLength(Edit) < length)
    Error("저장할 수 있는 메모리 크기를 벗어났습니다.");

  char *BasePtr = (char *)Base;
  char *EditPtr = (char *)Edit;
  int i;
  for (i = 0; i < length; i++) {
    EditPtr[i] = BasePtr[i];
  }
}
void MemoryMove(void *Edit, void *Base, Length length) {
  // * 조건 비교
  MemoryIndex index = Memory_Search(Edit);
  if (index.NotFound)
    Error("GC에서 할당한 메모리가 아닙니다.");

  if (MemoryLength(Edit) < length)
    Error("저장할 수 있는 메모리 크기를 벗어났습니다.");

  char *Buf = (char *)malloc(length);
  if (!Buf)
    Error("버퍼를 생성하지 못했습니다.");

  char *BasePtr = (char *)Base;
  char *EditPtr = (char *)Edit;
  int i;
  for (i = 0; i < length; i++)
    Buf[i] = BasePtr[i];

  for (i = 0; i < length; i++)
    EditPtr[i] = Buf[i];

  free(Buf);
}

int MemoryCompare(void *Object1, void *Object2, Length length) {
  // * 조건 비교
  MemoryIndex index1 = Memory_Search(Object1);
  MemoryIndex index2 = Memory_Search(Object2);
  if (index1.NotFound)
    Error("GC에서 할당한 메모리가 아닙니다.");
  if (index2.NotFound)
    Error("GC에서 할당한 메모리가 아닙니다.");

  char *Obj1Ptr = (char *)Object1;
  char *Obj2Ptr = (char *)Object2;
  int i;
  for (i = 0; i < length; i++) {
    if (Obj1Ptr[i] != Obj2Ptr[i])
      return 0;
  }
  return 1;
}
Length MemoryLength(void *Object) {
  MemoryIndex index = Memory_Search(Object);
  MemoryPage *page = MemoryPage_Get(index);
  return page->Datas[index.MemoryIndex].MemoryLength;
}