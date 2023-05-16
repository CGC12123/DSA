#include "tree.h"

Node::Node(int val) // 构造函数一 只传入值进行构建
{
    this->val = val;
    this->left = NULL;
    this->right = NULL;
}

Node::Node(int val, Node *left, Node *right) // 构造函数二 在传入值的基础上传入左右子节点
{
    this->val = val;
    this->left = left;
    this->right = right;
}

void BinaryTree::insert(Node *target_node, int node_val, bool left_or_right)
{
    // 在节点 target_node 的左或者右节点插入值为 node_val 的新节点
    // left_or_right 为 0 时代表左子节点
    if (target_node == NULL) // 父节点不存在
    {
        cout << "目标父节点不存在" << endl;
        return;
    }

    if (!left_or_right) // 目标位置为左节点
    {
        target_node->setLeft(new Node(node_val)); // 按输入值申请新节点最为当前父节点的左节点
    }
    else // 目标位置为右节点
    {
        target_node->setRight(new Node(node_val)); // 按输入值申请新节点最为当前父节点的右节点
    }
}

int BinaryTree::getDepth(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int leftDepth = getDepth(node->getLeft()); // 递归完返回根节点的左节点下的最大深度 下同
    int rightDepth = getDepth(node->getRight());

    return 1 + max(leftDepth, rightDepth); // 获取的根节点下的最大深度 +1 即为当前树的深度
}

void BinaryTree::show()
{
    if (this->root == NULL)
    {
        cout << "当前树为空" << endl;
        return;
    }

    int depth = getDepth(this->root);
    int width = pow(2, depth - 1) * 4;

    queue<Node *> queue;    // 使用队列进行数据存储
    queue.push(this->root); // 将节点push进队列

    // 以下为循环遍历每一层数据
    for (int i = 0; i < depth; i++)
    {
        int level_size = queue.size();           // 获取当前层的节点个数
        int padding = pow(2, depth - i - 1) - 1; // 获取当前层的节点个数 调整该值可以使树更好看
        int spacing = pow(2, depth - i) - 1;     // 当前层节点值之间的空格数

        // 循环遍历当前层的每个节点
        for (int j = 0; j < level_size; j++)
        {
            Node *node = queue.front(); // 在队列上进行pop操作
            queue.pop();

            cout << setw(padding) << ""; // 使用setw函数会默认在未满足宽度的剩余量上不补上空格 用此进行空格输出
            if (node != NULL)            // 节点不为空则正常输出节点值
            {
                cout << setw(2) << node->getVal();
                queue.push(node->getLeft()); // 将输出后的左右节点入队
                queue.push(node->getRight());
            }
            else // 无数值则输出空格并push null进队列进行占位 使得输出正常
            {
                cout << "  ";
                queue.push(NULL);
                queue.push(NULL);
            }
            cout << setw(spacing) << "";
        }

        cout << endl;
    }
}

void BinaryTree::preOrderTraversal_recursion(bool print_path = true)
{
    vector<int> path;                                      // 使用向量储存路径 用于路径输出
    preOrderTraversalHelper(this->root, print_path, path); // 进入递归函数进行递归
}

void BinaryTree::preOrderTraversalHelper(Node *node, bool print_path, vector<int> &path)
{
    if (node == NULL) // 节点为空直接return
    {
        return;
    }

    // 先输出根节点
    if (print_path) // 若需要 输出当前遍历到数据
    {
        for (int val : path)
        {
            cout << val << " -> ";
        }
        cout << node->getVal() << endl;
    }
    else
    {
        cout << node->getVal() << " ";
    }

    path.push_back(node->getVal()); // 将当前节点值加入路径 便于下一次递归调用路径
    // 对左右节点分别进行递归查找 先不断对左子节点进行递归 再逐步回调
    preOrderTraversalHelper(node->getLeft(), print_path, path);
    preOrderTraversalHelper(node->getRight(), print_path, path);
    path.pop_back();
}

void BinaryTree::postOrderTraversal_recursion(bool print_path = true)
{
    vector<int> path;
    postOrderTraversalHelper(this->root, print_path, path);
}

void BinaryTree::postOrderTraversalHelper(Node *node, bool print_path, vector<int> &path)
{
    // 与先序类似 只是输出顺序不同
    if (node == NULL)
    {
        return;
    }

    // 后序遍历 先对左子节点进行遍历 再对右节点 最后是根节点
    path.push_back(node->getVal());
    postOrderTraversalHelper(node->getLeft(), print_path, path);
    postOrderTraversalHelper(node->getRight(), print_path, path);

    if (print_path)
    {
        for (int val : path)
        {
            cout << val << " -> ";
        }
        cout << node->getVal() << endl;
    }
    else
    {
        cout << node->getVal() << " ";
    }

    path.pop_back();
}

void BinaryTree::levelOrderTraversal_recursion(bool print_path = true)
{
    levelOrderTraversalHelper(this->root, print_path);
}

void BinaryTree::levelOrderTraversalHelper(Node *node, bool print_path)
{
    if (node == NULL)
    {
        return;
    }

    queue<Node *> queue;
    queue.push(node);

    while (!queue.empty())
    {
        int level_size = queue.size();

        for (int i = 0; i < level_size; i++)
        {
            Node *node = queue.front();
            queue.pop();

            if (print_path)
            {
                cout << node->getVal() << endl;
            }
            else
            {
                cout << node->getVal() << " ";
            }

            if (node->getLeft() != NULL)
            {
                queue.push(node->getLeft());
            }
            if (node->getRight() != NULL)
            {
                queue.push(node->getRight());
            }
        }

        if (print_path)
        {
            cout << endl;
        }
    }
}

