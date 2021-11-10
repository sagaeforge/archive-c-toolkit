
#include "Operator.h"
#include "GarbageCollection.h"

static FuncNode *FuncNode_Search(const char *DataType) {
  if (FuncNodeTableLength == 0)
    return NULL;

  int i;
  for (i = 0; i < FuncNodeTableLength; i++) {
    if (strcmp(FuncNodeTable[i].DataType, DataType) == 0)
      return &FuncNodeTable[i];
    break;
  }
  return NULL;
}
NoMethod Constructor_Search(const char *DataType) {
  FuncNode *Node = FuncNode_Search(DataType);
  if (Node != NULL)
    return Node->Constructor;

  return (void (*)(void))MemoryCreate;
}
void (*Destructor_Search(const char *DataType))(void **) {
  FuncNode *Node = FuncNode_Search(DataType);
  if (Node != NULL)
    return Node->Destructor;

  return MemoryRemove;
}
NoMethod Operator1_Search(const char *DataType, const char *Operator) {
  if (OperatorTableLength == 0)
    return NULL;

  int i;
  for (i = 0; i < OperatorTableLength; i++) {
    if (strcmp(OperatorTable[i].Operator, Operator) == 0 &&
        strcmp(OperatorTable[i].DataType1, DataType) == 0)
      return OperatorTable[i].OperatorMethod;
  }
  return NULL;
}
NoMethod Operator2_Search(const char *DataType1, const char *Operator,
                          const char *DataType2) {
  if (OperatorTableLength == 0)
    return NULL;

  int i;
  for (i = 0; i < OperatorTableLength; i++) {
    if (strcmp(OperatorTable[i].Operator, Operator) == 0 &&
        strcmp(OperatorTable[i].DataType1, DataType1) == 0 &&
        strcmp(OperatorTable[i].DataType2, DataType2) == 0)
      return OperatorTable[i].OperatorMethod;
  }
  return NULL;
}