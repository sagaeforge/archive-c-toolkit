
#include "String.h"

bool String_isEmpty(const String obj)
{
    return obj->length == 0 ? true : false;
}