#include <stdio.h>
#include <stdlib.h>


int get_mid(int b[],int left,int right)/*取重合点完成一次排序*/
{
    int pivot=b[left];/*指定第一个key*/
    while (left<right)
    {
        while(b[right]>=pivot&&left<right)/*从右向左扫描*/
            right--;
            b[left]=b[right];/*换位*/
        while(b[left]<=pivot&&left<right)/*从右向左扫描*/
            left++;
            b[right]=b[left];/*换位*/
    }
    b[left]=pivot;/*指定新key*/
    return left;
}

void quick_sort(int b[],int left,int right)
{
    if(left<right)
    {
    int mid=get_mid(b,left,right);
    quick_sort(b,left,mid-1);/*对左边再次排序*/
    quick_sort(b,mid+1,right);/*对右边再次排序*/
    }
}


int main()
{
    int c[10]={};/*对不同个数排序时更该处数字*/
    int m;
    printf("Please print 10 numbers:\n");
    for(m=0;m<10;m++)
    scanf("%d",&c[m]);
    
    int i;
    printf("before:\n");
    for(i=0;i<10;i++)
    printf("%d\t",c[i]);
    printf("\n");

    printf("after\n:");
    quick_sort(c,0,9);
    for(i=0;i<10;i++)
        printf("%d\t",c[i]);
    printf("\n");

    
    system("pause");
}

