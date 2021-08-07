
#include "DMem.h"
#include "__DMem.h"

void DynamicMemory_append(int mode, void *ptr)
{
    if(DM_Mgr == NULL)
        DynamicMemory_Manager();

    // TODO 페이지가 없을 경우
    struct DMemPageNode *page;
    if(DM_Mgr->start == NULL)
    {
        page = DMemPage_Page();
        
        page->values[0].dataType = mode;
        page->values[0].value = ptr;
        page->count = 1;

        DM_Mgr->memoryPageCount = 1;
        DM_Mgr->totalMemoryCount = 1;
        DM_Mgr->start = page;
        DM_Mgr->last = page;
        return;
    }

    // TODO 페이지가 있는 경우
    int i, j;
    struct DMemPageNode *thispage = DM_Mgr->last;
    for (j = 0; j < PageElementCount; j++)
        if (thispage->values[j].value == NULL)
        {
            thispage->values[j].dataType = mode;
            thispage->values[j].value = ptr;
            thispage->count++;
            DM_Mgr->totalMemoryCount++;
            return;
        }
    
    // TODO 페이지가 여유가 없는 경우
    thispage = DM_Mgr->last;
    page = DMemPage_Page();
    thispage->next = page;

    page->values[0].dataType = mode;
    page->values[0].value = ptr;
    page->count = 1;

    DM_Mgr->last = page;
    DM_Mgr->memoryPageCount++;
    DM_Mgr->totalMemoryCount++;
}