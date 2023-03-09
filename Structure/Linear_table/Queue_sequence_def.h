/* 链表定义队列 */
# ifndef __QUEUE_LINKED_H__
# define __QUEUE_LINKED_H__

# include <stdio.h>
# include <stdlib.h>

# define ERROR -1 // 定义错误

typedef int ElementType;
typedef struct Node * Node;
typedef struct QNode * Queue;

struct Node // 链中的一个节点
{
    ElementType Data;
    Queue Next;
};

struct QNode //链队列结构
{
    Node rear; // 尾节点 每个节点为一个Node
    Node front; //头节点
};

ElementType DeleteQ(Queue PtrQ);

void AddQ(ElementType X, Queue Q);

# endif