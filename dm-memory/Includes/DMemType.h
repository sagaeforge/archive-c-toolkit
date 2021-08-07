
#ifndef __NUGUNGA_DMEM_TYPE_HEADER__
#define __NUGUNGA_DMEM_TYPE_HEADER__

#define PageElementCount 8
#define LogElementCount 16

#define DEBUG

#include <stdio.h>
#include <stdbool.h>

#pragma pack(push, 1)
// * 동적 메모리 관리자
typedef struct Struct_DMManager
{
    // + memorypagecount(uint) : 전체 메모리 페이지 수
    unsigned int memoryPageCount;
    // + totalmemorycount(uint) : 전체 메모리 할당 수
    unsigned int totalMemoryCount;

    // + start, last(DMemPageNode *) : 동적 메모리 페이지 처음값, 마지막 값
    struct DMemPageNode
    {
        // + count(uint16) : 원소의 개수
        unsigned int count;
        // + values[index] : index 위치의 데이터가 존재하는 위치
        struct
        {
            // + dataType(short) : <memory_true : file_false> 여부
            bool dataType;
            
            void *value;
        } values[PageElementCount];
        // + next(DMemPageNode *) : 다음 페이지 위치
        struct DMemPageNode *next;
    } *start, *last;

    #ifdef DEBUG
    // + logs(LogsNode *) : Log 파일 저장용
    struct LogsNode
    {
        // + values[index] : index 위치의 로그 데이터
        struct
        {
            bool isAlloc;
            void *ptr;
            char *name;
        } values[LogElementCount];
        struct LogsNode *next;
    } *logs;
    #endif

} *DM_Manager;

#pragma pack(pop)







#endif // !__NUGUNGA_DMEM_TYPE_HEADER__