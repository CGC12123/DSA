#include "head/graph.h"

int main()
{
    // 创建一个7个顶点的图
    Graph g(7);
    g.add_edge(1, 6);
    g.add_edge(1, 7);
    g.add_edge(2, 3);
    g.add_edge(2, 7);
    g.add_edge(3, 5);
    g.add_edge(4, 5);
    g.add_edge(4, 7);
    g.add_edge(5, 6);
    g.add_edge(6, 7);

    cout << "当前图结构为：" << endl;
    g.show_graph_struct();

    cout << endl;
    cout << "当前图临界矩阵为：" << endl;
    g.show_matrix(); // 打印邻接矩阵
    cout << endl;

    cout << "当前图的所有边为：";
    g.show_side();
    cout << "(由于为无向图，故在此处重复的边不重复展示)" << endl
         << endl;

    cout << "----------------------------------------------------------------" << endl
         << endl;

    /////////////////// 以下为输入数据及处理部分 ///////////////////////

    int A, B, C, D, E, F, G; // 图数据
    bool mode = 0;
    cout << "请选择图数值初始化方法：按照默认初始化(0) 自定义初始化(1): ";
    cin >> mode;
    if (!mode)
    {
        A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6;
    }
    else
    {
        cout << "请以此输入A~G: ";
        cin >> A >> B >> C >> D >> E >> F >> G;
    }
    g.set_num(A, B, C, D, E, F, G); // 完成图的构造

    cout << "当前图为：" << endl;
    g.show_graph(); // 可视化当前图
    cout << endl;

    if (!mode)
    {
        cout << "以下为示例搜索及查找示例：" << endl;
    }

    cout << endl;
    cout << "广度优先：" << endl;
    g.bfs(4, 1, true);
    g.bfs_traverse(4);

    cout << "深度优先：" << endl;
    g.dfs(0, 1, true);
    g.dfs_traverse(0);

    cout << endl;

    int point1, point2;
    point1 = 1, point2 = 4;
    cout << "获取" << point1 << "与" << point2 << "之间的路径" << endl;
    g.show_paths(point1, point2);

    return 0;
}