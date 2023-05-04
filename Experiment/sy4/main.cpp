#include "../template/vector.h"

int main()
{
    int UnSortedVector31[] = {6, 3, 2, 7, 1, 5, 8, 4};
    Vector UnSesrchA(8, -1);
    UnSesrchA.add_vector(UnSortedVector31, 0, 8);

    Vector UnSesrchB(8, -1);
    UnSesrchB.add_vector(UnSortedVector31, 0, 8);

    Vector UnSesrchC(8, -1);
    UnSesrchC.add_vector(UnSortedVector31, 0, 8);

    cout << "orinal vector: ";
    UnSesrchA.show();
    
    cout << "merge in [0, 8): ";
    UnSesrchA.mergeSort(0, 7);
    UnSesrchA.show();

    cout << "merge in [0, 7): ";
    UnSesrchB.mergeSort(0, 6);
    UnSesrchB.show();

    cout << "merge in [3, 6): ";
    UnSesrchC.mergeSort(3, 5);
    UnSesrchC.show();

    // 以下为对比归并与冒泡
    cout << endl;
    cout << "The following is a comparison of bubbling and merging" << endl;
    cout << "Count a thousand random data to sort and record time" << endl;
    cout << endl;

    int rand_vector[1000];
    // 初始化随机种子
    srand(time(0)); 

    // 生成随机数组
    for (int i = 0; i < 1000; i++) 
    {
        rand_vector[i] = rand() % 100; // 生成0~99之间的随机数
    }

    Vector UnSesrchbubble(1000, -1);
    UnSesrchbubble.add_vector(rand_vector, 0, 1000);

    Vector UnSesrchmerge(1000, -1);
    UnSesrchmerge.add_vector(rand_vector, 0, 1000);

    clock_t start_bubble = clock();
    UnSesrchbubble.bubblesort(0, 1000);
    clock_t stop_bubble = clock();
    cout << "time of bubble:" << double(stop_bubble - start_bubble) / CLOCKS_PER_SEC << endl;
    clock_t start_merge = clock();
    UnSesrchmerge.mergeSort(0, 1000);
    clock_t stop_merge = clock();
    cout << "time of merge:" << double(stop_merge - start_merge) / CLOCKS_PER_SEC << endl;

    return 0;
}