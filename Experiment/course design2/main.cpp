#include "head/tree.h"

int main()
{
    cout << "请选择您要使用的初始化方式：使用默认初始化(0) 自定义初始化(1)" << endl;

    int A, B, C, D, E, F, G, H;
    bool mode;
    cin >> mode;

    if (mode)
    {
        cout << "请依次输入数据A~H" << endl;
        cin >> A >> B >> C >> D >> E >> F >> G >> H;
    }
    else
    {
        A = 1, B = 2, C = 4, D = 7, E = 3, F = 5, G = 6, H = 8;
    }
    // 根节点初始化
    Node node_(A);
    BinaryTree tree(node_); // A

    // 初始化目标树
    tree.insert(tree.get_Root(), B, 0);                         // B
    tree.insert(tree.get_Root(), E, 1);                         // E
    tree.insert(tree.get_Root()->getLeft(), C, 0);              // C
    tree.insert(tree.get_Root()->getLeft(), F, 1);              // F
    tree.insert(tree.get_Root()->getLeft()->getLeft(), D, 1);   // D
    tree.insert(tree.get_Root()->getRight(), G, 1);             // G
    tree.insert(tree.get_Root()->getRight()->getRight(), H, 0); // H

    // 对树初始化完进行show
    cout << "当前树为：" << endl;
    tree.show();
    cout << endl;

    // 三种递归遍历
    cout << "先序遍历-递归：";
    tree.preOrderTraversal_recursion(false); // 先序遍历
    cout << endl;
    cout << "后序遍历-递归：";
    tree.postOrderTraversal_recursion(false); // 后序遍历
    cout << endl;
    cout << "层次遍历-递归：";
    tree.levelOrderTraversal_recursion(false); // 层次遍历
    cout << endl << endl;
    // 三种非递归遍历
    cout << "先序遍历-非递归：";
    tree.preOrderTraversal_norecursion(false); // 先序遍历
    cout << endl;
    cout << "后序遍历-非递归：";
    tree.postOrderTraversal_norecursion(false); // 后序遍历
    cout << endl;
    cout << "层次遍历-非递归：";
    tree.levelOrderTraversal_norecursion(false); // 层次遍历
    cout << endl;

    cout << endl;

    // 搜索
    cout << "先序查找：" << endl;
    int val1 = 5;
    tree.searchpreOrderTraversal(true, val1);
    tree.show_search_path(tree.search_pre, val1);

    int val2 = 8;
    cout << "后序查找：" << endl;
    tree.searchpostOrderTraversal(true, val2);
    tree.show_search_path(tree.search_post, val2);

    int val3 = 9;
    vector<Node *> path_level;
    cout << "层次查找：" << endl;
    Node *node_level = tree.searchLevelOrder(val3, path_level);
    searchPath_show(node_level, val3, path_level);
    path_level.clear();

    return 0;
}