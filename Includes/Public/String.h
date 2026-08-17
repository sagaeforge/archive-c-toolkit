
#ifndef __NLB_STRING__
#define __NLB_STRING__

#include "DataTypes.h"
#include "Operator.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  wchar_t *Values;
  Length Length;
} String;

typedef struct {
  Length Length;
  struct StringAryNode {
    String *Value;
    struct StringAryNode *Next;
  } * StringAryValues;
} StringAry;

// [*] 생성자와 소멸자
#define StringConstructorCaster String *(*)(wchar_t *)
#define String(value) Create(String, StringConstructorCaster)(L##value)
#define String_Copy(Obj) String(Obj->Value)
String *String_Constructor(wchar_t *Datas);

void String_Destructor(String **Obj);

#define StrStrToStr String *(*)(String *, String *)
#define StrLenToStr String *(*)(String *, Length)
#define StrStrToSry StringAry *(*)(String *, String *)
#define StrStrToVid void (*)(String *, String *)
#define StrStrToInt int (*)(String *, String *)
#define StrCmp int (*)(String *, Stirng *)

String *String_Join(String *Obj1, String *Obj2);
void String_Append(String *Obj1, String *Obj2);
String *String_SubString(String *Obj1, String *Obj2);
String *String_Loop(String *Obj1, Length Length);
StringAry *String_Split(String *Obj1, String *Obj2);
bool String_Compare(String *Obj1, String *Obj2);
String *String_Trim(String *Obj);
bool String_Contains(String *Obj, String *Find);
Length *String_Count(String *Obj, String *Find);
wchar_t *String_Get(String *Obj);
void String_Set(String *Obj1, String *Obj2);
Length *String_GetLength(String *Obj);

String *String_ToLower(String *Obj1);
String *String_ToUpper(String *Obj1);
bool String_IsNone(String *Obj1);
Index String_IndexOf(String *Obj, String *Find);
Index String_LastOfIndex(String *Obj, String *Find);
String *String_Replace(String *Obj, String *Find, String *Obj2);
String *String_ReplaceFor(String *Obj, String *Find, String *Obj2,
                          Length Count);
String *String_ReplaceAll(String *Obj, String *Find, String *Obj2);
String *String_Left(String *Obj, Length Count);
String *String_Right(String *Obj, Length Count);
String *String_Middle(String *Obj, Index Start, Index End);

#ifndef __NLB_STRINGLIBARY__
#define __NLB_STRINGLIBARY__
String *Format(String *Format, ...);
#define String_ToString(DataType, Instance) String_ToString_##DataType(Instance)
String *String_ToString_bool(bool Value);
String *String_ToString_ld(long Value);
String *String_ToString_lld(long long Value);
String *String_ToString_f(float Value);
String *String_ToString_lf(double Value);
String *String_ToString_Chs(char *Value);
bool String_ValueOf_bool(String *str);
long String_ValueOf_ld(String *str);
long long String_ValueOf_lld(String *str);
float String_ValueOf_f(String *str);
double String_ValueOf_lf(String *str);
char *String_ValueOf_Chs(String *str);
wchar_t *String_ValueOf_Wcs(String *str);

#ifndef __NLB_STRINGNIO__
#define __NLB_STRINGNIO__

void Input(FILE *InputBuffer, const char *format, ...);
void Output(FILE *OutPutBuffer, const char *format, ...);

void Print(Length length, ...);
void Println(Length length, ...);
String Scan();
String ScanLine();

/*
  Output
  Input

  FileInput
  FileOutput

  NetworkInput
  NetworkOutput
 */

#endif
#endif
#endif