#include <stdio.h>
#include "GC.h"

int main(int argc, char const *argv[])
{
    printf("Test World\n");
    printf("%lu\n", sizeof(struct GCManagerPageStruct));
    MemoryCreate(12);
    return 0;
}
