
#include "Delegate.h"
#include <stdio.h>

Action(DelegateTest, int);
void t1(int);

int main(int argc, char const *argv[]) {
  DelegateTest.Invoke = t1;
  DelegateTest.Invoke(23);
  return 0;
}

void t1(int a) { printf("%d", a); }