#ifndef __LIST_ARRAY_H
#define __LIST_ARRAY_H
#include "iostream"
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

class LinkedList
{
private:
    int *arr;
    int size;     // 元素数量
    int capacity; // 容量

public:
    LinkedList(int capa, int init_num); // 构造函数 初始化容量及初始数值

    ~LinkedList(); // 析构函数

    void init();

    void expand(); // 扩容函数 容量扩容两倍

    void add(int *array, int lo, int hi); // 填入数组

    void findIndex(int value); // 查询索引对应数值

    void insert(int value);

    void insert(int index, int value);

    int get_size();

    void remove(int value);

    void removeDuplicates2();

    void bubblesort(int start, int end);

    int binSearchA(int target, int left, int right);

    int binSearchB(int target, int left, int right);

    int binSearchC(int target, int left, int right);

    void Sort();

    void merge(int left, int mi, int right);

    void mergeSort(int left, int right);

    int get(int index);

    bool judege(); // 判断是否有序

    void show();
};

#endif