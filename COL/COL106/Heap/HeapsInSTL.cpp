#include <bits/stdc++.h>
using namespace std;

// priority queue
// push O(logn)
// pop O(logn)
// top O(1)
// size O(1)

int main()
{
    // Max heap
    priority_queue<int, vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout << pq.top() << endl; // 3
    pq.pop();
    cout << pq.top() << endl; // 2

    // min heap
    priority_queue<int, vector<int>, greater<int>> mpq;
    mpq.push(2);
    mpq.push(3);
    mpq.push(1);

    cout << mpq.top() << endl; // 3
    mpq.pop();
    cout << mpq.top() << endl; // 2
    return 0;
}