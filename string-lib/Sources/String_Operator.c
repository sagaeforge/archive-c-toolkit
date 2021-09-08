
#include "String.h"

bool String_equal(const String obj1, const String obj2)
{
    if(obj1->length != obj2->length)
        return false;

    int i;
    for (i = 0; i < obj1->length; i++)
        if(obj1->value[i] != obj2->value[i])
            return false;
    return true;
}

bool String_notEqueal(const String obj1, const String obj2)
{
    return !String_equal(obj1, obj2);
}
