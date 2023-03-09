#include "Stack_linked_def.h"

void push(ElementType item, Stack PtrS) // push
{
    if(PtrS -> Top == MAXSIZE - 1) // 已满
    {
        print("full\n"); 
        return;
    }
    else
    {
        PtrS -> Data[++ (PtrS -> Top)] = item;
        return;
    }
}

ElementType POP(Stack PtrS) // pop
{
    if(PtrS -> Top == -1) // 栈空
    {
        printf("full\n");
        return ERROR;
    }
    else
    {
        return(PtrS -> Data[(PtrS -> Top) --]); 
    }
}