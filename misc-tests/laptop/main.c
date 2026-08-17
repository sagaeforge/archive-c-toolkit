
#include <stdio.h>
#include <string.h>

// 파일 대신 생성해주는 함수

int
main(int argc, char const* argv[])
{
  const char* FileName[] = { "GarbageCollection_Append.c",
                             "GarbageCollection_Remove.c",
                             "GarbageCollection_Find.c",
                             "GarbageCollection_PageGet.c",
                             "GarbageCollection_EmptyPageGet.c" };
  const char Writer[] = "\n#include \"GarbageCollection.h\"\n#include "
                        "\"Private_GarbageCollection.h\"\n";

  char buf[200] = "";
  const char* Path = "/home/nugunga8086/Projects/test/Export/";

  int i, j;
  for (i = 0; i < 5; i++) {
    strcat(buf, Path);
    strcat(buf, FileName[i]);

    FILE* fp = fopen(buf, "w+");
    fputs(Writer, fp);
    fclose(fp);
    for (j = 0; j < 200; j++)
      buf[j] = '\0';
  }

  return 0;
}
