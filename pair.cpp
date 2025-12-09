#include <bits/stdc++.h>
using namespace std;

void Pair() {
    pair<int,int> p = {1, 3};
    cout<<p.first<<" "<<p.second<<endl;
    pair<int, pair<int,int>> d={1,{3,4}};
    cout<<d.first<< " "<<d.second.second<<" "<< d.second.first<<endl;
    pair<int, int> arr[]={ {2,3},{2,4},{1,8}};
    cout<<arr[1].second;
}
int main() {
    Pair();   
    return 0;
}