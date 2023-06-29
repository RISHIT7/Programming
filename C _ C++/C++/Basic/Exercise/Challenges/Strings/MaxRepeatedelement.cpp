#include <iostream>
using namespace std;

int main()
{
    // METHOD 1 O(N^2)//
    // string s;
    // cin >> s;
    // int Max = INT_MIN;
    // for (int i = 0; i < s.length(); i++)
    // {
    //     int count = 0;
    //     for (int j = 0; j < s.length(); j++)
    //     {
    //         if (s[i] == s[j])
    //         {
    //             count += 1;
    //         }
    //     }
    //     Max = max(count, Max);
    // }
    // cout << Max << endl;
    // METHOD 2 O(N)//
    string s;
    cin >> s;
    int freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }
    char ans = 'a';
    int max = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > max)
        {
            max = freq[i];
            ans = i + 'a';
        }
    }
    cout << max << " " << ans << endl;
    return 0;
}