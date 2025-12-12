#include<bits/stdc++.h>
using namespace std;

void Vector(){
    vector<int> v = {2, 5, 10, 15};
    v.push_back(1);
    v.emplace_back(2);
    for (int x : v)
    cout << x << endl;

    vector<pair<int,int>> vec;
    vec.push_back({2,3});
    vec.emplace_back(2,4);

    vector<int>a(5);
    cout<<a.at(1)<< " printed vector: a"<<endl;
    vector<int>b(5,100);
    cout<<b.at(1)<< " printed vector: b"<<endl;

    vector<int>::iterator it = v.begin();//iterator points to memory address NOT elemnt
    it++;                               // move to second element
    cout << *(it) << " hi"<<endl;               // prints 5

    it = it + 2;                        // move 2 steps forward
    cout << *(it) << "there "<<endl;               // prints 15


  vector<int>::iterator it1 = v.end();              // points AFTER last element
  vector<int>::reverse_iterator it2 = v.rend();     // points BEFORE first (reverse)
  vector<int>::reverse_iterator it3 = v.rbegin();  

    //  accessing elements 
    cout << v[0] << " " << v.at(0) << endl;   // both print 2
    cout << v.back() << " "<<endl;                


    //  normal iterator loop
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " normal"<<endl;
    }

    cout << endl;

    // using auto iterator 
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << "auto "<<endl;
    }

    
    // erase examples
    vector<int> k = {10, 20, 12, 23};

    k.erase(k.begin() + 1);
    // result → {10, 12, 23}

    k = {10, 20, 12, 23, 35};
    k.erase(v.begin() + 2, k.begin() + 4);
    // result → {10, 20, 35}   // [start, end)


    //insert examples
    vector<int> v2(2, 100);               
    // v2 = {100, 100}

    v2.insert(v2.begin(), 300);
    // v2 = {300, 100, 100}

    v2.insert(v2.begin() + 1, 2, 10);
    // v2 = {300, 10, 10, 100, 100}

    vector<int> copy(2, 50);              
    // copy = {50, 50}

    v2.insert(v2.begin(), copy.begin(), copy.end());
    // v2 = {50, 50, 300, 10, 10, 100, 100}

    // size example 
    vector<int> v3 = {10, 20};
    cout << v3.size() << endl; // prints 2

    // pop_back 
    v3.pop_back();
    // v3 = {10}

    // swap 
    vector<int> v1 = {10, 20};
    vector<int> v4 = {30, 40};

    v1.swap(v4);
    // v1 = {30, 40}
    // v4 = {10, 20}

    v.clear();// erases entire vector
    cout<<v.empty()<< endl;
    
}
    


int main(){
    Vector();
    return 0;
}