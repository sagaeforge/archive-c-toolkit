
#include "ProgramManager.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  ProgramManager_Init();
  printf("%d", Program.Exception.ErrorCode.i);
  return 0;
}
