#ifndef __NLB_OPERATOR__
#define __NLB_OPERATOR__

// 산술 연산자 오버로딩
#include <stdio.h>

// 데이터 타입 정의
#define type(x)                                                                \
  _Generic((x),                                                     \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                   char *: "char *",                 \
       void *: "void *",                         int *: "int *",                  \
      default: "unknown",)

typedef struct Operator {
  char OperatorType[3];
  char *Operand1_DataType;
  char *Operand2_DataType;
  void *(*Method)(void *, void *);
  Operator *next;
} ArithmeticOperation, LogicOperation;

typedef struct {
  void *Instance;
  char *DataType;
} Instance;

ArithmeticOperation ArithmeticOperationTable[] = {
    {"+", NULL, NULL, NULL, NULL}};
LogicOperation LogicOperationTable[] = {{"==", NULL, NULL, NULL, NULL}};

typedef enum {
  OperatorType_Plus = '+',
  OperatorType_Minus = '-',
  OperatorType_Multi = '*',
  OperatorType_Division = '/',
  OperatorType_Equal,
  OperatorType_NotEqual,
} OperatorType;

/*
  오퍼레이터를 판명하고

  Operator(Str1, +, Str2);
*/

#define Operator(Instance1, Operator, Instance2, MethodCaster)
void (*OperatorSearch(Instance ins1, OperatorType OperatorType,
                      Instance ins2))(void);

typedef struct GCMemoryFunc {
  char *DataType;
  void (*Constructor)(void);
  void (*Destructor)(void **);
  struct GCMemoryFunc *Next;
} MemoryFunc;

// * 생성자와 소멸자 관련
MemoryFunc *FuncNode_Search(const char *DataType);
#define Create(DataType, Casting)                                              \
  (DataType *)((Casting)Constructor_Search(#DataType))
void *(*Constructor_Search(char *DataType))(void);
#define Remove(DataType, Instance)                                             \
  Constructor_Destructor(#DataType)((void **)&Instance)
void (*Constructor_Destructor(char *DataType))(void **);

void FuncNode_Append(void (*Contructor)(void), void (*Destructor)(void **),
                     const char *DataType);

MemoryFunc *FuncNode_Get(unsigned int Index);

#define NoConstructor void *(*)(unsigned int)

#endif