/* 数组定义堆栈 */
# ifndef __STACK_LINKED_DEF_H__
# define __STACK_LINKED_DEF_H__

# include <stdio.h>
# include <stdlib.h>

# define MAXSIZE 20 // 定义最大参数个数
# define ERROR -1 // 定义错误

typedef int Position;  // 定义数据类型
typedef int ElementType; // 表内数据类型
typedef struct SNode * Stack;

struct SNode 
{
    ElementType Data[MAXSIZE];
    int Top;
};

void push(ElementType item, Stack PtrS); // push

ElementType POP(Stack PtrS); // pop

# endif