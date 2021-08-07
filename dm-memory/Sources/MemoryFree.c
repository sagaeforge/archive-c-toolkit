
#include "DMem.h"
#include "__DMem.h"

void MemoryFree(void *ptr)
{
    if(ptr == NULL)
        return;
    
    DynamicMemory_remove(ptr);
    free(ptr);
#ifdef DEBUG
    SaveLogs(FLAG_Free, ptr, "Memory");
#endif // DEBUG
}