#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int temp{};
    int m{}, n{};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> temp;
            if (temp == 1)
            {
                m = i;
                n = j;
                break;
            }
        }
    }
    cout << abs(2 - m) + abs(2 - n) << endl;
    return 0;
}
