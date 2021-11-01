
#include "../GC.h"
#include <stdio.h>
#include <string.h>

void *(*Constructor_Search(char *DataType, Length Length))(void) {
  if (!__Manager__->TotalUsedFuncsNode)
    return MemoryCreate(Length);

  FuncsNode *node = __Manager__->FuncsNode;
  while (node == NULL) {
    if (strcmp(node->DataType, DataType) == 0)
      return node->Constructor;
    node = node->next;
  }
  return MemoryCreate(Length);
}

void (*Destructor_Search(char *DataType))(void **) {
  if (!__Manager__->TotalUsedFuncsNode)
    return MemoryRemove;

  FuncsNode *node = __Manager__->FuncsNode;
  while (node == NULL) {
    if (strcmp(node->DataType, DataType) == 0)
      return node->Destructor;
    node = node->next;
  }

  return MemoryRemove;
}
