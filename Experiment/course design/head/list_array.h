#ifndef __LIST_ARRAY_H
#define __LIST_ARRAY_H
#include "iostream"
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;

struct Node
{
    int val;
    int next;
};

class LinkedList
{
private:
    Node nodes[MAX_SIZE]; // 存储链表结点的数组
    int head;                 // 链表头结点的下标
    int size;                 // 链表的大小
public:
    LinkedList();

    void init();

    void add(int val);

    void add(int val, int pos);

    void remove(int val);

    void find(int value);

    void show();
};

#endif