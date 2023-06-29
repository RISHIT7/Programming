#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        int tests = 0;
        string res;
        for (int j = 0; j < N; j++)
        {
            int i = 0;
            string s, r;
            cin >> s >> r;
            for (int k = 0; k < M; k++)
            {
                if (r[k] == '1')
                {
                    i += 1;
                }
            }
            if ((s == "correct") && (i == M))
            {
                tests += 1;
            }
            else if ((s == "correct") && (i != M))
            {
                res = "INVALID";
            }
            else if ((s == "wrong") && (i != M))
            {
                tests += 1;
            }
            else if ((s == "wrong") && (i == M) && (res != "INVALID"))
            {
                res = "WEAK";
            }
        }
        if (tests == N)
        {
            cout << "FINE" << endl;
        }
        else
        {
            cout << res << endl;
        }
    }
    return 0;
}
