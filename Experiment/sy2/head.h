#ifndef __HEAD_H
#define __HEAD_H
#include "iostream"
#include <algorithm>
using namespace std;

class Array {
  private:
    int *arr;
    int size;

  public:
    Array(int s, int array[]) ;

    int findIndex(int value);

    void insert(int index, int value);

    int Size();

    void removeDuplicates2();

    int get(int index);

    void show();

    bool judege();
}; 

#endif