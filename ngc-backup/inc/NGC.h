#ifndef __NUGUNGA_LIBARY_GARBAGE_COLLECTION__
#define __NUGUNGA_LIBARY_GARBAGE_COLLECTION__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// * Public 함수

// + 메모리 할당자, 소멸자
bool MemoryAlloc(size_t size, void **Ref);
bool MemoryFree (void **Ref);

// * Private 함수

#define MemoryPageSize 512
#define GCManager struct StructGCManager *
#define MemoryPage struct StructGCPage *
#define MemoryPageIndex struct StructGCPageIndex

#define MemoryPageIndex_None 0 // 정해지지 않음.
#define MemoryPageIndex_First 1 // 첫번째 값
#define MemoryPageIndex_Last 2 // 마지막 값
#define MemoryPageIndex_BeforeLast 4 // 비어 있는 값
#define MemoryPageIndex_IsEmpty 8 // 비어 있는 값
#define MemoryPageIndex_NULL 16 // 찾는 값이 없음


typedef struct StructGCInsert
{
  void* (*Ref)  (void *);
  void  (*UnRef)(void *);

  bool (*Remove)(void *);
} GCInsert;


struct StructGCManager
{
  size_t MemoryLength;
  size_t PageLength;
  struct StructGCPage {
    unsigned short UseMemoryCount;
    struct {
      void *ptr;
      unsigned short RefCount;
    } Values[MemoryPageSize];
    struct StructGCPage *next;
  } Pages;
};

struct StructGCPageIndex {
  unsigned char Postion;
  unsigned int PageIndex:24;
  size_t AryIndex;
};

void *          GC_Ref(void *ptr); // 메모리 접근
void            GC_UnRef(void *ptr, GCInsert *gcinsert); // 메모리 접근 해제
void            GC_Init(); //  메모리 관리자 세팅
void            GC_Clean(); // 레퍼런스 카운트가 0인 메모리 삭제 비어있는 메모리 정렬까지함.
void            GC_Clear(); // 전체 메모리 삭제
void            MemoryPageElment_Append(void *ptr); // insert 정렬로 삽입함.
MemoryPageIndex MemoryPageElment_Find(void *ptr); // 이진탐색 트리로 탐색함.
void            MemoryPageElment_Remove(void *ptr); // 해당 주소에 있는 값을 삭제
void            MemoryPageElment_Remove_index(MemoryPageIndex index); // 해당 인덱스에 있는 값을 삭제함.
MemoryPage      MemoryPage_Get(MemoryPageIndex index); // 해당 페이지 가져오기
MemoryPage      MemoryPage_Append(); // 메모리 페이지 추가


extern GCManager __GCManager__;


#endif