#include<bits/stdc++.h>
using namespace std;

void Vector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    for (int x : v)
    cout << x << endl;


}
int main(){
    Vector();
    return 0;
}