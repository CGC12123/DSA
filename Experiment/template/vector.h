#ifndef __VECTOR_H
#define __VECTOR_H
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
    Vector(int capa, int init_num); // 构造函数 初始化容量及初始数值

    ~Vector(); // 析构函数

    void expand(); // 扩容函数 容量扩容两倍

    void add_vector(int* array, int lo, int hi); // 填入数组 

    int findIndex(int value); // 查询索引对应数值

    void insert(int index, int value);

    int get_size();

    void removeDuplicates2();
    
    int binSearchA(int target, int left, int right);

    int binSearchB(int target, int left, int right);

    int binSearchC(int target, int left, int right);

    void Sort();

    int get(int index);

    bool judege(); // 判断是否有序

    void show();
}; 

#endif