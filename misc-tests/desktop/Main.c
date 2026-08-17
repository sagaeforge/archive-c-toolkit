
#include <stdio.h>
#include <string.h>

char* Name[] = { "Object_Boxing_Char.c",
                 "Object_Boxing_U_Char.c",
                 "Object_Boxing_Short.c",
                 "Object_Boxing_U_Short.c",
                 "Object_Boxing_Int.c",
                 "Object_Boxing_U_Int.c",
                 "Object_Boxing_Long.c",
                 "Object_Boxing_U_Long.c",
                 "Object_Boxing_LongLong.c",
                 "Object_Boxing_U_LongLong.c",
                 "Object_Boxing_Float.c",
                 "Object_Boxing_Double.c",
                 "Object_Boxing_Ptr_Char.c",
                 "Object_Boxing_Double_Ptr_Char.c",
                 "Object_Boxing_Ptr_U_Char.c",
                 "Object_Boxing_Double_Ptr_U_Char.c",
                 "Object_Boxing_Ptr_Short.c",
                 "Object_Boxing_Double_Ptr_Short.c",
                 "Object_Boxing_Ptr_U_Short.c",
                 "Object_Boxing_Double_Ptr_U_Short.c",
                 "Object_Boxing_Ptr_Int.c",
                 "Object_Boxing_Double_Ptr_Int.c",
                 "Object_Boxing_Ptr_U_Int.c",
                 "Object_Boxing_Double_Ptr_U_Int.c",
                 "Object_Boxing_Ptr_Long.c",
                 "Object_Boxing_Double_Ptr_Long.c",
                 "Object_Boxing_Ptr_U_Long.c",
                 "Object_Boxing_Double_Ptr_U_Long.c",
                 "Object_Boxing_Ptr_Long_Long.c",
                 "Object_Boxing_Double_Ptr_Long_Long.c",
                 "Object_Boxing_Ptr_U_Long_Long.c",
                 "Object_Boxing_Double_Ptr_U_Long_Long.c",
                 "Object_Boxing_Ptr_Float.c",
                 "Object_Boxing_Double_Ptr_Float.c",
                 "Object_Boxing_Ptr_Double.c",
                 "Object_Boxing_Double_Ptr_Double.c",
                 "Object_Boxing_Ptr_Void.c",
                 "Object_Boxing_Double_Ptr_Void.c",
                 "Object_Boxing_Triple_Ptr_Void.c",
                 "Object_Boxing_Bool.c",
                 "Object_UnBoxing_Char.c",
                 "Object_UnBoxing_U_Char.c",
                 "Object_UnBoxing_Short.c",
                 "Object_UnBoxing_U_Short.c",
                 "Object_UnBoxing_Int.c",
                 "Object_UnBoxing_U_Int.c",
                 "Object_UnBoxing_Long.c",
                 "Object_UnBoxing_U_Long.c",
                 "Object_UnBoxing_LongLong.c",
                 "Object_UnBoxing_U_LongLong.c",
                 "Object_UnBoxing_Float.c",
                 "Object_UnBoxing_Double.c",
                 "Object_UnBoxing_Ptr_Char.c",
                 "Object_UnBoxing_Double_Ptr_Char.c",
                 "Object_UnBoxing_Ptr_U_Char.c",
                 "Object_UnBoxing_Double_Ptr_U_Char.c",
                 "Object_UnBoxing_Ptr_Short.c",
                 "Object_UnBoxing_Double_Ptr_Short.c",
                 "Object_UnBoxing_Ptr_U_Short.c",
                 "Object_UnBoxing_Double_Ptr_U_Short.c",
                 "Object_UnBoxing_Ptr_Int.c",
                 "Object_UnBoxing_Double_Ptr_Int.c",
                 "Object_UnBoxing_Ptr_U_Int.c",
                 "Object_UnBoxing_Double_Ptr_U_Int.c",
                 "Object_UnBoxing_Ptr_Long.c",
                 "Object_UnBoxing_Double_Ptr_Long.c",
                 "Object_UnBoxing_Ptr_U_Long.c",
                 "Object_UnBoxing_Double_Ptr_U_Long.c",
                 "Object_UnBoxing_Ptr_Long_Long.c",
                 "Object_UnBoxing_Double_Ptr_Long_Long.c",
                 "Object_UnBoxing_Ptr_U_Long_Long.c",
                 "Object_UnBoxing_Double_Ptr_U_Long_Long.c",
                 "Object_UnBoxing_Ptr_Float.c",
                 "Object_UnBoxing_Double_Ptr_Float.c",
                 "Object_UnBoxing_Ptr_Double.c",
                 "Object_UnBoxing_Double_Ptr_Double.c",
                 "Object_UnBoxing_Ptr_Void.c",
                 "Object_UnBoxing_Double_Ptr_Void.c",
                 "Object_UnBoxing_Triple_Ptr_Void.c",
                 "Object_UnBoxing_Bool.c" };

const char* Content[] = {
  "",
  "#include \"Object.h\"",
  "#include \"Private_GarbageCollection.h\"",
  "",
};

const char FilePath[] = "/home/nugunga/Project/test/Export/";

int
main(int argc, char const* argv[])
{
  int i;
  for (i = 0; i < 80; i++) {
    char NameBuffer[200] = {
      0,
    };
    strcat(NameBuffer, FilePath);
    strcat(NameBuffer, Name[i]);
    FILE* fp = fopen(NameBuffer, "w+");
    int j;
    for (j = 0; j < 4; j++) {
      fputs(Content[j], fp);
      fputs("\n", fp);
    }
    fclose(fp);
  }

  return 0;
}
