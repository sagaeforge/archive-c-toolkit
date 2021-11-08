#ifndef __NLB_STRING__
#define __NLB_STRING__

#include <stdlib.h>

#pragma pack(push, 1)
typedef struct String {
  wchar_t *Values;
  unsigned int IsNone : 1;
  unsigned int Length : 31;
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

  1. 연산자(+, -, *, /. ==, !=)
  2. 특정 문자열이 몇 번 등장하는가? Contains, Count
  3. Getter, Setter
  4. 소문자로, 대문자로 Lower Upper
  5. 존재하지 않는가? 존재하는가? IsNone
  6. 문자열에 더하기 Join

 */

#endif