#include "../template/vector.h"

int main()
{
    Vector vec(7, -1);

    Vector UnSesrchA(7, -1);
    int UnSortedVector31[7] = {2, 5, 4, 9, 8, 12, 7};
    UnSesrchA.add_vector(UnSortedVector31);
    cout << "array: ";
    UnSesrchA.show();

    cout << "after sort:" << endl;
    UnSesrchA.Sort();
    UnSesrchA.show();

    cout << endl;
    cout << "Question1: : using binSearchA" << endl;
    cout << "find 7 in [1, 5):" << endl;
    if (UnSesrchA.binSearchA(7, 1, 5) != -1)
        cout << UnSesrchA.binSearchA(7, 1, 5) << endl;
    else
        cout << "nofind" << endl;

    cout << "find 2 in [1, 5):" << endl;
    if (UnSesrchA.binSearchA(2, 1, 5) != -1)
        cout << UnSesrchA.binSearchA(2, 1, 5) << endl;
    else
        cout << "nofind" << endl;

    cout << "find 12 in [1, 5):" << endl;
    if (UnSesrchA.binSearchA(12, 1, 5) != -1)
        cout << UnSesrchA.binSearchA(12, 1, 5) << endl;
    else
        cout << "nofind" << endl;

    cout << endl;
    /////////////////////////////////////////////////
    cout << "Question2: : using binSearchB" << endl;

    cout << "find 7 in [1, 5):" << endl;
    if (UnSesrchA.binSearchB(7, 1, 5) != -1)
        cout << UnSesrchA.binSearchB(7, 1, 5) << endl;
    else
        cout << "nofind" << endl;

    cout << "find 2 in [1, 5):" << endl;
    if (UnSesrchA.binSearchB(2, 1, 5) != -1)
        cout << UnSesrchA.binSearchB(2, 1, 5) << endl;
    else
        cout << "nofind" << endl;

    cout << "find 12 in [1, 5):" << endl;
    if (UnSesrchA.binSearchB(12, 1, 5) != -1)
        cout << UnSesrchA.binSearchB(12, 1, 5) << endl;
    else
        cout << "nofind" << endl;
    cout << endl;
    ///////////////////////////////////////////////////////
    cout << "Question3: using binSearchC" << endl;

    cout << "find 7 in [1, 5):" << endl;
    cout << UnSesrchA.binSearchC(7, 1, 5) << endl;

    cout << "find 2 in [1, 5):" << endl;
    cout << UnSesrchA.binSearchC(2, 1, 5) << endl;

    cout << "find 12 in [1, 5):" << endl;
    cout << UnSesrchA.binSearchC(12, 1, 5) << endl;

    return 0;
}