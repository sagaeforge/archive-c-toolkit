
#include "Exception.h"
#include "Private_ProcessEvent.h"
#include "ProgramManager.h"
#include <stdlib.h>

static void AddListener(FP_Func Method) {
  FuncChainNode *ptr = (FuncChainNode *)malloc(sizeof(FuncChainNode));
  ProcessEvent event = Program.ProcessEvent.Events[ProcessEventCode_Quit];
  if (ptr == NULL) {
    printf("ERR > NODE 생성 실패");
    // TODO 에러 처리
    return;
  }
  ptr->Next = NULL;
  FuncChainNode *Pos = event.Nodes;
  if (Pos == NULL)
    event.Nodes = Pos = ptr;
  else {
    while (Pos->Next != NULL)
      Pos = Pos->Next;
    Pos->Next = ptr;
    Pos = Pos->Next;
  }
  Pos->Method = Method;
}
static void RemoveListener(FP_Func Method) {
  ProcessEvent event = Program.ProcessEvent.Events[ProcessEventCode_Quit];
  FuncChainNode *Pos = event.Nodes;
  FuncChainNode *Last = event.Nodes;
  while (Pos != NULL) {
    if (Pos->Method == Method) {
      if (Pos == event.Nodes) {
        event.Nodes = Pos->Next;
      } else {
        Last->Next = Pos->Next;
      }
      Pos->Method = NULL;
      Pos->Next = NULL;
      free(Pos);
      break;
    }
    Last = Pos;
    Pos = Pos->Next;
  }
}
static void RemoveAllListener() {
  ProcessEvent event = Program.ProcessEvent.Events[ProcessEventCode_Quit];
  int length = 1;
  FuncChainNode *Pos = event.Nodes;
  if (Pos == NULL)
    return;
  while (Pos->Next != NULL) {
    length++;
    Pos = Pos->Next;
  }
  void *tempAry = malloc(sizeof(FuncChainNode) * length);
  if (tempAry == NULL) {
    Error("버퍼공간을 확보하지 못했습니다.");
    // TODO 에러 처리
  }
  FuncChainNode **Ary = (FuncChainNode **)tempAry;
  Pos = event.Nodes;
  int i = 0;
  while (Pos != NULL) {
    Ary[i++] = Pos;
    Pos = Pos->Next;
  }
  for (i = 0; i < length; i++)
    free(Ary[i]);
  free(tempAry);
}
static void Invoke() {
  ProcessEvent event = Program.ProcessEvent.Events[ProcessEventCode_Quit];
  FuncChainNode *Pos = event.Nodes;
  while (Pos != NULL) {
    Pos->Method();
    Pos = Pos->Next;
  }
}
void ProcessEventModule_Main_Initialized() {
  ProcessEvent event = Program.ProcessEvent.Events[ProcessEventCode_Quit];
  event.AddListener = AddListener;
  event.RemoveListener = RemoveListener;
  event.RemoveAllListener = RemoveAllListener;
  event.Invoke = Invoke;
}