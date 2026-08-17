#ifndef __NLB_STRING__
#define __NLB_STRING__

#include <stdlib.h>

#pragma pack(push, 1)
typedef struct String {
  wchar_t *Values;
  unsigned int Length;
} String;
#pragma pack(pop)

// * 생성자 대응
#define StringConstructor1 String *(*)(wchar_t *);
#define StringConstructor2 String *(*)(char *);
#define StringConstructor3 String *(*)(void);
String *_String_Constructor1(wchar_t *Data);
String *_String_Constructor2(char *Data);
String *_String_Constructor3(void);

// * 소멸자 대응
#define StringDestructor void (*)(String **);
void _String_Destructor(String **Obj);

// * 가변적인 기능 지원
unsigned int CharectorData_Length(String *Obj);
void CharectorData_Set(String *Obj, wchar_t *Values, unsigned int Length);

/*
  기본 문자열의 기능

  append
  join
  subString
  loop
  split
  trim
  equal
  comapre
  contains
  count
  get
  set
  length
  toLower
  toUpper
  isNone
  format
  indexOf
  lastOfIndex
  replace
  replaceAll

  to~
  valueOf

  IsDigit
  IsAlpha

  * StringAry
  append
  remove
  get


  * StringIO
  1. 표준 입출력 지원
  2. 파일 입출력 지원


 */

#endif