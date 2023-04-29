#include "../template/vector.h"

int main()
{
    Vector UnSesrchA(7, -1);
    int UnSortedVector31[] = {2, 5, 4, 1, 9, 8, 12, 7};
    UnSesrchA.add_vector(UnSortedVector31, 0, 8);
    UnSesrchA.show();
    
    UnSesrchA.mergeSort(0, 7);
    UnSesrchA.show();
    return 0;
}