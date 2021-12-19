#ifndef __DELEGATE__
#define __DELEGATE__

#include <stdarg.h>
#include <stdio.h>

#define Delegate(Ret, Name, args...)                                           \
  typedef Ret (*Name##Type)(args);                                             \
  typedef struct _Delegate_##Name {                                            \
    Ret (*Method)(args);                                                       \
    struct _Delegate_##Name *Next;                                             \
  } Delegate_##Name;                                                           \
  Delegate_##Name *Name;

// 추가하고 삭제하는 메소드

// #define Action(Name, ...) typedef void (*Name)(##__VA_ARGS__)

// typedef struct Delegate_Name {
//   Ret (*Funcs)(...)
// } Name;

#endif