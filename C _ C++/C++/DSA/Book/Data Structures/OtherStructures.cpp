#include <iostream>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

int main()
{

    bitset<10> s; // it is an array for bits
    s[1] = 1;
    s[3] = 1;
    s[4] = 1;
    s[7] = 1;
    bitset<10> S(string("0010011010")); // from right to left
    cout << s[4] << endl; // 1 
    cout << s[5] << endl; // 0
    cout << s.count() << endl; // 4, return the number of ones
    // &, ^, | are and, xor, or, operators respectively

    deque <int> d;
    d.push_back(5);
    d.push_back(2);
    d.push_front(3); // [3, 5, 2]
    d.pop_back();
    d.pop_front(); // a dual directional list
    // adding and removing an element is done in O(1) time complexity

    stack <int> st; // filo
    st.push(3); 
    st.push(2);
    st.push(5);
    st.top(); // 5
    st.top(); // 2

    queue<int> q; // fifo // only possible to access first and last element which are added in O(1)
    q.push(3);
    q.push(2);
    q.push(5);
    cout<<q.front()<<endl; // 3
    q.pop();
    cout<<q.front()<<endl; // 2

    priority_queue<int> pq;
    // search from documentation
    return 0;
}