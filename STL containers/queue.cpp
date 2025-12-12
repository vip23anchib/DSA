#include <bits/stdc++.h>
using namespace std;

int main() {

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.emplace(40);    // 10 20 30 40

    cout << "Front: " << q.front() << endl;  // 10
    cout << "Back:  " << q.back()  << endl;  // 40

    q.pop(); // removes 10

    cout << "Front after pop: " << q.front() << endl; // 20

    cout << "Queue contents: ";
    queue<int> temp = q; 
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }

    return 0;
}
