
#include "Operator.h"
#include "String.h"

Length OperatorTableLength = 6;
Operator OperatorTable[] = {
  {"String *", "String *", "+", (NoMethod) String_Join},
  {"String *", "String *", "-", (NoMethod) String_SubString},
  {"String *", "unsigned int", "*", (NoMethod) String_Loop},
  {"String *", "String *", "/", (NoMethod) String_Split},
  {"String *", "String *", "+=", (NoMethod) String_Append},
  {"String *", "String *", "==", (NoMethod) String_Compare},
};

Length FuncNodeTableLength = 1;
FuncNode FuncNodeTable[] = {{"String", (NoMethod)String_Constructor,
                             (void (*)(void **))String_Destructor}};