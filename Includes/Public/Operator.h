#ifndef __NLB_OPERATOR__
#define __NLB_OPERATOR__

#include <stdbool.h>
#include <string.h>

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
  /* 사용자 정의 자료형 끝 */                                                  \
  default: "unknown" )

// [Public] TypeCompare(Instance1: 변수, Instance2: 변수),
// [Public] 두 변수의 자료형을 비교합니다.
#define TypeCompare(Instance1, Instance2)                                      \
  strcmp(GetType(Instance1), GetType(Instance2)) == 0

// [+ END] 자료형 끝

// [*] [생성자와 소멸자]
// [+ START] 생성자와 소멸자

// [Public] Create(DataType: char*, Caster: 함수포인터),
// [Public] DataType의 생성자가 있다면 반환하지만
// [Public] 없으면 기본 메모리 할당자를 반환합니다.
#define Create(DataType, Caster)

// [Public] Remove(DataType: char*),
// [Public] DataType의 소멸자가 있다면 반환하지만
// [Public] 없으면 기본 메모리 소멸자를 반환합니다.
#define Remove(DataType)

// [+ END] 생성자와 소멸자 끝

// [*] [연산자 파트]

// [+ START] 단항 연산자
// [Public] Operator1(Operator: char *, Caster: 함수포인터, Instance : 변수)
// [Public] Instance 자료형의 단항 연산자 Operator가 등록되어 있다면
// [Public] 해당 메소드를 호출합니다.
#define Operator1(Operator, Caster, Instance)

// [+ END] 단항 연산자 끝

// [+ START] 이항 연산자
// [Public] Operator2(... ↓)
// [Public] Instacne1: 변수,
// [Public] Operator: char *,
// [Public] Instacne2: 변수,
// [Public] Caster: 함수포인터
//
// [Public] Instance1, Instance2 자료형의 이항 연산자 Operator가 등록되어 있다면
// [Public] 해당 메소드를 호출합니다.
#define Operator2(Instacne1, Operator, Instacne2, Caster)

// [+ END] 이항 연산자 끝

#define NoMethodCaster void (*)(void)

#endif