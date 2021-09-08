
#ifndef __NUGUNGA_DMEM_FUNC_HEADER__
#define __NUGUNGA_DMEM_FUNC_HEADER__

#include "DMem.h"
#include "DMemType.h"

#define FLAG_Alloc 0
#define FLAG_Free 1
#define FLAG_FILE 0
#define FLAG_PTR 1

extern DM_Manager DM_Mgr;

// 로그 파일 세이브
#ifdef DEBUG
void SaveLogs(int mode, void *ptr, const char *name);
void FileWriteDebugLog();
#endif // DEBUG

// 다이나믹 메모리 매니저 생성자
void DynamicMemory_Manager();

// 다이나믹 메모리에 추가
void DynamicMemory_append(int mode, void *ptr);
void DynamicMemory_remove(void *ptr);

// 페이지 관련
struct DMemPageNode* DMemPage_Page();
void DMemPage_AllElementsFree(struct DMemPageNode* page);
void DMemPage_ElementFree(int mode, void *ptr);





#endif // !__NUGUNGA_DMEM_FUNC_HEADER__