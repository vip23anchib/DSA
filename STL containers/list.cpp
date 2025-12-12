#include <bits/stdc++.h>
using namespace std;

void List(){
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(5);
    ls.emplace_front(6);
    // ls now: 6 5 2 4

    auto it = ls.begin();// inserting at specific position
    advance(it, 2);            // move iterator to 3rd element (points to 2)
    ls.insert(it, 50);         // insert 50 before it -> 6 5 50 2 4
    ls.insert(it, 3, 100);     // insert three 100s before it

    if (!ls.empty()) ls.pop_back();
    if (!ls.empty()) ls.pop_front();

    if (ls.size() > 1) {
        auto it2 = ls.begin();
        advance(it2, 1);
        ls.erase(it2);
    }

    ls.remove(20); // safe even if 20 not present

    // accessing elements
    if (!ls.empty()) cout << "front: " << ls.front() << endl;
    if (!ls.empty()) cout << "back:  " << ls.back()  << endl;

    cout << "iterate with iterator:" << endl;
    for (auto it2 = ls.begin(); it2 != ls.end(); ++it2) {
        cout << *it2 << " it" << endl;
    }

    cout << "range-based loop:" << endl;
    for (int x : ls) {
        cout << x << " for " << endl;
    }

    for_each(ls.begin(), ls.end(), [](int x){ //STL algorithm + lambda function combo.
    cout << x << " ";
                 });
}

int main(){
    List();
    return 0;
}
