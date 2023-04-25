#include "head.h"

Array::Array(int s, int array[]) 
{
    size = s;
    arr = array;
}

int Array::findIndex(int value) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == value) 
        {
            return i;
        }
    }
    cout << "nofind" << endl; // 如果元素不存在，则返回-1
    return -1;
}

void Array::insert(int index, int value) 
{
    size ++;
    for (int i = size - 1; i > index; i--) 
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
}

int Array::Size() 
{
    return size;
}

void Array::removeDuplicates2() {
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

int Array::get(int index) 
{
    return arr[index];
}

void Array::show()
{
    for (int i = 0; i < size; i++) 
    {
        cout << get(i) << " ";
    }
    cout << endl;
}