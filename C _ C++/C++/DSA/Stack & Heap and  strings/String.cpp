// no  need to define the size of the string, hence dynamic
// larger size of char array need to be defind for concatenation, whereas string is much better
// char array has no terminating char
//  string has '\0'
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str; // without spaces
    cout << str << endl;
    // diff types to declare a string
    string str1(5, 'n');
    cout << str1 << endl;
    string str2 = "ApniKaksha"; // no space!!
    str2.clear();               // O(1)
    // with spacess
    string sen;
    getline(cin, sen);
    cout << sen << endl;
    string s1 = "fam";
    string s2 = "ily";
    s1.append(s2);           // s1 = family
    cout << s1 + s2 << endl; // concatenation O(N) N = size of new string
    // comparing strings
    string a1 = "abc";
    string a2 = "xyz";
    cout << s2.compare(s1) << endl;
    string sa = "nincompoop";
    sa.erase(3, 3); // O(N)
    cout << sa << endl;
    cout << s1.find("a") << endl; // O(N)
    sa.insert(2, "lol");          // O(N)
    sa.length();                  // O(1)
    sa.resize(6);                 // O(N)
    sa.size();                    // O(1)
    sa.substr(3, 4);              // O(N)
    int x = stoi(sa);
    cout << x + 2 << endl;
    int y = 786;
    cout << to_string(y) << endl;
    sort(sa.begin(), sa.end());
    cout << sa << endl;
    return 0;
}