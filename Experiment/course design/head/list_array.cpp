#include "list_array.h"

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
    delete[] arr;
}

void Vector::init()
{
    int num;
    while (true)
    {
        cin >> num;
        if (num == 0)
            break;
        insert(num);
    }
}

void Vector::expand()
{
    if (size < capacity)
        return;
    else
    {
        // 创建新的数据数组
        int *old = arr;
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

void Vector::add_vector(int *array, int lo, int hi)
{
    expand();

    while (lo < hi)
    {
        arr[size++] = array[lo++];
    }
}

void Vector::findIndex(int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            cout << "找到该元素，其地址为" << arr + i << endl;
            return;
        }
    }
    cout << "未找到该元素" << endl;
    return;
}

void Vector::insert(int value)
{
    insert(size, value);
}

void Vector::insert(int index, int value)
{
    expand();

    size++;
    if (index >= size)
    {
        index = size - 1;
        cout << "目标位置大于列表长度，已自动将数据补至列表尾部" << endl;
    }
    else
    {
        for (int i = size - 1; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        // cout << "添加成功" << endl;
    }

    arr[index] = value;
}

int Vector::get_size()
{
    return size;
}

void Vector::remove(int value)
{
    bool temp = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            while (i < size)
            {
                arr[i] = arr[i + 1];
                i++;
            }
            size--;
            temp = 1;
        }
    }
    if (temp)
    {
        cout << "删除成功" << endl;
    }
    else if (temp == 0 && size == 0)
    {
        cout << "列表为空，无法删除" << endl;
    }
    else
    {
        cout << "未找到该数据" << endl;
    }
}

void Vector::removeDuplicates2()
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

bool Vector::judege()
{
    for (int i = 0; i < size; i++)
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    return true;
}

void Vector::bubblesort(int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        for (int j = start; j <= end - i + start; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int Vector::binSearchA(int target, int left, int right)
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

int Vector::binSearchB(int target, int left, int right)
{
    while (1 < right - left)
    {
        int mi = (right + left) >> 1;
        (target < arr[mi]) ? right = mi : left = mi;
    }
    return (target == arr[left]) ? left : -1;
}

int Vector::binSearchC(int target, int left, int right)
{
    while (right > left)
    {
        int mi = (right + left) >> 1;
        (target < arr[mi]) ? right = mi : left = mi + 1;
    }
    return --left;
}

void Vector::Sort()
{
    sort(arr, arr + size);
}

void Vector::merge(int left, int mi, int right) // mi为界
{
    int n1 = mi - left + 1, n2 = right - mi;
    int *tmp = new int[n1 + n2];
    int p = 0, p1 = left, p2 = mi + 1;

    while (p1 <= mi && p2 <= right)
    {
        if (arr[p1] <= arr[p2])
            tmp[p++] = arr[p1++];
        else
            tmp[p++] = arr[p2++];
    }

    while (p1 <= mi)
        tmp[p++] = arr[p1++];
    while (p2 <= right)
        tmp[p++] = arr[p2++];

    for (int i = 0; i < p; ++i)
        arr[left + i] = tmp[i];

    delete[] tmp;
}

void Vector::mergeSort(int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}