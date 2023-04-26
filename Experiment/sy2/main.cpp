#include "head.h"
using namespace std;

int main()
{
    // array 1;
    int array[20] = {1, 3, 4, 6, 7, 8, 9, 9, 10, 22};
    cout << "array: {1, 3, 4, 6, 7, 8, 9, 9, 10, 22}" << endl;
    Array arr(10, array);
    cout << "insert 0, 9" << endl; 
    arr.insert(0, 9);
    arr.show();
    cout << "insert 0, 4" << endl; 
    arr.insert(0, 4);
    arr.show();
    cout << "insert 1, 5" << endl; 
    arr.insert(1, 5);
    arr.show();
    cout << "insert 3, 6" << endl; 
    arr.insert(3, 6);
    arr.show();
    cout << endl;

    // array1
    int array1[20] = {1, 3, 4, 6, 7, 8, 9, 9, 10, 22};
    cout << "array1: {1, 3, 4, 6, 7, 8, 9, 9, 10, 22}" << endl;
    Array arr1(10, array1);

    arr1.removeDuplicates2();
    cout << "position of number 10: " << arr1.findIndex(10) << endl;

    cout << "after removeDuplicates: " << endl;
    arr1.show();
    cout << endl;

    // array 2
    cout << "array2: {1, 3, 4, 10, 8, 9, 22, 6, 7, 9}" << endl;
    int array2[20] = {1, 3, 4, 10, 8, 9, 22, 6, 7, 9};
    Array arr2(10, array2);
    
    arr2.removeDuplicates2();
    cout << "position of number 9: " << arr2.findIndex(9) << endl;
    cout << "after removeDuplicates: " << endl;
    arr2.show();

    cout << endl;

    // plus
    cout << "array3: {1, 3, 4, 10, 8, 9, 22, 6, 7, 9}" << endl;
    int array3[20] = {1, 3, 4, 10, 8, 9, 22, 6, 7, 9};
    Array arr3(10, array3);
    cout << "if orderly: " << arr3.judege() << endl;

    arr3.removeDuplicates2();
    arr3.show();

    return 0;
}