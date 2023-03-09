#include "find.h"

int SequentialSearch(List Tbl, ElementType K) // 顺序查找
{
    int i;
    Tbl -> Element[0] = K;
    for(i = Tbl -> Length; Tbl -> Element[i] != K; i--)
    return i; //查找成功返回下标，失败返回0
}

int BinarySearch(List Tbl, ElementType K) //二分查找
{
    int left, right, mid, NotFound = -1;
    left = Tbl -> Length;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(K < Tbl -> Element[mid])
            right = right - 1;
        else if(K > Tbl -> Element[mid])
            left = left + 1;
        else
            return mid;
    }
    return NotFound;
}
