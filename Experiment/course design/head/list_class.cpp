// 使用类定义列表
#include "list_class.h"

Node::Node(int value)
{
    this->value = value;
    this->next = NULL;
}

LinkedList::LinkedList()
{
    this->head = NULL;
}

// 初始化数据函数 空格或回车间隔均可
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

void LinkedList::add(int value)
{
    Node *new_node = new Node(value); // 申请新node用于加入
    if (this->head == NULL)           // 若当前列表头为空则使加进来的node为列表头
    {
        this->head = new_node;
    }
    else
    {
        Node *current_node = this->head;
        while (current_node->next != NULL)
        {
            current_node = current_node->next; // 后移直到达到列表尾的node
        }
        current_node->next = new_node; // 在尾部增加新node
    }
}

void LinkedList::add(int value, int position)
{
    Node *new_node = new Node(value);        // 申请新node用于加入
    if (position <= 1 || this->head == NULL) // 直接在列表头部add
    {
        new_node->next = this->head;
        this->head = new_node;
    }
    else
    {
        Node *current_node = this->head;
        int i = 1;
        while (i < position - 1 && current_node->next != NULL) // 移动直到达到position
        {
            current_node = current_node->next;
            i++;
        }
        new_node->next = current_node->next; // 在position上加入新node
        current_node->next = new_node;
    }
}

void LinkedList::remove(int value)
{
    if (this->head == NULL)
    {
        cout << "当前列表为空，无法进行删除操作" << endl;
        return;
    }
    if (this->head->value == value) // 要删除的节点在列表头部
    {
        this->head = this->head->next;
        cout << "删除成功" << endl;
    }
    else
    {
        Node *current_node = this->head;
        while (current_node->next != NULL)
        {
            if (current_node->next->value == value) // 不断后移直到达到目标
            {
                current_node->next = current_node->next->next;
                cout << "删除成功" << endl;
                return;
            }
            current_node = current_node->next;
        }
        cout << "该数据不在列表中，删除失败" << endl; // 退出while循环表示直到历遍完整个列表都找不到该数据
    }
}

void LinkedList::find(int value)
{
    Node *current_node = this->head;
    while (current_node != NULL)
    {
        if (current_node->value == value)
        {
            cout << "找到该数据，其地址为：" << current_node << endl;
            return;
        }
        current_node = current_node->next;
    }
    cout << "未找到该数据" << endl;
}

void LinkedList::show()
{
    Node *current_node = this->head;
    while (current_node != NULL)
    {
        cout << current_node->value << " ";
        current_node = current_node->next;
    }
    cout << endl;
}