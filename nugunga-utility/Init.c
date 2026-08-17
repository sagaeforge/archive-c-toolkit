
#include "GarbageCollection.h"
#include "Operator.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void Init() { setlocale(LC_ALL, ""); }

int main(int argc, char const *argv[]) {
  Init();

  // String *str1 = Create(String, StringConstructorCaster)(L"가나다라마바사");
  // String *str2 = Create(String, StringConstructorCaster)(L"ABCDEF1");

  // printf("%S\n", str1->Values);
  // printf("%u\n", str1->Length);
  
  // printf("%d\n", Operator2(str1, "==", str2, StrStrToInt));
  char *word = Create(char, NoConstructor)(12);
  

  GC_Clean();
  return 0;
}
