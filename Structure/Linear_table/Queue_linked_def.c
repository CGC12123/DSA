#include "Queue_linked_def.h"

Queue CreatQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(MaxSize*sizeof(Queue));
    Q -> Data = (ElementType *)malloc(MaxSize*sizeof(ElementType));
    Q -> Front = Q -> Rear = 0;
    
}

void AddQ(Queue PtrQ, ElementType item)
{
    if((PtrQ -> rear + 1) % MAXSIZE == PtrQ -> front)
    {
        printf("queue full\n");
        return;
    }
    PtrQ -> rear = (PtrQ -> rear + 1) % MAXSIZE;
    PtrQ -> Data[PtrQ -> rear] = item;
}

ElementType DeleteQ(Queue PtrQ)
{
    if(PtrQ -> front == PtrQ -> rear)
    {
        printf("queue empty\n");
        return ERROR;
    }
    else
    {
        PtrQ -> front = (PtrQ -> front + 1) % MAXSIZE;
        return PtrQ -> Data[PtrQ -> front];
    }
}
