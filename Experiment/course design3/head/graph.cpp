#include "graph.h"

Graph::Graph(int n)
{
    // 构造函数，n为顶点数
    graph.resize(n, vector<int>(n, 0)); // 邻接矩阵初始化
}

void Graph::add_edge(int u, int v, int w)
{
    // 添加边
    u = u - 1;
    v = v - 1;
    graph[u][v] = w;
    graph[v][u] = w;
}

void Graph::show_matrix()
{
    // 打印邻接矩阵
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::set_num(int a, int b, int c, int d, int e, int f, int g)
{
    A = a;
    B = b;
    C = c;
    D = d;
    E = e;
    F = f;
    G = g;
}

void Graph::show_graph_struct()
{
    cout << "_______________" << endl;
    cout << "|              |" << endl;
    cout << "|       F      G" << endl;
    cout << "|       | \\   / \\" << endl;
    cout << "|       |  \\ /   \\" << endl;
    cout << "|———D   |   A     B" << endl;
    cout << "     \\  |        /" << endl;
    cout << "      \\ |       /" << endl;
    cout << "        E —————C" << endl;
}

void Graph::show_graph()
{
    cout << "_______________" << endl;
    cout << "|              |" << endl;
    cout << "|       " << F << "      " << G << endl;
    cout << "|       | \\   / \\" << endl;
    cout << "|       |  \\ /   \\" << endl;
    cout << "|———" << D << "   |   " << A << "     " << B << endl;
    cout << "     \\  |        /" << endl;
    cout << "      \\ |       /" << endl;
    cout << "        " << E << " —————" << C << endl;
}

void Graph::show_side()
{
    // 利用邻接矩阵进行输出
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = i; j < graph.size(); j++)
        {
            if (graph[i][j] == 1)
            {
                cout << "(" << char(65 + i) << "," << char(65 + j) << ") "; // 换算成A~G
            }
        }
    }
    cout << endl;
}

void Graph::dfs(int start, int target, bool show_path)
{
    // show_path为true时才输出路径
    vector<bool> visited(graph.size(), false); // 储存已访问过的节点
    vector<int> path(graph.size(), -1);        // 储存访问路径
    stack<int> s;                              // 深度优先使用堆栈进行储存节点
    s.push(start);                             // 将初始访问的点放入堆栈
    visited[start] = true;                     // 设置为已访问过
    int found_target = -1;                     // 标志位记录是否找到目标
    while (!s.empty() && found_target == -1)   // 在找到目标或遍历完所有点之前进行不断操作
    {
        int cur = s.top(); // 将栈顶数据读取并pop掉
        s.pop();
        if (cur == target)
        {
            cout << endl
                 << "成功找到目标：" << get_node(target) << endl;
            found_target = target; // 将标志位更改
        }
        for (int i = 0; i < graph[cur].size(); ++i) // 对于邻接矩阵的当前行进行遍历并将所有未访问点进行push
        {
            if (graph[cur][i] != 0 && !visited[i])
            {
                s.push(i);
                visited[i] = true;
                path[i] = cur;
            }
        }
    }
    // 以下为输出访问路径
    if (found_target != -1 && show_path)
    {
        cout << "目标节点 " << get_node(target) << " 的搜索路径为：";
        if (path[target] == -1)
        {
            cout << "未找到路径" << endl;
        }
        else
        {
            cout << get_node(target);
            int parent = path[target];
            while (parent != start) // 使用储存访问路径的向量进行输出
            {
                cout << " <- " << get_node(parent);
                parent = path[parent];
            }
            cout << " <- " << get_node(start) << endl;
        }
    }
}

