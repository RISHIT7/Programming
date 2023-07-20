#include <bits/stdc++.h>
using namespace std;

/*
complete binary trees may be implemented as a array
*/

void swap(vector<int> A, int idx1, int idx2)
{
    int temp = A[idx1];
    A[idx1] = A[idx2];
    A[idx2] = temp;
}

void insert(vector<int> A, int n, int values)
{
    n = n + 1;
    A.push_back(values);
    int i = n;
    while (i > 1)
    {
        int parent = i / 2;
        if (A[parent] < a[i])
        {
            swap(A, parent, i);
            i = parent;
        }
        else
        {
            return;
        }
    }
}

void deletion(vector<int> A, int n)
{
    A[1] = A[n];
    n = n - 1;
    while (i < n)
    {
        int left = A[2 * i];
        int right = A[2 * i + 1];
        int larger = left > right ? 2 * i : 2 * i + 1;
        if (A[i] < A[larger])
        {
            swap(A, i, larger);
            i = larger;
        }
        else
        {
            return;
        }
    }
}