
#include "GarbageCollection.h"
#include "Operator.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void Init() { setlocale(LC_ALL, ""); }

int main(int argc, char const *argv[]) {

  Init();

  String *str1 = String("가나다");
  String *str2 = String("가나다");

  printf("%S\n", str2->Values);
  printf("%u\n", str2->Length);

  printf("%d\n", Operator2(str1, "==", str2, StrStrToInt));

  GC_Clean();
  return 0;
}