// 使用数组实现
#include "head/list_array.h"

int main()
{
    Vector list(1, -1);

    cout << "请输入初始化数据：(以0为结束)" << endl;
    list.init();

    char module;
    while (true)
    {
        cout << "请选择操作: 插入(i) 删除(d) 查找(f) 输出(o) 退出(e)" << endl;
        cin >> module;
        switch (module)
        {
        case 'i':
        {
            int pos, num;
            cout << "请输入插入的位置：";
            cin >> pos;
            cout << "请输入插入的数据：";
            cin >> num;

            list.insert(pos, num);

            break;
        }
        case 'd':
        {
            int num;
            cout << "请输入要删除的数据：";
            cin >> num;

            list.remove(num);

            break;
        }
        case 'f':
        {
            int num;
            cout << "请输入要找到数据：";
            cin >> num;
            list.findIndex(num);
            break;
        }
        case 'o':
        {
            list.show();
            break;
        }
        }
        if (module == 'e')
        {
            cout << "系统退出" << endl;
            break;
        }
    }

    return 0;
}