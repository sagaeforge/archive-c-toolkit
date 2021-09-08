
#include "String.h"

int String_index(const String obj, wchar_t chr)
{
    int i = 0;
    while (obj->value[i] != '\0')
        if(obj->value[i] == chr)
            return i;
        else
            i++;
    return -1;
}