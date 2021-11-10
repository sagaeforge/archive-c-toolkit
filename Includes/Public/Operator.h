
#ifndef __NLB_OPERATOR__
#define __NLB_OPERATOR__

#include <stdbool.h>
#include <string.h>

#include "DataTypes.h"
#include "GarbageCollection.h"

// [*] [생성자와 소멸자]
typedef void (*NoMethod)(void);

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