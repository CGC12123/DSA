#include "vector.h"

Vector::Vector(int capa, int init_num) 
{
    capacity = capa;
    arr = new int[capacity];
    for (int i = 0; i < sizeof(capa); i++)
    {
        arr[i] = init_num;
    }
    size = 0;
}

Vector::~Vector()
{
    delete [] arr;
}

void Vector::expand() 
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

void Vector::add_vector(int* array)
{
    expand();

    for (int i = 0; i < sizeof(array); i++) 
    {
        arr[i] = array[i];
    }

    size = sizeof(array);
}


int Vector::findIndex(int value) 
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

void Vector::insert(int index, int value) 
{
    expand();

    size ++;
    for (int i = size - 1; i > index; i--) 
    {
        arr[i] = arr[i - 1];
    }
    
    arr[index] = value;
}

int Vector::get_size() 
{
    return size;
}

void Vector::removeDuplicates2() {
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

int Vector::get(int index) 
{
    return arr[index];
}

void Vector::show()
{
    for (int i = 0; i < size; i++) 
    {
        cout << get(i) << " ";
    }
    cout << endl;
}
