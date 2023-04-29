#include "../template/vector.h"

int main()
{
    Vector UnSesrchA(7, -1);
    int UnSortedVector31[7] = {2, 5, 4, 9, 8, 12, 7};
    UnSesrchA.add_vector(UnSortedVector31, 0, 7);
    cout << "array: ";
    UnSesrchA.show();
    return 0;
}