#include <bits/stdc++.h>
using namespace std;

int main() {

    deque<int> dq = {10, 20, 30};

    dq.push_front(5);       // 5 10 20 30
    dq.push_back(40);       // 5 10 20 30 40
    dq.emplace_front(2);    // 2 5 10 20 30 40
    dq.emplace_back(50);    // 2 5 10 20 30 40 50

    // Accessing
    cout << dq.front() << endl;   // 2
    cout << dq.back()  << endl;   // 50
    cout << dq[3]      << endl;   // 20

    // Erasing
    dq.erase(dq.begin() + 2);     // remove element at index 2

    dq.pop_back();
    dq.pop_front();

    // Printing
    for (int x : dq) {
        cout << x << " ";
    }

    return 0;
}
