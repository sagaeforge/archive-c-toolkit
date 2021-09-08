
#include "String.h"
#include "__String.h"

String String_Constructor(const char *data)
{
    String temp = String_Constructor_n();
    uint length = __chrlen(data);

    temp->value = (wchar_t *) __StringMemoryAlloc(length);
    if(temp->value == NULL)
        return temp;
    temp->length = length;

    __wcsAssign_chr(temp->value, data, length);
    return temp;
}

String String_Constructor_n()
{
    void *ptr = NULL;
    if(!MemoryAlloc(sizeof(String_Value), &ptr))
        return NULL;
    String temp = (String) ptr;
    temp->value = L"";
    temp->length = 0;
    return temp;
}

String String_Constructor_wc(const wchar_t *data)
{
    String temp = String_Constructor_n();
    uint length = __wcslen(data);

    temp->value = (wchar_t *) __StringMemoryAlloc(length);
    if(temp->value == NULL)
        return temp;
    temp->length = length;

    __wcsAssign_wcs(temp->value, data, length);
    return temp;
}