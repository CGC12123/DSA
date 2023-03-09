#include "tree_traverse.h"

void PreOrderTraversal(BinTree BT) //先序遍历
{
    if(BT)
    {
        printf("%d", BT -> Data);
        PreOrderTraversal(BT -> Left);
        PreOrderTraversal(BT -> Right);
    }
}

void InOrderTraversal(BinTree BT) // 中序遍历
{
    if(BT)
    {
        PreOrderTraversal(BT -> Left);
        printf("%d", BT -> Data);
        PreOrderTraversal(BT -> Right);
    }
}

void PostOrderTraversal(BinTree BT) // 后序遍历
{
    if(BT)
    {
        PreOrderTraversal(BT -> Left);
        PreOrderTraversal(BT -> Right);
        printf("%d", BT -> Data);
    }
}

void InOrderTraversal(BinTree BT) // 使用堆栈非递归遍历
{
    BinTree T = BT;
    Stack S = CreateStack();
    while(T || IsEmpty(S))
    {
        Push(S, T);
        T = T -> Left;
    }
    if(!IsEmpty(S))
    {
        T = Pop(S);
        printf("%5d", T -> Data);
        T = T -> Right;
    }
}

void LevelOrderTraversal(BinTree BT) // 使用队列层级访问
{
    Queue Q;
    BinTree T;
    if(!BT)
        return;
    Q = CreatQueue(); // 该函数未处理
    AddQ(Q, BT);
    while(!IsEmptyQ(Q)) // 该函数未处理
        T = DeleteQ(Q);
        printf("%d\n", T -> Data);
        if(T -> Left) AddQ(T -> Left, BT);
        if(T -> Right) AddQ(T -> Right, BT);
}
