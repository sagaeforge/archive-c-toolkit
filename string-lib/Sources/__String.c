
#include "__String.h"
#include "DMem.h"

// * 글자 수 세기
uint __chrlen(const char *data)
{
    uint length = 0;
    while (data[length] != '\0')
        length++;
    return length;
}
uint __wcslen(const wchar_t *data)
{
    uint length = 0;
    while (data[length] != L'\0')
        length++;
    return length;
}

// * 글자 대입
void __wcsAssign_chr(wchar_t *obj, const char *data, uint length)
{
    uint pos = 0;
    while (pos < length)
    {
        obj[pos] = data[pos];
        pos++;
    }
    obj[pos] = '\0';
}
void __wcsAssign_wcs(wchar_t *obj, const wchar_t *data, uint length)
{
    uint pos = 0;
    while (pos < length)
    {
        obj[pos] = data[pos];
        pos++;
    }
    obj[pos] = '\0';
}

// 자동으로 length 구해서 메모리 할당
wchar_t *__StringMemoryAlloc(size_t length)
{
    void *ptr = NULL;
    if(!MemoryAlloc(sizeof(wchar_t) * (length + 1), &ptr))
        return NULL;
    return (wchar_t *) ptr;
}

bool __String_Check(wchar_t *ary, String find, uint start)
{
    int i;
    for (i = start; i < find->length; i++)
        if(ary[i] != find->value[i - start])
            return false;
    return true;
}