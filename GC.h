
#ifndef __NLB_GARBAGECOLLECTION__
#define __NLB_GARBAGECOLLECTION__

#define MemoryMaxLength 256

typedef struct GCMemoryPage {
  /* @brief 메모리 페이지에서 사용하는 메모리 수 */
  unsigned int UsedMemoryLength;
  /* @brief 메모리 페이지의 데이터 */
  struct {
    /* @brief 메모리 주소 */
    void *Value;
    /* @brief 메모리 크기 */
    unsigned int Length;
  } Datas[MemoryMaxLength];
  /* @brief 다음 메모리 페이지 주소 */
  struct GCMemoryPage *Next;
} MemoryPage;

typedef struct GCMemoryFunc {
  char *DataType;
  void (*Constructor)(void);
  void (*Destructor)(void **);
  struct GCMemoryFunc *Next;
} MemoryFunc;

typedef struct GCMemoryManager {
  unsigned int UsedMemoryLength;
  unsigned int UsedMemoryPageLength;
  unsigned int UsedMemoryFuncLength;

  MemoryPage Pages;
  MemoryFunc *Funcs;
} MemoryManager;

typedef struct GCMemoryIndex {
  unsigned int MemoryFound;
  unsigned int MemoryIndex;
  unsigned int MemoryPageIndex;
} MemoryIndex;

extern MemoryManager *__Manager__;

// * Memory 계열
// * 할당과 제거
/** @brief 메모리 생성자
 * @param Length(unsigned_int) 생성할 메모리 크기
 * @return void* 생성된 메모리
 */
void *MemoryCreate(unsigned int Length);
/** @brief 메모리 소멸자
 * @param ptr(void_**) 소멸할 메모리 위치
 */
void MemoryRemove(void **ptr);

// * 탐색과 가져오기
/** @brief 메모리 검색자
 * @param Ptr(void_*) 검색할 메모리
 * @return MemoryIndex 탐색된 정보
 */
MemoryIndex MemorySearch(void *Ptr);
/** @brief 메모리 Getter
 * @param Index(MemoryIndex) 해당하는 메모리 인덱서
 * @return void* 찾은 메모리 위치
 */
void *MemoryGet(MemoryIndex Index);
unsigned int MemoryGetLength(MemoryIndex Index);

// * 메모리 관리자에 등록과 삭제
/** @brief 메모리 페이지에 추가
 * @param Obj(void_*) 추가할 메모리 위치
 */
void MemoryPageMemoryAppend(void *Obj, unsigned int Length);
/** @brief 메모리 페이지에 삭제
 * @param Obj(void *) 삭제할 메모리 위치
 */
void MemoryPageMemoryRemove(void *Obj);

// * MemoryPage 계열
/** @brief MemoryPage 생성자
 */
void MemoryPageAppend();
/** @brief MemoryPage 소멸자 **/
void MemoryPageRemove(unsigned int Index);
/** @brief 특정 메모리 페이지 가져오기
 *
 * @param Index 특정 메모리 페이지 위치 정보
 * @return MemoryPage 메모리 페이지
 */
MemoryPage *MemoryPageGet(MemoryIndex Index);
MemoryPage *MemoryPageGetLast();
MemoryPage *MemoryPageGetEmpty();

// * 생성자와 소멸자 관련
MemoryFunc *FuncNode_Search(const char *DataType);
#define Create(DataType, Casting)                                              \
  (DataType *)((Casting)Constructor_Search(#DataType))
void *(*Constructor_Search(char *DataType))(void);
#define Remove(DataType, Instance)                                             \
  Constructor_Destructor(#DataType)((void **)&Instance)
void (*Constructor_Destructor(char *DataType))(void **);

void FuncNode_Append(void (*Contructor)(void), void (*Destructor)(void **),
                     const char *DataType);

MemoryFunc *FuncNode_Get(unsigned int Index);

#define NoConstructor void *(*)(unsigned int)

// * GC 관련
void GC_Init();
void GC_ManagerInit();
void GC_Clear();
void GC_Clean();

#define Error(format, ...)                                                     \
  do {                                                                         \
    fprintf(stderr, format, ##__VA_ARGS__);                                    \
    exit(-1);                                                                  \
  } while (0)

#define Warning(format, ...) fprintf(stderr, format, ##__VA_ARGS__)

#endif