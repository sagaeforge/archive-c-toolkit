
#include "ProgramManager.h"
#include "GarbageCollection.h"
#include <stdlib.h>

struct ProgramManager Manager;

// clang-format off
static void Awake_AddListener(FP_Func Method) {
  FuncChainNode *ptr = (FuncChainNode *)malloc(sizeof(FuncChainNode));
  if (ptr == NULL) {
    printf("ERR > NODE 생성 실패");
    return;
  }

  FuncChainNode *Pos = Manager.Awake.Nodes;
  if (Pos == NULL)
    Manager.Awake.Nodes = Pos = ptr;
  else {
    while (Pos->Next != NULL)
      Pos = Pos->Next;
    Pos->Next = ptr;
    Pos = Pos->Next;
  }
  Pos->Method = Method;
}
static void Awake_RemoveListener(FP_Func Method) {
  FuncChainNode *Pos = Manager.Awake.Nodes;
  FuncChainNode *Last = Manager.Awake.Nodes;
  if (Pos == NULL)
    return;

  while (Pos->Next != NULL) {
    if (Pos->Method == Method) {
      if (Pos == Manager.Awake.Nodes) {
        Manager.Awake.Nodes = Pos->Next;
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
static void Awake_RemoveAllListener() {
  // 노드의 계수 구하기
  int length = 1;
  FuncChainNode *Pos = Manager.Awake.Nodes;
  if (Pos == NULL)
    return;

  while (Pos->Next == NULL) {
    length++;
    Pos = Pos->Next;
  }

  FuncChainNode **Ary =
      (FuncChainNode **)malloc(sizeof(FuncChainNode) * length);
  Pos = Manager.Awake.Nodes;
  int i = 0;
  while (Pos->Next == NULL) {
    Ary[i++] = Pos;
    Pos = Pos->Next;
  }
  for (i = 0; i < length; i++)
    free(Ary[i]);

  free(Ary);
}
static void Awake_Invoke() {
  FuncChainNode *Pos = Manager.Awake.Nodes;
  if (Pos == NULL)
    return;

  while (Pos != NULL) {
    Pos->Method();
    Pos = Pos->Next;
  }
}

static void Init_AddListener(FP_Func Method) {
  FuncChainNode *ptr = (FuncChainNode *)malloc(sizeof(FuncChainNode));
  if (ptr == NULL) {
    printf("ERR > NODE 생성 실패");
    return;
  }

  FuncChainNode *Pos = Manager.Init.Nodes;
  if (Pos == NULL)
    Manager.Init.Nodes = Pos = ptr;
  else {
    while (Pos->Next != NULL)
      Pos = Pos->Next;
    Pos->Next = ptr;
    Pos = Pos->Next;
  }
  Pos->Method = Method;
}
static void Init_RemoveListener(FP_Func Method) {
  FuncChainNode *Pos = Manager.Init.Nodes;
  FuncChainNode *Last = Manager.Init.Nodes;
  if (Pos == NULL)
    return;

  while (Pos->Next != NULL) {
    if (Pos->Method == Method) {
      if (Pos == Manager.Init.Nodes) {
        Manager.Init.Nodes = Pos->Next;
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
static void Init_RemoveAllListener() {
  // 노드의 계수 구하기
  int length = 1;
  FuncChainNode *Pos = Manager.Init.Nodes;
  if (Pos == NULL)
    return;

  while (Pos->Next == NULL) {
    length++;
    Pos = Pos->Next;
  }

  FuncChainNode **Ary =
      (FuncChainNode **)malloc(sizeof(FuncChainNode) * length);
  Pos = Manager.Init.Nodes;
  int i = 0;
  while (Pos->Next == NULL) {
    Ary[i++] = Pos;
    Pos = Pos->Next;
  }
  for (i = 0; i < length; i++)
    free(Ary[i]);

  free(Ary);
}
static void Init_Invoke() {
  FuncChainNode *Pos = Manager.Init.Nodes;
  if (Pos == NULL)
    return;

  while (Pos != NULL) {
    Pos->Method();
    Pos = Pos->Next;
  }
}

static void Start_AddListener(FP_Func Method) {
  FuncChainNode *ptr = (FuncChainNode *)malloc(sizeof(FuncChainNode));
  if (ptr == NULL) {
    printf("ERR > NODE 생성 실패");
    return;
  }

  FuncChainNode *Pos = Manager.Start.Nodes;
  if (Pos == NULL)
    Manager.Start.Nodes = Pos = ptr;
  else {
    while (Pos->Next != NULL)
      Pos = Pos->Next;
    Pos->Next = ptr;
    Pos = Pos->Next;
  }
  Pos->Method = Method;
}
static void Start_RemoveListener(FP_Func Method) {
  FuncChainNode *Pos = Manager.Start.Nodes;
  FuncChainNode *Last = Manager.Start.Nodes;
  if (Pos == NULL)
    return;

  while (Pos->Next != NULL) {
    if (Pos->Method == Method) {
      if (Pos == Manager.Start.Nodes) {
        Manager.Start.Nodes = Pos->Next;
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
static void Start_RemoveAllListener() {
  // 노드의 계수 구하기
  int length = 1;
  FuncChainNode *Pos = Manager.Start.Nodes;
  if (Pos == NULL)
    return;

  while (Pos->Next == NULL) {
    length++;
    Pos = Pos->Next;
  }

  FuncChainNode **Ary =
      (FuncChainNode **)malloc(sizeof(FuncChainNode) * length);
  Pos = Manager.Start.Nodes;
  int i = 0;
  while (Pos->Next == NULL) {
    Ary[i++] = Pos;
    Pos = Pos->Next;
  }
  for (i = 0; i < length; i++)
    free(Ary[i]);

  free(Ary);
}
static void Start_Invoke() {
  FuncChainNode *Pos = Manager.Start.Nodes;
  if (Pos == NULL)
    return;

  while (Pos != NULL) {
    Pos->Method();
    Pos = Pos->Next;
  }
}

static void Quit_AddListener(FP_Func Method) {
  FuncChainNode *ptr = (FuncChainNode *)malloc(sizeof(FuncChainNode));
  if (ptr == NULL) {
    printf("ERR > NODE 생성 실패");
    return;
  }

  FuncChainNode *Pos = Manager.Quit.Nodes;
  if (Pos == NULL)
    Manager.Quit.Nodes = Pos = ptr;
  else {
    while (Pos->Next != NULL)
      Pos = Pos->Next;
    Pos->Next = ptr;
    Pos = Pos->Next;
  }
  Pos->Method = Method;
}
static void Quit_RemoveListener(FP_Func Method) {
  FuncChainNode *Pos = Manager.Quit.Nodes;
  FuncChainNode *Last = Manager.Quit.Nodes;
  if (Pos == NULL)
    return;

  while (Pos->Next != NULL) {
    if (Pos->Method == Method) {
      if (Pos == Manager.Quit.Nodes) {
        Manager.Quit.Nodes = Pos->Next;
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
static void Quit_RemoveAllListener() {
  // 노드의 계수 구하기
  int length = 1;
  FuncChainNode *Pos = Manager.Quit.Nodes;
  if (Pos == NULL)
    return;

  while (Pos->Next == NULL) {
    length++;
    Pos = Pos->Next;
  }

  FuncChainNode **Ary =
      (FuncChainNode **)malloc(sizeof(FuncChainNode) * length);
  Pos = Manager.Quit.Nodes;
  int i = 0;
  while (Pos->Next == NULL) {
    Ary[i++] = Pos;
    Pos = Pos->Next;
  }
  for (i = 0; i < length; i++)
    free(Ary[i]);

  free(Ary);
}
static void Quit_Invoke() {
  FuncChainNode *Pos = Manager.Quit.Nodes;
  if (Pos == NULL)
    return;

  while (Pos != NULL) {
    Pos->Method();
    Pos = Pos->Next;
  }
}
//clang-format on
static void ProgramManager_ProgramQuit() {
  Manager.Quit.Invoke();
  exit(0);
}

void ProgramManager_Init() {
  // clang-format off
  Manager.Awake.AddListener       = Awake_AddListener;
  Manager.Awake.RemoveListener    = Awake_RemoveAllListener;
  Manager.Awake.RemoveAllListener = Awake_RemoveAllListener;
  Manager.Awake.Invoke            = Awake_Invoke;

  Manager.Init.AddListener        = Init_AddListener;
  Manager.Init.RemoveListener     = Init_RemoveAllListener;
  Manager.Init.RemoveAllListener  = Init_RemoveAllListener;
  Manager.Init.Invoke             = Init_Invoke;

  Manager.Start.AddListener       = Start_AddListener;
  Manager.Start.RemoveListener    = Start_RemoveAllListener;
  Manager.Start.RemoveAllListener = Start_RemoveAllListener;
  Manager.Start.Invoke            = Start_Invoke;
  
  Manager.Quit.AddListener        = Quit_AddListener;
  Manager.Quit.RemoveListener     = Quit_RemoveAllListener;
  Manager.Quit.RemoveAllListener  = Quit_RemoveAllListener;
  Manager.Quit.Invoke             = Quit_Invoke;
  // clang-format on

  Manager.GarbageCollection.Method.MemoryCreate = MemoryCreate;
  Manager.GarbageCollection.Method.MemoryRemove = MemoryRemove;
  Manager.GarbageCollection.Method.MemoryCompare = MemoryCompare;
  Manager.GarbageCollection.Method.MemorySet = MemorySet;
  Manager.GarbageCollection.Method.MemoryCopy = MemoryCopy;
  Manager.GarbageCollection.Method.MemoryLength = MemoryLength;
  Manager.GarbageCollection.Method.MemoryMove = MemoryMove;

  Manager.Method.ProgramQuit = ProgramManager_ProgramQuit;
}
