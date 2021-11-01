
#ifndef __NLB_GARBAGECOLLECTION_FUNCS
#define __NLB_GARBAGECOLLECTION_FUNCS

#ifndef __LENGTH
#define __LENGTH
typedef unsigned int Length;
#endif

typedef struct GCFuncNode {
  char *DataType;
  void *(*Constructor)(void);
  void (*Destructor)(void **);
  struct GCFuncNode *next;
} FuncsNode;

#define Create(DataType, Casting)                                              \
  (DataType *)((Casting)Constructor_Search(#DataType))
void *(*Constructor_Search(char *DataType, Length Length))(void);

#define Remove(DataType, Instance) Destructor_Search(#DataType)(Instance);
void (*Destructor_Search(char *DataType))(void **);

#define NoCasting void *

#endif