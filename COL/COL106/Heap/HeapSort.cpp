// using basic insertion method, we can make a heap in O(nlogn) time complexity

// but using heapify, we can create a heap in O(n)
// HEAPIFY

#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void heapify(vector<int> a, int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (largest == n - 1 || (l == n - 1 && r == n - 1))
    {
        return;
    }
    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(a, i, largest);
        heapify(a, n, largest);
    }
}

void buildheap(vector<int> a, int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(a, n, i);
    }
}

void heapSort(vector<int> a, int n)
{
    for (int i = n; i > 1; i--) // n
    {
        swap(a, 1, i);
        heapify(a, i-1, 1); // log n
    }
    
}
// overall O(nlogn)

int main()
{
    return 0;
}