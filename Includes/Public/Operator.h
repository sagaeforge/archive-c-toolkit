#ifndef __NLB_OPERATOR__
#define __NLB_OPERATOR__

#include <stdbool.h>
#include <string.h>

// [*]  [자료형 파트]
// * 자료형
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
  /* 사용자 정의 자료형 끝 */                                                  \
  default: "unknown" )

#define TypeCompare(Instance1, Instance2)                                      \
  strcmp(GetType(Instance1), GetType(Instance2)) == 0

// * 자료형 끝

// [*] [생성자와 소멸자]
// * 생성자와 소멸자
// * 생성자와 소멸자 끝

// [*] [연산자 파트]

// * 단항 연산자
#define Operator1(Operator, MethodCaster, Instance)

// * 단항 연산자 끝

// * 이항 연산자
#define Operator2(Instacne1, Operator, Instacne2, MethodCaster)

// * 이항 연산자 끝

#define NoMethodCaster void (*)(void)

#endif