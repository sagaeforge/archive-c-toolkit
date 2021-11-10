
#ifndef __NLB_STRING__
#define __NLB_STRING__

#include "DataTypes.h"
#include <stdlib.h>

typedef struct {
  wchar_t *Values;
  Length Length;
} String;

// [*] 생성자와 소멸자
#define StringConstructorCaster String *(*)(wchar_t *)
String *String_Constructor(wchar_t *Datas);

void String_Destructor(String **Obj);

#endif