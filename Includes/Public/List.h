
#ifndef __LIST_PUBLIC__
#define __LIST_PUBLIC__

#include "_Types.h"
#include <stdio.h>

// 싱글톤된 일반화된 리스트를 만들어야함.
// Iterator 지원, foreach 지원, 표준 Iterator 함수는 가변 캐스팅을 통해
// 지원이됨.
//
// 각 리스트 매니저를 만들고 내부 구조체 값을 제어함.
// 추가 기능과 삭제, 인덱스 기능을 지원함.

/**
 * @brief 가나다
 */
#define Iterator(Type)                                                         \
  struct {                                                                     \
    Type *ListPool;                                                            \
    Type *_Start;                                                              \
    Type *_Last;                                                               \
    Type *Iterator;                                                            \
    Index _Index;                                                              \
    void (*Prev)();                                                            \
    void (*Next)();                                                            \
    void (*Set)(Index);                                                        \
    Index (*Get)();                                                            \
    void (*Start)();                                                           \
    void (*Last)();                                                            \
    bool (*IsStart)();                                                         \
    bool (*IsLast)();                                                          \
    void (*Foreach)(void (*)(Type *));                                         \
  } Iterator

#define List(_ListName, _ListValue, _Methods)                                  \
  typedef struct _##_ListName {                                                \
    Index Capacity;                                                            \
    _ListValue Value;                                                          \
    Iterator(_ListValue);                                                      \
    _Methods Methods;                                                          \
  } _ListName;                                                                 \
  extern _ListName *_ListName##_Manager;                                       \
  List_Iterator_Setting(_ListValue)

#define List_Iterator_Setting(Type)                                            \
  void Type##_Iterator_Set(void *);                                            \
  void Type##_Prev();                                                          \
  void Type##_Next();                                                          \
  void Type##_Set(Index);                                                      \
  Index Type##_Get();                                                          \
  void Type##_Start();                                                         \
  void Type##_Last();                                                          \
  bool Type##_IsStart();                                                       \
  bool Type##_IsLast();                                                        \
  void Type##_Foreach(void (*)(Type *))

#define List_Iterator_Implements(Type, List_Manager)                           \
  void Type##_Iterator_Set(void *IteratorPosition) {                           \
    Standard_Iterator *temp = (Standard_Iterator *)IteratorPosition;           \
    temp->Prev = Type##_Prev;                                                  \
    temp->Next = Type##_Next;                                                  \
    temp->Set = Type##_Set;                                                    \
    temp->Get = Type##_Get;                                                    \
    temp->Start = Type##_Start;                                                \
    temp->Last = Type##_Last;                                                  \
    temp->IsStart = Type##_IsStart;                                            \
    temp->IsLast = Type##_IsLast;                                              \
    temp->Foreach = (void (*)(void (*)(void *)))Type##_Foreach;                \
    temp->_Index = 0;                                                          \
    temp->_Last = NULL;                                                        \
    temp->_Start = NULL;                                                       \
    temp->ListPool = NULL;                                                     \
    temp->Iterator = NULL;                                                     \
  }                                                                            \
  static Type *GetNode(Index Index) {                                          \
    int index = 0;                                                             \
    Type *node = &List_Manager->Value;                                         \
    while (index <= List_Manager->Iterator._Index) {                           \
      node = node->Next;                                                       \
    }                                                                          \
    return node;                                                               \
  }                                                                            \
  void Type##_Set(Index Index) {                                               \
    if (Index < 0 || Index >= List_Manager->Capacity)                          \
      return;                                                                  \
    List_Manager->Iterator._Index = Index;                                     \
    List_Manager->Iterator.Iterator = GetNode(List_Manager->Iterator._Index);  \
  }                                                                            \
  void Type##_Next() {                                                         \
    if (List_Manager->Iterator._Index + 1 >= List_Manager->Capacity)           \
      return;                                                                  \
    List_Manager->Iterator._Index++;                                           \
    List_Manager->Iterator.Iterator = GetNode(List_Manager->Iterator._Index);  \
  }                                                                            \
  void Type##_Prev() {                                                         \
    if (List_Manager->Iterator._Index - 1 < 0)                                 \
      return;                                                                  \
    List_Manager->Iterator._Index--;                                           \
    List_Manager->Iterator.Iterator = GetNode(List_Manager->Iterator._Index);  \
  }                                                                            \
  void Type##_Start() {                                                        \
    List_Manager->Iterator._Index = 0;                                         \
    List_Manager->Iterator.Iterator = GetNode(List_Manager->Iterator._Index);  \
  }                                                                            \
  void Type##_Last() {                                                         \
    List_Manager->Iterator._Index = List_Manager->Capacity;                    \
    List_Manager->Iterator.Iterator = GetNode(List_Manager->Iterator._Index);  \
  }                                                                            \
  bool Type##_IsStart() { return List_Manager->Iterator._Index == 0; }         \
  bool Type##_IsLast() {                                                       \
    return List_Manager->Iterator._Index == List_Manager->Capacity - 1;        \
  }                                                                            \
  void Type##_Foreach(void (*CallBack)(Type *)) {                              \
    Index backup = List_Manager->Iterator._Index;                              \
    List_Manager->Iterator.Start();                                            \
    for (; !List_Manager->Iterator.IsLast(); List_Manager->Iterator.Next())    \
      CallBack(List_Manager->Iterator.Iterator);                               \
    List_Manager->Iterator.Set(backup);                                        \
  }                                                                            \
  Index Type##_Get() { return List_Manager->Iterator._Index; }

// 리스트 기본 기능 구현
/*
  Init
  Append
  Remove
  Find
  Free
*/

// typedef struct _ListValue {
//   struct _ListValue *Next;
//   struct _ListValue *Prev;
//   int value;
// } ListValue;

// typedef struct _ListMethod {
//   void (*test)();
// } ListMethod;

// List(Pages, ListValue, ListMethod);

#endif