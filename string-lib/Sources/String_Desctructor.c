
#include "String.h"
#include "DMem.h"

void String_Desctructor(String obj)
{
    if(obj == NULL)
        return;
    
    MemoryFree(obj->value);
    obj->length = 0;
    obj->value = NULL;
    MemoryFree(obj);
}