void BinaryTree::preOrderTraversal_norecursion(bool print_path = true)
{
    if (this->root == NULL)
    {
        cout << "当前树为空" << endl;
        return;
    }

    // 由于层次遍历为宽度优先搜索 其机制类似于堆栈的先入后出 在此处使用堆栈进行数据存储
    stack<Node *> s; // 创建新的堆栈用于储存节点
    s.push(this->root);
    vector<int> path;

    while (!s.empty())
    {
        Node *node = s.top(); // 查看栈顶
        s.pop();

        if (print_path)
        {
            for (int val : path)
            {
                cout << val << " -> ";
            }
            cout << node->getVal() << endl;
        }
        else
        {
            cout << node->getVal() << " ";
        }

        if (node->getRight() != NULL)
        {
            s.push(node->getRight());
        }
        if (node->getLeft() != NULL)
        {
            s.push(node->getLeft());
        }

        if (print_path)
        {
            path.push_back(node->getVal());
        }
    }
}

// 后序遍历 非递归
void BinaryTree::postOrderTraversal_norecursion(bool print_path = true)
{
    if (this->root == NULL)
    {
        cout << "Empty tree" << endl;
        return;
    }

    stack<Node *> s1, s2;
    s1.push(this->root);
    vector<int> path;

    while (!s1.empty())
    {
        Node *node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->getLeft() != NULL)
        {
            s1.push(node->getLeft());
        }
        if (node->getRight() != NULL)
        {
            s1.push(node->getRight());
        }

        if (print_path)
        {
            path.push_back(node->getVal());
        }
    }

    while (!s2.empty())
    {
        Node *node = s2.top();
        s2.pop();

        if (print_path)
        {
            for (int val : path)
            {
                cout << val << " -> ";
            }
            cout << node->getVal() << endl;
        }
        else
        {
            cout << node->getVal() << " ";
        }

        if (!path.empty())
        {
            path.pop_back();
        }
    }
}

// 层次遍历 非递归
void BinaryTree::levelOrderTraversal_norecursion(bool print_path = true)
{
    if (this->root == NULL)
    {
        cout << "Empty tree" << endl;
        return;
    }

    queue<Node *> queue;
    queue.push(this->root);
    vector<int> path;

    while (!queue.empty())
    {
        int level_size = queue.size();

        for (int i = 0; i < level_size; i++)
        {
            Node *node = queue.front();
            queue.pop();

            if (print_path)
            {
                for (int val : path)
                {
                    cout << val << " -> ";
                }
                cout << node->getVal() << endl;
            }
            else
            {
                cout << node->getVal() << " ";
            }

            if (node->getLeft() != NULL)
            {
                queue.push(node->getLeft());
            }
            if (node->getRight() != NULL)
            {
                queue.push(node->getRight());
            }
        }

        if (print_path)
        {
            for (int i = 0; i < level_size; i++)
            {
                path.pop_back();
            }
        }

        if (print_path)
        {
            for (int i = 0; i < level_size; i++)
            {
                path.push_back(-1);
            }
        }
    }
}

// 先序遍历查找
Node *BinaryTree::searchPreorder(int val, vector<Node *> &path)
{
    Node *node_temp = searchLevelOrderHelper(root, val, path);
    if (node_temp == NULL)
        cout << "查找失败，未查找到目标" << endl;

    return node_temp;
}

// 后序遍历查找
Node *BinaryTree::searchPostorder(int val, vector<Node *> &path)
{
    return searchPostorderHelper(root, val, path);
}

// 层次遍历查找
Node *BinaryTree::searchLevelOrder(int val, vector<Node *> &path)
{
    Node *node_temp = searchLevelOrderHelper(root, val, path);
    if (node_temp == NULL)
        cout << "查找失败，未查找到目标" << endl;

    return node_temp;
}

// 先序遍历查找辅助方法
Node *BinaryTree::searchPreorderHelper(Node *node, int val, vector<Node *> &path)
{
    if (node == NULL)
    {
        return NULL;
    }

    path.push_back(node);

    if (node->getVal() == val)
    {
        return node;
    }

    Node *left = searchPreorderHelper(node->getLeft(), val, path);
    if (left != NULL)
    {
        return left;
    }

    Node *right = searchPreorderHelper(node->getRight(), val, path);
    if (right != NULL)
    {
        return right;
    }

    path.pop_back();

    return NULL;
}

// 后序遍历查找辅助方法
Node *BinaryTree::searchPostorderHelper(Node *node, int val, vector<Node *> &path)
{
    if (node == NULL)
    {
        return NULL;
    }

    Node *left = searchPostorderHelper(node->getLeft(), val, path);
    if (left != NULL)
    {
        path.push_back(node);
        return left;
    }

    Node *right = searchPostorderHelper(node->getRight(), val, path);
    if (right != NULL)
    {
        path.push_back(node);
        return right;
    }

    if (node->getVal() == val)
    {
        path.push_back(node);
        return node;
    }

    return NULL;
}

// 层次遍历查找辅助方法
Node *BinaryTree::searchLevelOrderHelper(Node *node, int val, vector<Node *> &path)
{
    if (node == NULL)
    {
        return NULL;
    }

    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        Node *n = q.front();
        q.pop();

        path.push_back(n);

        if (n->getVal() == val)
        {
            return n;
        }

        if (n->getLeft() != NULL)
        {
            q.push(n->getLeft());
        }

        if (n->getRight() != NULL)
        {
            q.push(n->getRight());
        }
    }

    return NULL;
}

void searchPath_show(Node *node, int val, vector<Node *> path)
{
    if (node != nullptr)
    {
        cout << "成功查找到：" << val << "！";
        cout << "查找路劲为: ";
        for (auto n : path)
        {
            cout << n->getVal() << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "未找到数值：" << val << endl;
    }
}