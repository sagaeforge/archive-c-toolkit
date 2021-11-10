#ifndef __NLB_OPERATOR__
#define __NLB_OPERATOR__

#include <stdbool.h>
#include <string.h>

#include "GarbageCollection.h"

// [*]  [자료형 파트]
// [+ START] 자료형

typedef unsigned int Length;
typedef void (*NoMethod)(void);

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
// [+ START] 함수 노드 테이블
// * 생성자와 소멸자 노드
typedef struct {
  const char *DataType;
  NoMethod Constructor;
  void (*Destructor)(void **);
} FuncNode;

NoMethod Constructor_Search(const char *DataType);
void (*Destructor_Search(const char *DataType))(void **);
extern Length FuncNodeTableLength;
extern FuncNode FuncNodeTable[];

// [+ END] 함수 노드 테이블

// [+ START] 생성자와 소멸자
// [Public] Create(DataType: char*, Caster: 함수포인터),
// [Public] DataType의 생성자가 있다면 반환하지만
// [Public] 없으면 기본 메모리 할당자를 반환합니다.
#define Create(DataType, Caster)                                               \
  (DataType *)((Caster)Constructor_Search(#DataType))

#define NoConstructor void *(*)(unsigned int)

// [Public] Remove(DataType: char*),
// [Public] DataType의 소멸자가 있다면 반환하지만
// [Public] 없으면 기본 메모리 소멸자를 반환합니다.
#define Remove(DataType, Instance)                                             \
  Destructor_Search(#DataType)((void **)&Instance)

// [+ END] 생성자와 소멸자 끝

// [*] [연산자 파트]
#define Operator1(Instance, Operator, Caster)                                  \
  ((Caster)Operator1_Search(GetType(Instance), Operator))(Instance)
#define Operator2(Instance1, Operator, Instance2, Caster)                      \
  ((Caster)Operator2_Search(GetType(Instance1), Operator,                      \
                            GetType(Instance2)))(Instance1, Instance2)

NoMethod Operator1_Search(const char *DataType, const char *Operator);
NoMethod Operator2_Search(const char *DataType1, const char *Opertator,
                          const char *DataType2);

typedef struct {
  const char *DataType1;
  const char *DataType2;
  const char *Operator;
  NoMethod OperatorMethod;
} Operator;

extern Length OperatorTableLength;
extern Operator OperatorTable[];

#endif