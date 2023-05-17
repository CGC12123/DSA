#ifndef __TREE_H
#define __TREE_H
using namespace std;
#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>

// 定义二叉树结点结构体
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val);

    Node(int val, Node *left, Node *right);

    int getVal() { return this->val; } // 获取节点值

    Node *getLeft() { return this->left; } // 获取左节点

    Node *getRight() { return this->right; } // 获取右节点

    void setVal(int val) { this->val = val; } // 设置节点值

    void setLeft(Node *left) { this->left = left; } // 设置左子节点接口

    void setRight(Node *right) { this->right = right; } // 设置右子节点接口
};

// 二叉树类
class BinaryTree
{
private:
    Node *root; // 根节点

public:
    vector<int> search_pre; // 储存先序遍历的遍历值

    vector<int> search_post; // 储存后序遍历的遍历值

    BinaryTree(Node root_) { this->root = new Node(root_.getVal(), root_.getLeft(), root_.getRight()); } // 构造函数一

    BinaryTree() { this->root = NULL; } // 构造函数二，初始根节点为空

    Node *get_Root() { return this->root; } // 用于访问根节点的接口

    void setRoot(Node *root_) { this->root = root_; } // 改变根节点的值

    void insert(Node *target_node, int node_val, bool left_or_right); // 插入函数 用于为指定节点指定左右节点

    int getDepth(Node *node); // 获取树深度 show函数中需要调用

    void show(); // 输出树

    // 先序遍历 递归 print_path为true时输出遍历路径
    void preOrderTraversal_recursion(bool print_path); // 入口
    void preOrderTraversal(Node *node, bool print_path, vector<int> &path); // 先序遍历主体函数

    // 后序遍历 递归
    void postOrderTraversal_recursion(bool print_path); // 入口
    void postOrderTraversal(Node *node, bool print_path, vector<int> &path); // 后序遍历主题函数

    // 层次遍历 递归
    void levelOrderTraversal_recursion(); // 入口
    void levelOrderTraversal(Node *node); // 层次遍历主题函数

    // 先序遍历 非递归
    void preOrderTraversal_norecursion(bool print_path);

    // 后序遍历 非递归
    void postOrderTraversal_norecursion(bool print_path);

    // 层次遍历 非递归
    void levelOrderTraversal_norecursion(bool print_path);

    // 先序遍历查找
    void searchpreOrderTraversal(bool print_path, int target_num);
    // 先序遍历查找辅助函数
    void searchpreOrderTraversal_(Node *node, bool print_path, vector<int> &path, int target_num);

    // 后序遍历查找
    void searchpostOrderTraversal(bool print_path, int target_num);
    // 后序遍历查找辅助函数
    void searchpostOrderTraversal_(Node *node, bool print_path, vector<int> &path, int target_num);
    
    // 显示遍历次序函数 在两个向量中找到目标数值
    void show_search_path(vector<int> search, int target_num);

    // 层次遍历查找
    Node *searchLevelOrder(int val, vector<Node *> &path);
    // 层次遍历查找辅助函数
    Node *searchLevelOrder_(Node *node, int val, vector<Node *> &path);
};

// 输出查找路径函数
void searchPath_show(Node *node, int val, vector<Node *> path);

#endif