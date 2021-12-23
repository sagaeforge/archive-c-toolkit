#ifndef __EXCEPTION__
#define __EXCEPTION__

#include <stdio.h>
#include <string.h>

#define Warning(format, args...)                                               \
  do {                                                                         \
    char *FormatAry = malloc(strlen(format) + 16);                             \
    strcat(FormatAry, "Warning >>> ");                                         \
    strcat(FormatAry, format);                                                 \
    strcat(FormatAry, "\n");                                                   \
    fprintf(stderr, format, ##args);                                           \
    free(FormatAry);                                                           \
  } while (0)

#define Error(format, args...)                                                 \
  do {                                                                         \
    char *FormatAry = malloc(strlen(format) + 15);                             \
    strcat(FormatAry, "Error >>> ");                                           \
    strcat(FormatAry, format);                                                 \
    strcat(FormatAry, "\n");                                                   \
    fprintf(stderr, format, ##args);                                           \
    free(FormatAry);                                                           \
    exit(1);                                                                   \
  } while (0)

#endif