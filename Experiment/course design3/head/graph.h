#ifndef __GRAPH_H
#define __GRAPH_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph; // 邻接矩阵
    int A, B, C, D, E, F, G;

public:
    Graph(int n); // 构造函数 指定节点个数

    void set_num(int a, int b, int c, int d, int e, int f, int g); // 设置图中数值函数

    void add_edge(int u, int v, int w = 1); // 加入边 w为权重

    void show_matrix(); // 显示邻接矩阵

    void show_graph_struct(); // 显示图的结构

    void show_graph(); // 显示图的结构-带数值

    void show_side(); // 显示边的情况

    void bfs(int start, int target, bool show_path = 1); // 广度优先搜索

    void dfs(int start, int target, bool show_path = 1); // 深度优先搜索

    void bfs_traverse(int start); // 广度优先遍历

    void dfs_traverse(int start); // 深度优先遍历

    void show_paths(int start, int end); // 将显示两点间路径

    void paths(int cur, int end, vector<int> &path, vector<vector<int>> &all_paths); // 显示两点间路径
};

#endif