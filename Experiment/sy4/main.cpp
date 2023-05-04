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
    cout << endl;

    Vector UnSesrchbubble(8, -1);
    UnSesrchbubble.add_vector(UnSortedVector31, 0, 8);

    Vector UnSesrchmerge(8, -1);
    UnSesrchmerge.add_vector(UnSortedVector31, 0, 8);

    clock_t start_bubble = clock();
    UnSesrchbubble.bubblesort(0, 7);
    clock_t stop_bubble = clock();
    cout << "time of bubble:" << double(stop_bubble - start_bubble) / CLOCKS_PER_SEC << endl;
    clock_t start_merge = clock();
    UnSesrchmerge.mergeSort(0, 7);
    clock_t stop_merge = clock();
    cout << "time of merge:" << double(stop_merge - start_merge) / CLOCKS_PER_SEC << endl;

    return 0;
}