
#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

// 생성자
Stack* __NewStack(int size)
{
    Stack *temp = (struct StackTag *)malloc(sizeof(struct StackTag));
    if(cast(temp, void*) == NULL)
        return NULL;

    temp->Data = (DataType*)malloc(sizeof(DataType) * size);
    if(cast(temp->Data, void*) == NULL)
    {
        free(temp);
        temp = NULL;
        return NULL;
    }

    temp->SortData = (DataType*)malloc(sizeof(DataType) * size);
    if(cast(temp->SortData, void*) == NULL)
    {
        free(temp->Data);
        temp->Data = NULL;
        return NULL;
    }

    temp->top = 0;
    temp->capacity = size;

    temp->sort          = __Sort;
    temp->reSize        = __Resize;
    temp->push          = __Push;
    temp->delStack      = __DelStack;
    temp->getSize       = __GetSize;
    temp->search        = __Search;
    temp->peak          = __Peak;
    temp->pop           = __Pop;
    temp->copy          = __Copy;
    temp->isError       = __ErrorCheck;
    temp->isEmpty       = __IsEmpty;
    temp->getCapacity   = __GetCapacity;
    temp->replace       = __Replace;
    return temp;
}

// 소멸자
void __DelStack(Stack *this)
{
    if(cast(this, void*) == NULL || cast(this->Data, void*) == NULL || cast(this->SortData, void*) == NULL)
        return;

    free(this->SortData);
    free(this->Data);
    free(this);
}

int __Search(Stack *this, bool mode, DataType key)
{
    // 2진 탐색
    if(mode)
        return __BinarySearch(this, key);
    // 선열 탐색
    else
        return __LinearSearch(this, key);
}

int __BinarySearch(Stack *this, DataType key)
{
    int pl = 0;
    int pr = this->top - 1;
    int pc;

    do
    {
        pc = (pl + pr) / 2;

        if(this->SortData[pc] == key)
            return pc - 1;
        else if(this->SortData[pc] < key)
            pl = pc + 1;
        else
            pr = pc - 1;
    } while (pl <= pr);
    
    return -1;
}

int __LinearSearch(Stack *this, DataType key)
{
    int i;
    for (i = 0; i < this->top; i++)
        if(this->Data[i] == key)
            return i;
    return -1;
}

// 스택 관련

#define isComape(a, b, type) *cast(a, type*) < *cast(b, type*) ? -1 : *cast(a, type*) == *cast(b, type*) ? 0 : 1

int compare(const void *a, const void *b)
{
    return isComape(a, b, DataType);
}

void __Sort(Stack *this, int mode)
{
    switch (mode)
    {
    case 0:
        qsort(this->SortData, this->top, sizeof(DataType), compare);
        break;
    
    default:
        break;
    }
}

void __Push(Stack *this, DataType Data)
{
    if(this->top == this->capacity)
    {
        printf("스택 오버플로우\n");
        return;
    }
    
    this->Data[this->top++] = Data;
    this->SortData[this->top - 1] = Data;
}

Stack* __Resize(Stack *this, double multiple)
{
    if(__ErrorCheck(this, 0))
        return NULL;
    
    int Thiscapacity = cast(this->capacity * multiple, int);
    printf("%d\n", Thiscapacity);
    DataType *ary = (DataType*)realloc(this->Data, Thiscapacity);
    DataType *Sary= (DataType*)realloc(this->SortData, Thiscapacity);

    if(cast(ary, void*) == NULL || cast(Sary, void*) == NULL)
    {
        if(cast(ary, void*) == NULL && cast(Sary, void*) != NULL)
            return NULL;
        else if(cast(ary, void*) != NULL && cast(Sary, void*) == NULL)
        {
            free(ary);
            return NULL;
        }
        else
        {
            free(Sary);
            return NULL;
        }
    }

    this->Data = ary;
    this->SortData = Sary;
    this->capacity = Thiscapacity;
    return this;
}

void __CopyData(DataType *ary1, DataType *ary2, int arysize)
{
    int i;
    for (i = 0; i < arysize; i++)
        ary2[i] = ary1[i];
}

bool __ErrorCheck(Stack *this, int mode)
{
    switch (mode)
    {
        // Null Exception Error
        case 0:
            if(cast(this, void*) == NULL || cast(this->Data, void*) == NULL || cast(this->SortData, void*) == NULL)
            {
                if(cast(this, void*) == NULL)
                    printf("Null Exception : This\n");
                else if(cast(this->Data, void*) == NULL)
                    printf("Null Exception : Data\n");
                else if(cast(this->SortData, void*) == NULL)
                    printf("Null Exception : SortData\n");
                return true;
            }
            else
                return false;
            break;
        default:
            return false;
    }
}

int __GetSize(Stack *this)
{
    return this->top - 1;
}

DataType __Peak(Stack *this)
{
    if(this->top <= 0)
    {
        this->top = 0;
        printf("스택 언더플로우");
        return cast(0, DataType);
    }
    return this->Data[this->top - 1];
}

DataType __Pop(Stack *this)
{
    if(this->top <= 0)
    {
        this->top = 0;
        printf("스택 언더플로우");
        return cast(0, DataType);
    }
    this->SortData[this->search(this, true, this->Data[this->top - 1])] = 999999999999;
    return this->Data[--this->top];
}

Stack* __Copy(Stack *this, int size)
{
    Stack *temp = newStack(size);
    __CopyData(this->Data, temp->Data, size);
    __CopyData(this->SortData, temp->SortData, size);
    temp->top = this->top <= this->capacity ? this->top : size;
    return temp;
}

bool __IsEmpty(Stack *this)
{
    return this->top == 0 ? true : false;
}

int __GetCapacity(Stack *this)
{
    return this->capacity;
}

void __Replace(Stack *this, int index, DataType D)
{
    if(index >= this->getSize(this))
        return;
    
    this->SortData[this->search(this, true, this->Data[index - 1])] = D;
    this->Data[index - 1] = D;
    this->sort(this, 0);
}