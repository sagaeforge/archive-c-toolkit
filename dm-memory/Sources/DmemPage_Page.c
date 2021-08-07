
#include "DMem.h"
#include "__DMem.h"

struct DMemPageNode* DMemPage_Page()
{
    struct DMemPageNode *page = (struct DMemPageNode *) malloc(sizeof(struct DMemPageNode));
#ifdef DEBUG
    SaveLogs(FLAG_Alloc, page, "Page");
#endif // DEBUG
    
    page->count = 0;
    page->next = NULL;
    
    int i;
    for (i = 0; i < PageElementCount; i++)
    {
        page->values[i].dataType = true;
        page->values[i].value = NULL;
    }
    return page;
}