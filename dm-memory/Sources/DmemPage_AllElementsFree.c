
#include "__DMem.h"

void DMemPage_AllElementsFree(struct DMemPageNode* page)
{
    int i;
    for (i = 0; i < PageElementCount; i++)
        if(page->values[i].value != NULL)
        {
            DMemPage_ElementFree(page->values[i].dataType, page->values[i].value);
            page->values[i].dataType = true;
            page->values[i].value = NULL;
            page->count = 0;
        }
}