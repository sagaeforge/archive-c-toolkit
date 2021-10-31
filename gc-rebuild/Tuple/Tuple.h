#ifndef __NLB_Tuple
#define __NLB_Tuple

typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int Length;

typedef struct Tuple2 {
  struct {
    Length WordSize;
    uint64 Value;
  } Values[2];
} Tuple2;

typedef struct Tuple3 {
  struct {
    Length WordSize;
    uint64 Value;
  } Values[3];
} Tuple3;

typedef struct Tuple4 {
  struct {
    Length WordSize;
    uint64 Value;
  } Values[4];
} Tuple4;

void _Tuple_Get2(Tuple2 tuple, void *variable[2]);
void _Tuple_Get3(Tuple3 tuple, void *variable[3]);
void _Tuple_Get4(Tuple4 tuple, void *variable[4]);

#define Tuple2(datatype1, value1, datatype2, value2)                           \
  { sizeof(datatype1), (uint64)value1, sizeof(datatype2), (uint64)value2 }

#define Tuple2_Get(tuple, ptr_var1, ptr_var2)                                  \
  void *Temp##tuple##ptr_var1##ptr_var2[2] = {&ptr_var1, &ptr_var2};           \
  _Tuple_Get2(tuple, Temp##tuple##ptr_var1##ptr_var2)

#define Tuple3(datatype1, value1, datatype2, value2, datatype3, value3)        \
  {                                                                            \
    sizeof(datatype1), (uint64)value1, sizeof(datatype2), (uint64)value2,      \
        sizeof(datatype3), (uint64)value3                                      \
  }

#define Tuple3_Get(tuple, ptr_var1, ptr_var2, ptr_var3)                        \
  void *Temp##tuple##ptr_var1##ptr_var2##ptr_var3[3] = {&ptr_var1, &ptr_var2,  \
                                                        &ptr_var3};            \
  _Tuple_Get3(tuple, Temp##tuple##ptr_var1##ptr_var2##ptr_var3)

#define Tuple4(datatype1, value1, datatype2, value2, datatype3, value3,        \
               datatype4, value4)                                              \
  {                                                                            \
    sizeof(datatype1), (uint64)value1, sizeof(datatype2), (uint64)value2,      \
        sizeof(datatype3), (uint64)value3, sizeof(datatype4), (uint64)value4   \
  }

#define Tuple4_Get(tuple, ptr_var1, ptr_var2, ptr_var3, ptr_var4)              \
  void *Temp##tuple##ptr_var1##ptr_var2##ptr_var3##ptr_var4[4] = {             \
      &ptr_var1, &ptr_var2, &ptr_var3, &ptr_var4};                             \
  _Tuple_Get4(tuple, Temp##tuple##ptr_var1##ptr_var2##ptr_var3##ptr_var4)

#endif