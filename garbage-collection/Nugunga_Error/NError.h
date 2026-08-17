
#ifndef __NLB_ERROR
#define __NLB_ERROR

#include <stdlib.h>

#define Error(format, ...)                                                     \
  do {                                                                         \
    fprintf(stderr, format, ##__VA_ARGS__);                                    \
    exit(-1);                                                                  \
  } while (0)

#define Warning(format, ...) fprintf(stderr, format, ##__VA_ARGS__)

#endif