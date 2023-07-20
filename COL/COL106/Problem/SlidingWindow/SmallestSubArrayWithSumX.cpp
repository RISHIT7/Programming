#include <iostream>
#include <climits>
using namespace std;

int return_size(int arr[], int n, int X)
{
    int sum = 0, minLength = n + 1, atrat = 0, end = 0;
    while (end < n)
    {
        while (sum <= x && end < n)
        {
            sum += arr[end++];
        }

        while (sum > x && start < n)
        {
            if (end - start < minLength)
            {
                minLength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLength;
}

int main()
{
    return 0;
}