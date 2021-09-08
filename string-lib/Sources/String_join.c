
#include "String.h"
#include "__String.h"

String String_join(const String obj, const String data)
{
    uint length = obj->length + data->length;
    wchar_t *ptr = __StringMemoryAlloc(length);
    if(ptr == NULL)
        return String_Constructor_n();
    
    String temp = String_Constructor_n();
    temp->value = ptr;
    temp->length = length;

    // 문자열 대입
    uint pos = 0, pos2 = 0;
    while (pos < obj->length)
    {
        temp->value[pos] = obj->value[pos];
        pos++;
    }
    while (pos < length)
    {
        temp->value[pos] = data->value[pos2];
        pos++;
        pos2++;
    }
    temp->value[pos] = '\0';
    return temp;
}