#ifndef __LIST_CALSS_H
#define __LIST_CLASS_H
#include "iostream"
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value);
};

class LinkedList
{
public:
    // 使用Node构造链表头
    Node *head;
    // 构造函数
    LinkedList();
    // 用户输入初始化函数
    void init();
    // 添加函数 加在列表尾
    void add(int value);
    // 添加函数，指定位置
    void add(int value, int position);
    // 删除数据
    void remove(int value);
    // 找寻数据
    void find(int value);

    void show();
};

#endif