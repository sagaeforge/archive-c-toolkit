
#include "String.h"
#include "Exception.h"
#include "Operator.h"

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
  wchar_t *temp =
      Create(wchar_t, NoConstructor)(sizeof(wchar_t) * (obj->Length + 1));
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