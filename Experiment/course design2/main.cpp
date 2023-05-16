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
    tree.preOrderTraversal_norecursion(false); cout << endl; // 先序遍历
    cout << "后序遍历-非递归：";
    tree.postOrderTraversal_norecursion(false); cout << endl; // 后序遍历
    cout << "层次遍历-非递归：";
    tree.levelOrderTraversal_norecursion(false); cout << endl; // 层次遍历

    // 搜索
    int val = 4; // 要查找到数
    vector<Node *> path_pre;
    cout << "先序查找：";
    Node *node_pre = tree.searchLevelOrder(val, path_pre);
    searchPath_show(node_pre, 6, path_pre);
    path_pre.clear();

    vector<Node *> path_order;
    cout << "后序查找：";
    Node *node_order = tree.searchPostorder(val, path_order);
    searchPath_show(node_order, 6, path_order);
    path_order.clear();

    vector<Node *> path_level;
    cout << "层次查找：";
    Node *node_level = tree.searchLevelOrder(val, path_level);
    searchPath_show(node_level, 6, path_level);
    path_level.clear();

    return 0;
}