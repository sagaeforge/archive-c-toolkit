
#include "DMem.h"
#include "__DMem.h"

void DynamicMemory_remove(void *ptr)
{
    int i, j;
    struct DMemPageNode *thispage = DM_Mgr->start;
    for (i = 0; i < DM_Mgr->memoryPageCount; i++)
    {
        for (j = 0; j < PageElementCount; j++)
            if (thispage->values[j].value == ptr)
            {
                thispage->values[j].dataType = true;
                thispage->values[j].value = NULL;
                thispage->count--;
                DM_Mgr->totalMemoryCount--;
                return;
            }
        thispage = thispage->next;
    }
}