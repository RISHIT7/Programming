#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// #define int long long
#define ll long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define print_any(vec)     \
    for (auto value : vec) \
        cout << value << " ";
#define next_line cout << endl;

const int N = 1e5 + 2, MOD = 1e9 + 7;

vector<int> computeLPSArray(string pat, int M, vector<int> lps)
{
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    vector<int> lps(M);

    lps = computeLPSArray(pat, M, lps);    

    int i = 0;
    int j = 0;

    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

signed main()
{
    string sentence = "I am what I am";
    int length_sentence = sentence.size();
    string query = "I a";
    int query_sentence = query.size();

    KMPSearch(query, sentence);
    return 0;
}

int main()
{
    SearchEngine *choogle = new SearchEngine();

    choogle->insert_sentence(2, 3, 4, 5, "I am who I am");
    choogle->insert_sentence(2, 3, 4, 6, "I alskdjf aad fad");
    choogle->insert_sentence(2, 3, 4, 7, "I kjlf ashd flsd fad adf");
    choogle->insert_sentence(2, 3, 4, 8, "I  sdfla ldfas ddfja sld");
    choogle->insert_sentence(2, 3, 4, 9, "I s hdkfka lf fladf asfd I s hdkfka lf fladf asfd");
    choogle->insert_sentence(2, 3, 4, 873, "I s hdkfka lf fladf asfd hdkfka lf fladf asfd");
    choogle->insert_sentence(2, 3, 4, 10, "I a sdfh asfhf asffa sd");
    choogle->insert_sentence(2, 3, 4, 11, "I alksd fka fkd a df f");
    choogle->insert_sentence(2, 3, 4, 12, "I kasd hfkah fd kha df f");

    int matches = 0;
    choogle->search("kfka lf fl", matches);

    return 0;
}
