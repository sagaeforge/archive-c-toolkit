#ifndef __NUGUNGA_LIBARY_GARBAGE_COLLECTION__
#define __NUGUNGA_LIBARY_GARBAGE_COLLECTION__

#include "GCDefines.h"
// 메모리 할당자
Memory  MemoryCreate(Length length);
// 메모리 소멸자
void    MemoryRemove(void **ptr);

// 메모리 관리자에게 안 사용하는 페이지를 삭제하고 정리함.
void    GC_Clear();
// 메모리 관리자에게 전체 페이지에 삭제 명령을 내림
void    GC_Clean();

#endif