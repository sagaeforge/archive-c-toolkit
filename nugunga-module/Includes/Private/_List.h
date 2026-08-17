
#ifndef __LIST_PRIVATE__
#define __LIST_PRIVATE__

typedef struct _Standard_Iterator {
  void *ListPool;
  void *_Start;
  void *_Last;

  void *Iterator;
  Index _Index;

  void (*Prev)();
  void (*Next)();
  void (*Set)(Index);
  Length (*Get)();
  void (*Start)();
  void (*Last)();
  bool (*IsStart)();
  bool (*IsLast)();
  void (*Foreach)(void (*)(void *));
} Standard_Iterator;

#endif