
/*

*/

#ifndef __Stack_H__
#define __Stack_H__
#include <stdbool.h>

// 데이터형
#define DataType int

// 기본 용량
#define Capacity 128

#define cast(data, Type) (Type) (data)

typedef struct StackTag
{
    // 데이터 배열
    DataType *Data;

    // 검색용 테이블
    DataType *SortData;

    // 상위 값
    int top;
    
    // 용량
    int capacity;

    // 함수들
    struct
    {
        /*
            함수명      : sort
            기능        : 스택 내 SortData를 정렬
            파라미터
                Stack *this : 현재 스택 
                int Mode    : 정렬 알고리즘
        */
        void (*sort)            (struct StackTag*, int);

        /*
            함수명      : reSize
            기능        : 스택의 사이즈를 증가
            파라미터
                Stack *this : 현재 스택 
                double multi: 곱수

            주의점
                1. 축소할때 스택내에 데이터가 축소하고 남을 만큼만 있어야 합니다. 나머지는 삭제
        */
        struct StackTag* (*reSize)          (struct StackTag*, double);

        /*
            함수명      : push
            기능        : 스택 데이터 삽입
            파라미터
                Stack *this : 현재 스택 
                Type Data   : 삽입할 데이터
        */
        void (*push)            (struct StackTag*, DataType);

        /*
            함수명      : delStack
            기능        : 스택 삭제
            파라미터
                Stack *this : 현재 스택 
        */
        void (*delStack)        (struct StackTag*);

        /*
            함수명      : isError
            기능        : 스택 내 오류 검사
            파라미터
                Stack *this : 현재 스택 
                int Mode    : 오류 검사 알고리즘
        */
        bool (*isError)         (struct StackTag*, int);

        /*
            함수명      : getSize
            기능        : 스택 내 사용하고 있는 크기 반환
            파라미터
                Stack *this : 현재 스택
        */
        int (*getSize)          (struct StackTag*);
        
        /*
            함수명      : search
            기능        : 스택 내 데이터 검색
            파라미터
                Stack *this : 현재 스택 
                bool mode   : 검색 알고리즘
                Type key    : 찾을 값
        */
        int (*search)           (struct StackTag*, bool, DataType);

        /*
            함수명      : isEmpty
            기능        : 스택이 비어있는지 검사
            파라미터
                Stack *this : 현재 스택
        */
       bool (*isEmpty)          (struct StackTag*);

        /*
            함수명      : peak
            기능        : 스택의 값을 버리지 않고 얻어옴
            파라미터
                Stack *this : 현재 스택 
        */
        DataType (*peak)        (struct StackTag*);

        /*
            함수명      : pop
            기능        : 스택의 값을 버리고 얻어옴
            파라미터
                Stack *this : 현재 스택 
        */
        DataType (*pop)         (struct StackTag*);

        /*
            함수명      : copy
            기능        : 스택 복사
            파라미터
                Stack *this : 현재 스택 
                int size    : 스택 크기
        */
        struct StackTag* (*copy) (struct StackTag*, int);

        /*
            함수명      : getCapacity
            기능        : 현재 최대 용량 반환
            파라미터
                Stack *this : 현재 스택 
        */
        int (*getCapacity)      (struct StackTag*);

        /*
            함수명      : replace
            기능        : index에 해당하는 데이터를 스왑
            파라미터
                Stack *this : 현재 스택 
        */
        void (*replace)      (struct StackTag*, int, DataType);
    };
} Stack;

/* 추천 받음

1. new & del & copy
2. push & pop
3. Linear & Binary Search
4. peak
5. getsize, isEmpty
6. Sort
7. Resize
8. 에러 체크
9. copy
10.getcapacity
11.
*/

// 내부 명령

int __BinarySearch(Stack *this, DataType key);
int __LinearSearch(Stack *this, DataType key);
void __CopyData(DataType *ary1, DataType *ary2, int arysize);

// 스택 관련

#define newStack(size) __NewStack(size);
Stack* __NewStack(int size);
void __DelStack(Stack *this);
void __Sort(Stack *this, int mode);
void __Push(Stack *this, DataType Data);
void __Replace(Stack *this, int index, DataType D);
Stack* __Resize(Stack *this, double multiple);
int __GetCapacity(Stack *this);


int __GetSize(Stack *this);
int __Search(Stack *this, bool mode, DataType key);

bool __IsEmpty(Stack *this);
bool __ErrorCheck(Stack *this, int mode);

DataType __Peak(Stack *this);
DataType __Pop(Stack *this);

Stack* __Copy(Stack *this, int size);

#endif