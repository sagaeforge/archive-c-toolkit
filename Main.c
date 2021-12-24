#include "ProgramManager.h"
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

void Init() { setlocale(LC_ALL, ""); }

int main(int argc, char const *argv[]) {
  ProgramManager_Init();
  Manager.Awake.AddListener(Init);
  Manager.Method.ProgramStart();

  wchar_t *ary = (wchar_t *)Manager.GarbageCollection.Method.MemoryCreate(
      sizeof(wchar_t) * 10);
  Manager.GarbageCollection.Method.MemorySet(ary, L'가', 4, 9);
  ary[9] = '\0';
  printf("%S\n", ary);

  Manager.Method.ProgramQuit();
  return 0;
}
