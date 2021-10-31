
#include "Tuple.h"
#include <stdio.h>

void _Tuple_Get2(Tuple2 tuple, void *variable[2]) {
  int i = 0;
  while (i < 2) {
    switch (tuple.Values[i].WordSize) {
    case 1:
      *((char *)variable[i]) = (char)tuple.Values[i].Value;
      break;
    case 2:
      *((short *)variable[i]) = (short)tuple.Values[i].Value;
      break;
    case 4:
      *((float *)variable[i]) = (float)tuple.Values[i].Value;
      break;
    case 8:
      *((int64 *)variable[i]) = tuple.Values[i].Value;
      break;
    }
    i++;
  }
}

void _Tuple_Get3(Tuple3 tuple, void *variable[3]) {
  int i = 0;
  while (i < 3) {
    switch (tuple.Values[i].WordSize) {
    case 1:
      *((char *)variable[i]) = (char)tuple.Values[i].Value;
      break;
    case 2:
      *((short *)variable[i]) = (short)tuple.Values[i].Value;
      break;
    case 4:
      *((float *)variable[i]) = (float)tuple.Values[i].Value;
      break;
    case 8:
      *((int64 *)variable[i]) = tuple.Values[i].Value;
      break;
    }
    i++;
  }
}

void _Tuple_Get4(Tuple4 tuple, void *variable[4]) {
  int i = 0;
  while (i < 4) {
    switch (tuple.Values[i].WordSize) {
    case 1:
      *((char *)variable[i]) = (char)tuple.Values[i].Value;
      break;
    case 2:
      *((short *)variable[i]) = (short)tuple.Values[i].Value;
      break;
    case 4:
      *((float *)variable[i]) = (float)tuple.Values[i].Value;
      break;
    case 8:
      *((int64 *)variable[i]) = tuple.Values[i].Value;
      break;
    }
    i++;
  }
}