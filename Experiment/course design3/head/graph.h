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
    Graph(int n);

    void set_num(int a, int b, int c, int d, int e, int f, int g);

    void add_edge(int u, int v, int w = 1);

    void show_matrix();

    void show_graph_struct();

    void show_graph();

    void show_side();

    void dfs(int start, int target, bool show_path = 1);

    void bfs(int start, int target, bool show_path = 1);

    void dfs_traverse(int start);

    void bfs_traverse(int start);

    void show_paths(int start, int end);

    void dfs_paths(int cur, int end, vector<int> &path, vector<vector<int>> &all_paths);
};

#endif