
#include "GC.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  현재 오류

  생성하고 바로 소멸할 경우 페이지에 쓰레기 값이 들어가 오류를 일으킴.
*/

#define SWAP(DT, TempVarName, A1, A2)                                          \
  DT TempVarName = A1;                                                         \
  A1 = A2;                                                                     \
  A2 = TempVarName

MemoryManager *__Manager__;

int test = 0;

void *MemoryCreate(unsigned int Length) {
  void *ptr = malloc(Length);
  if (ptr == NULL) {
    Warning("경고 >> 메모리(%u)를 생성할 수 없습니다\n", Length);
    return NULL;
  }
  MemoryPageMemoryAppend(ptr, Length);
  return ptr;
}
void MemoryRemove(void **ptr) {
  MemoryIndex index = MemorySearch((*ptr));
  if (!index.MemoryFound) {
    Warning("등록된 메모리가 아닙니다 %p\n", (*ptr));
    return;
  }
  MemoryPageMemoryRemove((*ptr));
  free((*ptr));
}
MemoryIndex MemorySearch(void *Ptr) {
  MemoryPage *page = &__Manager__->Pages;
  MemoryIndex index = {
      0,
  };

  if (Ptr == NULL)
    return index;

  int i;
  for (i = 0; page != NULL; i++) {

    int pl = 0;
    int pr = page->UsedMemoryLength;
    int pc = 0;

    do {
      pc = (pl + pr) / 2;

      if (page->Datas[pc].Value == Ptr) {
        index.MemoryIndex = pc;
        index.MemoryPageIndex = i + 1;
        index.MemoryFound = true;
        return index;
      } else if (page->Datas[pc].Value < Ptr) // 1 2 3 4 5 6
        pl = pc + 1;
      else
        pr = pc - 1;

    } while (pl <= pr);

    page = page->Next;
  }
  return index;
}
void *MemoryGet(MemoryIndex Index) {
  if (Index.MemoryIndex > MemoryMaxLength ||
      Index.MemoryPageIndex > __Manager__->UsedMemoryPageLength)
    return NULL;

  MemoryPage *page = MemoryPageGet(Index);
  return page->Datas[Index.MemoryIndex].Value;
}
unsigned int MemoryGetLength(MemoryIndex Index) {
  if (Index.MemoryIndex > MemoryMaxLength ||
      Index.MemoryPageIndex > __Manager__->UsedMemoryPageLength)
    return 0;

  MemoryPage *page = MemoryPageGet(Index);
  return page->Datas[Index.MemoryIndex].Length;
}
void MemoryPageMemoryAppend(void *Obj, unsigned int Length) {
  MemoryIndex index = MemorySearch(Obj);
  if (index.MemoryFound) {
    Warning("등록된 메모리를 등록하려 했습니다. %p\n", Obj);
    return;
  }

  MemoryPage *page = MemoryPageGetEmpty();
  page->Datas[page->UsedMemoryLength].Value = Obj;
  page->Datas[page->UsedMemoryLength].Length = Length;

  if (page->UsedMemoryLength >= 2) {
    int i;
    for (i = page->UsedMemoryLength; i >= 0; i--) {
      if (page->Datas[i].Value < page->Datas[i - 1].Value) {
        SWAP(void *, temp_value, page->Datas[i - 1].Value,
             page->Datas[i].Value);
        SWAP(unsigned, temp_length, page->Datas[i - 1].Length,
             page->Datas[i].Length);
      } else
        break;
    }
  }

  page->UsedMemoryLength++;
  __Manager__->UsedMemoryLength++;
}
void MemoryPageMemoryRemove(void *Obj) {
  MemoryIndex index = MemorySearch(Obj);
  if (!index.MemoryFound) {
    Warning("잘못된 메모리를 지정했습니다 %p\n", Obj);
    return;
  }

  MemoryPage *page = MemoryPageGet(index);
  page->Datas[index.MemoryIndex].Value = NULL;
  page->Datas[index.MemoryIndex].Length = 0;

  int i;
  for (i = index.MemoryIndex; i < page->UsedMemoryLength; i++) {
    SWAP(void *, temp_value, page->Datas[i].Value, page->Datas[i + 1].Value);
    SWAP(unsigned int, temp_Length, page->Datas[i].Length,
         page->Datas[i + 1].Length);
  }

  page->UsedMemoryLength--;
  __Manager__->UsedMemoryLength--;
}
void MemoryPageAppend() {
  MemoryPage *page = MemoryPageGetLast();
  MemoryPage *NewPage = (MemoryPage *)malloc(sizeof(MemoryPage));
  if (NewPage == NULL) {
    Error("메모리 페이지를 생성하지 못했습니다.\n");
    return;
  }

  page->Next = NewPage;
  NewPage->Next = NULL;
  NewPage->UsedMemoryLength = 0;
  __Manager__->UsedMemoryPageLength++;
  int i;
  for (i = 0; i < MemoryMaxLength; i++) {
    NewPage->Datas[i].Length = 0;
    NewPage->Datas[i].Value = NULL;
  }
}
void MemoryPageRemove(unsigned int Index) {
  // TODO 조건 검사
  MemoryIndex index = {0, 0, Index};
  MemoryIndex lastIndex = {0, 0, Index - 1};
  MemoryPage *page = MemoryPageGet(index);
  MemoryPage *Last = MemoryPageGet(lastIndex);

  Last->Next = page->Next;
  __Manager__->UsedMemoryPageLength--;
  __Manager__->UsedMemoryLength -= page->UsedMemoryLength;

  int i;
  for (i = 0; i < page->UsedMemoryLength; i++) {
    free(page->Datas[i].Value);
  }

  free(page);
}
MemoryPage *MemoryPageGet(MemoryIndex Index) {
  // TODO 조건 검사

  if (Index.MemoryPageIndex > __Manager__->UsedMemoryPageLength)
    return MemoryPageGetLast();

  MemoryPage *page = &__Manager__->Pages;

  int i;
  for (i = 1; i < Index.MemoryPageIndex; i++) {
    page = page->Next;
  }

  return page;
}
MemoryPage *MemoryPageGetLast() {
  MemoryIndex index = {false, 0, __Manager__->UsedMemoryPageLength};
  return MemoryPageGet(index);
}
MemoryPage *MemoryPageGetEmpty() {
  MemoryPage *page = &__Manager__->Pages;
  while (page != NULL) {
    if (page->UsedMemoryLength < MemoryMaxLength)
      return page;
    page = page->Next;
  }

  MemoryPageAppend();
  return MemoryPageGetLast();
}

