
#include "_GarbageCollection.h"

void GC_Init() {
  if (__Manager__ == NULL)
    GC_ManagerInit();
  // 각종 초기화 함수를 호출
}