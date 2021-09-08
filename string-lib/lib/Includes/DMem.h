
#ifndef __NUGUNGA_DMEM_HEADER__
#define __NUGUNGA_DMEM_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "DMemType.h"

/** 메모리 할당후 반환
 * @brief <MemAlloc> 힙 메모리를 할당합니다.
 * 
 * @param size 할당할 메모리 크기
 * @return void* 할당된 메모리 위치
 */
void* SimpleAlloc(size_t size);
/** 메모리 할당 검사 후 반환
 * @brief <MemAlloc> 힙 메모리를 할당합니다.
 * 
 * @param size 할당할 메모리 크기 
 * @param ref 할당된 메모리 위치
 * @return <true/false> 메모리 할당 여부
 */
bool MemoryAlloc(size_t size, void **ref);
/** 메모리 반환
 * @brief <MemFree> 힙 메모리를 반환합니다.
 * 
 * @param ptr 할당된 메모리 위치
 */
void MemoryFree(void *ptr);
/** 파일 열기
 * @brief <MemAlloc> 힙 메모리에 파일을 할당합니다.
 * 
 * @param path 파일 위치
 * @param mode 파일 열기 모드
 * @return FILE* 해당 파일 위치
 */
FILE* File_Open(const char *path, const char *mode);
/** 파일 닫기
 * @brief <MemFree> 힙 메모리에 할당된 파일을 반환합니다.
 * 
 * @param file 반환할 파일 위치
 */
void File_Close(FILE* file);
/**
 * @brief 동적 메모리 전체 해제
 */
void DynamicMemory_AllFrees();

#endif // !__NUGUNGA_DMEM_HEADER__