
#ifndef __NLB_LENGTH__
#define __NLB_LENGTH__

typedef unsigned int Length;
typedef unsigned int Index;

#include "String.h"

// [*]  [자료형 파트]
// [+ START] 자료형

// [Public] GetType(Instance: Varaible), 변수의 자료형을 알아냅니다.
#define GetType(Instance)                                                      \
  _Generic(Instance,                                                           \
  /* 기본 자료형 */                                                            \
  char                  : "char",                                              \
  unsigned char         : "unsigned char",                                     \
  short                 : "short",                                             \
  unsigned short        : "unsigned short",                                    \
  int                   : "int",                                               \
  unsigned int          : "unsigned int",                                      \
  long                  : "long",                                              \
  unsigned long         : "unsigned long",                                     \
  long long             : "long long",                                         \
  unsigned long long    : "unsigned long long",                                \
  /* 기본 자료형 끝 */                                                         \
  /* 기본 자료형 포인터 */                                                     \
  char *                : "char *",                                            \
  char **               : "char **",                                           \
  const char *          : "const char *",                                      \
  const char **         : "const char *",                                      \
  int *                 : "int *",                                             \
  int **                : "int **",                                            \
  const int *           : "const int *",                                       \
  const int **          : "const int **",                                      \
  long *                : "long *",                                            \
  long **               : "long **",                                           \
  const long *          : "const long *",                                      \
  const long **         : "const long **",                                     \
  long long *           : "long long *",                                       \
  long long **          : "long long **",                                      \
  const long long *     : "const long long *",                                 \
  const long long **    : "const long long **",                                \
  void *                : "void *",                                            \
  void **               : "void **",                                           \
  void ***              : "void ***",                                          \
  const void *          : "const void *",                                      \
  const void **         : "const void **",                                     \
  const void ***        : "const void ***",                                    \
  /* 기본 자료형 포인터 끝 */                                                  \
  /* 시스템 확장 자료형 */                                                     \
  _Bool                 : "_Bool",                                             \
  /* 시스템 확장 자료형 끝 */                                                  \
  /* 사용자 정의 자료형 */                                                     \
  String                : "String",                                            \
  /* 사용자 정의 자료형 끝 */                                                  \
  default: "unknown" )

// [Public] TypeCompare(Instance1: 변수, Instance2: 변수),
// [Public] 두 변수의 자료형을 비교합니다.
#define TypeCompare(Instance1, Instance2)                                      \
  strcmp(GetType(Instance1), GetType(Instance2)) == 0

// [+ END] 자료형 끝

#endif