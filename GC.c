
#include "GC.h"
#include <stdio.h>
#include <stdlib.h>

MemoryManager *__Manager__;

void *MemoryCreate(unsigned int Length) {
  if (__Manager__ == NULL)
    GC_ManagerInit();

  void *ptr = malloc(Length);
  if (ptr == NULL) {
    Warning("경고 >> 메모리(%u)를 생성할 수 없습니다", Length);
    return NULL;
  }
  MemoryPageMemoryAppend(ptr);
  return ptr;
}
void MemoryRemove(void **ptr) {
  MemoryIndex index = MemorySearch((*ptr));
  if (!index.MemoryFound) {
    Warning("잘못된 메모리를 지정했습니다 %p", (*ptr));
    return;
  }
  MemoryPageMemoryRemove((*ptr));
  free((*ptr));
}
MemoryIndex MemorySearch(void *Ptr);
void *MemoryGet(MemoryIndex Index);
void MemoryPageMemoryAppend(void *Obj);
void MemoryPageMemoryRemove(void *Obj);
void MemoryPageAppend();
void MemoryPageRemove();
MemoryPage MemoryPageGet(MemoryIndex Index);
MemoryPage MemoryPageGetLast();
MemoryPage MemoryPageGetEmpty();
MemoryFunc FuncNode_Search(char *DataType);
void *(*Constructor_Search(char *DataType, unsigned int Length))(void);
void *(*Constructor_Destructor(char *DataType))(void **);
void GC_Init();
void GC_ManagerInit() {
  __Manager__ = malloc(sizeof(MemoryManager));
  if (__Manager__ == NULL)
    Error("GarbageCollection을 생성하지 못했습니다.");

  __Manager__->UsedMemoryLength = 0;
  __Manager__->UsedMemoryPageLength = 1;
  __Manager__->UsedMemoryFuncLength = 0;

  __Manager__->Pages.Next = NULL;
  __Manager__->Pages.UsedMemoryLength = 0;

  int i;
  for (i = 0; i < MemoryMaxLength; i++) {
    __Manager__->Pages.Datas[i].Length = 0;
    __Manager__->Pages.Datas[i].Value = NULL;
  }
}
void GC_Clear();
void GC_Clean() {
  // Funcs 해제
  MemoryFunc *Func = __Manager__->Funcs;
  while (Func != NULL) {
    free(Func);
    Func = Func->Next;
  }

  // 페이지 해제
  MemoryPage *page = __Manager__->Pages.Next;
  int i;
  while (page == NULL) {
    for (i = 0; i < page->UsedMemoryLength; i++) {
      free(page->Datas[i].Value);
    }

    free(page);
    page = page->Next;
  }

  for (i = 0; i < __Manager__->Pages.UsedMemoryLength; i++) {
    free(__Manager__->Pages.Datas[i].Value);
  }

  // 메모리 관리자 해제
  free(__Manager__);
}
