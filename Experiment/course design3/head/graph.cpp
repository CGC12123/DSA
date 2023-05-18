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
                cout << "(" << char(65 + i) << "," << char(65 + j) << ") ";
            }
        }
    }
    cout << endl;
}

void Graph::dfs(int start, int target, bool show_path)
{
    cout << "初始搜索节点：" << start << ":" << endl;
    vector<bool> visited(graph.size(), false);
    vector<int> path(graph.size(), -1);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        cout << cur << " ";
        if (cur == target)
        {
            cout << endl
                 << "成功找到目标：" << target << endl;
            return;
        }
        for (int i = 0; i < graph[cur].size(); ++i)
        {
            if (graph[cur][i] != 0 && !visited[i])
            {
                s.push(i);
                visited[i] = true;
                path[i] = cur;
            }
        }
    }
    cout << endl;
    if (show_path)
    {
        cout << "搜索路径为：";
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] != -1)
            {
                cout << i << " <- ";
                int parent = path[i];
                while (parent != start)
                {
                    cout << parent << " <- ";
                    parent = path[parent];
                }
                cout << start << endl;
            }
        }
    }
}

void Graph::bfs(int start, int target, bool show_path)
{
    cout << "初始搜索节点：" << start << ":" << endl;
    vector<bool> visited(graph.size(), false);
    vector<int> path(graph.size(), -1);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        if (cur == target)
        {
            cout << endl
                 << "成功找到目标：" << target << endl;
            return;
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
    cout << endl;
    if (show_path)
    {
        cout << "搜索路径为：" << endl;
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] != -1)
            {
                cout << i << " <- ";
                int parent = path[i];
                while (parent != start)
                {
                    cout << parent << " <- ";
                    parent = path[parent];
                }
                cout << start << endl;
            }
        }
    }
}

void Graph::dfs_traverse(int start)
{
    cout << "遍历初始节点：" << start << ":" << endl;
    vector<bool> visited(graph.size(), false);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        cout << cur << " ";
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
    cout << "广度优先遍历初始节点：" << start << ":" << endl;
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
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
    vector<vector<int>> all_paths; // 存储所有路径
    vector<int> path;              // 当前路径
    path.push_back(start);
    dfs_paths(start, end, path, all_paths);

    // 显示路径及路径边数
    for (auto p : all_paths)
    {
        int edges = 0;
        cout << "搜索路径：";
        for (auto v : p)
        {
            cout << v << " ";
            edges++;
        }
        cout << "， 所用搜索次数: " << edges << endl;
    }

    // 找到最长和最短路径
    int max_path = 0, min_path = 0;
    for (int i = 0; i < all_paths.size(); i++)
    {
        if (all_paths[i].size() > max_path)
        {
            max_path = i;
        }
        if (all_paths[i].size() < min_path || min_path == 0)
        {
            min_path = i;
        }
    }
    cout << "最长搜索路径：";
    for (auto v : all_paths[max_path])
        cout << v << " ";
    cout << "，搜索次数：" << all_paths[max_path].size() << endl;
    cout << "最短搜索路径：";
    for (auto v : all_paths[min_path])
        cout << v << " ";
    cout << "，搜索次数：" << all_paths[min_path].size() << endl;
}

void Graph::dfs_paths(int cur, int end, vector<int> &path, vector<vector<int>> &all_paths)
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
                dfs_paths(i, end, path, all_paths); // 深度优先遍历
                path.pop_back();                    // 回溯
            }
        }
    }
}