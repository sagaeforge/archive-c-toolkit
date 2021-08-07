
#include "DMem.h"
#include "__DMem.h"

bool MemoryAlloc(size_t size, void **ref)
{
    void *ptr = SimpleAlloc(size);
    if(ptr == NULL)
    {
        (*ref) = NULL;
        return false;
    }
    (*ref) = ptr;
    return true;
}