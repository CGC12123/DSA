#ifndef __VECTOR_H
#define __VECTOR_H
#include "iostream"
#include <algorithm>
using namespace std;

class Array 
{
  private:
    int *arr;
    int size; // 元素数量
    int capacity; // 容量

  public:
    Array(int capa, int init_num); // 构造函数 初始化容量及初始数值

    ~Array(); // 析构函数

    void expand(); // 扩容函数 容量扩容两倍

    void add_vector(int* array); // 填入数组 

    int findIndex(int value); // 查询索引对应数值

    void insert(int index, int value);

    int get_size();

    void removeDuplicates2();

    int get(int index);

    void show();
}; 

#endif