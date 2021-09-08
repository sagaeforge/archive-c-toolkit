
#ifndef __NUGUNGA_STRINGARY_HEADER__
#define __NUGUNGA_STRINGARY_HEADER__

#include "StringType.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


StringAry StringAry_StringAry();
void StringAry_Free(StringAry ary);
StringAry StringAry_get(uint index);
StringAry StringAry_set(uint index, String value);
StringAry StringAry_append(uint index, String value);
StringAry StringAry_remove(uint index, String value);


#endif