MemoryFunc *FuncNode_Search(const char *DataType) {
  // TODO 조건 검사
  if (__Manager__ == NULL)
    GC_ManagerInit();

  if (__Manager__->UsedMemoryFuncLength == 0)
    return NULL;

  MemoryFunc *func = __Manager__->Funcs;
  while (func != NULL) {
    if (strcmp(DataType, func->DataType) == 0)
      return func;
    func = func->Next;
  }

  return NULL;
}
void *(*Constructor_Search(char *DataType))(void) {
  // TODO 조건 검사
  MemoryFunc *func = FuncNode_Search(DataType);
  if (func == NULL)
    return (void *(*)(void))MemoryCreate;

  return (void *(*)(void))func->Constructor;
}
void (*Constructor_Destructor(char *DataType))(void **) {
  // TODO 조건 검사
  MemoryFunc *func = FuncNode_Search(DataType);
  if (func == NULL)
    return MemoryRemove;

  return func->Destructor;
}

void FuncNode_Append(void (*Constructor)(void), void (*Destructor)(void **),
                     const char *DataType) {
  MemoryFunc *func = (MemoryFunc *)malloc(sizeof(MemoryFunc));
  if (func == NULL) {
    Warning("함수 노드를 생성하지 못했습니다.\n");
    return;
  }
  func->Constructor = Constructor;
  func->Destructor = Destructor;
  func->DataType = (char *)DataType;
  func->Next = NULL;

  MemoryFunc *now = FuncNode_Get(__Manager__->UsedMemoryFuncLength);
  if (now == NULL)
    __Manager__->Funcs = func;
  else
    now->Next = func;
  __Manager__->UsedMemoryFuncLength++;
}
MemoryFunc *FuncNode_Get(unsigned int Index) {
  if (Index > __Manager__->UsedMemoryFuncLength)
    return __Manager__->Funcs;

  int i;
  MemoryFunc *func = __Manager__->Funcs;
  for (i = 0; i < Index; i++) {
    func = func->Next;
  }
  return func;
}

void GC_Init() {
  // 각종 초기화 함수를 호출
}
void GC_ManagerInit() {
  __Manager__ = malloc(sizeof(MemoryManager));
  if (__Manager__ == NULL)
    Error("GarbageCollection을 생성하지 못했습니다.\n");

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

void GC_Clear() {
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
static void FuncNode_Remove(int Index) {
  int i;
  MemoryFunc *Last = NULL;
  MemoryFunc *Now = __Manager__->Funcs;
  for (i = 0; i < Index; i++) {
    Last = Now;
    Now = Now->Next;
  }

  free(Now);
  if (Last != NULL)
    Last->Next = NULL;
  __Manager__->UsedMemoryFuncLength--;
}
void GC_Clean() {
  // Funcs 해제
  int i;
  for (i = __Manager__->UsedMemoryFuncLength; i > 0; i--) {
    FuncNode_Remove(i);
  }

  // 페이지 해제
  for (i = __Manager__->UsedMemoryPageLength; i > 1; i--) {
    MemoryPageRemove(i);
  }

  for (i = 0; i < __Manager__->Pages.UsedMemoryLength; i++) {
    free(__Manager__->Pages.Datas[i].Value);
  }

  // 메모리 관리자 해제
  free(__Manager__);
}
