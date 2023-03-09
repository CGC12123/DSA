# include "Linear_linked_def.h"

List MakeEmpty() // 创建空表
{
    List PtrL;
    PtrL = (List) malloc(sizeof(struct LNode)); // 申请对应空间
    PtrL -> Last = -1; // 无元素时为-1 代指数组下标为-1
    return PtrL; // 返回指针
}

int Find(ElementType X, List PtrL) // 查找数据 传入查找元素与对应表指针
{
    int i = 0;
    while(i <= PtrL -> Last && PtrL ->Data[i] != X)
        i ++;
    if (i > PtrL -> Last) return -1; // 没找到
    else return i; //找到后返回对应储存位置
}

void Insert(ElementType X, int i, List PtrL) // 插入数据 i为目标次序
{
    int j;
    if(PtrL -> Last == MAXSIZE -1) // 检查表满否
    {
        printf("full\n");
        return;
    }
    if(i < 1 || i >= PtrL -> Last + 2) // 检查输入位置合法性
    {
        printf("position wrong\n");
        return;
    }
    for (j = PtrL -> Last; j >= i-1; j--)
        PtrL -> Data[j + 1] = PtrL -> Data[j]; // 从后往前依次向后挪位置
    PtrL -> Data[i-1] = X;
    PtrL -> Last ++;
    return;
}

void delete(int i, List PtrL) // 删除数据
{
    int j;
    if (i < 1 || PtrL -> Last + 1)
        PtrL -> Data[j - 1] = PtrL -> Data[j]; // 顺序向前移动
    PtrL -> Last ++;
    return;
}