
#include "ProgramManager.h"
#include <stdio.h>

void test() { printf("test1\n"); }
void test1() { printf("test1\n"); }
void test2() { printf("test2\n"); }
void test3() { printf("test3\n"); }

int main(int argc, char const *argv[]) {
  FuncChain_Setting(&Init);
  Init.AddListener(&Init, test1);
  Init.AddListener(&Init, test2);
  Init.AddListener(&Init, test3);
  Init.RemoveListener(&Init, test);
  Init.Invoke(&Init);

  // return 0;
}
