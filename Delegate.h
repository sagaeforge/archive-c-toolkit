#ifndef __DELEGATE__
#define __DELEGATE__

#include <stdarg.h>
#include <stdio.h>

#define Delegate(Ret, Name, args...)                                           \
  typedef Ret (*Delegate_##Name)(args);                                        \
  struct __DelegateChain_##Name {                                              \
    struct __DelegateChainNode_##Name {                                        \
      Delegate_##Name Method;                                                  \
      struct __DelegateChainNode_##Name *Next;                                 \
    } Nodes;                                                                   \
    void (*AddListener)(struct __DelegateChain_##Name *, Delegate_##Name);     \
    void (*RemoveListener)(struct __DelegateChain_##Name *, Delegate_##Name);  \
    void (*Invoke)(args);                                                      \
  };                                                                           \
  struct __DelegateChain_##Name Name;

// #define Action(Name, ...) typedef void (*Name)(##__VA_ARGS__)
#define Action(Name, args...)                                                  \
  typedef void (*Action_##Name)(args);                                         \
  struct __ActionChain_##Name {                                                \
    struct __ActionChainNode_##Name {                                          \
      Action_##Name Method;                                                    \
      struct __ActionChainNode_##Name *Next;                                   \
    } * Nodes;                                                                 \
    void (*AddListener)(struct __ActionChain_##Name *, Action_##Name);         \
    void (*RemoveListener)(struct __ActionChain_##Name *, Action_##Name);      \
    void (*RemoveAllListener)(struct __ActionChain_##Name *);                  \
    void (*Invoke)(args);                                                      \
  };                                                                           \
  struct __ActionChain_##Name Name;

#endif