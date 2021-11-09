
#include "Operator.h"
#include <stdio.h>
#include <stdlib.h>

struct a {
  bool b;
};

int main(int argc, char const *argv[]) {
  struct a A = {20};

  int a;
  unsigned int b;

  printf("%s\n", TypeCompare(a, b) ? "같습니다." : "틀립니다.");
  return 0;
}
