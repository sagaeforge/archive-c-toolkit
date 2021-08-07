
#include "DMem.h"
#include "__DMem.h"

DM_Manager DM_Mgr = NULL;

void DynamicMemory_Manager()
{
    if(DM_Mgr != NULL)
        return;
    
    DM_Mgr = (DM_Manager) malloc(sizeof(struct Struct_DMManager));
#ifdef DEBUG
    DM_Mgr->logs = NULL;
    SaveLogs(FLAG_Alloc, DM_Mgr, "Manager");
#endif // DEBUG

    if(DM_Mgr == NULL)
        return;
    
    DM_Mgr->memoryPageCount = 0;
    DM_Mgr->totalMemoryCount = 0;
    DM_Mgr->start = NULL;
    DM_Mgr->last = NULL;
}