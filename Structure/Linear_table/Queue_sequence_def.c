# include "Queue_sequence_def.h"

ElementType DeleteQ(Queue PtrQ) // 从front删除
{
    Node FrontCell;
    ElementType FrontElem;
    
    if(PtrQ -> front == NULL) // 队列空
    {
        printf("Queue Empty");
        return ERROR;
    }

    FrontCell = PtrQ -> front;
    if(PtrQ -> front == PtrQ -> rear) // 只有一个元素
        PtrQ -> front = PtrQ -> rear = NULL;
    else
        PtrQ -> front = PtrQ -> front -> Next; // 队列接到删除元素的下一个上 front代指头地址
    FrontElem = FrontCell -> Data;
    free(FrontCell);
    return FrontElem;
}

void AddQ(ElementType X, Queue Q)
{
    Node TmpCell;
    TmpCell = (Node)malloc(sizeof(struct Node));
    TmpCell -> Data  = X; // 对新增节点赋值
    Q -> rear -> Next = TmpCell -> Next;
    Q -> rear = TmpCell; // 队列尾节点为新进入的TmpCell
}
