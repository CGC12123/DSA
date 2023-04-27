// #include "vector.h"

#include "iostream"
#include <algorithm>
using namespace std;

class Vector 
{
  private:
    int *arr;
    int size; // 元素数量
    int capacity; // 容量

  public:
    Vector(int capa, int init_num) // 构造函数 初始化容量及初始数值
{
    capacity = capa;
    arr = new int[capacity];
    for (int i = 0; i < sizeof(capa); i++)
    {
        arr[i] = init_num;
    }
    size = 0;
}
    ~Vector() // 析构函数
{
    delete [] arr;
}
    void expand() // 扩容函数 容量扩容两倍
{
    if(size < capacity)
        return;
    else
    {
        // 创建新的数据数组
        int* old = arr;
        arr = new int[capacity <<= 1]; // 容量翻倍
        
        // 复制旧的数据到新的数组中
        for (int i = 0; i < size; i++) 
        {
            arr[i] = old[i];
        }
    
        // 删除旧的数据数组
        delete[] old;
    }
}
    void add_vector(int* array) // 填入数组 
{
    expand();

    for (int i = 0; i < sizeof(array); i++) 
    {
        arr[i] = array[i];
    }

    size = sizeof(array);
}
    int findIndex(int value) // 查询索引对应数值
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == value) 
        {
            return i;
        }
    }
    cout << "nofind" << endl; 
    // 如果元素不存在，则返回-1
    return -1;
}

    void insert(int index, int value)
{
    expand();

    size ++;
    for (int i = size - 1; i > index; i--) 
    {
        arr[i] = arr[i - 1];
    }
    
    arr[index] = value;
}
    int get_size()
{
    return size;
}
    void Sort()
    {
    sort(arr, arr + size);  
    }
    
    void removeDuplicates2()
    {
    sort(arr, arr + size);
    int i = 0;
    while (i < size - 1) 
    {
        if (arr[i] == arr[i + 1]) 
        {
            for (int j = i + 1; j < size - 1; j++) 
            {
                arr[j] = arr[j + 1];
            }
            size--;
        } 
        else 
        {
            i++;
        }
    }
}
    

    int get(int index)
{
    return arr[index];
}
    bool judege() // 判断是否有序
{
    for(int i = 0; i < size; i++)
    if(arr[i] > arr[i + 1])
    {
        return false;
    }
    return true;
}
    void show()
    {
    for (int i = 0; i < size; i++) 
    {
        cout << get(i) << " ";
    }
    cout << endl;
}

int binSearchA(int target, int left, int right)
{
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) 
            return mid;
        else if (arr[mid] < target) 
            left = mid + 1; 
        else 
            right = mid - 1;
    }
    return -1;
}

int binSearchB(int target, int left, int right)
{
    while(1 < right - left)
    {
        int mi = (right + left) >> 1;
        (target < arr[mi]) ? right = mi : left = mi;
    }
    return (target == arr[left]) ? left : -1;
}

int binSearchC(int target, int left, int right)
{
    while(right > left)
    {
        int mi = (right + left) >> 1;
        (target < arr[mi]) ? right = mi : left = mi + 1;
    }
    return --left;
}
}; 

int main()
{
    Vector UnSesrchA(9, -1);
    int UnSortedVector31[9] = {2, 5, 4, 7, 4, 9, 8, 9, 12};
    UnSesrchA.add_vector(UnSortedVector31);
    cout << UnSesrchA.get_size() << endl;
    cout << "array: ";
    UnSesrchA.show();

    // cout << "after sort:" << endl;
    // UnSesrchA.Sort();
    // UnSesrchA.show();

    cout << endl;

    cout << "Question1: find 4 in [1, 8):" << endl;
    cout << " using binSearchA: " << UnSesrchA.binSearchA(4, 1, 8) << endl;
    cout << " using binSearchC: " << UnSesrchA.binSearchC(4, 1, 8) << endl;
    cout << endl;

    cout << "Question2: find 9 in [1, 8):" << endl;
    cout << " using binSearchA: " << UnSesrchA.binSearchA(9, 1, 8) << endl;
    cout << " using binSearchC: " << UnSesrchA.binSearchC(9, 1, 8) << endl;
    cout << endl;


    cout << "Question3: find 2 in [1, 8):" << endl;
    cout << " using binSearchA: " << UnSesrchA.binSearchA(2, 1, 8) << endl;
    cout << " using binSearchC: " << UnSesrchA.binSearchC(2, 1, 8) << endl;
    cout << endl;
    

    cout << "Question4: find 12 in [1, 8):" << endl;
    cout << " using binSearchA: " << UnSesrchA.binSearchA(12, 1, 8) << endl;
    cout << " using binSearchC: " << UnSesrchA.binSearchC(12, 1, 8) << endl;

    return 0;
}