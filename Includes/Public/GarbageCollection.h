
#ifndef __GARBAGECOLLECTION_PUBLIC__
#define __GARBAGECOLLECTION_PUBLIC__

#ifndef __GCType__
#define __GCType__
#include <stdbool.h>
typedef unsigned int Index;
typedef unsigned int Length;
typedef void * MemoryPosition;
#endif

// 메모리 생성
void *  MemoryCreate  (Length Length);
// 메모리 소멸
void    MemoryRemove  (MemoryPosition *Position);
// 메모리 설정
void    MemorySet     (MemoryPosition Src, int Value, Length WordSize, Length Length);
// 메모리 복사 - 속도 중심
void    MemoryCopy    (MemoryPosition Src, MemoryPosition Value, Length Length);
// 메모리 복사 - 안전 중심
void    MemoryMove    (MemoryPosition Src, MemoryPosition Value, Length Length);
// 메모리 비교
bool    MemoryCompare (MemoryPosition Src, MemoryPosition Obj, Length Length);
// 메모리 크기
Length  MemoryLength  (MemoryPosition Src);

// Src 메모리를 GC에서 생성하였는가?
bool    GC_MemoryCheck(MemoryPosition Src);
// GC 초기화
void    GC_Init       ();
// GC 프로그램 종료
void    GC_ProgramExit();

#endif