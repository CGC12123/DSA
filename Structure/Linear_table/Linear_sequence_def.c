#include "Linear_sequence_def.h"

int Length(List PtrL) // 查表长
{
    List p = PtrL;
    int j = 0;
    while (p)
    {
        p = p -> Next;
        j++;
    }
    return j;
}

List FindKth(int K, List PtrL) // 按序号查找
{
    List p = PtrL;
    int i = 1;
    while (p != NULL && i < K) // 还未找到
    {
        p = p -> Next;
        i ++;
    }
    if(i == K) return p; // 找到第n个 返回对应指针

    else return NULL; // 否则为空
}

List Find(ElementType X, List PtrL) // 按值查找
{
    List p = PtrL;
    while(p != NULL && p -> Data != X) // 未找到或且指针非空
        p = p -> Next;
    return p;
}

List Insert(ElementType X, int i, List PtrL) // 新增
{
    List p, s;
    if(i == 1) // 在首位
    {
        s = (List)malloc(sizeof(struct LNode));
        s -> Data = X;
        s -> Next = PtrL;
        return;
    }

    p = FindKth(i - 1, PtrL); // 找到目标位置的上个点

    if(p == NULL)
    {
        printf("input number wrong\n");
        return NULL;
    }
    else
    {
        s = (List)malloc(sizeof(struct LNode)); // 申请新的节点
        s -> Data = X; // 填充新节点
        s -> Next = p -> Next; // 讲新节点插入在第i-1个节点后
        p -> Next = s; // 与前一个（第i-1）节点项链
        return PtrL;
    }
}

List Delete(int i, List PtrL) // 删除对应节点
{
    List p, s;
    if(i == 1) // 第一个节点
    {
        s = PtrL;
        if (PtrL != NULL) PtrL = PtrL->Next;
        else return NULL;
        free(s); // 释放该节点
        return PtrL;
    }

    p = FindKth(i-1, PtrL); // 找到上一个

    if(p == NULL) //节点不存在
    {
        printf("can not find\n");
        return NULL;
    }
    else if(p -> Next == NULL)
    {
        printf("do not exist\n");
        return NULL;
    }
    else
    {
        s = p -> Next;
        p -> Next = s -> Next;
        free(s);
        return PtrL;
    }
}