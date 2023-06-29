#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(3); // hence has variable size
    v.push_back(2);
    v.push_back(1);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    for (auto x : v)
    {
        cout << x << endl; // like for ele in arr: from python
    }
    v.pop_back(); // pops the last element
    string a = "hatti";
    string b = a + a;
    cout << b << endl; // hattihatti
    cout << b.substr(0, 5) << endl;
    
    return 0;
}