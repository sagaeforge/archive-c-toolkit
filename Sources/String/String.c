
#include <stdbool.h>
#include "String.h"
#include "Exception.h"

static wchar_t *_StringValueCreate(Length length)
{
  return Create(wchar_t, NoConstructor)(sizeof(wchar_t) * length + 1);
}

static Length _String_Length(wchar_t *Datas) {
  int i = 0;
  while (Datas[i] != '\0')
    i++;
  return i;
}

static void _String_Setting(String *obj, wchar_t *Datas) {
  obj->Length = _String_Length(Datas);
  if (obj->Values != NULL)
    Remove(wchar_t, obj->Values);
  wchar_t *temp = _StringValueCreate(obj->Length);

  if (temp == NULL) {
    Warning("값을 설정하지 못했습니다.");
    return;
  }

  int i = 0;
  for (i = 0; i < obj->Length; i++)
    temp[i] = Datas[i];
  temp[i] = '\0';
  obj->Values = temp;
}

String *String_Constructor(wchar_t *Datas) {
  void *ptr = Create(void *, NoConstructor)(sizeof(String));
  if (ptr == NULL) {
    Warning("문자열 객체를 생성하지 못했습니다.");
    return NULL;
  }

  String *obj = (String *)ptr;
  _String_Setting(obj, Datas);
  return obj;
}

void String_Destructor(String **Obj) {
  free((*Obj)->Values);
  free((*Obj));

  if ((*Obj) != NULL)
    (*Obj) = NULL;
}

String *String_Join(String *Obj1, String *Obj2)
{
  //TODO 해야함
  printf("Join");
  return NULL;
}
void String_Append (String *Obj1, String *Obj2)
{
  //TODO 해야함
  return;
}
String *String_SubString (String *Obj1, String *Obj2)
{
  //TODO 해야함
  printf("subString");
  return NULL;
}
String *String_Loop (String *Obj1, Length Length)
{
  //TODO 해야함
  printf("Loop");
  return NULL;
}
StringAry *String_Split (String *Obj1, String *Obj2)
{
  //TODO 해야함
  printf("Split");
  return NULL;
}

bool String_Compare(String *Obj1, String *Obj2)
{
  if(Obj1->Length != Obj2->Length)
    return false;
  
  int i;
  for (size_t i = 0; i < Obj1->Length; i++)
    if(Obj1->Values[i] != Obj2->Values[i])
      return false;
  return true;
}