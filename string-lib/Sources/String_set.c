
#include "String.h"
#include "__String.h"

void String_set(String obj, const String data)
{
    String_set_wc(obj, data->value);
}

void String_set_c(String obj, const char *data)
{
    uint length = __chrlen(data);

    wchar_t *ptr = __StringMemoryAlloc(length);
    if(ptr == NULL)
        return;
    
    MemoryFree(obj->value);
    obj->value = ptr;
    __wcsAssign_chr(obj->value, data, length);
}

void String_set_wc(String obj, const wchar_t *data)
{
    uint length = __wcslen(data);

    wchar_t *ptr = __StringMemoryAlloc(length);
    if(ptr == NULL)
        return;
    
    MemoryFree(obj->value);
    obj->value = ptr;
    __wcsAssign_wcs(obj->value, data, length);
}