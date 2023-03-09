/* 数组定义队列 */
# ifndef __QUEUE_LINKED_H__
# define __QUEUE_LINKED_H__

# include <stdio.h>
# include <stdlib.h>

# define MAXSIZE 20
# define ERROR -1 // 定义错误

typedef int ElementType;
typedef struct QNode * Queue;


struct QNode
{
    ElementType Data[MAXSIZE];
    int rear;
    int front;
};

Queue CreatQueue(int MaxSize);

void AddQ(Queue PtrQ, ElementType item);

ElementType DeleteQ(Queue PtrQ);


# endif