#include<bits/stdc++.h>
using namespace std;

void Vector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    for (int x : v)
    cout << x << endl;

    vector<pair<int,int>> vec;
    v.push_back({2,3});
    v.emplace_back(2,4);

    vector<int>a(5);
    vector<int>b(5,100);

    vector<int>::iterator it = v.begin();//iterator points to memory address NOT elemnt
    it++;                               // move to second element
    cout << *(it) << " ";               // prints 5

    it = it + 2;                        // move 2 steps forward
    cout << *(it) << " ";               // prints 10


    // ---------------- end(), rend(), rbegin() ----------------
    vector<int>::iterator it1 = v.end();    // points AFTER last element
    vector<int>::iterator it2 = v.rend();   // points BEFORE first (reverse)
    vector<int>::iterator it3 = v.rbegin(); // points to last element

    // ---------------- accessing elements ----------------
    cout << v[0] << " " << v.at(0) << " ";   // both print 2
    cout << v.back() << " ";                 // prints 15


    // ---------------- normal iterator loop ----------------
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    cout << endl;

    // ---------------- using auto iterator ----------------
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    return 0;
    


}
int main(){
    Vector();
    return 0;
}