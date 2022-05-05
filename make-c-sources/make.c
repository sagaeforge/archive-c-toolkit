#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *HeaderNames[] = {
  "ServerString.h"
};

const char *FileNames[] = {
  "String_Constructor_chs",
  "String_Constructor_wcs",
  "String_Destructor",
  "String_UTF8Decoder",
  "String_UTF8Encoder",
  "String_getChs",
  "String_getWcs",
  "String_setChs",
  "String_setWcs",
  "String_setStr",
  "String_Compare",
  "String_CompareOption",
  "String_toUpper",
  "String_toLower",
  "String_isUpper",
  "String_isLower",
  "String_Extract",
  "String_Reverse",
  "String_Left",
  "String_Right",
  "String_Middle",
  "String_Trim",
  "String_Join",
  "String_Append",
  "String_SubString",
  "String_Format",
  "String_Pattern",
  "Console_Print",
  "Console_Printf",
  "Console_Println",
  "Console_ErrPrint",
  "Console_ErrPrintf",
  "Console_ErrPrintln",
  "StringAry_Constructor",
  "StringAry_Destructor",
  "StringAry_Clear",
  "StringAry_get",
  "StringAry_set",
  "StringAry_Insert",
  "StringAry_Remove",
  "StringAry_Push",
  "StringAry_Pop",
  "StringAry_Peak",
  "StringAry_Search",
  "StringAry_Contains",
  "StringAry_Length",
};

const char *Funcs[] = {
  "string_t*       String_Constructor_chs  (const chs_t Value)",
  "string_t*       String_Constructor_wcs  (const wcs_t Value)",
  "bool            String_Destructor       (string_t **Value)",
  "chs_t           String_UTF8Decoder      (const wcs_t Value, int *Size)",
  "wcs_t           String_UTF8Encoder      (const chs_t Value, int *Size)",
  "chs_t           String_getChs           (const string_t* Self)",
  "wcs_t           String_getWcs           (const string_t* Self)",
  "bool            String_setChs           (      string_t* Self, const chs_t Data)",
  "bool            String_setWcs           (      string_t* Self, const wcs_t Data)",
  "bool            String_setStr           (      string_t* Self, const string_t* Data)",
  "bool            String_Compare          (const string_t* Self, const string_t* Target)",
  "int             String_CompareOption    (const string_t* Self, const string_t* Target, const int Flag)",
  "string_t*       String_toUpper          (const string_t* Self)",
  "string_t*       String_toLower          (const string_t* Self)",
  "bool            String_isUpper          (const string_t* Self)",
  "bool            String_isLower          (const string_t* Self)",
  "string_t*       String_Extract          (const string_t* Self, const int Start, const uint32_t Length)",
  "string_t*       String_Reverse          (const string_t* Self)",
  "string_t*       String_Left             (const string_t* Self, const uint32_t Length)",
  "string_t*       String_Right            (const string_t* Self, const uint32_t Length)",
  "string_t*       String_Middle           (const string_t* Self, const int Start, const int Last)",
  "string_t*       String_Trim             (const string_t* Self)",
  "string_t*       String_Join             (const string_t* Self, const string_t* Target)",
  "string_t*       String_Append           (      string_t* Self, const string_t* Target)",
  "string_t*       String_SubString        (const string_t* Self, const string_t* KeyWord)",
  "string_t*       String_Format           (const string_t* Format, ...)",
  "bool            String_Pattern          (const string_t* Self, const string_t* KeyWord)",
  "string_t*       Console_Print           (const string_t* Self)",
  "string_t*       Console_Printf          (const string_t* Format, ...)",
  "string_t*       Console_Println         (const string_t* Self)",
  "string_t*       Console_ErrPrint        (const string_t* Self)",
  "string_t*       Console_ErrPrintf       (const string_t* Format, ...)",
  "string_t*       Console_ErrPrintln      (const string_t* Self)",
  "stringAry_t*    StringAry_Constructor   (const int Count, ...)",
  "bool            StringAry_Destructor    (      stringAry_t** Self)",
  "bool            StringAry_Clear         (      stringAry_t*  Self)",
  "stringAry_t*    StringAry_get           (const stringAry_t*  Self, const uint32_t Index)",
  "bool            StringAry_set           (const stringAry_t*  Self, const uint32_t Index, const string_t* Value)",
  "bool            StringAry_Insert        (      stringAry_t*  Self, const string_t* Value, const uint32_t Index)",
  "bool            StringAry_Remove        (      stringAry_t*  Self, const uint32_t Index)",
  "bool            StringAry_Push          (      stringAry_t*  Self, const string_t* Value)",
  "stringAry_t*    StringAry_Pop           (      stringAry_t*  Self)",
  "stringAry_t*    StringAry_Peak          (const stringAry_t*  Self)",
  "int             StringAry_Search        (const stringAry_t*  Self, const string_t* Value)",
  "bool            StringAry_Contains      (const stringAry_t*  Self, const string_t* Value)",
  "uint32_t        StringAry_Length        (const stringAry_t*  Self)",
};           

const char *PATH = "./output/";

int main(int argc, char const *argv[])
{
  size_t s = sizeof(FileNames) / sizeof(char *);
  size_t h = sizeof(HeaderNames) / sizeof(int *);

  int i, j;
  for (i = 0; i < s; i++)
  {
    char path[512];
    for (j = 0; j < 512; j++)
        path[j] = '\0';

    strcat(path, PATH);
    strcat(path, FileNames[i]);
    strcat(path, ".c");

    FILE *f = fopen(path, "w+");
    if(f == NULL)
    {
      perror("fopen");
      return 0;
    }

    fprintf(f, "\n");
    for (j = 0; j < h; j++)
      fprintf(f, "#include <%s>", HeaderNames[j]);
    fprintf(f, "\n");
    fprintf(f, "\n");

    fprintf(f, "%s {}", Funcs[i]);

    fclose(f);
  }
  return 0;
}
