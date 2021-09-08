
#include "String.h"
#include "__String.h"


unsigned int String_count(const String obj, const String pivot)
{
    if(String_isEmpty(obj) || String_isEmpty(pivot))
        return 0;
    if(obj->length < pivot->length)
        return 0;
    
    uint i, total = 0;
    for (i = 0; i < obj->length; i++)
        if(obj->value[i] == pivot->value[0])
            if(__String_Check(obj->value, pivot, i))
                total++;
    return total;
}