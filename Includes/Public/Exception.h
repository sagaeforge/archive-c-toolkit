
#ifndef __NLB_EXCEPTION__
#define __NLB_EXCEPTION__

#include <stdio.h>
#include <string.h>

#define Warning(format, ...)                                                   \
  do {                                                                         \
    char *FormatAry = malloc(strlen(format) + 16);                             \
    strcat(FormatAry, "Warning >>> ");                                         \
    strcat(FormatAry, format);                                                 \
    strcat(FormatAry, "\n");                                                   \
    fprintf(stderr, format, ##__VA_ARGS__);                                    \
    free(FormatAry);                                                           \
  } while (0)

#define Error(format, ...)                                                     \
  do {                                                                         \
    char *FormatAry = malloc(strlen(format) + 15);                             \
    strcat(FormatAry, "Error >>> ");                                           \
    strcat(FormatAry, format);                                                 \
    strcat(FormatAry, "\n");                                                   \
    fprintf(stderr, format, ##__VA_ARGS__);                                    \
    free(FormatAry);                                                           \
    exit(1);                                                                   \
  } while (0)

#endif