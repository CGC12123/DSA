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
    cout << "当前图邻接矩阵为：" << endl;
    g.show_matrix(); // 打印邻接矩阵
    cout << endl;

    cout << "当前图的所有边为：";
    g.show_side();
    cout << "(此为无向图，在此处重复的边不重复展示)" << endl
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

    while (true)
    {
        cout << "请输入功能：输出当前图(1) 查找(2) 遍历(3) 获取两点间路径(4) 退出(5)" << endl;
        int mode2;
        cin >> mode2;

        switch (mode2)
        {
        case 1:
        {
            cout << "当前图为：" << endl;
            g.show_graph(); // 可视化当前图
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "----------------------------------------------------------------" << endl;
            map<string, int> variables;
            variables["A"] = A, variables["B"] = B, variables["C"] = C, variables["D"] = D;
            variables["E"] = E, variables["F"] = F, variables["G"] = G;
            string target, start;
            cout << "请选择要进行查找的节点(A~G)：";
            cin >> target;
            if (variables.find(target) != variables.end())
            {
            }
            else
            {
                cout << "输入的节点不存在" << endl;
                break;
            }
            cout << "请选择要从何节点(A~G)开始查找：";
            cin >> start;
            if (variables.find(start) != variables.end())
            {
            }
            else
            {
                cout << "输入的节点不存在" << endl;
                break;
            }
            cout << endl;
            cout << "从" << start << "(" << variables[start] << ")"
                 << "开始搜索" << target << "(" << variables[target] << ")" << endl << endl;
            cout << "广度优先查找：" << endl;
            g.bfs(variables[start], variables[target], true);
            cout << endl;
            cout << "深度优先查找：";
            g.dfs(variables[start], variables[target], true);
            cout << endl;
            break;
        }
        case 3:
        {
            cout << "----------------------------------------------------------------" << endl;
            map<string, int> variables;
            variables["A"] = A, variables["B"] = B, variables["C"] = C, variables["D"] = D;
            variables["E"] = E, variables["F"] = F, variables["G"] = G;
            string node;
            cout << "请选择要开始进行遍历的节点(A~G)：";
            cin >> node;
            if (variables.find(node) != variables.end())
            {
            }
            else
            {
                cout << "输入的节点不存在" << endl;
                break;
            }
            cout << "请输入开始的遍历节点(A~H)" << endl;
            cout << "从" << node << "(" << variables[node] << ")"
                 << "开始遍历" << endl;
            cout << "广度优先遍历：" << endl;
            g.bfs_traverse(variables[node]);
            cout << "深度优先遍历：" << endl;
            g.dfs_traverse(variables[node]);
            break;
        }
        case 4:
        {
            cout << "----------------------------------------------------------------" << endl;
            map<string, int> variables;
            variables["A"] = A, variables["B"] = B, variables["C"] = C, variables["D"] = D;
            variables["E"] = E, variables["F"] = F, variables["G"] = G;
            cout << "请依次输入要进行查找的两个节点：";
            string compare_a, compare_b;
            cin >> compare_a >> compare_b;
            if (variables.find(compare_a) != variables.end())
            {
            }
            else
            {
                cout << "输入的节点不存在" << endl;
            }
            cout << "获取" << compare_a << "(" << variables[compare_a] << ")"
                 << "与" << compare_b << "(" << variables[compare_b] << ")"
                 << "之间的路径" << endl;
            g.show_paths(variables[compare_a], variables[compare_b]);
        }
        }
        if (mode2 == 5)
        {
            cout << "系统退出" << endl;
            break;
        }
    }

    return 0;
}