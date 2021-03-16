
#include <stdio.h>

#include "./Stack/Stack.h"

int main()
{
    Stack *stk = newStack(128);
    int i;
    
    for (i = 1; i < 11; i++)
    {
        stk->push(stk, 9000000 / i + 1);
    }
    
    for (i = 0; i < stk->top; i++)
    {
        printf("%d\n", stk->SortData[i]);
    }

    stk->sort(stk, 0);

    for (i = 0; i < stk->top; i++)
    {
        printf("%d\n", stk->SortData[i]);
    }


    stk->delStack(stk);
    return 0;
}