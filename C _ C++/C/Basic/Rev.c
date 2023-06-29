#include <stdio.h>

void func(int n, int[] ans, int j)
{
    if (n <= 0)
    {
        int i = 0;
        while (ans[i] != 0)
        {
            i++;
        }
        printf("%d", i);
    }
    else
    {
        int i = 0;
        printf("%d", n);

        while (((i + 1) * (i + 1) <= n) or (i * i > n))
        {
            i++;
        }

        ans[j] += i;
        j++;

        func(n - (i * i), ans, j);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int[] ans = {0} * n;
    func(n, ans, 0);

    return 1;
}