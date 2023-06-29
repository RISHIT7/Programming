#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(5);
    s.count(3); // 1
    set<int> k = {2, 2, 5, 5, 8};
    k.count(5); // 1, only unique elements
    multiset<int> l = {2, 2, 5, 5, 8};
    l.count(5); // 2, may coutain same element
    k.erase(5); // removes all the instances
    // if only one instance is to be removed
    l.erase(l.find(5));
    return 0;
}