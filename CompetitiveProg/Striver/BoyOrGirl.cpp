#include <iostream>
#include <set>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;

    set<char> st;
    for (char c : s)
        st.insert(c);
    
    st.size() % 2 == 0 ? cout << "CHAT WITH HER!" : cout << "IGNORE HIM!";

    return 0;
}