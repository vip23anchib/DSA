#include <bits/stdc++.h>
using namespace std;

void explainPQ() {

    //MAX HEAP (default)
    priority_queue<int> pq;

    pq.push(5);     // {5}
    pq.push(2);     // {5, 2}
    pq.push(8);     // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top() << endl;   // prints 10  (max element)

    pq.pop();                   // removes 10 → {8, 5, 2}

    cout << pq.top() << endl;   // prints 8


    // size(), empty(), swap() behave same as other containers


    // ---------------- MIN HEAP ----------------
    priority_queue<int, vector<int>, greater<int>> mpq;

    mpq.push(5);     // {5}
    mpq.push(2);     // {2, 5}
    mpq.push(8);     // {2, 5, 8}
    mpq.emplace(10); // {2, 5, 8, 10}

    cout << mpq.top() << endl;  // prints 2  (smallest element)
}

int main() {
    explainPQ();
    return 0;
}
