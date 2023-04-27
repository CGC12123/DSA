#include "../template/vector.h"

#include "iostream"
#include <algorithm>
using namespace std;

int main()
{
    Vector UnSesrchA(9, -1);
    int UnSortedVector31[20] = {2, 5, 4, 7, 4, 9, 8, 9, 12};
    UnSesrchA.add_vector(UnSortedVector31, 0, 9);
    cout << "array: ";
    UnSesrchA.show();

    cout << "after sort:" << endl;
    UnSesrchA.Sort();
    UnSesrchA.show();

    cout << endl;

    cout << "Question1: find 4 in [1, 8):" << endl;
    cout << " using binSearchA: " << UnSesrchA.binSearchA(4, 1, 8) << endl;
    cout << " using binSearchC: " << UnSesrchA.binSearchC(4, 1, 8) << endl;
    cout << endl;

    cout << "Question2: find 9 in [1, 8):" << endl;
    cout << " using binSearchA: " << UnSesrchA.binSearchA(9, 1, 8) << endl;
    cout << " using binSearchC: " << UnSesrchA.binSearchC(9, 1, 8) << endl;
    cout << endl;


    cout << "Question3: find 2 in [1, 8):" << endl;
    cout << " using binSearchA: " << UnSesrchA.binSearchA(2, 1, 8) << endl;
    cout << " using binSearchC: " << UnSesrchA.binSearchC(2, 1, 8) << endl;
    cout << endl;
    

    cout << "Question4: find 12 in [1, 8):" << endl;
    cout << " using binSearchA: " << UnSesrchA.binSearchA(12, 1, 8) << endl;
    cout << " using binSearchC: " << UnSesrchA.binSearchC(12, 1, 8) << endl;

    return 0;
}