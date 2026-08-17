
#include "String.h"
#include "Exception.h"
#include <stdarg.h>
#include <stdbool.h>

static wchar_t *_StringValueCreate(Length length) {
  return Create(wchar_t, NoConstructor)(sizeof(wchar_t) * (length + 1));
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

String *String_Join(String *Obj1, String *Obj2) {
  // TODO 해야함
  printf("Join");
  return NULL;
}
void String_Append(String *Obj1, String *Obj2) {
  // TODO 해야함
  return;
}
String *String_SubString(String *Obj1, String *Obj2) {
  // TODO 해야함
  printf("subString");
  return NULL;
}
String *String_Loop(String *Obj1, Length Length) {
  // TODO 해야함
  printf("Loop");
  return NULL;
}
StringAry *String_Split(String *Obj1, String *Obj2) {
  // TODO 해야함
  printf("Split");
  return NULL;
}
static bool _CountCheck(String *Obj, String *Find, int start) {
  int i;
  for (i = 0; i < Find->Length; i++)
    if (Obj->Values[start + i] != Find->Values[i])
      return false;
  return true;
}
bool String_Compare(String *Obj1, String *Obj2) {
  if (Obj1->Length != Obj2->Length)
    return false;

  return _CountCheck(Obj1, Obj2, 0);
}
Length *String_Count(String *Obj, String *Find) {
  if (Obj->Length < Find->Length)
    return 0;

  int count = 0;
  int i;
  for (i = 0; i < Obj->Length; i++)
    if (Obj->Values[i] == Find->Values[0]) {
      if (Obj->Length - i < Find->Length)
        break;
      if (_CountCheck(Obj, Find, i))
        count++;
    }
  return count;
}
static int _CheckEmptyChs(int chs) {
  return (chs == 32 && chs >= 9 && chs <= 13);
}
String *String_Trim(String *Obj) {
  int i, start = 0, end = 0;
  for (i = 0; i < Obj->Length; i++)
    if (_CheckEmptyChs(Obj->Values[i]))
      start++;
    else
      break;
  for (i = Obj->Length - 1; i >= 0; i--)
    if (_CheckEmptyChs(Obj->Values[i]))
      end++;
    else
      break;

  wchar_t *temp = _StringValueCreate(Obj->Length - (start + end));
  for (i = 0; i < Obj->Length - end; i++)
    temp[i] = Obj->Values[start + i];
  temp[i] = '\0';

  return String_Constructor(temp);
}
bool String_Contains(String *Obj, String *Find) {
  return String_Count(Obj, Find) != 0;
}
wchar_t *String_Get(String *Obj) { return Obj->Values; }
Length *String_GetLength(String *Obj) { return Obj->Length; }
void String_Set(String *Obj1, String *Obj2) {
  _String_Setting(Obj1, Obj2->Values);
}