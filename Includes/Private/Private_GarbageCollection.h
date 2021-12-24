
#ifndef __PRIVATE_GARBAGECOLLECTION__
#define __PRIVATE_GARBAGECOLLECTION__

#include "ProgramManager.h"

void Clear();
void *Memory(MemoryPosition Position);
MemoryInfo Info(void *Obj);
void GC_Append(void *Obj, Length Length);
void GC_Remove(void *Obj);
bool GC_CreateCheck(void *Obj1, void *Obj2);

#endif