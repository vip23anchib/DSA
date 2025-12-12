#include <bits/stdc++.h>
using namespace std;

int main() {

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // 30

    st.pop(); // removes 30

    cout << "Top after pop: " << st.top() << endl; // 20

    cout << "Size: " << st.size() << endl; // 2

    // Printing all elements
    cout << "Stack contents: ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    return 0;
}
