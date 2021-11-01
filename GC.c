
#include "GC.h"
#include <stdio.h>
#include <stdlib.h>

GCMemoryManager *__Manager__;

void GCManager_Init() {
  __Manager__ = malloc(sizeof(GCMemoryManager));
  if (!__Manager__)
    Error("메모리 관리자를 생성할 수 없습니다.");

  __Manager__->FuncsNode = NULL;
  __Manager__->TotalUsedFuncsNode = 0;
  __Manager__->TotalUsedMemory = 0;
  __Manager__->TotalUsedMemoryPageNode = 1;

  __Manager__->MemoryPageNode.Next = NULL;
  __Manager__->MemoryPageNode.UsedMemory = 0;

  int i;
  for (i = 0; i < MemoryMaxLength; i++) {
    __Manager__->MemoryPageNode.Datas[i].MemoryLength = 0;
    __Manager__->MemoryPageNode.Datas[i].Value = NULL;
  }
}

// * 안 사용하는 메모리 페이지 삭제 및 메모리 페이지 합치기
void GC_Clear() {
  // TODO 구현하셈
}

//
void GC_Clean() {
  // TODO 구현하셈
}