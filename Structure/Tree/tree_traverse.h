//二叉树的遍历
#ifndef __TREE_TRAVERSE_H__
#define __TREE_TRAVERSE_H__

# include <stdio.h>
# include <stdlib.h>
# include "tree_traverse.h"
# include "Stack_sequence_def.h"
# include "Queue_sequence_def.h"


#define MAXSIZE 20
typedef int ElementType;
typedef struct TreeNode *BinTree;
typedef BinTree Position;

struct TreeNode // 定义二叉树
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
void PreOrderTraversal(BinTree BT); //先序遍历

void InOrderTraversal(BinTree BT); // 中序遍历

void PostOrderTraversal(BinTree BT); // 后序遍历

void InOrderTraversal(BinTree BT); // 使用堆栈非递归遍历

void LevelOrderTraversal(BinTree BT); // 使用队列层级访问

#endif