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

void BinaryTree::set_num(int a, int b, int c, int d, int e, int f, int g, int h)
{
    A = A, B = B, C = C, D = D, E = E, F = F, G = G, H = H;
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
    vector<int> path;                                // 使用向量储存路径 用于路径输出
    preOrderTraversal(this->root, print_path, path); // 进入递归函数进行递归
}

void BinaryTree::preOrderTraversal(Node *node, bool print_path, vector<int> &path)
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
    preOrderTraversal(node->getLeft(), print_path, path);
    preOrderTraversal(node->getRight(), print_path, path);
    path.pop_back();
}

void BinaryTree::postOrderTraversal_recursion(bool print_path = true)
{
    vector<int> path;
    postOrderTraversal(this->root, print_path, path);
}

void BinaryTree::postOrderTraversal(Node *node, bool print_path, vector<int> &path)
{
    // 与先序类似 只是输出顺序不同
    if (node == NULL)
    {
        return;
    }

    // 后序遍历 先对左子节点进行遍历 再对右节点 最后是根节点
    path.push_back(node->getVal());
    postOrderTraversal(node->getLeft(), print_path, path);
    postOrderTraversal(node->getRight(), print_path, path);

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

void BinaryTree::levelOrderTraversal_recursion()
{
    levelOrderTraversal(this->root);
}

void BinaryTree::levelOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    // 宽度优先搜索思想 与队列思想类似 创建队列用于储存节点
    queue<Node *> queue;
    queue.push(node);

    while (!queue.empty())
    {
        int level_size = queue.size(); // 记录当前队列的size 用于遍历

        for (int i = 0; i < level_size; i++)
        {
            Node *node = queue.front(); // 读取队列头 并将其pop
            queue.pop();

            cout << node->getVal() << " "; // 输出队列头的值

            if (node->getLeft() != NULL)
            {
                queue.push(node->getLeft()); // 左节点入队
            }
            if (node->getRight() != NULL)
            {
                queue.push(node->getRight()); // 右节点入队
            }
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

    // 由于先序遍历的节点先进入的其右节点往往最后才被读取 其机制类似于堆栈的先入后出 在此处使用堆栈进行数据存储
    stack<Node *> s; // 创建新的堆栈用于储存节点
    s.push(this->root);
    vector<int> path; // 创建向量储存遍历路径

    while (!s.empty())
    {
        Node *node = s.top(); // 当前栈顶元素
        s.pop();              // 读取后将其pop

        if (print_path) // 若需要 输出当前已遍历过的路径
        {
            for (int val : path)
            {
                cout << val << " -> ";
            }
            cout << node->getVal() << endl;
        }
        else // 否则只需要一次输出当前值即可
        {
            cout << node->getVal() << " ";
        }

        if (node->getRight() != NULL)
        {
            s.push(node->getRight()); // 将右节点入栈
        }
        if (node->getLeft() != NULL)
        {
            s.push(node->getLeft()); // 将左节点入栈
        }

        if (print_path) // 若有输出需求则将当前值保存 便于下一次调用
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
        cout << "当前树为空" << endl;
        return;
    }

    // 由于后序遍历最后输出节点值 其读取完左右儿子不能直接将当前节点pop 在此处申请两个堆栈分别储存左右儿子的节点
    // 其余步骤与先序遍历大同小异
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
        cout << "当前树为空" << endl;
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

void BinaryTree::searchpreOrderTraversal(bool print_path, int target_num)
{
    vector<int> path;                                                   // 使用向量储存路径 用于路径输出
    searchpreOrderTraversal_(this->root, print_path, path, target_num); // 进入递归函数进行递归
}

void BinaryTree::searchpreOrderTraversal_(Node *node, bool print_path, vector<int> &path, int target_num)
{
    if (node == NULL) // 节点为空直接return
    {
        return;
    }

    search_pre.push_back(node->getVal()); // 公有 用于储存遍历过的数据 不覆盖

    path.push_back(node->getVal()); // 将当前节点值加入路径 便于下一次递归调用路径
    // 对左右节点分别进行递归查找 先不断对左子节点进行递归 再逐步回调
    searchpreOrderTraversal_(node->getLeft(), print_path, path, target_num);
    searchpreOrderTraversal_(node->getRight(), print_path, path, target_num);
    path.pop_back();
}

void BinaryTree::searchpostOrderTraversal(bool print_path, int target_num)
{
    vector<int> path;
    searchpostOrderTraversal_(this->root, print_path, path, target_num);
}

void BinaryTree::searchpostOrderTraversal_(Node *node, bool print_path, vector<int> &path, int target_num)
{
    if (node == NULL) // 节点为空直接return
    {
        return;
    }

    path.push_back(node->getVal()); // 将当前节点值加入路径 便于下一次递归调用路径
    // 对左右节点分别进行递归查找 先不断对左子节点进行递归 再逐步回调
    searchpostOrderTraversal_(node->getLeft(), print_path, path, target_num);
    searchpostOrderTraversal_(node->getRight(), print_path, path, target_num);

    search_post.push_back(node->getVal()); // 公有 用于储存遍历过的数据 不覆盖

    path.pop_back();
}

// 层次遍历查找
Node *BinaryTree::searchLevelOrder(int val, vector<Node *> &path)
{
    Node *node_temp = searchLevelOrder_(root, val, path);
    if (node_temp == NULL)
        cout << "查找失败，未查找到目标" << endl;

    return node_temp;
}

// 层次遍历查找辅助方法
Node *BinaryTree::searchLevelOrder_(Node *node, int val, vector<Node *> &path)
{
    if (node == NULL)
    {
        return NULL;
    }

    queue<Node *> q; // 构造队列
    q.push(node);    // push节点

    while (!q.empty()) // 只要队列中有节点就将其取出并将其从队列中pop
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

void BinaryTree::show_search_path(vector<int> search, int target_num)
{
    vector<int> path; // 保存搜索路径中经过的所有节点
    bool found = false;

    // 保存所有匹配的位置
    vector<int> target_indices;
    for (int i = 0; i < search.size(); i++)
    {
        path.push_back(search[i]);
        if (search[i] == target_num)
        {
            found = true;
            target_indices.push_back(i);
        }
    }

    // 输出所有匹配的位置及其对应的搜索路径
    if (found)
    {
        for (int i = 0; i < target_indices.size(); i++)
        {
            int index = target_indices[i];
            cout << "成功查找到：" << target_num << "！"
                 << "其路径为：";
            for (int j = 0; j <= index; j++)
            {
                cout << path[j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "未找到：" << target_num << endl;
    }
}

void searchPath_show(Node *node, int val, vector<Node *> path)
{
    if (node != nullptr)
    {
        cout << "成功查找到：" << val << "！";
        cout << "查找路径为: ";
        for (auto n : path)
        {
            cout << n->getVal() << " ";
        }
        cout << endl;
    }
}

string BinaryTree::get_node(int num)
{
    if (num == A)
        return "A";
    else if (num == B)
        return "B";
    else if (num == C)
        return "C";
    else if (num == D)
        return "D";
    else if (num == E)
        return "E";
    else if (num == F)
        return "F";
    else if (num == G)
        return "G";
    else if (num == H)
        return "H";
    else
        return "null";
}