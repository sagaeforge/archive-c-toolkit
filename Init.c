
#include "GarbageCollection.h"
#include "Operator.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void Init() { setlocale(LC_ALL, ""); }

int main(int argc, char const *argv[]) {
  Init();

  String *str = Create(String, StringConstructorCaster)(L"가나다");

  printf("%S\n", str->Values);
  printf("%u\n", str->Length);
  GC_Clean();
  return 0;
}
