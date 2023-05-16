#include "list_array.h"

LinkedList::LinkedList()
{
    // 初始化链表为空
    head = -1;
    size = 0;
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        nodes[i].next = -1;
    }
}

void LinkedList::init()
{
    int num;
    while (true)
    {
        cin >> num;
        if (num == 0)
            break;
        add(num);
    }
}

void LinkedList::add(int val) // 添加新结点
{

    int new_node = size++;
    nodes[new_node].val = val;
    nodes[new_node].next = -1;

    if (head == -1) // 如果链表为空，新结点作为头结点
    {
        head = new_node;
    }
    else // 否则将新结点插入到链表末尾
    {
        int cur = head;
        while (nodes[cur].next != -1)
        {
            cur = nodes[cur].next;
        }
        nodes[cur].next = new_node;
    }
}

void LinkedList::add(int val, int pos)
{
    if (pos < 0 || pos > size)
    {
        cout << "插入位置不合法" << endl;
        return;
    }

    // 添加新结点
    int new_node = size++;
    nodes[new_node].val = val;

    if (pos == 0)
    {
        // 如果要插入的位置是头结点，新结点作为头结点
        nodes[new_node].next = head;
        head = new_node;
    }
    else
    {
        // 否则将新结点插入到指定位置
        int prev = head;
        for (int i = 0; i < pos - 1; ++i)
        {
            prev = nodes[prev].next;
        }
        nodes[new_node].next = nodes[prev].next;
        nodes[prev].next = new_node;
    }
    cout << "插入成功" << endl;
}

void LinkedList::remove(int val)
{
    if (head == -1) // 如果链表为空，无法删除
    {
        cout << "当前列表为空，无法进行删除操作" << endl;
        return;
    }

    if (nodes[head].val == val) // 如果要删除的是头结点
    {
        head = nodes[head].next;
        cout << "删除成功" << endl;
        return;
    }
    else // 否则查找要删除的结点
    {
        int prev = head;
        int cur = nodes[head].next;
        while (cur != -1 && nodes[cur].val != val)
        {
            prev = cur;
            cur = nodes[cur].next;
        }
        if (cur != -1)
        {
            // 如果找到了要删除的结点，删除它
            nodes[prev].next = nodes[cur].next;
            cout << "删除成功" << endl;
            return;
        }
        cout << "未找到该元素" << endl;
    }
}

void LinkedList::find(int val)
{
    // 遍历整个链表，查找指定值的元素
    int cur = head;
    while (cur != -1)
    {
        if (nodes[cur].val == val)
        {
            // 如果找到指定值的元素，返回对应结点的地址
            cout << "找到该元素，其地址为：" << &nodes[cur].val << endl;
            return;
        }
        cur = nodes[cur].next;
    }
    cout << "未找到该元素" << endl;
    return;
}

void LinkedList::show() // 遍历整个链表，并输出每个结点的值
{
    int cur = head;
    while (cur != -1)
    {
        cout << nodes[cur].val << " ";
        cur = nodes[cur].next;
    }
    cout << endl;
}
