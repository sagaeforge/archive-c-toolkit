
#include "DMem.h"
#include "__DMem.h"

FILE* File_Open(const char *path, const char *mode)
{
    FILE *temp = fopen(path, mode);
    DynamicMemory_append(FLAG_FILE, temp);
#ifdef DEBUG
    SaveLogs(FLAG_Alloc, temp, "File");
#endif // DEBUG
    return temp;
}