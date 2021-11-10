
#include "Operator.h"
#include "String.h"

Length OperatorTableLength = 0;
Operator OperatorTable[] = {

};

Length FuncNodeTableLength = 1;
FuncNode FuncNodeTable[] = {{"String", (NoMethod)String_Constructor,
                             (void (*)(void **))String_Destructor}};