
#include "DMem.h"
#include "__DMem.h"

void* SimpleAlloc(size_t size)
{
    void *ptr = NULL;
    ptr = malloc(size);
    DynamicMemory_append(FLAG_PTR, ptr);
#ifdef DEBUG
    SaveLogs(FLAG_Alloc, ptr, "Memory");
#endif // DEBUG
    return ptr;
}