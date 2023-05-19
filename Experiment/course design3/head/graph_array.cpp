#include "graph_array.h"

Graph::Graph(int n)
{
    num_vertices = n;
    matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0; // 邻接矩阵初始化
        }
    }
}

void Graph::add_edge(int u, int v, int w)
{
    u = u - 1;
    v = v - 1;
    matrix[u][v] = w;
    matrix[v][u] = w;
}

void Graph::show_matrix()
{
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::set_num(int a, int b, int c, int d, int e, int f, int g)
{
    matrix[0][3] = d; // A-D
    matrix[0][4] = e; // A-E
    matrix[1][2] = c; // B-C
    matrix[1][3] = f; // B-D
    matrix[1][6] = g; // B-G
    matrix[2][5] = b; // C-F
    matrix[3][4] = a; // D-E
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
    cout << "|       " << get_node(5) << "      " << get_node(6) << endl;
    cout << "|       | \\   / \\" << endl;
    cout << "|       |  \\ /   \\" << endl;
    cout << "|———" << get_node(3) << "   |   " << get_node(0) << "     " << get_node(1) << endl;
    cout << "     \\  |        /" << endl;
    cout << "      \\ |       /" << endl;
    cout << "        " << get_node(4) << " —————" << get_node(2) << endl;
}

void Graph::show_side()
{
    for (int i = 0; i < num_vertices; i++)
    {
        cout << "节点 " << get_node(i) << " 的相邻节点：";
        for (int j = 0; j < num_vertices; j++)
        {
            if (matrix[i][j] != 0)
            {
                cout << get_node(j) << " ";
            }
        }
        cout << endl;
    }
}

void Graph::dfs(int start, int target, bool show_path)
{
    vector<bool> visited(num_vertices, false); // 储存已访问过的节点
    vector<int> parent(num_vertices, -1);      // 储存访问路径
    stack<int> stack;                          // 深度优先使用堆栈进行储存节点

    stack.push(start);
    visited[start] = true; // 设置为已访问过

    while (!stack.empty())
    {
        int current = stack.top(); // 将栈顶数据读取并pop掉
        stack.pop();

        if (current == target)
        {
            if (show_path)
            {
                int node = current;
                vector<int> path;
                while (node != -1)
                {
                    path.push_back(node);
                    node = parent[node];
                }
                reverse(path.begin(), path.end());
                for (int i = 0; i < path.size(); i++)
                {
                    cout << get_node(path[i]) << " ";
                }
                cout << endl;
            }
            return;
        }

        for (int i = 0; i < num_vertices; i++)
        {
            if (matrix[current][i] != 0 && !visited[i])
            {
                stack.push(i);
                visited[i] = true;
                parent[i] = current;
            }
        }
    }

    cout << "从节点 " << get_node(start) << " 到节点 " << get_node(target) << " 的深度优先搜索路径不存在" << endl;
}

void Graph::bfs(int start, int target, bool show_path)
{
    queue<int> queue;
    vector<bool> visited(num_vertices, false);
    vector<int> parent(num_vertices, -1);

    queue.push(start);
    visited[start] = true;

    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        if (current == target)
        {
            if (show_path)
            {
                int node = current;
                vector<int> path;
                while (node != -1)
                {
                    path.push_back(node);
                    node = parent[node];
                }
                reverse(path.begin(), path.end());
                for (int i = 0; i < path.size(); i++)
                {
                    cout << get_node(path[i]) << " ";
                }
                cout << endl;
            }
            return;
        }

        for (int i = 0; i < num_vertices; i++)
        {
            if (matrix[current][i] != 0 && !visited[i])
            {
                queue.push(i);
                visited[i] = true;
                parent[i] = current;
            }
        }
    }

    cout << "从节点 " << get_node(start) << " 到节点 " << get_node(target) << " 的广度优先搜索路径不存在" << endl;
}

void Graph::dfs_traverse(int start)
{
    stack<int> stack;
    vector<bool> visited(num_vertices, false);

    stack.push(start);
    visited[start] = true;

    cout << "深度优先搜索遍历：";

    while (!stack.empty())
    {
        int current = stack.top();
        stack.pop();
        cout << get_node(current) << " ";

        for (int i = 0; i < num_vertices; i++)
        {
            if (matrix[current][i] != 0 && !visited[i])
            {
                stack.push(i);
                visited[i] = true;
            }
        }
    }

    cout << endl;
}

void Graph::bfs_traverse(int start)
{
    queue<int> queue;
    vector<bool> visited(num_vertices, false);

    queue.push(start);
    visited[start] = true;

    cout << "广度优先搜索遍历：";

    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();
        cout << get_node(current) << " ";

        for (int i = 0; i < num_vertices; i++)
        {
            if (matrix[current][i] != 0 && !visited[i])
            {
                queue.push(i);
                visited[i] = true;
            }
        }
    }

    cout << endl;
}

void Graph::show_paths(int start, int end)
{
    vector<vector<int>> all_paths;
    vector<int> path;

    paths(start, end, path, all_paths);

    cout << "从节点 " << get_node(start) << " 到节点 " << get_node(end) << " 的所有路径：" << endl;

    int shortest_path_length = INT_MAX;
    int longest_path_length = INT_MIN;
    vector<int> shortest_path;
    vector<int> longest_path;

    for (int i = 0; i < all_paths.size(); i++)
    {
        int path_length = all_paths[i].size();
        if (path_length < shortest_path_length)
        {
            shortest_path_length = path_length;
            shortest_path = all_paths[i];
        }
        if (path_length > longest_path_length)
        {
            longest_path_length = path_length;
            longest_path = all_paths[i];
        }

        cout << "搜索路径：";
        for (int j = 0; j < all_paths[i].size(); j++)
        {
            cout << get_node(all_paths[i][j]) << " ";
        }
        cout << "，所用搜索次数: " << path_length - 1 << endl;
    }

    cout << "最短搜索路径：";
    for (int i = 0; i < shortest_path.size(); i++)
    {
        cout << get_node(shortest_path[i]) << " ";
    }
    cout << "，搜索次数：" << shortest_path_length - 1 << endl;

    cout << "最长搜索路径：";
    for (int i = 0; i < longest_path.size(); i++)
    {
        cout << get_node(longest_path[i]) << " ";
    }
    cout << "，搜索次数：" << longest_path_length - 1 << endl;
}

void Graph::paths(int cur, int end, vector<int> &path, vector<vector<int>> &all_paths)
{
    path.push_back(cur);

    if (cur == end)
    { // 到达终点
        all_paths.push_back(path);
        return;
    }
    else
    { // 遍历相邻节点
        for (int i = 0; i < num_vertices; i++)
        {
            if (matrix[cur][i] != 0 && find(path.begin(), path.end(), i) == path.end())
            {
                paths(i, end, path, all_paths);
            }
        }
    }

    path.pop_back();
}

string Graph::get_node(int num)
{
    string node;
    switch (num)
    {
    case 0:
        node = "A";
        break;
    case 1:
        node = "B";
        break;
    case 2:
        node = "C";
        break;
    case 3:
        node = "D";
        break;
    case 4:
        node = "E";
        break;
    case 5:
        node = "F";
        break;
    case 6:
        node = "G";
        break;
    default:
        node = "未知";
        break;
    }
    return node;
}