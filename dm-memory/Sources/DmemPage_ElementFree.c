
#include "__DMem.h"

void DMemPage_ElementFree(int mode, void *ptr)
{
    DM_Mgr->totalMemoryCount--;
#ifdef DEBUG
    SaveLogs(FLAG_Free, ptr, mode == FLAG_PTR ? "Memory" : "File");
#endif // DEBUG
    if(mode == FLAG_PTR)
        free(ptr);
    else
        fclose((FILE *) ptr);
}