#include <iostream>
#include <utility>
#include "head.h"
using namespace std;



int main()
{
    int A[7] = {5, 2, 7, 4, 6, 3, 1};
    int j;
    cout << "origin nums: " << endl;
    for (j = 0; j < 7; j ++)
    {
        cout << A[j] << ",";
    }
    cout << endl;
    int n = 7;
    bubble(A, n);
    cout << "sorted: " << endl;
    for (j = 0; j < 7; j ++)
    {
        cout << A[j] << ",";
    }
    return 0;
}