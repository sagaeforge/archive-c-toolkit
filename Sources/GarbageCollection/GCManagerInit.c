
#include "_GarbageCollection.h"
#include "Exception.h"


MemoryManager *__Manager__;

void GC_ManagerInit() {
  __Manager__ = malloc(sizeof(MemoryManager));
  if (__Manager__ == NULL)
    Error("GarbageCollection을 생성하지 못했습니다.\n");

  __Manager__->UsedMemoryLength = 0;
  __Manager__->UsedMemoryPageLength = 1;

  __Manager__->Pages.Next = NULL;
  __Manager__->Pages.UsedMemoryLength = 0;

  int i;
  for (i = 0; i < MemoryMaxLength; i++) {
    __Manager__->Pages.Datas[i].Length = 0;
    __Manager__->Pages.Datas[i].Value = NULL;
  }
}