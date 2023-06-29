#include <iostream>
using namespace std;

int main()
{
	for (int n = 3; n <= 2022; n++)
	{
		int sum = 0;
		for (int i = n + 1; i <= 2 * n; i++)
		{
			sum = sum + i * i * i;
		}
		int flag = 0;

		for (int j = 1; j <= sum / 2; j++)
		{
			if (sum == j * j)
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			cout << n << endl;
		}
	}
	return 0;
}