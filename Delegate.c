
#include "Delegate.h"
#include <stdio.h>
#include <stdlib.h>

static void AddListener(FuncChain *Chain, FP_Func Method) {
  struct __FuncChainNode *ptr =
      (struct __FuncChainNode *)malloc(sizeof(struct __FuncChainNode));
  if (ptr == NULL) {
    printf("ERR > NODE 생성 실패");
    return;
  }

  struct __FuncChainNode *Pos = Chain->Nodes;
  if (Pos == NULL)
    Chain->Nodes = Pos = ptr;
  else {
    while (Pos->Next != NULL)
      Pos = Pos->Next;
    Pos->Next = ptr;
    Pos = Pos->Next;
  }
  Pos->Method = Method;
}
static void RemoveListener(FuncChain *Chain, FP_Func Method) {
  struct __FuncChainNode *Pos = Chain->Nodes;
  struct __FuncChainNode *Last = Chain->Nodes;
  if (Pos == NULL)
    return;

  while (Pos->Next != NULL) {
    if (Pos->Method == Method) {
      if (Pos == Chain->Nodes) {
        Chain->Nodes = Pos->Next;
      } else {
        Last->Next = Pos->Next;
      }
      Pos->Method = NULL;
      Pos->Next = NULL;
      free(Pos);
    }
    Last = Pos;
    Pos = Pos->Next;
  }
}
static void RemoveAllListener(FuncChain *Chain) {
  // 노드의 계수 구하기
  int length = 1;
  struct __FuncChainNode *Pos = Chain->Nodes;
  if (Pos == NULL)
    return;

  while (Pos->Next == NULL) {
    length++;
    Pos = Pos->Next;
  }

  struct __FuncChainNode **Ary = (struct __FuncChainNode **)malloc(
      sizeof(struct __FuncChainNode) * length);
  Pos = Chain->Nodes;
  int i = 0;
  while (Pos->Next == NULL) {
    Ary[i++] = Pos;
    Pos = Pos->Next;
  }
  for (i = 0; i < length; i++)
    free(Ary[i]);

  free(Ary);
}
static void Invoke(struct __FuncChain *Chain) {
  struct __FuncChainNode *Pos = Chain->Nodes;
  if (Pos == NULL)
    return;

  while (Pos != NULL) {
    Pos->Method();
    Pos = Pos->Next;
  }
}

void FuncChain_Setting(FuncChain *Chain) {
  Chain->AddListener = AddListener;
  Chain->RemoveListener = RemoveListener;
  Chain->RemoveAllListener = RemoveAllListener;
  Chain->Invoke = Invoke;
}