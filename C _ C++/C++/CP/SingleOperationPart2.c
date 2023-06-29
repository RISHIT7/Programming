#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, count=0, value = 0;
        scanf("%d", &n);
        char str[n];
        scanf("%s", str);
        for (int i = n-1; i >= 0; i--)
        {
            if (str[i] == '1')
            {
                value += pow(2, count);
            }
            count += 1;
        }
        int y, min = value;
        for (int i = 1; i <= n ; i++)
        {
            int temp = value/pow(2, i);
            int tem = value^temp;
            if (min >= tem)
            {
                min = tem;
                y = i;
            }
        }
        printf("%d\n", y);
    }
    return 0;
}