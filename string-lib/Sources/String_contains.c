
#include "String.h"

bool String_contains(const String obj, const String pivot)
{
    return String_count(obj, pivot) > 0 ? true : false;
}