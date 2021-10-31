
#include "Tuple.h"
#include <stdio.h>
#include <stdlib.h>

Tuple _Tuple2(Length a1, void *data1, Length a2, void *data2) {
  Tuple temp1 = (Tuple)malloc(sizeof(struct Struct_Tuple));
  char *temp2 = malloc(a1 + a2);
  unsigned char *temp3 = malloc(2);
  if (!temp1 || !temp2 || !temp3) {
    printf("튜플을 생성하지 못했습니다.");
    free(temp1);
    free(temp2);
    free(temp3);
    return NULL;
  }

  temp1->TupleType = 2;
  temp1->Datas = temp2;
  temp1->WordSize = temp3;

  // 데이터 삽입

  int iterator = 0;
  while (iterator < a1 + a2) {
    if (iterator < a1) {
      temp1->Datas[iterator] = *((char *)data1) + iterator;
    } else {
      temp1->Datas[iterator] = *((char *)data2) + iterator - a1;
    }
    iterator++;
  }

  temp1->WordSize[0] = a1;
  temp1->WordSize[1] = a2;

  return temp1;
}

void RemoveTuple(Tuple tuple) {
  free(tuple->Datas);
  free(tuple->WordSize);
  free(tuple);
}