
#include "ProgramManager.h"
#include <stdio.h>

void test() { printf("init: test1\n"); }
void test1() { printf("start: test1\n"); }
void test2() { printf("awake: test2\n"); }
void test3() { printf("test3\n"); }

int main(int argc, char const *argv[]) {
  ProgramManager_Init();
  Manager.Awake.AddListener(test2);
  Manager.Init.AddListener(test);
  Manager.Start.AddListener(test1);
  Manager.Method.ProgramStart();
  Manager.Method.ProgramQuit();
  // return 0;
}
