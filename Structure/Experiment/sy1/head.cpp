#include "head.h"

void bubble(int A[], int n)
{
    int num_scan = 0, num_change = 0;
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        int i;
        for (i = 0; i < n - 1; i++)
        {
            num_scan++;
            if (A[i] > A[i + 1])
            {
                num_change++;
                swap(A[i], A[i + 1]);
                sorted = false;
            }
        }
        num_scan++;
    }
    cout << "num_scan: " << num_scan << endl;
    cout << "num_change: " << num_change << endl;
}