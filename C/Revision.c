#include <stdio.h>

int setBits(int a)
{
    int count = 0;
    while (a > 0)
    {
        if (a % 2 == 1)
        {
            count += 1;
        }
        a /= 2;
    }

    return count;
}

int coPrime(int a)
{
    int count = 0;
    for (int i = 1; i < a; i++)
    {
        if (a % i != 0)
        {
            count += 1;
        }
    }
    return count + 1;
}

int isMersenne(int a)
{
    a += 1;
    while (a != 1)
    {
        if (a % 2 == 1)
        {
            return 0;
        }
        a /= 2;
    }
    return 1;
}

int main()
{
    int a;
    scanf("%d", &a);
    while (a != -1)
    {
        // all the stuff
        if (a == 1)
        {
            printf("(%d, %d, %d)\n", 1, 0, 0);
        }
        else
        {
            printf("(%d, %d, %d)\n", setBits(a), coPrime(a), isMersenne(a));
        }
        scanf("%d", &a);
    }

    return 0;
}