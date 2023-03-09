// 查找
#ifndef __FIND_H__
#define __FIND_H__

# include <stdio.h>
# include <stdlib.h>

typedef int ElementType;
typedef struct LNode *List;

#define MAXSIZE 20

struct LNode
{
    ElementType Element[MAXSIZE];
    int Length;
};

int SequentialSearch(List Tbl, ElementType K); // 顺序查找

int BinarySearch(List Tbl, ElementType K); // 二分查找

#endif