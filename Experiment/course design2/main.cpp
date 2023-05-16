#include "head/tree.h"

int main()
{
    // 根节点初始化
    Node node_(1);
    BinaryTree tree(node_); // A

    // 初始化目标树
    tree.insert(tree.get_Root(), 2, 0);                         // B
    tree.insert(tree.get_Root(), 5, 1);                         // E
    tree.insert(tree.get_Root()->getLeft(), 4, 0);              // C
    tree.insert(tree.get_Root()->getLeft(), 5, 1);              // F
    tree.insert(tree.get_Root()->getLeft()->getLeft(), 7, 1);   // D
    tree.insert(tree.get_Root()->getRight(), 6, 1);             // G
    tree.insert(tree.get_Root()->getRight()->getRight(), 8, 0); // H

    // 对树初始化完进行show
    tree.show();

    // 三种递归遍历
    cout << "先序遍历-递归：";
    tree.preOrderTraversal_recursion(false);
    cout << endl; // 先序遍历
    cout << "后序遍历-递归：";
    tree.postOrderTraversal_recursion(false);
    cout << endl; // 后序遍历
    cout << "层次遍历-递归：";
    tree.levelOrderTraversal_recursion(false);
    cout << endl; // 层次遍历

    // 三种非递归遍历
    cout << "先序遍历-非递归：";
    tree.preOrderTraversal_norecursion(false);
    cout << endl; // 先序遍历
    cout << "后序遍历-非递归：";
    tree.postOrderTraversal_norecursion(false);
    cout << endl; // 后序遍历
    cout << "层次遍历-非递归：";
    tree.levelOrderTraversal_norecursion(false);
    cout << endl; // 层次遍历

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