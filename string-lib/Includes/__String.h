
#ifndef __NUGUNGA_PRIVATE_STRING_HEADER__
#define __NUGUNGA_PRIVATE_STRING_HEADER__

#include <stdlib.h>
#include <stdio.h>
#include "String.h"

// ! 내부 처리에서 사용하는 함수들


// * 글자 수 세기
uint __chrlen(const char *data);
uint __wcslen(const wchar_t *data);

// * 글자 대입
void __wcsAssign_chr(wchar_t *obj, const char *data, uint length);
void __wcsAssign_wcs(wchar_t *obj, const wchar_t *data, uint length);

// 자동으로 length 구해서 메모리 할당
wchar_t *__StringMemoryAlloc(size_t length);
bool __String_Check(wchar_t *ary, String find, uint start);

#endif // !__NUGUNGA_PRIVATE_STRING_HEADER__