void Graph::bfs(int start, int target, bool show_path)
{
    // 广度优先和深度优先类似 广度优先在open表为先入先出 使用队列进行操作 其他与深度优先类似
    // cout << "初始搜索节点：" << start << ":" << endl;
    vector<bool> visited(graph.size(), false);
    vector<int> path(graph.size(), -1);
    queue<int> q; // 使用队列进行储存
    q.push(start);
    visited[start] = true;
    int found_target = -1;
    while (!q.empty() && found_target == -1)
    {
        int cur = q.front();
        q.pop();
        // cout << cur << " ";
        if (cur == target)
        {
            cout << "成功找到目标：" << get_node(target) << endl;
            found_target = target;
        }
        for (int i = 0; i < graph[cur].size(); ++i)
        {
            if (graph[cur][i] != 0 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
                path[i] = cur;
            }
        }
    }
    if (found_target != -1 && show_path)
    {
        // cout << "搜索路径为：" << endl;
        cout << "目标节点 " << get_node(target) << " 的搜索路径为：";
        if (path[target] == -1)
        {
            cout << "未找到路径" << endl;
        }
        else
        {
            cout << get_node(target) << " <- ";
            int parent = path[target];
            while (parent != start)
            {
                cout << get_node(parent) << " <- ";
                parent = path[parent];
            }
            cout << get_node(start) << endl;
        }
    }
}

void Graph::dfs_traverse(int start)
{
    // 与搜索部分大体逻辑一致
    //  cout << "遍历初始节点：" << start << ":" << endl;
    vector<bool> visited(graph.size(), false);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        cout << get_node(cur) << " ";
        for (int j = 0; j < graph[cur].size(); ++j)
        {
            if (graph[cur][j] != 0 && !visited[j])
            {
                s.push(j);
                visited[j] = true;
            }
        }
    }
    cout << endl;
}

void Graph::bfs_traverse(int start)
{
    // 与搜索部分大体逻辑一致
    // cout << "广度优先遍历初始节点：" << start << ":" << endl;
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << get_node(cur) << " ";
        for (int j = 0; j < graph[cur].size(); ++j)
        {
            if (graph[cur][j] != 0 && !visited[j])
            {
                q.push(j);
                visited[j] = true;
            }
        }
    }
    cout << endl;
}

void Graph::show_paths(int start, int end)
{
    // 搜索两个节点之间的路径
    vector<vector<int>> all_paths; // 二位向量 存储所有路径
    vector<int> path;              // 当前路径
    path.push_back(start);
    paths(start, end, path, all_paths); // 进入辅助函数

    // 找到最长和最短路径
    int max_path_length = 0, min_path_length = 0;
    for (auto p : all_paths)
    {
        int path_length = p.size();
        if (path_length > max_path_length)
        {
            max_path_length = path_length;
        }

        if (path_length < min_path_length || min_path_length == 0)
        {
            min_path_length = path_length;
        }
    }

    // 输出所有路径及路径边数
    for (auto p : all_paths)
    {
        int edges = 0;
        cout << "搜索路径：";
        for (auto v : p)
        {
            cout << get_node(v) << " ";
            edges++;
        }
        cout << "， 所用搜索次数: " << edges << endl;
    }

    // 输出最长路径
    cout << "最长搜索路径：";
    for (auto p : all_paths)
    {
        if (p.size() == max_path_length)
        {
            for (auto v : p)
            {
                cout << get_node(v) << " ";
            }
            cout << "，搜索次数：" << p.size() << endl;
        }
    }

    // 输出最短路径
    cout << "最短搜索路径：";
    for (auto p : all_paths)
    {
        if (p.size() == min_path_length)
        {
            for (auto v : p)
            {
                cout << get_node(v) << " ";
            }
            cout << "，搜索次数：" << p.size() << endl;
        }
    }
}

void Graph::paths(int cur, int end, vector<int> &path, vector<vector<int>> &all_paths)
{
    if (cur == end)
    { // 到达终点
        all_paths.push_back(path);
        return;
    }
    for (int i = 0; i < graph[cur].size(); i++)
    { // 遍历相邻节点
        if (graph[cur][i] != 0)
        {
            if (find(path.begin(), path.end(), i) == path.end()) // 避免形成环路
            {
                path.push_back(i);
                paths(i, end, path, all_paths); // 深度优先遍历
                path.pop_back();                // 回溯
            }
        }
    }
}

string Graph::get_node(int num)
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
    else
        return "null";
}