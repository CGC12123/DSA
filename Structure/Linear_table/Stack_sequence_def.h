/* 链表定义堆栈 */
# ifndef __STACK_SEQUENCE_DEF_H__
# define __STACK_SEQUENCE_DEF_H__

# include <stdio.h>
# include <stdlib.h>

typedef struct SNode * Stack;
typedef int Position;  // 定义数据类型
typedef int ElementType; // 表内数据类型


struct SNode
{
    ElementType Data;
    Stack Next;
};

Stack CreateStack(); // 创建空栈

int IsEmpty(Stack s); // 判断是否栈空

void Push(ElementType X, Stack S); //push

ElementType Pop(Stack S); //pop

# endif