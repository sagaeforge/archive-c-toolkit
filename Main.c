
#include "ProgramManager.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

void test() { printf("init: test1\n"); }
void test1() { printf("start: test1\n"); }
void test2() { printf("awake: test2\n"); }
void test3() { printf("init : test3\n"); }
void test4() { printf("init : test4\n"); }
void test5() { printf("init : test5\n"); }
void test6() { printf("init : test6\n"); }
void test7() { printf("init : test7\n"); }
void test8() { printf("Quit : test8\n"); }

int main(int argc, char const *argv[]) {
  setlocale(LC_ALL, "");
  ProgramManager_Init();
  // Manager.Awake.AddListener(test2);
  // Manager.Init.AddListener(test);
  // Manager.Start.AddListener(test1);
  // Manager.Init.AddListener(test3);
  // Manager.Init.AddListener(test4);
  // Manager.Init.AddListener(test5);
  // Manager.Init.AddListener(test6);
  // Manager.Init.RemoveListener(test4);
  // Manager.Init.AddListener(test7);
  // Manager.Quit.AddListener(test8);
  // Manager.Method.ProgramStart();
  // Manager.Method.ProgramQuit();

  wchar_t *test = (wchar_t *)malloc(sizeof(wchar_t) * 10);
  if (test == NULL)
    return 0;
  Manager.GarbageCollection.Method.MemorySet(test, L'가', 4, 10);
  // test[9] = '\0';
  printf("%S", test);

  free(test);
  // return 0;
}
