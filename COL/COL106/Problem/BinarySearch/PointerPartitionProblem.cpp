#include <iostream>
#include <climits>
using namespace std;

int findFeasible(int boards[], int n, int limit)
{
    int sum = 0, painters = 1;
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
        if (sum >limits)
        {
            sum = boards[i];
            painters++;
        }
    }
    return painters;
}

int paintersPartition(int boards[], int n, int m)
{
    int total = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        k = max(k, boards[i]);
        total += boards[i];
    }

    int low = k, high = total;
    while (low < high)
    {
        int mid = (low + high) / 2;
        int painters = findFeasible(boards, n, mid);
        if (painters <= m)
        {
            high = mid;
        }
        else
        {
            low = mid - 1;
        }
    }
    return low;
}

int main()
{
    return 0;
}