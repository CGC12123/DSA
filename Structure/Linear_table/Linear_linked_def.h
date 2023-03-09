/* 数组实现线性表 */
# ifndef __LINEAR_SEQUENCE_DEF_H__
# define __LINEAR_SEQUENCE_DEF_H__

# include <stdio.h>
# include <stdlib.h>

typedef int Position;  // 定义数据类型
typedef int ElementType; // 表内数据类型
typedef struct PolyNode *Polynomial; 
typedef struct LNode *List; // 顺序表结构体别名指针
# define MAXSIZE 20 // 顺序表最大数量

struct PolyNode // 节点结构体
{
    int coef;
    int expon;
    Polynomial link;
};

struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; // 最后一个元素所在位置对应下标
};

List MakeEmpty(); // 创建空表

int Find(ElementType X, List PtrL); // 查找数据 传入查找元素与对应表指针

void Insert(ElementType X, int i, List PtrL); // 插入数据 i为目标次序

void delete(int i, List PtrL); // 删除数据

# endif 