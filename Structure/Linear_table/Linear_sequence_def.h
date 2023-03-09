/* 链表实现线性表 */
# ifndef __LINEAR_LINKED_DEF_H__
# define __LINEAR_LINKED_DEF_H__

# include <stdio.h>
# include <stdlib.h>

typedef int Position;  // 定义数据类型
typedef int ElementType; // 表内数据类型
typedef struct PolyNode *Polynomial; // 结构体别名指针
typedef struct LNode *List; 


struct PolyNode // 节点结构体
{
    int coef;
    int expon;
    Polynomial link;
};

struct LNode
{
    ElementType Data;
    List Next; // 指向下一点
};

int Length(List PtrL); // 查表长

List FindKth(int K, List PtrL); // 按序号查找

List Find(ElementType X, List PtrL); // 按值查找

List Insert(ElementType X, int i, List PtrL); // 新增

List Delete(int i, List PtrL); // 删除对应节点

# endif