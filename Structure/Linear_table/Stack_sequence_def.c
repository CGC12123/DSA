#include "Stack_sequence_def.h"

Stack CreateStack() // 创建空栈
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S -> Next = NULL;
    return S;
}

int IsEmpty(Stack S) // 判断是否栈空
{
    return(S -> Next == NULL);
}
 
void Push(ElementType X, Stack S) //push
{
    Stack TmpCell;
    TmpCell = (Stack)malloc(sizeof(struct SNode));
    TmpCell -> Data  = X;
    TmpCell -> Next = S -> Next;
    S -> Next = TmpCell;
}

ElementType Pop(Stack S) //pop
{
    Stack FirstCell;
    ElementType TopElem;
    if(IsEmpty(S))
    {
        FirstCell = S -> Next;
        S -> Next = FirstCell -> Next;
        TopElem = FirstCell -> Data;
        free(FirstCell);
        return TopElem;
    }
}