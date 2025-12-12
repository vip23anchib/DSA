#include <bits/stdc++.h>
using namespace std;

int main() {

    set<int> s;

    s.insert(5);
    s.insert(1);
    s.insert(3);
    s.insert(5);   // ignored duplicate

    // print
    for (int x : s) cout << x << " ";
    cout << endl;

    // find
    auto it = s.find(3); //returns an iterator pointing to 3 
    if (it != s.end()) cout << "3 found\n";

    // erase by value
    s.erase(1);

    //cound
    int c=s.count(1);

    // erase using iterator
    it = s.find(5);
    if (it != s.end()) s.erase(it);

    set<int> se={1,2,3,4,5};
    auto it1=se.find(2);
    auto it2=se.find(3);
    se.erase(it1,it2);//{1,4,5}

    // boundaries
    s.insert(4);
    s.insert(7);
    s.insert(9);

    cout << "lower_bound(6): " << *s.lower_bound(6) << endl;  // 7
     it=s.lower_bound(7);
    cout <<*it<<endl;
    cout << "upper_bound(7): " << *s.upper_bound(7) << endl;  // 9

    return 0;
}
