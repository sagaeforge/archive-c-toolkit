
#include "DMem.h"
#include "__DMem.h"

void File_Close(FILE* file)
{
    if(file == NULL)
        return;
    
    DynamicMemory_remove(file);
#ifdef DEBUG
    SaveLogs(FLAG_Free, file, "File");
#endif // DEBUG
    fclose(file);
}